#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable(long _a, long _c, long _m) {
    a = _a ? _a : 1; // Default to 3 if not provided
    c = _c ? _c : 0; // Default to 1 if not provided
    m = _m;
    size = 0;

    // Allocate memory for buckets
    buckets = new int[m];

    // Initialize buckets to -1 (indicating empty slots)
    for (long i = 0; i < m; ++i) {
        buckets[i] = -1;
    }
}

HashTable::~HashTable() {
    // Free allocated memory for buckets
    delete[] buckets;
}

void HashTable::insert(int key) {
    if (key <= 0) {
        throw std::invalid_argument("Only strictly positive numbers are allowed.");
    }

    // Check if load factor is 1 (table is full)
    double lFactor = loadFactor();
    if (lFactor == 1) {
        extend();
    }

    // Compute hash index
    long index = (a * key + c) % m; // Using the hash function
    long originalIndex = index;

    // Linear probing to resolve collisions
    while (buckets[index] != -1) { // if slot is occupied
        index = (index + 1) % m; // then move to the next slot
        if (index == originalIndex) { // if came back in circle, then the array is full
            throw std::runtime_error("Hash table is full even after extending.");
        }
    }

    // after ensuring linear probing goes ok, then insert the key
    buckets[index] = key;
    size++;
}



void HashTable::extend() {
    long new_m = m * 2; // Double the table size
    std::cout << "Extending table size from " <<m <<" to "<<new_m << std::endl;
    int* old_buckets = buckets;

    // Allocate a new larger table
    buckets = new int[new_m];
    for (long i = 0; i < new_m; ++i) {
        buckets[i] = -1; // Initialize new table to empty
    }

    // Rehash elements from the old table
    for (long i = 0; i < m; ++i) {
        if (old_buckets[i] != -1) { // If the slot is not empty
            insert(old_buckets[i]); // Reinsert into the new table
        }
    }

    // Update table size and free old memory
    m = new_m;
    delete[] old_buckets;
}




bool HashTable::find(int key) {
    for (long i = 0; i < m; ++i) {
        if(buckets[i] == key){
            std::cout << "Found "<<key<<" in hastable" << std::endl;
            return true;

        }
    }
  std::cout << "Not found "<<key<<" in hastable" << std::endl;
  return false;
  
}

void HashTable::remove(int key){
    for (long i = 0; i < m; ++i) {
        if(buckets[i] == key){
            buckets[i] =-1;
            printTable();    // Corrected call to printTable
            return;      
        }
    }
    std::cout << "Key " << key << " not found in hashtable." << std::endl;
}

double HashTable::loadFactor() {
    double empties = 0;
     for (long i = 0; i < m; ++i) {
        if (buckets[i] == -1) {
            empties ++;
        }
    }
    return static_cast<double>(m-empties) / m;
}

void HashTable::printTable() {
    std::cout << "Hash Table Contents:" << std::endl;
    for (long i = 0; i < m; ++i) {
        if (buckets[i] == -1) {
            std::cout << "Bucket " << i << ": EMPTY" << std::endl;
        } else {
            std::cout << "Bucket " << i << ": " << buckets[i] << std::endl;
        }
    }
}



int main() {
    HashTable hashTable(1, 0, 3); // a = 3, c = 7, m = 5
    std::cout << "HashTable initialized successfully!" << std::endl;

    try {
        hashTable.insert(9); // Valid key
        std::cout << "Load Factor: " << hashTable.loadFactor() << std::endl;
        hashTable.insert(10); // Valid key
        std::cout << "Load Factor: " << hashTable.loadFactor() << std::endl;
        hashTable.insert(11); // Valid key
        std::cout << "Load Factor: " << hashTable.loadFactor() << std::endl;
        hashTable.insert(12); // Valid key
        std::cout << "Load Factor: " << hashTable.loadFactor() << std::endl;
        hashTable.insert(0);  // Invalid key, should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // check out hashtable
    hashTable.printTable();

    // Check load factor
    std::cout << "Load Factor: " << hashTable.loadFactor() << std::endl;
    hashTable.find(10);
    hashTable.remove(10);
    std::cout << "Load Factor: " << hashTable.loadFactor() << std::endl;

    return 0;
}




