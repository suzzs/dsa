#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;
int main(){
    string postfix;
    cout<<"Enter the postfix expression to be evaluated"<<endl;
    getline(cin,postfix);
    stack<int>s;//stack to store operands
    int top=-1;
    for(char c:postfix){
        if(isalnum(c)){
            s.push(c-'0');//coverting intro integer 
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();

            int result;
            //now we are using switch case statements
            switch(c){
                case '+':
                result=b+a; //yo order crucial xa kinaki b suruma halieko hunxa stack ma so it should be kept first,addition ma prblm navaeni aruma huna sakxa 
                break;

                case '-':
                result =b-a;
                break;

                case '*':
                result=b*a;
                break;

                case '/':
                result=b/a;
                break;

                case '^':
                result =b^a;
                break;
                
                default:
                cout<<"Invalid operator"<<endl;

            }
            s.push(result);

        }
    }
    if(!s.empty()){
        cout<<"The answer is"<<s.top();
    }
    else{
        cout<<"Invalid postfix expression"<<endl;
    }
    return 0;
}