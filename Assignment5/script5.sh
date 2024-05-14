



#!/bin/bash

# Function to find the greatest of three numbers
find_greatest() {
    num1=$1
    num2=$2
    num3=$3

    if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
        echo "$num1 is the greatest."
    elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
        echo "$num2 is the greatest."
    else
        echo "$num3 is the greatest."
    fi
}

# Main script starts here
echo -n "Enter first number: "
read num1
echo -n "Enter second number: "
read num2
echo -n "Enter third number: "
read num3

find_greatest $num1 $num2 $num3

