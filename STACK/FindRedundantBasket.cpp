#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isredundantbracket(string str){
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            s.push(ch);
        }

        if(ch == ')'){
            bool isredundant = true;
            while(s.top() != '('){
                char top = s.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    isredundant = false;
                }
                s.pop();
            }
            if(isredundant == true) return true;
            s.pop(); // pop the opening bracket '('
        }
    }
    return false;
}

int main(){
    string str = "((a+b)+c)";

    if(isredundantbracket(str)){
        cout << "Redundant bracket present." << endl;
    }
    else{
        cout << "Redundant bracket absent." << endl;
    }
    return 0;
}
