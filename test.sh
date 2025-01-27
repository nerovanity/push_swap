#!/bin/bash

# Function to generate permutations for small sets or random numbers for larger sets
generate_numbers() {
    local count=$1
    if [ "$count" -le 5 ]; then
        # Generate all permutations of [1, 2, ..., count]
        echo $(python3 -c "import itertools; print(' '.join([':'.join(map(str, p)) for p in itertools.permutations(range(1, $count + 1))]))")
    else
        # Generate random numbers for larger sets
        echo $(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, $count + 1), $count))))")
    fi
}

# Path to the executables
PUSH_SWAP=./push_swap
CHECKER=./checker

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Ask the user for the number of elements
echo "Select the number of elements to test (3, 4, 5, 100, 500):"
read count

if [ "$count" -eq 100 ] || [ "$count" -eq 500 ]; then
    echo "Select the number of tests:"
    read loops
fi


# Function to run tests
run_tests() {
    local count=$1
    local tests=$2
    local all_passed=true

    for ((i=1; i<=tests; i++)); do
        echo "Test $i for $count numbers"
        numbers=$(generate_numbers $count)

        # Convert numbers string to array if small set of permutations or keep as single string for larger sets
        if [ "$count" -le 5 ]; then
            IFS=' ' read -r -a number_array <<< "$numbers"
        else
            number_array=("$numbers")
        fi

        # Loop through each permutation or test the single random set
        for permutation in "${number_array[@]}"; do
            # Replace ":" with " " to get the correct format
            perm=$(echo $permutation | tr ':' ' ')
            
            # Skip the sorted case for small sets
            if [ "$count" -le 5 ] && [ "$perm" == "$(seq -s ' ' 1 $count)" ]; then
                continue
            fi
            
            # Print the current permutation
            echo "Testing permutation: $perm"
            
            # Run push_swap and capture the output
            moves=$($PUSH_SWAP $perm)
            Number=$(echo "$moves" | wc -l)
            
            # Pipe the result into checker
            result=$(echo "$moves" | $CHECKER $perm)

            # Check the result from checker
            if [ "$result" == "OK" ]; then
                echo -e "Permutation: $perm - Moves: $Number - ${GREEN}OK${NC}"
            else
                echo -e "Permutation: $perm - ${RED}KO${NC}"
                all_passed=false
            fi
            
            # Check for memory leaks using valgrind
            valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 $PUSH_SWAP $perm 2>&1)
            if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
                echo -e "${GREEN}No Leaks${NC}"
            else
                echo -e "${RED}LEAKS${NC}"
                all_passed=false
            fi

            # Check if number of moves is within the specified limit
            if [ "$count" -eq 3 ] && [ "$Number" -gt 3 ]; then
                echo -e "${RED}KO${NC} - More than 3 moves for 3 numbers"
                all_passed=false
            elif [ "$count" -eq 5 ] && [ "$Number" -ge 12 ]; then
                echo -e "${RED}KO${NC} - More than or equal to 12 moves for 5 numbers"
                all_passed=false
            elif [ "$count" -eq 100 ] && [ "$Number" -ge 700 ]; then
                echo -e "${RED}KO${NC} - More than or equal to 700 moves for 100 numbers"
                all_passed=false
            elif [ "$count" -eq 500 ] && [ "$Number" -ge 5500 ]; then
                echo -e "${RED}KO${NC} - More than or equal to 5500 moves for 500 numbers"
                all_passed=false
            fi
        done
    done

    if [ "$all_passed" = true ]; then
        echo -e "${GREEN}All tests passed${NC}"
    else
        echo -e "${RED}Some tests failed${NC}"
    fi
}

# Run tests based on the count of numbers
if [ "$count" -le 5 ]; then
    run_tests $count 1
elif [ "$count" -eq 100 ] || [ "$count" -eq 500 ]; then
    run_tests $count $loops
else
    echo "Invalid option. Please select 3, 4, 5, 100, or 500."
fi