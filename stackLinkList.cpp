#include <iostream>
using namespace std;

class Node{
    public: 
    int key;
    Node* next;
    Node(int value,Node* next=NULL){
        this->key=value;
        this->next=next;
    }
};

class Stack{
    public:
    int currentSize;
    int size;
    Node* stackTop;

    public:
        Stack(int size){
            stackTop=NULL;
            this->size=size;
            currentSize=0;
        }
        bool isEmpty(){
            if(stackTop==NULL){
                return true;
            } 
            return false;
        }

        bool isFull(){
            if (size==currentSize){
                return true;
            }
            return false;
        }

        void push(int value){
            Node* node = new Node(value,stackTop);
            stackTop=node;
            currentSize++;
        }
    
        int pop(){
            if(isEmpty()){
                cout <<"Stack is underflow.";
                return -1 ;
            }
            Node* curr = stackTop;
            int topValue=curr->key;
            stackTop = stackTop->next;
            delete curr;
            return topValue;

        }

        int getTop(){
            if (isEmpty()){
                cout<<"Stack is empty.";
                return -1;
            }
            return stackTop->key;
        }

        void displayStack(){
            if (isEmpty()){
                cout<<"Stack is empty.";
                return;
            }
            Node* curr =stackTop;
            while(curr != NULL){
                cout<<curr->key<<" ";
                curr=curr->next;
            }
            cout<<endl;

        }

};

int main(){
    clock_t start,end;
    start=clock();
    Stack mystack(10);
    mystack.push(8);
    mystack.push(10);
    mystack.push(5);
    mystack.push(15);
    mystack.push(23);
    mystack.push(6);
    mystack.push(18);
    mystack.push(20);
    mystack.push(17);
    mystack.displayStack();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.displayStack();
    mystack.push(4);
    mystack.push(30);
    mystack.push(3);
    mystack.push(1);
    mystack.displayStack();
    end=clock();
    double total_t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );

    return 0;
}





