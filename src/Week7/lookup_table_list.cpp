#include <iostream>
using namespace std;

struct Pair {
    int key;
    int value;
};

class LookupTable {
private:
    Pair* arr;
    int maxSize, currSize;

    int binarySearch(int key);

public:
    LookupTable(int size);
    int size();
    void insert(int key, int value);
    int find(int key);
    void erase(int key);
    void display();
};

// Constructor
LookupTable::LookupTable(int size) {
    maxSize = size;
    currSize = 0;
    arr = new Pair[size];
}

// Return current size: O(1)
int LookupTable::size() {
    return currSize;
}

// Insert: O(n)
void LookupTable::insert(int key, int value) {
    // Kiểm tra và thay thế nếu key đã tồn tại
    int index = binarySearch(key);
    if (index != -1) {
        arr[index].value = value;
        return;
    }

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
int LookupTable::binarySearch(int key) {
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
int LookupTable::find(int key) {
    int index = binarySearch(key);
    if (index != -1) {
        return arr[index].value;
    }
    return INT_MIN;
}

// Erase a key-value: O(n)
void LookupTable::erase(int key) {
    int index = binarySearch(key);
    if (index == -1) return;

    for (int i = index; i < currSize - 1; i++) {
        arr[i] = arr[i + 1];
    }

    --currSize;
}

// Display all key-value: O(n)
void LookupTable::display() {
    for (int i = 0; i < currSize; i++) {
        cout << "Key: " << arr[i].key << ", Value: " << arr[i].value << endl;
    }
}

int main() {
    LookupTable table(5);

    table.insert(1, 30);
    table.insert(2, 25);
    table.insert(3, 35);

    cout << "Contents of the lookup table after inserts:" << endl;
    table.display();

    return 0;
}
