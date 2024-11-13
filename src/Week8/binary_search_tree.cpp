#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree{
private:
    Node* root;

    void insertHelper(Node* &head, int val);
    void deletehelper(Node* &head, int val);
    Node* searchHelper(Node* head, int val);
    void inOrderHelper(Node* head);
    void preOrderHelper(Node* head);
    void postOrderHelper(Node* head);
public:
    BinarySearchTree();
    void insert(int val);
    Node* search(int val);
    void erase(int val);
    void inOrder();
    void preOrder();
    void postOrder();
};


BinarySearchTree::BinarySearchTree(){ root = NULL; }

void BinarySearchTree::insert(int val) { insertHelper(root, val); }

Node* BinarySearchTree::search(int val) { return searchHelper(root, val); }

void BinarySearchTree::erase(int val) { deletehelper(root, val); }

void BinarySearchTree::inOrder() { inOrderHelper(root); }

void BinarySearchTree::preOrder() { preOrderHelper(root); }

void BinarySearchTree::postOrder() { postOrderHelper(root); }


void BinarySearchTree::inOrderHelper(Node* head){
    if(head == NULL) return;
   
    inOrderHelper(head->left);
    cout << head->data << " ";
    inOrderHelper(head->right);
}

void BinarySearchTree::preOrderHelper(Node* head){
    if(head == NULL) return;

    cout << head->data << " ";
    preOrderHelper(head->left);
    preOrderHelper(head->right);
}

void BinarySearchTree::postOrderHelper(Node* head) {
    if (head == nullptr) return;

    postOrderHelper(head->left);
    postOrderHelper(head->right);
    cout << head->data << " ";
}



void BinarySearchTree::insertHelper(Node* &head, int val){
    if(head == NULL){
        head = new Node(val);
        return;
    }

    if(head->data < val) insertHelper(head->right, val);

    else if(head->data > val) insertHelper(head->left, val);

}

Node* BinarySearchTree::searchHelper(Node* head, int val){
    if(head == NULL || head->data == val){
        return head;
    } 

    if(head->data < val) return searchHelper(head->right, val);

    return searchHelper(head->left, val);
}

void BinarySearchTree::deletehelper(Node* &head, int val) {
    // Trường hợp cây rỗng
    if (head == NULL) return;

    // Tìm nút cần xóa
    if (head->data > val) {
        deletehelper(head->left, val);
    } else if (head->data < val) {
        deletehelper(head->right, val);
    } else {
        // Trường hợp 1 và 2: nút có một hoặc không có con
        if (head->left == NULL) {
            root = root->right;  
            return;
        }

        if (head->right == NULL) {
            head = head->left;   
            return;
        }

        // Trường hợp 3: nút có hai con
        Node* replaceNode = head->right;  // Tìm nút thay thế
        while (replaceNode->left != NULL) {
            replaceNode = replaceNode->left;
        }
        
        head->data = replaceNode->data;                    // Thay giá trị
        deletehelper(head->right, replaceNode->data);        // Xóa nút thay thế
    }
}

int main(){

}