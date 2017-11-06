/**
 * Matthew Aquiles
 * CPE 593 HW4b
 * due 11-13-2017
**/

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class DoubleLinkedList2 {
private:
    class Node{
    private:

    public:
        int data;
        Node* next;
        Node* prev;

        Node(int d, Node* n, Node* p) : data(d), next(n), prev(p) {}
        ~Node(){
            //delete the Node
        }
    };
    Node* head;
    Node* tail;

public:
    DoubleLinkedList2(){
        head = nullptr;
        tail = nullptr;
    }

    ~DoubleLinkedList2(){
        if(tail == nullptr && head == nullptr){
            return;
        }
        Node* temp;
        while(temp != nullptr){
            tail = tail->prev;
            delete temp;
        }
    }

    DoubleLinkedList2(const DoubleLinkedList2& orig){
        head = orig.head;
        tail = orig.tail;
    }

    DoubleLinkedList2& operator=(const DoubleLinkedList2& orig){
        if(this != &orig){
            head = orig.head;
            tail = orig.tail;
        }
        return *this;
    }

    //add data to the front of the DoubleLinkedList2
    void addFirst(int a){
        if(head == nullptr && tail == nullptr){
            Node* temp = new Node(a, nullptr, nullptr);
            head = temp;
            tail = temp;
        }
        else{
            Node* temp = new Node(a, head, nullptr);
            head->prev = temp;
            head = temp;
        }
    }

    //ADD_FRONT
    //means add start, start+step, start=2*step... until end, at the front
    void addFront(int start, int step, int end){
        if(step == 0){
            return;
        }

        int i = 0;
        while (start + (step*i) <= end){
            addFirst(start + (step*i));
            i++;
        }
    }

    //add a number to the end of the DoubleLinkedList2
    void addLast(int b){
        if(head == nullptr && tail == nullptr){
            Node* temp = new Node(b, nullptr, nullptr);
            head = temp;
            tail = temp;
        }
        else{
            Node* temp = new Node(b, nullptr, tail);
            tail->next = temp;
            tail = temp;
        }
    }

    //ADD_BACK
    //means add start, start+step, start+2*step.. unitl end, at the back
    void addBack(int start, int step, int end){
        if(step == 0){
            return;
        }

        int i = 0;
        while (start + (step*i) <= end){
            addLast(start + (step*i));
            i++;
        }
    }

    //REMOVE_FRONT
    //means remove the first n nodes from the list
    void removeFront(int n){
        for (int i = 0; i<n; i++){
            if(head == nullptr && tail == nullptr){
                return;
            }
            else if(head == tail){
                delete head;
                return;
            }

            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    //REMOVE_BACK
    //means remove the last n nodes from the list
    void removeBack(int m){
        for (int i = 0; i<m; i++){
            if(head == nullptr && tail == nullptr){
                return;
            }
            else if(head == tail){
                delete head;
                return;
            }

            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    //OUTPUT
    void output(){
        Node* temp = head;
        cout<< "head <-> ";
        while (temp != tail){
            cout<< temp->data<< " <-> ";
            temp = temp->next;
        }
        cout<< "tail"<< "\n";
    }
};

int main(){
    DoubleLinkedList2* DLL2 = new DoubleLinkedList2();
    DLL2->addFront(5, 5, 10);
    DLL2->addBack(5, 5, 30);
    DLL2->output();
    DLL2->removeFront(2);
    DLL2->removeBack(2);
    DLL2->output();
    
    return 0;
}