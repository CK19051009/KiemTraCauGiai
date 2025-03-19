#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    T *dataArray;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    Queue(int capacity) {
        this->capacity = capacity;
        dataArray = new T[capacity];
        front = rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] dataArray;
    }

    // Enqueue: Thêm phần tử vào hàng đợi
    void enqueue(T val) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0; // Nếu hàng đợi rỗng, đặt front = 0
        rear = (rear + 1) % capacity;
        dataArray[rear] = val;
    }

    // Dequeue: Xóa phần tử khỏi hàng đợi
    void dequeue() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            // Nếu chỉ còn một phần tử, đặt hàng đợi về trạng thái rỗng
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    // Kiểm tra hàng đợi có rỗng không
    bool empty() {
        return front == -1;
    }

    // Peek: Lấy phần tử ở đầu hàng đợi
    T peek() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return -1; // Giá trị mặc định khi hàng đợi rỗng
        }
        return dataArray[front];
    }

    // Hiển thị các phần tử trong hàng đợi
    void display() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << dataArray[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q(5);

    // Thêm phần tử vào hàng đợi
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    // Hiển thị hàng đợi
    q.display();

    // Xóa phần tử khỏi hàng đợi
    q.dequeue();
    q.dequeue();

    // Hiển thị hàng đợi sau khi xóa
    q.display();


    // Lấy phần tử ở đầu hàng đợi
    cout << "Front element: " << q.peek() << endl;

    return 0;
}