#include <iostream>
#include<unordered_map>
using namespace std;

struct Node {
    int val, key;
    Node* next;
    Node* prev;
    
    Node(int key, int value)
        : val(value), key(key), next(nullptr), prev(nullptr) {}
};

/*
Approach - 
1. Use a doubly linked list to maintain the order of usage.
2. Use a hashmap to store the key and its corresponding node in the linked list.    
3. When accessing a key, move the node to the front of the linked list.
4. When adding a new key, if the cache is full, remove the least recently used (LRU) node from the front of the linked list and the hashmap.
5. Insert the new key at the end of the linked list and update the hashmap.
Time Complexity: O(1) for both get and put operations.
Space Complexity: O(n) for the hashmap and the linked list.

*/

class LRUCache {
public:
    /*

     */
    int cap = 0;
    // left - denotes lru  key , right - denotes mru key
    Node* right ;
    Node* left;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        cache.clear();
        right = new Node(0,0);
        left = new Node(0,0);
        right->prev = left;
        left->next = right;
        cap = capacity;
    }

    // remove node from the list
    void remove(Node* node) {
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    //  insert node to right of the list
    void insert(Node* node) {
        Node* prv = right->prev;
        prv->next = node;
        node->prev = prv;
        node->next = right;
        right->prev = node;
    }

    int get(int key) {
        if (cache.count(key)) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->val = value;
            remove(cache[key]);
            insert(cache[key]);
        } else {
            cache[key] = new Node(key, value);
            insert(cache[key]);
        }

        if (cache.size() > cap) {
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(left->next);
        }
    }
};

