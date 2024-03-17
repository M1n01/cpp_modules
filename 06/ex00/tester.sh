#!/bin/bash

ARG=("0" "nan" "42.0f" "+inf" "-inf" "+inff" "-inff" "nanf" "0.0" "0.0f")

for i in "${ARG[@]}"
do
	echo "Test with \"$i\""
	./convert $i
	echo "----------------"
done
