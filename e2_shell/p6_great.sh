# Q3
# Greatest
echo -n "a: "
read a
echo -n "b: "
read b
echo -n "c: "
read c

if ((a > b && a > c))
then
    echo "$a is greatest"
    
elif ((b > a && b > c))
then 
    echo "$b is greatest"

else
    echo "$c is greatest"
fi

