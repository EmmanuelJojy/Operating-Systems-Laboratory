a=$1
b=$2
c=$3

if [[ $a > $c ]]
then
	temp=$a
	a=$c
	c=$temp
fi

if [[ $a > $b ]]
then
	temp=$a
	a=$b
	b=$temp
fi

if [[ $b > $c ]]
then
	temp=$b
	b=$c
	c=$temp
fi

echo "Alphabetic Order -> $a, $b, $c"
