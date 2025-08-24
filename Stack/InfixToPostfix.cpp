#include <iostream>
#include <cctype>   // for isalnum
#include <string>
using namespace std;

/* 
IMPORTANT
In a singly linked list implementation of a stack:
- The topmost node is pointed to by the stack’s top pointer.
- Each node’s next pointer points down to the node below it.
- The bottommost node’s next is nullptr (or null), because there’s nothing below it.
*/

struct Node {
    char data;
    Node* next; //pointer to the next node, stores the address of the next node

    Node(char val): data(val), next(nullptr) {}
    /*  
    Above line is same as following code but better and faster
    Node(char val) {
    data = val;
    next = nullptr; //A new node should not point to anything by default (until we connect it). So we set next = nullptr to indicate it’s not linked yet.
    }   
    */
};


class Stack {
    private:
        Node* top; //pointer to the top node of stack
    /* top is the internal pointer that tracks the top of the stack. We don’t want anyone outside the stack class to directly modify top (for example: stack.top = nullptr; — that would break everything). By making it private, only the class’s own methods can touch it. */

    public:
        Stack(): top(nullptr) {}

        bool isEmpty() {
            return top == nullptr;
        }

        void push(char x){
            Node* newNode = new Node(x);
            newNode->next = top; //linking new node to old top
            top = newNode; //update top pointer 
        }

        char pop(){
            if(isEmpty()){
                cout << "Stack Underflow! \n";
                return -1;
            }

            Node* temp = top;
            char val = temp->data;
            top = top->next; //move top to next node, means node below it.
            delete temp;
            return val;
        } //if we get ) in expression, we should pop from stack until we get (

        char peek(){
            if(isEmpty()){
                return -1;
            }
            return top->data;
        }


};


int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

/* 
Precedence Rule
If the encountered operator has lower OR equal precedence than the operator on top of the stack, then the operator(s) from the stack are popped to the postfix expression first. After that, the encountered operator is pushed onto the stack.
*/

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(const string& infix){
    Stack s;
    string postfix;

    for(char c : infix){
        if(isalnum(c)){
            postfix += c;
        }
        else if (c == '('){
            s.push(c);
        }
        else if (c == ')') {
            while(!s.isEmpty() && s.peek() != '('){
                postfix += s.pop();
            }
            s.pop(); //to remove the first encountered '('
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                if( c=='^' && s.peek()=='^') break; //here if we ^ is encountered in expression as well in stack, then its just simply pushed to stack
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()){
        postfix += s.pop();
    }

    return postfix;
    
}


int main () {
    string infix;
    cout << "Enter the Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}