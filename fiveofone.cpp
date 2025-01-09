#include<iostream>
#include<stack>
#include<cmath>
#include<string>
using namespace std;
int main(){
    string exp;
    cout<<"Enter an expression"<<endl;
    getline(cin,exp);
    stack<char>s;
    int top=-1;

    for(char c:exp){
        if(c=='('||c=='{'||c=='['){
            s.push(c);
        }
        else if(c==')'||c=='}'||c==']')
        {
            if(s.empty()){
                cout<<"Parentheses are unbalanced";
                return 0;
            }

                char top = s.top(); // Get the top element
            s.pop();

            // Checking for mismatched parentheses
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                cout << "Parentheses are unbalanced" << endl;
                return 0;
            }
          
        }
    }
    if (!s.empty())
    {
        cout<<"Unbalanced parentheses";
    }

    else{
cout<<"Parentheses are balanced";
}

return 0;
}