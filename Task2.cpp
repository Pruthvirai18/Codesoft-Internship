//Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division.
// Allow the user to input two numbers and choose an operation to perform.

using namespace std;
#include<iostream>
int main()
{
    int a,b,result;
    char op;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;
    cout<<"Enter the operator"<<endl;
    cin>>op;
    switch(op)
    {
        case '+':
            result=a+b;
            cout<<"Addition "<<result<<endl;
            break;
        case '-':
            result=a-b;
            cout<<"Subtraction "<<result<<endl;
            break;
        case '*':
            result=a*b;
            cout<<"Multiplication "<<result<<endl;
            break;
        case '/':
            if(b==0)
            cout<<"Divide by zero error"<<endl;
            else
            {
                result=a/b;
                cout<<"Division "<<result<<endl;
            }
            break;
        default:
            cout<<"Inavlid operator input"<<endl;
    }
    return 0;
}