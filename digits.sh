echo "Avatansh Awasthi 1947208"

echo "Enter two three digits numbers"

echo -n "Enter the first number"
read n1

echo -n "Enter the second number"
read n2

sum=0
mul=1

while [ $n1 -gt 0 ]
do
	rem=$(($n1%10))
	n1=$(($n1/10))
	sum=$(($sum+$rem))
done

while [ $n2 -gt 0 ]
do
	rem=$(($n2%10))
	n2=$(($n2/10))
	mul=$(($mul*$rem))
done

result=$(($sum+$mul))

echo "Result : $result"
