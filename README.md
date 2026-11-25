*This project has been created as part of the 42 curriculum by maratana and ccascava*

# Description

Push_swap is a sorting algorithm project where the goal is to sort a stack of integers in ascending order using a limited set of operations and two stacks (a and b), while minimizing the total number of moves.

The project focuses on algorithm optimization, problem-solving, and efficient data manipulation. It requires developing sorting strategies adapted to different input sizes while respecting the constraints of the available operations.

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order.

# Instructions

# Resources

We used online documentation and YouTube to learn more about the Turk Algorithm. Additionally, manual pages, GitHub repositories, and AI tools were used to gain a better understanding of certain concepts and improve our code.

# Justification/Explanation

For the simple algorithm, we implemented an adaptation of Bubble Sort because we considered it a straightforward and efficient approach for sorting the integers. The algorithm compares adjacent elements and swaps them whenever they are in the wrong order.

For the medium algorithm, we implemented an adaptation of Bucket Sort. We use the number of input integers and their ranks to determine how to distribute the elements into buckets. We then push the elements from stack A to stack B according to their ranks, aiming to place larger values closer to the top of stack B. This allows us to push the elements back to stack A in descending order, resulting in an ascending order once they are transferred.

For the complex algorithm, we implemented an adaptation of the Turk Algorithm. The algorithm assigns a target position in stack A to each element in stack B. We then calculate the cost of moving each element and its target into the correct positions at the top of their respective stacks. By choosing the element with the lowest movement cost, we optimize the number of operations needed to push elements back from stack B to stack A.

# Authors

Martin Atanasov — 42 School Vienna
Calin Cascaval — 42 School Vienna
