#!/bin/bash

cd `dirname $0`
wget -q -c "http://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"

OUT="../data/iris.in"

echo -n "( 4 3 " > "$OUT"
echo -n $[`wc -l iris.data | cut -f1 -d' '` - 1] >> "$OUT"
echo " )" >> "$OUT"

echo "(" >> "$OUT"
(
cat "iris.data" | while read LN
	do
		if [ ${#LN} -gt 2 ]
		then
			echo -ne "\t( ( "${LN:0:15}" ) " | tr ',' ' '
			K=${LN:16}
			case "$K" in
				"Iris-setosa")		echo -n "( 1 0 0 )" ;;
				"Iris-versicolor")	echo -n "( 0 1 0 )" ;;
				"Iris-virginica")	echo -n "( 0 0 1 )" ;;
			esac
			echo " )"
		fi
	done)  >> "$OUT"
echo ")" >> "$OUT"
