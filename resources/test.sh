#!/bin/sh

for i in $(seq $# -1 2)
do
	arg=${!i}
	./corewar $1 $arg | grep "has won" | grep "Contestant 2"
done
