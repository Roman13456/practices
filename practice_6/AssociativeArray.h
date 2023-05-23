//
// Created by User on 23.05.2023.
//

#include <iostream>

template<typename Key, typename Value>
struct Node {
    Key key;
    Value value;
    Node<Key, Value>* next;

    Node(const Key& k, const Value& v) : key(k), value(v), next(nullptr) {}
};



template<typename Key, typename Value>
class Pair {
public:
    Key key;
    Value value;

    Pair() : key(), value() {}

    Pair(const Key& k, const Value& v) : key(k), value(v) {}
};



template<typename Key, typename Value>
class AssociativeArray {
private:
    Node<Key, Value>** table;
    int TableSize;
    int hash(const Key& key) {
        return static_cast<int>(key) % TableSize;
    }

public:
    AssociativeArray(int length):TableSize(length) {
        table = new Node<Key, Value>*[length];
        for (int i = 0; i < TableSize; i++) {
            table[i] = nullptr;
        }
    }

    ~AssociativeArray() {
        clear();
        delete[] table;
    }

    void addPair(const Key& key, const Value& value) {
        int index = hash(key);

        Node<Key, Value>* newNode = new Node<Key, Value>(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node<Key, Value>* curr = table[index];
            newNode->next = curr;
            table[index] = newNode;
        }
    }

    Pair<Key, Value> findMaxPair() {
        Pair<Key, Value> maxPair;
        bool firstPair = true;
        for (int i = 0; i < TableSize; i++) {
            Node<Key, Value>* curr = table[i];
            while (curr != nullptr) {
                if (firstPair || curr->key > maxPair.key) {
                    maxPair.key = curr->key;
                    maxPair.value = curr->value;
                    firstPair = false;
                }
                curr = curr->next;
            }
        }

        return maxPair;
    }

    void clear() {
        for (int i = 0; i < TableSize; i++) {
            Node<Key, Value>* curr = table[i];
            while (curr != nullptr) {
                Node<Key, Value>* temp = curr;
                curr = curr->next;
                delete temp;
            }
            table[i] = nullptr;
        }
    }

    class Iterator {
    private:
        Node<Key, Value>** table; // Reference to the hash table
        int tableSize;
        int currentCell; // Current cell index
        Node<Key, Value>* current; // Current node within the current cell

    public:
        Iterator(Node<Key, Value>** tbl, int size) : table(tbl), tableSize(size), currentCell(0), current(nullptr) {}

        void reset() {
            currentCell = 0;
            current = nullptr;
        }

        bool atEnd() {
            return currentCell >= tableSize;
        }

        Node<Key, Value>* getValue() {
            return current;
        }

        void next() {
            if (current != nullptr) {
                current = current->next;
            }

            while (current == nullptr && currentCell < tableSize) {
                // Move to the next non-empty cell
                currentCell++;
                if (currentCell < tableSize) {
                    current = table[currentCell];
                }
            }
        }
    };

    Iterator begin() {
        return Iterator(table, TableSize);
    }

};



