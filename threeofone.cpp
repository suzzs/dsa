#include<iostream>
#include<string>
#include<stack>
#include<cctype>
#include<algorithm>
using namespace std;

int precedence( char o){
    if(o=='+' ||o=='-')return 1;
    if(o== '*' ||o=='/')return 2;
    if(o=='^') return 3;
    return 0;
}

bool isoperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';

}
 string postfix(string infix){
    stack<char>s;//this is a stack to store operators as we cant append them directly to postfix 
    string postfix="";//This is the initialization for final postfix expn 
  
  //Now we should be scanning all the things in infix that has been inputted by the user so for that|
  for(char c: infix ){
    if(isalnum(c)){
        postfix+=c;
    }
    else if(c=='('){
        s.push(c);
    }
    else if(c==')'){
        while(!s.empty()&&s.top()!='(')//this condition is to ensure when to stop popping operators
        {
            postfix+=s.top();
            s.pop();

        }
        if(!s.empty()&&s.top()== '(')
        s.pop();

    }
    else if(isoperator(c)){
        while(!s.empty()&&precedence(s.top())>precedence(c)){
            postfix+=s.top();
            s.pop();
            
        }
        s.push(c);

    }
  }
  while(!s.empty()){
    postfix+=s.top();
    s.pop();
  }
  return postfix;
  }
   int main(){
    string infix;


    cout<<"Enter an infix expression"<<endl;
    //I faced an issue while doing this (cin>>infix;)so for proper input of the string;

    getline(cin,infix);
    reverse(infix.begin(),infix.end());//yo ta gariyo but aba paranthesis lai swap pani garna parxa,ani you cant directly assign the expression hai!!!!
for(char &c:infix){
    if(c=='(')
    c=')';
    else if(c==')')
    c='(';
}
    string post =postfix(infix);
    reverse(post.begin(),post.end());

    cout<<"Prefix expression  is"<<post<<endl;
    return 0;

  }


