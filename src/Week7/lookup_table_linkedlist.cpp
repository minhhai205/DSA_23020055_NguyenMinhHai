#include <iostream>
using namespace std;

#define KV template <typename K, typename V> 

KV
struct Node {
    K key;
    V value;
    Node* next;

    Node(K k, V v) : key(k), value(v), next(nullptr) {}
};

KV
class LookupTable {
private:
    Node<K, V>* head;
    int currSize;

    Node<K, V>* findNode(K key);

public:
    LookupTable();
    int size();
    void insert(K key, V value);
    V* find(K key);
    bool replace(K key, V newValue);
    void erase(K key);
    void display();
};


KV  // Constructor
LookupTable<K, V>::LookupTable() : head(nullptr), currSize(0) {}


KV  // Return current size: O(1)
int LookupTable<K, V>::size() {
    return currSize;
}


KV  // Find node by key: O(n)
Node<K, V>* LookupTable<K, V>::findNode(K key) {
    Node<K, V>* current = head;
    while (current != nullptr) {
        if (current->key == key) return current;
        current = current->next;
    }
    return nullptr;
}


KV  // Insert: O(n)
void LookupTable<K, V>::insert(K key, V value) {
    if(replace(key, value)) return;

    Node<K, V>* newNode = new Node<K, V>(key, value);
    newNode->next = head;
    head = newNode;
    ++currSize;
}


KV  // Find: O(n)
V* LookupTable<K, V>::find(K key) {
    Node<K, V>* node = findNode(key);
    return (node != nullptr) ? &(node->value) : nullptr;
}


KV  // Replace: O(n)
bool LookupTable<K, V>::replace(K key, V newValue) {
    Node<K, V>* node = findNode(key);
    if (node != nullptr) {
        node->value = newValue;
        return true;
    }
    return false;
}


KV  // Erase: O(n)
void LookupTable<K, V>::erase(K key) {
    if (head == nullptr) return;

    if(head->key == key){
        head = head->next;
        --currSize;
        return;
    }

    Node<K, V> * curr = head;
    while(curr->next != nullptr && curr->next->key != key){
        curr = curr->next;
    }

    if(curr->next != nullptr){
        curr->next = curr->next->next;
        --currSize;
    }
}


KV  // Display all key-value: O(n)
void LookupTable<K, V>::display() {

    Node<K, V>* current = head;
    while (current != nullptr) {
        cout << "Key: " << current->key << ", Value: " << current->value << endl;
        current = current->next;
    }
}


int main() {
    LookupTable<string, int> table;

    table.insert("Alice", 30);
    table.insert("Bob", 25);
    table.insert("Charlie", 35);

    cout << "Contents of the lookup table after inserts:" << endl;
    table.display();

    cout << "\nAttempting to insert 'Alice' with a new value 31:" << endl;
    table.insert("Alice", 31);
    table.display();

    string keyToFind = "Bob";
    int* value = table.find(keyToFind);
    if (value) {
        cout << "\n" << keyToFind << "'s age: " << *value << endl;
    } else {
        cout << "\n" << keyToFind << " not found!" << endl;
    }

    table.replace("Charlie", 40);
    cout << "\nAfter replacing Charlie's age:" << endl;
    table.display();

    table.erase("Bob");
    cout << "\nAfter removing Bob:" << endl;
    table.display();

    return 0;
}
