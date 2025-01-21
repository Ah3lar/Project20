#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
    }

    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else {
            head = tail = newNode;
        }
    }

    void pop_front() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void pop_back() {
        if (tail) {
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
        }
    }

    T& front() {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    void clear() {
        head = tail = nullptr;
    }

    ~List() {
        clear();
    }
};

int main() {
    List<int> list;
    list.push_back(10);
    list.push_front(5);
    list.push_back(20);

    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;

    list.pop_front();
    list.pop_back();

    std::cout << "After pops:" << std::endl;
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;

    return 0;
}
