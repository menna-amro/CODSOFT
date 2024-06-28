#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	int guess;
	char play;

	cout << "* * * * NUMBER GUESSING GAME * * * *" << endl << endl;
	cout << "I have selected a number between 1 and 100. Try guessing it!" << endl;

	do
	{
		// Initialize random seed using current time to ensure different random numbers on each program run
		srand(time(0));

		// generate random number between 1 and 100
		int randomNum = rand() % 100 + 1;

		do
		{
			cout << endl << "Enter your guess : ";
			cin >> guess;

			if (guess < randomNum)
				cout << "Oops too low. Try again!" << endl << endl;
			else if (guess > randomNum)
				cout << "Oops too high. Try again!" << endl << endl;
			else
			{
				cout << "Congratulations! You guessed the correct number." << endl << endl;
				cout << "-------------------------------------------------------" << endl << endl;
			}

		} while (guess != randomNum);

		cout << "Do you want to play again? (y/n) : ";
		cin >> play;

		play = tolower(play);

		while (play != 'y' && play != 'n')
		{
			cout << "Invalid choice. Please enter 'y' to play again or 'n' to exit : ";
			cin >> play;
			play = tolower(play);
		}

	} while (play == 'y');

	return 0;
}
