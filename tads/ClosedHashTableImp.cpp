#ifndef HASH_TABLE_IMP
#define HASH_TABLE_IMP
#include "HashTable.h"
#include <cassert>
#include <cmath>
#include <cstdlib>

template <class K, class V>
struct KeyValue {
    K key;
    V value;
    KeyValue(K _key, V _value) {
        key = _key;
        value = _value;
    }
};
template <class K, class V>
class ClosedHashTableImp : public HashTable<K,V>
{
private:
    int buckets;
    int N; //Elementos en la tabla
    int size;
    int (*hashFunction)(K);
    int (*hashFunction2)(K);
    KeyValue<K,V> **table;
    bool *eliminado;

    int pos(K key, unsigned int i)
    {
        // doble hashing
        return std::abs((int)(hashFunction(key) + i * hashFunction2(key))) % buckets;
    }


    void rehash() 
    {
        this->buckets *= 2;
        KeyValue<K,V> **newTable = new KeyValue<K,V>*[buckets]();
        for (int i = 0; i < buckets; i++)
        {
            newTable[i] = NULL;
        }
        bool *newEliminado = new bool[buckets]();
        for (int i = 0; i < buckets/2; i++)
        {
            if(table[i] != NULL && !eliminado[i]) {
                int intento = 0;
                bool actualice = false;
                while(!actualice) {
                    int p = pos(table[i]->key, intento);
                    if(newTable[p] == NULL) {
                            newTable[p] = new KeyValue<K,V>(table[i]->key, table[i]->value);
                        actualice = true;
                    }
                    intento++;
                    assert(intento < buckets);
                }
            }
        }

        for (int i = 0; i < buckets/2; i++) {
            delete table[i];
        }
        delete[] table;
        delete[] eliminado;
        table = newTable;
        eliminado = newEliminado; 
    }

public:
    
    ClosedHashTableImp(int _B, int (*_hashFunction)(K), int (*_hashFunction2)(K))
    {
        buckets = _B;
        N = 0;
        hashFunction = _hashFunction;
        hashFunction2 = _hashFunction2;
        table = new KeyValue<K,V>*[buckets]();
        for (int i = 0; i < buckets; i++)
        {
            table[i] = NULL;
        }
        eliminado = new bool[buckets]();
    }
    
   
    // void insert(K key, V value)
    // {
    //     assert(N < buckets);
    //     int intento = 0;
    //     while (intento < buckets) {
    //         int p = pos(key, intento);
    //         if (table[p] == NULL || eliminado[p]) {
    //             if (table[p] != NULL) {
    //                 delete table[p]; // limpiar si había basura
    //             }
    //             table[p] = new KeyValue<K,V>(key, value);
    //             eliminado[p] = false;
    //             N++;
    //             return;
    //         }
    //         if (!eliminado[p] && table[p]->key == key) {
    //             table[p]->value = value;
    //             return;
    //         }
    //         intento++;
    //     }
    //     if(this->getLoadFactor() >= 0.7) {
    //         this->rehash();
    //     }
    //     assert(false); 

    // }

    void insert(K key, V value)
{
    if (this->getLoadFactor() >= 0.7) {
        this->rehash();
    }

    int intento = 0;
    while (intento < buckets) {
        int p = pos(key, intento);

        if (table[p] == NULL || eliminado[p]) {
            if (table[p] != NULL) {
                delete table[p];
            }
            table[p] = new KeyValue<K,V>(key, value);
            eliminado[p] = false;
            N++;
            return;
        }

        if (!eliminado[p] && table[p]->key == key) {
            table[p]->value = value;
            return;
        }

        intento++;
    }

    assert(false); // esto ya no debería pasar casi nunca
}

    V get(K key)
    {
        assert(this->exists(key));
        for (int intento = 0; intento < buckets; intento++)
        {
            int p = pos(key, intento);
            if(table[p] != NULL && !eliminado[p]) {
                if(table[p]->key == key) {
                    return table[p]->value;
                }
            }
        }
        assert(false);
    }

    bool exists(K key)
    {
        bool existe = false;
        for (int intento = 0; intento < buckets; intento++)
        {
            int p = pos(key, intento);
            if(table[p] == NULL && !eliminado[p]) {
                return false;
            }
            if(table[p] != NULL && !eliminado[p]) {
                if(table[p]->key == key) {
                    return true;
                }
            }
        }
        return false; 
    }

    float getLoadFactor() {
        return (float) N / buckets;
    }

    int getSize() {
        return N;
    }

    void remove(K key)
    {
        for (int intento = 0; intento < buckets; intento++)
        {
            int p = pos(key, intento);
            if(table[p] == NULL && !eliminado[p]) {
                return;
            }
            if(table[p] != NULL && !eliminado[p]) {
                if(table[p]->key == key) {
                    eliminado[p] = true;
                    delete table[p];
                    N--;
                    return;
                }   
            }
        }
};
};
#endif