
#!/bin/bash

# Function to check if a number is prime
is_prime() {
    num=$1
    if [ $num -le 1 ]; then
        echo "$num is not prime."
        exit 1
    fi

    i=2
    while [ $((i * i)) -le $num ]; do
        if [ $((num % i)) -eq 0 ]; then
            echo "$num is not prime."
            exit 1
        fi
        i=$((i + 1))
    done
    echo "$num is prime."
}

# Main script starts here
echo -n "Enter a number: "
read number

is_prime $number

