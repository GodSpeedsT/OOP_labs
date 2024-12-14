#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    
    struct Node {
        T data;     
        Node* next;   

        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head; 

public:
    List() : head(nullptr) {}

    ~List() {
        clear();
    }

    void append(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool remove(const T& value) {
        if (!head) return false;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        return false; 
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    List<int> myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);

    std::cout << "Список: ";
    myList.print();

    myList.remove(2);
    std::cout << "После удаления 2: ";
    myList.print();

    myList.clear();
    std::cout << "После очистки списка: ";
    myList.print();

    return 0;
}



