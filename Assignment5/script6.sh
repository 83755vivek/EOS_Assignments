
#!/bin/bash

# Function to check if a given year is a leap year
is_leap_year() {
    year=$1

    # Check if the year is divisible by 4 but not by 100, or if it's divisible by 400
    if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]; then
        echo "$year is a leap year."
    else
        echo "$year is not a leap year."
    fi
}

echo -n "Enter a year: "
read year

is_leap_year $year

