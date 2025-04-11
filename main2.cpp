#include <iostream>
using namespace std;

template <class T>
struct node {
    node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    node() {
        this->next = nullptr;
        this->prev = nullptr;
    }
    T data;
    node<T>* next;
    node<T>* prev;
};

template <class T>
class DoublyLinkedList {
private:
    node<T>* head;
    node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    DoublyLinkedList(const DoublyLinkedList<T>& list) {
        head = tail = nullptr;
        node<T>* current = list.head;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
    }

    void push(T data) {
        if (head == nullptr) {
            head = new node<T>(data);
            tail = head;
            return;
        }
        node<T>* newNode = new node<T>(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        if (head == nullptr){
            cout << "Cannot remove data which does not exist";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        node<T>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    int size(){
        int count = 0;
        node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    T* at(int idx) {
        node<T>* current = head;
        for (int i = 0; i < idx; i++) {
            if (current == nullptr) return nullptr;
            current = current->next;
        }
        if (current != nullptr) {
            return &(current->data);
        } else {
            return nullptr;
        }
    }

    ~DoublyLinkedList() {
        node<T>* current = head;
        while (current) {
            node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void operator=(const DoublyLinkedList<T>& OGlist) {
        // Clear existing list
        node<T>* current = head;
        while (current) {
            node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;

        // Deep copy
        current = OGlist.head;
        while (current) {
            push(current->data);
            current = current->next;
        }
    }

    void print() {
        node<T>* current = head;
        if (!current) {
            cout << "No data to print" << endl;
            return;
        }
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void insert(T data, int idx){
        if(idx < 0){
            cout << "Index cannot be negative number" << endl;
            return;
        }
        if(idx > size()){
            cout << "Index cannot be end of list or beyond list. Use push instead." << endl;
            return;
        }
        node<T>* current = head;
         for (size_t i = 0; i < idx-1; i++){
            current = current->next;
         }
         node<T>* temp = current->next;
         node<T>* newNode = new node<T>(data);
         current->next = newNode;
         newNode->next = temp;
    }
    void remove(int idx){
        if(idx<0){
            cout << "Index cannot be negative number" << endl;
            return;
        }
        if(idx >= size()){
            cout << "Index cannot be beyond list. Use pop instead if you intended to delete the tail." << endl;
            return;
        }
        if(idx == 0){ //1 hour of my life gone because I for got to put '==' instead of '='
            node<T>* temp = head;
            temp = temp->next;
            delete head;
            head = temp;
            return;
        }
        node<T>* current = head;
        for (size_t i = 1; i < idx; i++){
            current = current->next;
        }
        current->next = current->next->next;
        current = current->next;
        delete current;
    }

};
int main(){
    return 0;
}
