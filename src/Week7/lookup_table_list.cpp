#include <iostream>
using namespace std;

#define KV template <typename K, typename V> 

KV
struct Pair {
    K key;
    V value;
};

KV
class LookupTable {
private:
    Pair<K, V>* arr;
    int maxSize, currSize;

    int binarySearch(K key);

public:
    LookupTable(int size);
    int size();
    void insert(K key, V value);
    V* find(K key);
    bool replace(K key, V newValue);
    void erase(K key);
    void display();
};


KV  // Constructor
LookupTable<K, V>::LookupTable(int size) {
    maxSize = size;
    currSize = 0;
    arr = new Pair<K, V>[size];
}


KV  // Return current size: O(1)
int LookupTable<K, V>::size() {
    return currSize;
}


KV  // insert: O(n)
void LookupTable<K, V>::insert(K key, V value) {
    // kiểm tra và thay thế nếu key đã tồn tại
    if (replace(key, value)) return; 

    if (currSize >= maxSize) return;

    int pos = currSize - 1;
    while (pos >= 0 && arr[pos].key > key) {
        arr[pos + 1] = arr[pos];
        --pos;
    }

    arr[pos + 1] = {key, value};
    ++currSize;
}


KV  // Binary search for a key: O(log(n))
int LookupTable<K, V>::binarySearch(K key) {
    int left = 0, right = currSize - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].key == key) return mid;
        else if (arr[mid].key < key) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}


KV  // Find a value by key: O(log(n))
V* LookupTable<K, V>::find(K key) {
    int index = binarySearch(key);
    if (index != -1) {
        return &arr[index].value;
    }
    return nullptr;
}


KV  // Replace a value by key: O(log(n))
bool LookupTable<K, V>::replace(K key, V newValue) {
    int index = binarySearch(key);
    if (index != -1) {
        arr[index].value = newValue;
        return true;
    }
    return false;
}


KV  // Erase a key-value: O(n)
void LookupTable<K, V>::erase(K key) {
    int index = binarySearch(key);
    if (index == -1) return;

    for (int i = index; i < currSize - 1; i++) {
        arr[i] = arr[i + 1];
    }

    --currSize;
}


KV  // Display all key-value: O(n)
void LookupTable<K, V>::display() {
    for (int i = 0; i < currSize; i++) {
        cout << "Key: " << arr[i].key << ", Value: " << arr[i].value << endl;
    }
}


int main() {
    LookupTable<string, int> table(5);

    table.insert("Alice", 30);
    table.insert("Bob", 25);
    table.insert("Charlie", 35);

    cout << "Contents of the lookup table after inserts:" << endl;
    table.display();

    return 0;
}