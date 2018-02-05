#!/bin/bash

player[0]=abanlin.filler
player[1]=carli.filler
player[2]=champely.filler
player[3]=grati.filler
player[4]=hcao.filler
player[5]=superjeannot.filler

map=(map00 map01 map02)

if [[ $3 = 0 ]]
then

./filler_vm -p1 players/${player[$1]} -p2 ./oantonen.filler -f maps/${map[$2]} > project/fight1.txt
sed -e 's/x/+/g; s/o/-/g' project/fight1.txt > project/fight.txt

else

./filler_vm -p1 players/${player[$1]} -p2 ./oantonen.filler -f maps/${map[$2]} 

fi
