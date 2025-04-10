#include <iostream>
using namespace std;

struct node{
    node(int data){
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    node(){
        this->next = nullptr;
        this->prev = nullptr;
    }
    int data; 
    node* next; //1 element IN FRONT OF the node
    node* prev; //1 element BEHIND the node
};

class DoublyLinkedList{
    private:
    node* head;
    node* tail;
    int numElements;

    public:
    DoublyLinkedList(){ //Default Constructor
        head = nullptr;
        tail = nullptr;
        numElements = 0;
    };
    DoublyLinkedList(const DoublyLinkedList& list){ //Copy Constructor
        this->numElements=numElements;
        this->head = head; //Contains nullptr,data, next element pointer
        this->tail = tail; //Contains previous pointer, data, nullptr
        node* current = head;
        while (head->next != tail){
            node* n = new node(head->data);
            head = head->next;
        }
        head = current;
        delete current;
    };
    void push(int data){      // appends a new node on the end of the list
        cout << "Push Called" << endl;
        numElements++;

        //List is empty
        if(head==nullptr){
            cout << "Empty List Push" << endl;
            head = new node(data);
            tail = head;
            return;
        }
        cout << "Non-Empty Push called" << endl;
        node* newNode = new node(data);
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
        delete newNode;
    }; 

    void pop(); // removes the last element of the list

    int size(){  // returns the number of elements in the list
        int count = 0;
        node* current = head;
        while(current != nullptr){
            count++;
            current = current->next;
        }
        return count;
    }; 

    int& at(int idx){ // returns a reference to the data at the requested index, "idx"
        node* current = head;
        for (size_t i = 0; i < idx; i++){
            current = current->next;
        }
        return current->data;
    }; 


    ~DoublyLinkedList(){   //Destructor

    };
     
    void operator=(const DoublyLinkedList& list);
    void print(){
        node* current = head;
        while(current->next != nullptr){
            cout << "Print function called" << endl;
            cout << current->data << endl;
            current = current->next;
        }
        cout << current->data << endl;
    }
};


int main(){
    DoublyLinkedList dll;
    dll.push(5);
    dll.push(10);
    dll.push(100);
    dll.print();
    dll.print();
    return 0;
}
