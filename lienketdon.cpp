#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node{
    T data;
    Node<T>* next;
};
template <class T>
class linkedList{
    

    private:
        Node<T>* head;
    
    public:
        linkedList(){
            head = NULL;
        }
        bool empty(){
            return (head == NULL);
        }
        ~linkedList(){
            while(!empty()){
                Node<T> *temp = head;
                head = head->next;
                delete temp;

            }
        }
        int getSize(){
            Node<T> * temp = head;
            int count = 0;
            while (temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }
        T getFirst(){
            return head->data;
        }
        void pushFront(T val){
            Node<T> *newNode = new Node<T>;
            newNode->data = val;
            newNode->next = head;
            head = newNode;
        }
        void insert(int pos, T val){
            Node<T> *newNode = new Node<T>;
            newNode->data = val;
            newNode->next = NULL;
            if(pos == 1){
                newNode -> next = head;
                head = newNode;
            }
            else {
                Node<T> * temp = head;
                int count = 1;
                while (temp != NULL && count < pos - 1){
                    temp = temp -> next;
                    count++;
                }
                if(temp == NULL){
                    cout<<"Position is out of range"<<endl;
                }
                else{
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }

        void popFront(){
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        void popBack(){
            Node<T> *temp = head;
            while (temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        void remove(T val){
            Node<T> *temp = head;
            if(temp->data == val) {
                head = temp->next;
                delete temp;
            }
            else{
                while (temp->next != NULL && temp->next->data !=val) temp = temp ->next;
                if(temp->next != NULL){
                    Node<T> *del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                }
            }
        }

        bool contains(T val){
            Node<T> *temp = head;
            while (temp != NULL){
                if(temp->data == val) return true;
                temp = temp->next;
            }
            return false;
        }
        void print(){
            Node<T> *temp = head;
            while (temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            
        }

}; 

int main(){
    linkedList<int> l;
    l.pushFront(8);
    l.pushFront(10);
    l.pushFront(11);
    l.pushFront(12);
    l.pushFront(13);
    cout<<l.contains(10)<<endl;
    // l.popBack();
    // l.popFront();
    // l.remove(10);
    // l.insert(2, 9);
    // l.remove(13);
    l.print();


    return 0;
}