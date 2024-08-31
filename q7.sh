
# Name : Harsh Shah
# Roll No. : MT2024136
# Q7. Write a program to copy file1 into file2 ($cp file1 file2).

source_file="example.txt"
destination_file="exampleQ7.txt"


if [ ! -f "$source_file" ]; then
    echo "Error"
    exit 1
fi

cp "$source_file" "$destination_file"

if [ $? -eq 0 ]; then
    echo "Success"
else
    echo "Error"
    exit 1
fi

#harsh-shah@harsh-hp-laptop:~/MTech/Software Systems/HandsOn1$ ./q7.sh
#Success
