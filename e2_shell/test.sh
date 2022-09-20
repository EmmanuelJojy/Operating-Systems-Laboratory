var1=$1
var2=$2
if [[ $var1 -gt $var2 ]]
then
	echo "$var1 > $var2"
elif [[ $var1 -eq $var2 ]]
then
	echo "$var1 = $var2"
else
	echo "$var1 < $var2"
fi

((var3=var1+var2))
echo "Sum is $var3"

fact=1

for((i=1;i<=var3;i++))
do
	((fact*=i))
done 

echo "Factorial $fact"
