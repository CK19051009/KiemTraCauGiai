#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next, *prev;
};

template <class T>
class linkedListDouble{
    private:
        Node<T> *header, *trailer, *currentPos;
    public: 
        linkedListDouble(){
            header = trailer = NULL;
        }
        bool empty(){
            return (header == NULL);
        }
        ~linkedListDouble(){
            while(!empty()){
                Node<T> *temp = header;
                header = header->next;
                delete temp;
            }
        }
        int getSize(){
            Node<T> *temp = header;
            int count = 0;
            while (temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }   
        T getFirst(){
            return header->data;
        }
        T getLast(){
            return trailer->data;
        }
        void pushFront(T val){
            Node<T> *newNode = new Node<T>;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = header;
            if(empty()) trailer = newNode;
            else {
                header->prev = newNode;
                newNode->next = header;
            }
            header = newNode;
            currentPos = newNode;
        }
        void pushBack(T val){
            Node<T> *newNode = new Node<T>;
            newNode->data = val;
            newNode->prev = trailer;
            newNode->next = NULL;
            if(empty()) header = newNode;
            else{
                trailer->next = newNode;

            }
            trailer = newNode;
            currentPos = newNode;
        }
        void insert(int pos, T val){
            Node<T> *newNode = new Node<T>;
            newNode->data = val;
            // newNode->next = NULL;
            if(pos == 1){
                newNode->next = header;
                newNode->prev = NULL;
                if(empty()) trailer = newNode;
                else header->prev = newNode;
                header = newNode;
            }
            else{
                Node<T> *temp = header;
                int count = 1;
                while (temp != NULL && count < pos - 1){
                    temp = temp->next;
                    count++;
                    cout<<count<<endl;
                }
                if(temp == NULL){
                    newNode->prev = trailer;
                    newNode->next = NULL;
                    if(empty()) header = newNode;
                    else trailer->next = newNode;
                    trailer = newNode;
                }
                else{
                    newNode->next = temp->next;
                    if(temp->next != NULL){
                        temp->next->prev = newNode;
                        newNode->prev = temp;
                    } 

                    else  trailer = newNode;
                    temp->next = newNode;
                }
            }

        }
        void printAll(){
            Node<T> *temp = header;
            while (temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            
        }
};   


int main(){
    linkedListDouble<int> ds;
    ds.pushFront(5);
    ds.pushFront(6);
    ds.pushFront(1);
    ds.insert(2,10);
    ds.printAll();
    // 1 10 6 5
    return 0;
}