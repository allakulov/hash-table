#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

class HashTable {
public: // for testing purposes
  int *buckets = 0;
  long m;       // Total number of buckets
  int size = 0; // Number of occupied buckets
  long a, c;    // Hash function parameters

public:
  HashTable(long, long, long);
  ~HashTable();
  void insert(int);
  void extend();
  bool find(int);
  void remove(int);
  double loadFactor();
  void printTable();

};

#endif
