#include <iostream>
using namespace std;

template <typename K, typename V>
struct Pair {
    K key;
    V value;
};

template <typename K, typename V>
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

// Constructor
template <typename K, typename V>
LookupTable<K, V>::LookupTable(int size) {
    maxSize = size;
    currSize = 0;
    arr = new Pair<K, V>[size];
}

// Return current size: O(1)
template <typename K, typename V>
int LookupTable<K, V>::size() {
    return currSize;
}

// insert: O(n)
template <typename K, typename V>
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

// Binary search for a key: O(log(n))
template <typename K, typename V>
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

// Find a value by key: O(log(n))
template <typename K, typename V>
V* LookupTable<K, V>::find(K key) {
    int index = binarySearch(key);
    if (index != -1) {
        return &arr[index].value;
    }
    return nullptr;
}

// Replace a value by key: O(log(n))
template <typename K, typename V>
bool LookupTable<K, V>::replace(K key, V newValue) {
    int index = binarySearch(key);
    if (index != -1) {
        arr[index].value = newValue;
        return true;
    }
    return false;
}

// Erase a key-value: O(n)
template <typename K, typename V>
void LookupTable<K, V>::erase(K key) {
    int index = binarySearch(key);
    if (index == -1) return;

    for (int i = index; i < currSize - 1; i++) {
        arr[i] = arr[i + 1];
    }

    --currSize;
}

// Display all key-value: O(n)
template <typename K, typename V>
void LookupTable<K, V>::display() {
    for (int i = 0; i < currSize; i++) {
        cout << "Key: " << arr[i].key << ", Value: " << arr[i].value << endl;
    }
}


int main() {
    // Tạo một LookupTable với kích thước tối đa là 5
    LookupTable<string, int> table(5);

    
    // Thêm các cặp key-value
    cout << "Test 1: \n";
    table.insert("Alice", 30);
    table.insert("Bob", 25);
    table.insert("Charlie", 35);
    table.insert("David", 40);
    table.insert("Eve", 28);
    
    cout << "Contents of the lookup table after inserts:" << endl;
    table.display();

    
    // Thử thêm một phần tử khi bảng đã đầy
    cout << "\nTest 2:\n";
    cout << "Attempting to insert 'Frank':" << endl;
    table.insert("Frank", 20);
    table.display();

    
    // Thêm giá trị cho một key đã tồn tại
    cout << "\nTest 3:\n";
    cout << "Attempting to insert 'Alice' with a new value 31:" << endl;
    table.insert("Alice", 31);
    table.display();

    
    // Tìm kiếm một giá trị
    cout << "\nTest 4:\n";
    string keyToFind = "Bob";
    int* value = table.find(keyToFind);
    if (value) {
        cout << keyToFind << "'s age: " << *value << endl;
    } else {
        cout << keyToFind << " not found!" << endl;
    }

    
    // Thay thế giá trị của một key
    cout << "\nTest 5:\n";
    table.replace("Alice", 32);
    cout << "After replacing Alice's age:" << endl;
    table.display();

    
    // Xóa một cặp key-value
    cout << "\nTest 6:\n";
    table.erase("Bob");
    cout << "After removing Bob:" << endl;
    table.display();

    
    // Thử tìm kiếm lại key đã xóa
    cout << "\nTest 7:\n";
    value = table.find("Bob");
    if (value) {
        cout << "Bob's age: " << *value << endl;
    } else {
        cout << "Bob not found!" << endl;
    }


    // Thử xóa một key không tồn tại
    cout << "\nTest 8:\n";
    table.erase("Zoe");

    cout << "Final contents of the lookup table:" << endl;
    table.display();


    // Thay thế một key không tồn tại
    cout << "\nTest 9:\n";
    if (!table.replace("Zoe", 22)) {
        cout << "Key 'Zoe' not found for replacement." << endl;
    }

    return 0;
}