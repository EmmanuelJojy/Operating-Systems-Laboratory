# Q4
# Choice
echo "1. Area of Circle"
echo "2. Circumference of Circle"
echo "3. Area of Recatangle"
echo "4. Area of Square"

echo -n "Enter Choice: "
read ch

if ((ch == 1))
then 
    echo -n "R = "
    read r
    ((a = 22 / 7 * r * r))
    echo "Area = $a"

elif ((ch == 2))
then 
    echo -n "R = "
    read r
    ((a = 2 * 22 / 7 * r))
    echo "Circumference = $a"

elif ((ch == 3))
then 
    echo -n "L = "
    read l
    echo -n "B = "
    read b
    ((a = l * b))
    echo "Area = $a"

elif ((ch == 4))
then 
    echo -n "x = "
    read r
    ((a = r * r))
    echo "Area = $a"
    
else
    echo "Invalid Choice"
fi
