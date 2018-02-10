#!/bin/bash

player[0]=players/abanlin.filler
player[1]=players/carli.filler
player[2]=players/champely.filler
player[3]=players/grati.filler
player[4]=players/hcao.filler
player[5]=players/superjeannot.filler

me=./oantonen.filler

map=(maps/map00 maps/map01 maps/map02)

out=project/fight1.txt

stati=project/statistica.txt

runs=10;

x_wins=0;

if [[ $3 = 0 ]]
then

./filler_vm -p2 ${player[$1]} -p1 ${me} -f ${map[$2]} > ${out}
sed -e 's/x/+/g; s/o/-/g' project/fight1.txt > project/fight.txt
o_figures=$(grep "== O" project/fight.txt | sed 's/[^0-9]*//g')
x_figures=$(grep "== X" project/fight.txt | sed 's/[^0-9]*//g')
# echo "== O fin: $o_figures"
# echo "== X fin: $x_figures"

else
	rm project/statistica2.txt

	while [ $runs -gt 0 ]
	do
	./filler_vm -p2 ${player[$1]} -p1 ${me} -f ${map[$2]} -q > ${stati}
	sed -e '/#/d' ${stati} >> project/statistica2.txt
	o_figures=$(grep "== O" project/statistica.txt | sed 's/[^0-9]*//g')
	x_figures=$(grep "== X" project/statistica.txt | sed 's/[^0-9]*//g')
		if [[ $x_figures -gt $o_figures ]]
		then
		x_wins=$(( x_wins + 1 ))
		fi
	echo "Numbers of runs left = $runs"
	runs=$[ $runs - 1 ]

	done
	o_wins=$(( 10 - $x_wins ))
	echo "X is winning with a score $x_wins : $o_wins" >> project/statistica2.txt
	echo "X is winning with a score $x_wins : $o_wins" 
	
fi
