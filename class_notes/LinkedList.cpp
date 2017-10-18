#include <iostream>
using namespace std;

class LinkedList{
private:
    class Node{
    public:
        int val;
        Node* next;
        Node(int v, Node* n) : val(v), next(n) {}
    };
    Node* head;
    Node* tail;
public:
    LinkedList(): head(nullptr), tail(nullptr) {}
    ~LinkedList() {
        Node* temp;
        for (Node* p = head; p != nullptr; p = temp){
            temp = p->next;
            delete p;
        }
    }
    LinkedList(const LinkedList& orig) {}
    LinkedList& operator =(const LinkedList& orig) {}
    void addFirst(int v) {
        // Node* temp = new Node();
        // temp->val = v;
        // temp->next = head;
        // head = temp;
        // if(tail == nullptr){
        //     tail = head;
        // }
        head = new Node(v, head);
    }
    void addLast(int v) {
        // Node* temp = new Node();
        // temp->val = v;
        // temp->next = nullptr;
        // tail->next = temp;
        if(tail == nullptr){
            head = tail = new Node(v, nullptr);
            return;
        }
        tail->next = new Node(v, nullptr);
    }
    bool isEmpty() const {
        head == nullptr;
    }
    void removeFirst() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void removeLast() {
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* p;
        for (p = head; p->next != tail; p = p->next)
            ;
        p->next = nullptr;
        delete tail;
        tail = p;
    }
    void insert(int pos, int val){
        //slow way -- O(n)
        for (int i = 0; i < pos; i++){
            p = p->next;
        }
        Node* temp = new Node(val, p->next);
        p->next = temp;
    }
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(const LinkedList& list){
            current = list.head;
        }
        //no destructor since we dont allocate memory
        bool operator !() const {
            return current != nullptr;
        }
        //this is ++i
        void operator ++() {
            current = current->next;
        } 
        //this is i++
        void operator ++(char*) {
            current = current->next;
        }
        int operator *() const {
            return current->val;
        }
    };
};

int main(){
    for (LinkedList::Iterator i = a; !i; ++i){
        cout<< *i<< " ":
    }
    cout<< "\n";
}