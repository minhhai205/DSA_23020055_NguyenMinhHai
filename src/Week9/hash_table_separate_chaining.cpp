#include<bits/stdc++.h>
using namespace std;

class HashTable{
private:
    static const int CAPACITY = 99;
    vector<pair<int, int>> table[CAPACITY];

    int hash(int key);

public:
    void put(int key, int val);
    int get(int key);  
    void remove(int key);
};

int HashTable::hash(int key){
    return key % CAPACITY;
}

void HashTable::put(int key, int val){
    int index = hash(key);
    for(auto &data : table[index]){
        if(data.first == key){
            data.second = val; return;
        }
    }
    table[index].push_back({key, val});
}

int HashTable::get(int key){
    int index = hash(key);
    for(auto data : table[index]){
        if(data.first == key) return data.second;
    }
    return INT_MIN;
}

void HashTable::remove(int key){
    int index = hash(key);
    for(int i=0; i<table[index].size(); i++){
        if(table[index][i].first == key){
            table[index].erase(table[index].begin() + i);
            break;
        }
    }
}

int main(){
    HashTable ht;

    ht.put(1, 100);
    ht.put(2, 200);
    ht.put(3, 300);

    cout << "Value for key 1: " << ht.get(1) << endl;  // 100
    cout << "Value for key 2: " << ht.get(2) << endl;  // 200

    ht.put(2, 250);  // Cập nhật key 2
    cout << "Updated value for key 2: " << ht.get(2) << endl;  // 250

    ht.remove(2);  // Xóa key 2
    cout << "Value for key 2 after removal: " << ht.get(2) << endl;  // INT_MIN

    return 0;
}