#include <iostream>
using namespace std;

class InfixToPostfix {
private:
    char data[20];
    int top;

public:
    InfixToPostfix() {
	 top = -1;
	 }


    int precedence(char op) {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

 
    void convert(char infix[]) {
        char postfix[20];
        int j = 0;

        for (int i = 0; infix[i] != '\0'; i++) {
            char ch = infix[i];

            
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                postfix[j++] = ch;
            }

           
            else if (ch == '(') {
                data[++top] = ch;
            }

            
            else if (ch == ')') {
                while (top != -1 && data[top] != '(') {
                    postfix[j++] = data[top--];
                }
                top--; 
            }

           
            else {
                while (top != -1 && precedence(data[top]) >= precedence(ch)) {
                    postfix[j++] = data[top--];
                }
                data[++top] = ch; 
            }
        }

        
        while (top != -1) {
            postfix[j++] = data[top--];
        }

        postfix[j] = '\0'; 
        cout << "Postfix Expression: " << postfix << endl;
    }
};

int main() {
    InfixToPostfix obj;
    char infix[20];

    cout << "Enter Infix Expression: ";
    cin >> infix;

    obj.convert(infix);
    return 0;
}
