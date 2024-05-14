

#!/bin/bash

while true; do
    # Display menu options
    echo "Menu:"
    echo "1. Date"
    echo "2. Cal"
    echo "3. Ls"
    echo "4. Pwd"
    echo "5. Exit"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)
            # Execute 'date' command
            date
            ;;
        2)
            # Execute 'cal' command
            cal
            ;;
        3)
            # Execute 'ls' command
            ls
            ;;
        4)
            # Execute 'pwd' command
            pwd
            ;;
        5)
            # Exit the script
            echo "Exiting..."
            exit 0
            ;;
        *)
            # Handle invalid input
            echo "Invalid choice. Please enter a number from 1 to 5."
            ;;
    esac

    # Add a newline for better readability
    echo
done

