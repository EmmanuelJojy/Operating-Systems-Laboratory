a=$1
b=$2
echo "A = $a, B = $b"

((res = a + b))
echo "Sum = $res"

((res = a - b))
echo "Dif = $res"

((res = a * b))
echo "Pdt = $res"

((res = a / b))
echo "Div = $res"
