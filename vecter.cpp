#include <bits/stdc++.h>
using namespace std;

class Vector {
    private:
        int * arrayVector;
        int capacity;
        int size;
    public:
        Vector(int lenth = 100){
            capacity = lenth;
            arrayVector = new int[capacity];
            size = 0;
        }
        ~Vector(){
            delete [] arrayVector;
        }
        int getSize(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        void expand(int newCapacity)
        {
            if(newCapacity < size) return;
            int * old = arrayVector;
            arrayVector = new int[newCapacity];
            for(int i = 0; i < size; i++){
                arrayVector[i] = old[i];
            }
            delete [] old;
            capacity = newCapacity;
        }
        void puckBack(int val){
            if(size == capacity) expand(2 * capacity);
            arrayVector[size] = val;
            size++;
        }
        void insert(int index, int val){
            if(index < 0 || index > size) return;
            if(size == capacity) expand(2 * capacity);
            for (int i = size ; i >= index; i--)
                arrayVector[i] = arrayVector[i - 1];
            arrayVector[--index] = val;
            size++;
        }
        // 1 2 3 4 5 size = 5 
        // insert (2 , 19)
        // 5 -> 3
        // a[5] = a[4] = 5 , a[4] = a[3] = 4, a[3] = a[2] = 3
        // a[2] = 19

        void popBack(){
            if(isEmpty()) return;
            size--;
        }
        void erase(int index){
            if(index < 0 || index >= size) return;
            for (int i = index; i < size - 1; i++)
                arrayVector[i] = arrayVector[i + 1];
            size--;
        }
        void print(){
            for(int i = 0; i < size; i++){
                cout<<arrayVector[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Vector v;
    if(v.isEmpty()) cout<<"Vector is empty"<<endl;
    v.puckBack(1);
    v.puckBack(2);
    v.puckBack(3);
    v.puckBack(4);
    v.puckBack(5);
    v.insert(2, 19);
    v.print();

    return 0;
}