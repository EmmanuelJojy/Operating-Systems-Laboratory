# Q5
# Fib
echo -n "n: "
read n

a=0
b=1

echo -n "fib series: $a $b "

((x = a + b))

while ((x < n))
do
    echo -n "$x "
    ((a = b))
    ((b = x))
    ((x = a + b))
done

echo ""
