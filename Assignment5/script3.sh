



#!/bin/bash

# Prompt the user to enter a name
echo -n "Enter a name: "
read name

# Check if the name exists
if [ ! -e "$name" ]; then
    echo "Error: $name does not exist."
    exit 1
fi

# Check if it's a file
if [ -f "$name" ]; then
    echo "$name is a file."
    # Display file size
    size=$(du -sh "$name" | awk '{print $1}')
    echo "Size: $size"
elif [ -d "$name" ]; then
    echo "$name is a directory."
    # Display directory contents
    echo "Contents of $name:"
    ls -l "$name"
else
    echo "$name exists but is neither a file nor a directory."
fi

