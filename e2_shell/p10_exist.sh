if [[ -d "bash" ]]
then
	echo "1. Directory bash exist"
else
	echo "1. Directory does not exist"
	mkdir bash
	echo "2. Directory bash created"
fi
echo "3. Listing"
ls

