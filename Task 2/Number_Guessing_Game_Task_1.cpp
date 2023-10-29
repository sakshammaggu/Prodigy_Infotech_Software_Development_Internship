/*
    Task 1:
    -------
    Create a program that generates a random number and asks the
    user to guess it. Provide feedback on whether the guess is too
    high or too low until the user guesses the correct number.
*/
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// function that will generate the random number in a range specified
int generateRandomNumber(int minimum, int maximum) 
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(minimum, maximum);
    return dist(mt);
}

// function that will provide the user feedback i.e guessed number is low or high or it's guessed
void number_guessing_game(int random_number)
{
    int new_user_guess;

    while (new_user_guess != random_number)
    {
        cout<<"Enter your guess: ";
        cin>>new_user_guess;
        cout<<endl;

        // if guessed number is lesser than random number generated
        if (new_user_guess < random_number) 
        {
            cout<<"It's low! Guess high! Try again." << endl;
        } 

        // if guessed number is greater than random number generated
        else if (new_user_guess > random_number) 
        {
            cout<<"It's high! Guess low! Try again." << endl;
        } 

        // guessed number is equal to random number generated
        else 
        {
            cout<<"Congratulations! You guessed the correct number: " << random_number << endl;
        }

        cout<<endl;
    }
}
int main() 
{
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
    
    int min_value, max_value;
    cout<<"Enter the minimum value of the range the random number has to be generated: ";
    cin>>min_value;
    cout<<"Enter the maximum value of the range the random number has to be generated: ";
    cin>>max_value;
    
    cout<<endl;

    int random_number=generateRandomNumber(min_value, max_value);

    int number_guessed_by_user;
    cout<<"Enter a guessing number: ";
    cin>>number_guessed_by_user;

    cout<<endl;

    if (random_number==number_guessed_by_user)
    {
        cout<<"Awesome, you guessed the number in the first time."<<endl;
        cout<< "Random number which was generated: " << random_number << endl;
        cout<<"Number guessed by you"<<number_guessed_by_user<<endl;
    }
    else
    {
        cout<<"Sorry, you haven't guessed the right number in your first time. It's okay try again till you guessed it right."<<endl;
        number_guessing_game(random_number);
    }
    
    return 0;
}