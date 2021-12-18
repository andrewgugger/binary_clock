#!/bin/bash


for h in {1..24}; do 
	for m in {0..59}; do
		for s in {0..59}; do 
			echo "$h:$m:$s"
			sleep .001
		done
	done
done	
