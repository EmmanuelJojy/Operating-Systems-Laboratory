# Shell Script
# P1 GCD
a=$1
b=$2

echo -n "GCD($a, $b) = "

while ((a!=b))
do
	if ((a>b))
	then
		((a=a-b))
	else
		((b=b-a))
	fi
done

echo "$a"
