# Q1
# OPERATOR 
echo -n "a: "
read a
echo -n "b: "
read b
echo -n "operator: "
read op

if [[ "$op" == "+" ]]
then
    ((res = a + b))
    echo "$res"
    
elif [[ "$op" == '-' ]]
then
    ((res = a - b))
    echo "$res"
    
elif [[ "$op" == '*' ]]
then
    ((res = a * b))
    echo "$res"
    
elif [[ "$op" == '/' ]]
then
    ((res = a / b))
    echo "$res"

else
    echo "Invalid operator"

fi
