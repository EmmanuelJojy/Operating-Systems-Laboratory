echo -n "N: "
read n

sum=0
echo "Enter Numbers: "
for ((i=0; i<n; i++))
do
	read a
	((sum += a))
done

((avg = sum / n))
echo "Average = $avg"
