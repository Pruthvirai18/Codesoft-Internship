//Create a program that generates a random number and asks the user to guess it. 
//Provide feedback on whether the guess is too high or too low until the user guesses the correct number.

using namespace std;
#include<iostream>
#include<cstdlib>
#include<ctime>
int main()
{
    srand(time(0));
    int random_no=rand()%100+1;
    int user_guess;
    int attempts=0;
    cout<<"Welcome to Number guessing game"<<endl;
    cout<<"Guess a number between 1 to 100"<<endl;
    do
    {
        cout<<"Enter your guess"<<endl;
        cin>>user_guess;
        attempts++;
        if(user_guess==random_no)
        cout<<"Congratulations!!User guessed the correct number in "<<attempts<<" attempts"<<endl;
        else if(user_guess<random_no)
        cout<<"Guess is too low!!Try again"<<endl;
        else
        cout<<"Guess is too high!!Try again"<<endl;
    }
    while(user_guess!=random_no);
return 0;
}