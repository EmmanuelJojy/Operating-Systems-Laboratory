read number
fact=1

i=1
while((i<=number))
do
	((fact*=i))
	((i++))
done

echo "fact($number) = $fact"
