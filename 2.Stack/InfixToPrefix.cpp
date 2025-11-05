#include <iostream>
#include <cctype>   // for isalnum
#include <string>
#include <algorithm> // for reverse
using namespace std;

/* 
Same singly-linked-list Stack implementation as before.
*/

struct Node {
    char data;
    Node* next;

    Node(char val): data(val), next(nullptr) {}
};

class Stack {
    private:
        Node* top;

    public:
        Stack(): top(nullptr) {}

        bool isEmpty() {
            return top == nullptr;
        }

        void push(char x){
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }

        char pop(){
            if(isEmpty()){
                cout << "Stack Underflow! \n";
                return -1;
            }
            Node* temp = top;
            char val = temp->data;
            top = top->next;
            delete temp;
            return val;
        }

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

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert an infix string (no spaces, single-char operands) to postfix
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
            s.pop(); // remove '('
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                // '^' is right-associative: when both top and current are '^', do NOT pop
                if( c=='^' && s.peek()=='^') break;
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

// Convert infix to prefix using the reverse + postfix trick
string infixToPrefix(const string& infix){
    // 1) Reverse the infix
    string rev = infix;
    reverse(rev.begin(), rev.end());

    // 2) Swap '(' with ')' and vice versa
    for(char &c : rev){
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // 3) Get postfix of modified string
    string postfix = infixToPostfix(rev);

    // 4) Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main () {
    string infix;
    cout << "Enter the Infix Expression: ";
    cin >> infix; // no spaces in expression; single-character operands

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
