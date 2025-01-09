#include<iostream>
using namespace std;
class stack{
    private:
    float arr[5];
    int top=-1;
    public:
   void input(float x){
    if (top==4){
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        arr[top]=x; //stores value in stack
    cout<<"The value ["<<x<<"] has been  pushed onto the stack"<<endl;
    }

    }

    float pop(){

        if(top==-1){
            cout<<"Underflow"<<endl;
            return 0;
        }
        else{
            float y=arr[top];
            
            top--;
            cout<<"["<<y<<"] has been popped"<<endl;
            return y;

        }
    }
    

    };



int main(){
    stack s;
    s.input(10);
    s.input(20);
    s.input(30);
    s.input(40);
    s.input(50);
    s.input(60);
    s.pop();
    s.pop();
    return 0;

}