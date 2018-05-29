#!/bin/bash

player[0]=resources/players/abanlin.filler
player[1]=resources/players/carli.filler
player[2]=resources/players/champely.filler
player[3]=resources/players/grati.filler
player[4]=resources/players/hcao.filler
player[5]=resources/players/superjeannot.filler

me=./oantonen.filler

map=(resources/maps/map00 resources/maps/map01 resources/maps/map02)

out=out/fight1.txt

stati=out/statistica.txt

runs=10;

x_wins=0;

if [[ $4 = X ]]
	then
	me="-p2 ./oantonen.filler"
	him="-p1 ${player[$1]}"
fi

if [[ $4 = O ]]
	then
	me="-p1 ./oantonen.filler"
	him="-p2 ${player[$1]}"
fi

if [[ $3 = 0 ]]
then

./resources/filler_vm ${him} ${me} -f ${map[$2]} > ${out}
sed -e 's/x/+/g; s/o/-/g' out/fight1.txt > out/fight.txt
o_figures=$(grep "== O" out/fight.txt | sed 's/[^0-9]*//g')
x_figures=$(grep "== X" out/fight.txt | sed 's/[^0-9]*//g')
echo "== O fin: $o_figures"
echo "== X fin: $x_figures"
rm out/fight1.txt

fi

if [[ $3 = 1 ]]
then

./resources/filler_vm ${him} ${me} -f ${map[$2]} 

fi

if [[ $3 = 2 ]]
	then
	rm out/statistica2.txt

	while [ $runs -gt 0 ]
	do
	./resources/filler_vm ${him} ${me} -f ${map[$2]} -q > ${stati}
	sed -e '/#/d' ${stati} >> out/statistica2.txt
	o_figures=$(grep "== O" out/statistica.txt | sed 's/[^0-9]*//g')
	x_figures=$(grep "== X" out/statistica.txt | sed 's/[^0-9]*//g')
		if [[ $x_figures -gt $o_figures ]]
		then
		x_wins=$(( x_wins + 1 ))
		fi
	echo "Numbers of runs left = $runs"
	runs=$[ $runs - 1 ]

	done
	o_wins=$(( 10 - $x_wins ))
	echo "X is winning with a score $x_wins : $o_wins" >> out/statistica2.txt
	echo "X is winning with a score $x_wins : $o_wins" 

fi
