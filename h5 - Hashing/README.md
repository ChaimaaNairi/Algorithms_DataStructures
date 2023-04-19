# h5 - Hashing

<h3> Analysis of Double Hashing and Quadratic Hashing Algorithms: </h3>
<b>Double Hashing Algorithm:</b>
Double hashing is a collision resolution method using a second hash function. First, an index is calculated using the main hash function, and if this index is already occupied, a step is skipped using the second hash function and a new index is calculated. This process is repeated until an empty cell is found.

<b>Quadratic Hashing Algorithm:</b>
Quadratic hashing is also a collision resolution method. In case of a collision, a new index is calculated by increasing by one square at each step. If this index is already occupied, a new index is calculated by increasing by two squares in the next step. This process is repeated until an empty cell is found. As the size of the table increases, the probability of collisions decreases, but resolving collisions also takes more time.

<h3>Placing Numbers in a Hash Table:</h3>
The numbers 23, 12, 88, 45, 62, 7, 1 were placed in a hash table using a hash function with mod 10.</br></br>

The hash function was designed as follows:</br>
<b>Pseudo-code:</b></br>
hash_table = [None]10 </br>
def hash_func(x): </br>
return (3x) % 10 </br>
numbers = [23, 12, 88, 45, 62, 7, 1] </br>
for num in numbers: </br>
index = hash_func(num) </br>
hash_table[index] = num </br>
print(hash_table) </br>

Output: -1 1 12 23 62 45 -1 7 88 -1