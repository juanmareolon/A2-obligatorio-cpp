#ifndef HASH_TABLE_H
#define HASH_TABLE_H

template <class K, class V>
class HashTable
{
public:
    // pre:
    // post: the element and its value is inserted to the table
    virtual void insert(K key, V value) = 0;

    // pre: -
    // post: remove the value of the element that is equal to the given key
    virtual void remove(K key) = 0;

    // pre: 
    // post: returns the value at the given key
    virtual V get(K key) = 0;

    // pre: -
    // post: returns if the key is in the table
    virtual bool exists(K key) = 0;

    // pre: -
    // post: returns the load factor of the table   CONSULTAR
    virtual float getLoadFactor() = 0;

    // pre: -
    // post: returns the number of elements in the table
    virtual int getSize() = 0;

    virtual ~HashTable() {}

};
#endif