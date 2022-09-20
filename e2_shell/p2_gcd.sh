a=$1
b=$2

echo -n "GCD($a, $b) = "

while ((b!=0))
do
	((t=b))
	((b=a%b))
	((a=t))
done

echo "$a"
