#pragma once
#include <cstdio>
using namespace std;

template<typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        int index = -1;
    };

    Node* nodes;
    int capacity;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        Node* newNodes = new Node[newCapacity];
        for (int i = 0; i < size; i++) {
            newNodes[i] = nodes[i];
        }
        delete[] nodes;
        nodes = newNodes;
        capacity = newCapacity;
    }

public:
    Map() : size(0), capacity(10) {
        nodes = new Node[capacity];
    }

    ~Map() {
        delete[] nodes;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < size; i++) {
            if (nodes[i].key == key) {
                return nodes[i].value;
            }
        }

        if (size == capacity) {
            resize();
        }

        nodes[size].key = key;
        nodes[size].index = size;
        size++;
        return nodes[size - 1].value;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < size; i++) {
            if (nodes[i].key == key) {
                value = nodes[i].value;
                return true;
            }
        }
        return false;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < size; i++) {
            if (nodes[i].key == key) {
                nodes[i] = nodes[size - 1];
                size--;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        size = 0;
    }

    bool Includes(const Map<K, V>& other) {
        for (int i = 0; i < other.size; i++) {
            V value;
            if (!Get(other.nodes[i].key, value)) {
                return false;
            }
        }
        return true;
    }

    auto begin() {
        return &nodes[0];
    }

    auto end() {
        return &nodes[size];
    }
};

