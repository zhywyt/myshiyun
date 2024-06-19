mkdir build
cmake . -B build
cd build
make -j4
for test_file in ../test_cases/$1*.sy
do
	./compiler $test_file
	echo "Test file : $test_file"
	cat -n $test_file
	echo 
	read -p "#################### enter to continue #####################" enter
done
 
