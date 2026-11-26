*This project has been created as part of the 42 curriculum by maratana and ccascava*

# Description

Push_swap is a sorting algorithm project where the goal is to sort a stack of integers in ascending order using a limited set of operations and two stacks (a and b), while minimizing the total number of moves.

The project focuses on algorithm optimization, problem-solving, and efficient data manipulation. It requires developing sorting strategies adapted to different input sizes while respecting the constraints of the available operations.

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order.

## Operations Description
sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.

rrr : rra and rrb at the same time.

# Instructions

## Usage 

To compile the program run make at the root of the repository.

```
make
```

To use run 
```
./push_swap 3 2 1

```
### Valid input rules

Input can start with optional "--bench" flag that enables the benchmark mode.
```
./push_swap --bench
```

Then continue with another optional flag for strategy selection "--simple" ; "--medium"; "--complex"; "--adaptive" if no flag is selected the program will select the adaptive strategy by default.

examples:

```
./push_swap --bench --simple
./push_swap --medium
```

Then there is mandatory list of numbers:

The numbers must fit INT;

There can be arbetery number of spaces before and after each number;

There can be a single '-' or '+' before each number representing positiveor negative value;

The lsit of numbers can be passed as single string with multiple numbers, single numbers or combination of both:
```
./push swap 3 2 1
./push swap "3 2 1"
./push swap 3 "2 1"
```

# Expected Output

If there is invalid output (invalid list of operations, flags or placement fo the flags).The expected output is "Error" in the stderr.
If there is no list of numbers provided (even if there are flags provided) program simply does not diplay anything and gives the prompt back.

# Resources

We used online documentation and YouTube to learn more about the Turk Algorithm. Additionally, manual pages, GitHub repositories, and AI tools were used to gain a better understanding of certain concepts and improve our code.

# Justification/Explanation

For the simple algorithm, we implemented an adaptation of Bubble Sort because we considered it a straightforward and efficient approach for sorting the integers. The algorithm compares adjacent elements and swaps them whenever they are in the wrong order.

For the medium algorithm, we implemented an adaptation of Bucket Sort. We use the number of input integers and their ranks to determine how to distribute the elements into buckets. We then push the elements from stack A to stack B according to their ranks, aiming to place larger values closer to the top of stack B. This allows us to push the elements back to stack A in descending order, resulting in an ascending order once they are transferred.

For the complex algorithm, we implemented an adaptation of the Turk Algorithm. The algorithm assigns a target position in stack A to each element in stack B. We then calculate the cost of moving each element and its target into the correct positions at the top of their respective stacks. By choosing the element with the lowest movement cost, we optimize the number of operations needed to push elements back from stack B to stack A.

# Contributions
## Martin
Structure of the project.

Input parsing and validation.

Validation and acceptence of flags/strategies.

Algorythm selection via adaptive strategy

Bench mode output.

Testing and debuging related to the input part fothe project.

## Calin



# Authors

Martin Atanasov — 42 School Vienna

Calin Cascaval — 42 School Vienna
