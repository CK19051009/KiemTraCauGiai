#include <iostream>
#include <string>
using namespace std;

// Kiểu của các nút trên cây (chứa thông tin về một sinh viên).
struct Node {
    int sbd;           // Số báo danh
    string hoTen;      // Họ tên sinh viên
    Node* left;        // Con trỏ tới nút con trái
    Node* right;       // Con trỏ tới nút con phải

    // Hàm tạo.
    Node(int s, string h, Node* l = nullptr, Node* r = nullptr) 
        : sbd(s), hoTen(h), left(l), right(r) {}
};

// Lớp cây nhị phân tìm kiếm.
class BSTree {
public:
    // Hàm tạo (ban đầu cây rỗng).
    BSTree() : root(nullptr) {}

    // Hàm hủy (xóa hết các nút trên cây).
    ~BSTree() {
        makeEmpty();
    }

    // Kiểm tra cây có rỗng hay không.
    bool isEmpty() {
        return root == nullptr;
    }

    // Xóa hết các nút trên cây.
    void makeEmpty() {
        makeEmpty(root);
    }

    // Chèn một sinh viên mới vào cây.
    void insert(int sbd, string hoTen) {
        insert(sbd, hoTen, root);
    }

    // Tìm sinh viên theo số báo danh.
    Node* search(int sbd) {
        return search(sbd, root);
    }

private:
    Node* root; // Con trỏ tới nút gốc của cây

    // Xóa rỗng cây (viết theo kiểu đệ quy).
    void makeEmpty(Node*& t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }

    // Chèn một sinh viên mới vào cây (viết theo kiểu đệ quy).
    void insert(int sbd, string hoTen, Node*& t) {
        if (t == nullptr) {
            t = new Node(sbd, hoTen);
        } else if (sbd < t->sbd) {
            insert(sbd, hoTen, t->left);
        } else if (sbd > t->sbd) {
            insert(sbd, hoTen, t->right);
        } else {
            // Nếu số báo danh đã tồn tại, không làm gì cả.
            cout << "Số báo danh " << sbd << " đã tồn tại!" << endl;
        }
    }

    // Tìm sinh viên theo số báo danh (viết theo kiểu đệ quy).
    Node* search(int sbd, Node* t) {
        if (t == nullptr || t->sbd == sbd) {
            return t;
        } else if (sbd < t->sbd) {
            return search(sbd, t->left);
        } else {
            return search(sbd, t->right);
        }
    }
};

int main() {
    BSTree bst;

    // Chèn một số sinh viên mới vào cây.
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");

    // Tìm hai sinh viên có số báo danh 4 và 9.
    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    // In kết quả tìm kiếm
    if (n1 != nullptr)
        cout << "Sinh viên với SBD=4 là " << n1->hoTen << endl;
    if (n2 == nullptr)
        cout << "Không tìm thấy sinh viên với SBD=9" << endl;

    // Làm rỗng cây.
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cây đã bị xóa rỗng" << endl;

    return 0;
}