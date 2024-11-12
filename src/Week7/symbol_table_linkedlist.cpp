#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class SymbolTable {
private:
    Node* head;
    int currSize;
    Node* findNode(int key);
public:
    SymbolTable();
    int size();
    void insert(int key, int value);
    int find(int key);
    void erase(int key);
    void display();
};

SymbolTable::SymbolTable() : head(nullptr), currSize(0) {}

// Return current size: O(1)
int SymbolTable::size() {
    return currSize;
}

// Find node by key: O(n)
Node* SymbolTable::findNode(int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) return current;
        current = current->next;
    }
    return nullptr;
}

// Insert: O(n)
void SymbolTable::insert(int key, int value) {
    // Nếu key đã tồn tại thì thay thế
    Node* node = findNode(key);
    if (node != nullptr) {
        node->value = value;
        return ;
    }

    Node* newNode = new Node(key, value);
    newNode->next = head;
    head = newNode;
    ++currSize;
}

// Find: O(n)
int SymbolTable::find(int key) {
    Node* node = findNode(key);
    return (node != nullptr) ? (node->value) : INT_MIN;
}

// Erase: O(n)
void SymbolTable::erase(int key) {
    if (head == nullptr) return;

    if (head->key == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        --currSize;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->key != key) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        --currSize;
    }
}

// Display all key-value: O(n)
void SymbolTable::display() {
    Node* current = head;
    while (current != nullptr) {
        cout << "Key: " << current->key << ", Value: " << current->value << endl;
        current = current->next;
    }
}

int main() {
    SymbolTable table;

    table.insert(1, 30);
    table.insert(2, 25);
    table.insert(3, 35);

    cout << "Contents of the SymbolTable after inserts:" << endl;
    table.display();

    return 0;
}
