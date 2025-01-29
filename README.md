# Hash Table Implementation with Linear Probing

This repository contains a C++ implementation of a hash table using **linear probing** for collision resolution. The hash table supports insertion, deletion, searching, and dynamic resizing (extending and rehashing) when the load factor reaches 1.

## Hash Function
The hash function used is:

h(k) = (a * k + c) mod m

where:
- `a` and `c` are positive integer coefficients.
- `m` is the number of buckets in the hash table.
- `k` is the key to be hashed.

## Features

### 1. **Constructor (`HashTable`)**
- Initializes the hash table with user-defined values for `a`, `c`, and `m`.
- Allocates memory for the hash table buckets.

### 2. **Destructor (`~HashTable`)**
- Deallocates memory used by the hash table.

### 3. **Insertion (`insert`)**
- Inserts a strictly positive integer key into the hash table.
- Uses **linear probing** to resolve collisions.
- Automatically extends and rehashes the table when the load factor reaches 1.

### 4. **Table Extension (`extend`)**
- Increases the size of the hash table when necessary.
- Creates a temporary array to store existing elements.
- Rehashes all elements into the new, larger table.

### 5. **Search (`find`)**
- Searches for a key in the hash table.
- Returns `true` if the key is found, otherwise `false`.

### 6. **Deletion (`remove`)**
- Removes a key from the hash table.
- Handles cases where keys are not in their natural position due to linear probing.

### 7. **Load Factor (`loadFactor`)**
- Computes and returns the current load factor of the hash table as a `double`.
- The load factor is defined as the fraction of occupied buckets.

## Code Structure
- **`HashTable.hpp`**: Contains the class definition and method prototypes.
- **`HashTable.cpp`**: Implements the hash table methods.


