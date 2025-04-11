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

    public:
    DoublyLinkedList(){ //Default Constructor
        head = nullptr;
        tail = nullptr;
    };
    DoublyLinkedList(DoublyLinkedList& list){ //Copy Constructor
        cout << "Copy Constructor Called" << endl;
        this->head = head; //Contains nullptr,data, next element pointer
        this->tail = tail; //Contains previous pointer, data, nullptr
        node* current = head;
        while (current->next != list.tail){
            node* n = new node(current->data);
            current = current->next;
        }
        this->head = current;
        delete current;
    };
    void push(int data){      // appends a new node on the end of the list

        //List is empty
        if(head==nullptr){
            head = new node(data);
            tail = head;
            return;
        }
        node* newNode = new node(data);
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
        delete newNode;
    }; 

    void pop(){  // removes the last element of the list
        if(head != tail){
            node* temp = tail;
            tail = tail->prev;
            tail->next=nullptr;
            delete temp;
        }
        else{
            delete tail;
            head = tail = nullptr;
        }
    };

    int size(){  // returns the number of elements in the list
        int count = 0;
        node* current = head;
        while(current->next != nullptr){
            count++;
            current = current->next;
        }
        count++;
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
        delete this->head;
        delete this->tail;
    };
     
    void operator=(DoublyLinkedList& OGlist){ //Operator Overload
        cout << "Operator overload called" << endl;
        for (int i = 0; i < OGlist.size(); i++){
            this->push(OGlist.at(i));
        }
    };
    void print(){ //Print every entry in DLL
        if(head != tail){
        node* current = head;
        while(current != tail){
            cout << current->data << endl;
            current = current->next;
        }
        cout << current->data << endl;
    }
    else{cout << "No data found" << endl;}
    }
};


int main(){
    DoublyLinkedList dll;
    dll.push(5);
    dll.push(1230);
    dll.push(14);
    dll.print();
    cout << dll.at(1) << endl;
    cout << dll.size() << endl;
    DoublyLinkedList secondDLL;
    secondDLL = dll;
    secondDLL.print();
    secondDLL.pop();
    secondDLL.print();
    cout << "Code finished without crashing" << endl;
    return 0;
}
