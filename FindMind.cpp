#include <iostream>
#include <climits>
using namespace std;

class TwoStacks {
private:
    int* arr;       // Mảng dùng chung
    int capacity;   // Kích thước mảng
    int top1;       // Đỉnh của stack1
    int top2;       // Đỉnh của stack2
    int* minStack;  // Ngăn xếp phụ để lưu giá trị nhỏ nhất
    int minTop;     // Đỉnh của minStack

public:
    // Constructor
    TwoStacks(int size) {
        capacity = size;
        arr = new int[capacity];
        minStack = new int[capacity];
        top1 = -1;
        top2 = capacity;
        minTop = -1;
    }

    // Destructor
    ~TwoStacks() {
        delete[] arr;
        delete[] minStack;
    }

    // Push vào stack1
    void push1(int value) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top1] = value;

        // Cập nhật minStack
        if (minTop == -1 || value <= minStack[minTop]) {
            minStack[++minTop] = value;
        }
    }

    // Push vào stack2
    void push2(int value) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[--top2] = value;
    }

    // Pop từ stack1
    int pop1() {
        if (top1 == -1) {
            cout << "Stack1 Underflow" << endl;
            return INT_MIN;
        }
        int value = arr[top1--];

        // Cập nhật minStack
        if (value == minStack[minTop]) {
            minTop--;
        }
        return value;
    }

    // Pop từ stack2
    int pop2() {
        if (top2 == capacity) {
            cout << "Stack2 Underflow" << endl;
            return INT_MIN;
        }
        return arr[top2++];
    }

    // Tìm phần tử nhỏ nhất trong stack1
    int findMin() {
        if (minTop == -1) {
            cout << "Stack1 is empty" << endl;
            return INT_MIN;
        }
        return minStack[minTop];
    }

    // Hiển thị stack1
    void displayStack1() {
        if (top1 == -1) {
            cout << "Stack1 is empty" << endl;
            return;
        }
        cout << "Stack1: ";
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Hiển thị stack2
    void displayStack2() {
        if (top2 == capacity) {
            cout << "Stack2 is empty" << endl;
            return;
        }
        cout << "Stack2: ";
        for (int i = capacity - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TwoStacks stacks(10);

    // Thao tác với stack1
    stacks.push1(5);
    stacks.push1(3);
    stacks.push1(7);
    stacks.push1(2);

    stacks.displayStack1();
    cout << "Minimum in stack1: " << stacks.findMin() << endl;

    stacks.pop1();
    stacks.displayStack1();
    cout << "Minimum in stack1: " << stacks.findMin() << endl;

    stacks.pop1();
    stacks.displayStack1();
    cout << "Minimum in stack1: " << stacks.findMin() << endl;

    // Thao tác với stack2
    stacks.push2(10);
    stacks.push2(20);
    stacks.push2(30);

    stacks.displayStack2();

    return 0;
}