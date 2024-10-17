


Stack::Stack(int n) {
    a = new int[n];
    maxSize = n;
    currSize = 0;
}

void Stack::push(int val) {
    if (currSize >= maxSize) {
        cout << "Stack overflow!" << endl;
        return;
    }
    a[currSize++] = val;
}

int Stack::pop() {
    if (currSize == 0) {
        cout << "Stack underflow!" << endl;
        return INT_MIN;
    }
    return a[--currSize];  
}

int Stack::top() {
    if (currSize == 0) {
        cout << "Stack is empty!" << endl;
        return INT_MIN;
    }
    return a[currSize - 1];
}

bool Stack::isEmpty() {
    return currSize == 0;
}

int Stack::size() {
    return currSize;
}

int main(){
    
}
