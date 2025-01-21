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

    int find(const T& value) {
        Node<T>* node = head;
        int position = 0;
        while (node) {
            if (node->data == value) {
                return position;
            }
            node = node->next;
            position++;
        }
        return -1;
    }

    void erase(int position) {
        if (position < 0) return;

        Node<T>* node = head;
        int currentPos = 0;

        while (node) {
            if (currentPos == position) {
                if (node->prev) {
                    node->prev->next = node->next;
                }
                else {
                    head = node->next;
                }

                if (node->next) {
                    node->next->prev = node->prev;
                }
                else {
                    tail = node->prev;
                }

                delete node;
                return;
            }
            node = node->next;
            currentPos++;
        }
    }

    void reverse() {
        Node<T>* node = head;
        Node<T>* temp = nullptr;

        while (node) {
            temp = node->prev;
            node->prev = node->next;
            node->next = temp;
            node = node->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    void print() {
        Node<T>* node = head;
        while (node) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    ~List() {
        clear();
    }
};

int main() {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_front(5);

    std::cout << "List after adding elements: ";
    list.print();

    int pos = list.find(20);
    std::cout << "Position of 20: " << pos << std::endl;

    list.erase(2);
    std::cout << "List after erasing element at position 2: ";
    list.print();

    list.reverse();
    std::cout << "List after reversing: ";
    list.print();

    return 0;
}
