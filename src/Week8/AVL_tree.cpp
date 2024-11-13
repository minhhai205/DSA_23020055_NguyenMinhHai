#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    void insertHelper(Node* &node, int val);
    void deleteHelper(Node* &node, int val);

public:
    AVLTree() : root(nullptr) {}
    void insert(int val);
    void erase(int val);
};

void AVLTree::insert(int val) { insertHelper(root, val); }

void AVLTree::erase(int val) { deleteHelper(root, val); }


// Hàm trả về chiều cao của một nút
int AVLTree::getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Hàm tính độ chênh lệch cân bằng
int AVLTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Hàm xoay phải
Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Hàm xoay trái
Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Hàm chèn nút vào cây AVL
void AVLTree::insertHelper(Node*& node, int val) {
    if (node == nullptr) {
        node = new Node(val);
        return;
    }

    if (val < node->data) {
        insertHelper(node->left, val);
    }
    else if (val > node->data) {
        insertHelper(node->right, val);
    }
    else return;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && val < node->left->data) {
        node = rotateRight(node);
    } else if (balance < -1 && val > node->right->data) {
        node = rotateLeft(node);
    } else if (balance > 1 && val > node->left->data) {
        node->left = rotateLeft(node->left);
        node = rotateRight(node);
    } else if (balance < -1 && val < node->right->data) {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }
}

// Hàm xóa nút khỏi cây AVL
void AVLTree::deleteHelper(Node*& node, int val) {
    if (node == nullptr)
        return;

    if (val < node->data) {
        deleteHelper(node->left, val);
    } else if (val > node->data) {
        deleteHelper(node->right, val);
    } else {

        if (node->left == NULL) {
            node = node->right;  
        } else if (node->right == NULL) {
            node = node->left; 
        } else {
            Node* temp = node->right;
            while (temp->left != nullptr){ // tìm nút thay thế
                temp = temp->left;
            }
       
            node->data = temp->data;
            deleteHelper(node->right, temp->data);
        }
    }

    if (node == nullptr)
        return;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        node = rotateRight(node);
    } else if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        node = rotateRight(node);
    } else if (balance < -1 && getBalance(node->right) <= 0) {
        node = rotateLeft(node);
    } else if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }
}

int main() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);

    avl.erase(30);

    return 0;
}
