#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>
using namespace std;


void IntroScreen();
string RandomWord(int);
int RandomNumber();
void Design(int);
int PrintWord(string word, string letter);


int main() {
	int selection;
	do
	{
		IntroScreen();
		cin >> selection;
		if (selection == 1)
		{
			int counter1 = 0;
			int live = 7;
			string letter;
			string word;
			string guessedLetters = "";

			word = RandomWord(RandomNumber());
			system("cls");

			while (live > 0)
			{
				Design(live);
				PrintWord(word, guessedLetters);


				if (counter1 == word.length())
					break;
				cout << "\n\nEnter one letter only once: " << endl;
				cout << "\n\nLetters guesses: " << guessedLetters << endl;
				cout << "\n\nEnter a letter: ";
				cin >> letter;

				guessedLetters += letter[0];

				if (word.find(letter) != -1)
				{
					counter1 += 1;
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					live--;
				}
			}

			if (live == 0) 
			{
				system("cls");
				Design(0);
				cout << "\n\n\n\t\t\t >>>You Lose!<<<\n\n";
				cout << "The word was: " << word << endl;
			}
			if (live > 0) 
			{
				cout << "\n\n\n\t\t\t >>>You WIN!<<<\n\n";
				cout << "The word was: " << word << endl;
			}

			system("pause");
		}
		if (selection == 2) {
			system("cls");
			string line;
			string word;
			ifstream file("wordlist.txt");
			while (getline(file, line))
			{
				cout << line << endl;
			}
			system("pause");
		}


	} while ((selection != 3 ));

	return 0;
}


void IntroScreen() {
	system("cls");
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "             _   _                  ___  ___            " << endl;
	cout << "            | | | |                 |  \\/  |            " << endl;
	cout << "            | |_| | __ _ _ __   __ _| .  . | __ _ _ __  " << endl;
	cout << "            |  _  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\ " << endl;
	cout << "            | | | | (_| | | | | (_| | |  | | (_| | | | |" << endl;
	cout << "            \\_| |_/\\__,_|_| |_|\\__, \\_|  |_/\\__,_|_| |_|" << endl;
	cout << "                                __/ |                   " << endl;
	cout << "                               |___/                    " << endl <<endl;

	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "-------------------------------------------------Menu-----------------------------------------------" << endl;
	cout << "---------------------------------------Press 1 To Play The Game ------------------------------------" << endl;
	cout << "---------------------------------------Press 2 To View The Word List -------------------------------" << endl;
	cout << "---------------------------------------Press 3 To quit-----------------------------------------" << endl <<endl;
	cout << "---------------------------------------Enter your choice--------------------------------------------" << endl;
}


string RandomWord(int choice) {
	int random_number = RandomNumber();
	//remove after test
	cout << random_number;
	int counter = 0;
	string line;
	string word;
	ifstream file("wordlist.txt");
	while (getline(file, line))
	{
		if (random_number == counter)
		{
			word = line;
			break;
		}
		counter++;
	}
	return word;
}


int RandomNumber() {
	srand(time(0));
	int random;
	random = (rand() % 7) + 0;

	return random;
}


void Design(int live) {
	switch (live)
	{
	case 0:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|       / \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;

	case 1:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|         \\" << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 2:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|        |" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 3:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|       /|\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 4:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |\\" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 5:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|        |  " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 6:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|        0" << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	case 7:
		cout << "\t\t\t|--------|" << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|         " << endl;
		cout << "\t\t\t|           " << endl;
		cout << "\t\t\t|" << endl;
		cout << "\t\t\t|_" << endl;
		break;
	default:
		break;
	}
}


int PrintWord(string word, string letter) {
	for (int x = 0; x < word.size(); x++)
	{
		if (letter.find(word.at(x)) != -1)
			cout << word.at(x) << " ";
		else
		{
			cout << "_ ";
		}
	}
	return 0;
}