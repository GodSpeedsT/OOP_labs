/*#include <iostream>
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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
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

   cout << "Список: ";
    myList.print();

    myList.remove(2);
   cout << "После удаления 2: ";
    myList.print();

    myList.clear();
    cout << "После очистки списка: ";
    myList.print();

    return 0;
}*/



// lab 2

/*#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double calculateZ1(double x) {
    double numerator = x * x + 2 * x - 3 + (x + 1) * sqrt(x * x - 9);
    double denominator = x * x - 2 * x - 3 + (x - 1) * sqrt(x * x - 9);

    if (denominator == 0) {
        throw runtime_error("Ошибка: деление на ноль при вычислении Z1.");
    }

    return numerator / denominator;
}


double calculateZ2(double x) {
    double value = (x + 3) / (x - 3);

   
    if (value < 0) {
        throw runtime_error("Ошибка: отрицательное значение под квадратным корнем при вычислении Z2.");
    }

    return sqrt(value);
}

int main() {
    setlocale(LC_ALL, "RU");
    double x;

    cout << "Введите значение x: ";
    cin >> x;

    try {
        double z1 = calculateZ1(x);
        double z2 = calculateZ2(x);

        cout << fixed << setprecision(6);
        cout << "Z1 = " << z1 << endl;
        cout << "Z2 = " << z2 << endl;

        if (fabs(z1 - z2) < 1e-6) {
            cout << "Z1 и Z2 приблизительно одинаковы." << endl;
        }
        else {
            cout << "Z1 и Z2 различаются." << endl;
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}*/


//lab 3

#include <iostream>
using namespace std;

template <typename T>
class APtr {
public:
   
    APtr(T* ptr = nullptr) : ptr_(ptr) {}

   
    APtr(APtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    APtr(const APtr&) = delete;
    ~APtr() {
        delete ptr_;
    }

    APtr& operator=(APtr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    APtr& operator=(const APtr&) = delete;

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    T* get() const {
        return ptr_;
    }

    void reset(T* ptr = nullptr) {
        delete ptr_; 
        ptr_ = ptr;  
    }

private:
    T* ptr_; 
};

int main() {
    setlocale(LC_ALL , "RU");
    APtr<int> p1(new int(42)); 

    cout << "Значение: " << *p1 << endl;

    APtr<int> p2 = move(p1); 

    if (p1.get() == nullptr) {
       cout << "p1 теперь пустой." <<endl;
    }

    cout << "Значение через p2: " << *p2 << endl;

    p2.reset(); 

    return 0;
}
