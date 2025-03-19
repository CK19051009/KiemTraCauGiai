#include <bits/stdc++.h>
using namespace std;

template <class T>

class Stack{
    private:
        T *dataArray;
        int size;
        int top;
        int capacity;
    public:
        Stack(int capacity){
            this->capacity = capacity;
            dataArray = new T[capacity];
            top = -1;
        }
        ~Stack(){
            delete[] dataArray;
        }
        void push(T val){
            if(top == capacity - 1){
                cout<<"Stack is full"<<endl;
                return;
            }
            dataArray[++top] = val;
        }
        void pop(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
        }
        T peek(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return dataArray[top];
        }
        bool empty(){
            return top == -1;
        }
        int getSize(){
            return top + 1;
        }
        void print(){
            for(int i = 0; i <= top; i++){
                cout<<dataArray[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.print();
    cout<<s.peek()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}