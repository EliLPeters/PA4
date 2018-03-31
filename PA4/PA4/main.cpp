// CS-211 Spring 2018
// Eli Peters
// PA#4 main.cpp

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "node.h"

using namespace std;

node* createAnimal()
{
	cout << "I\'m stumped, what animal were you thinking of?" << endl;
	string new_animal;
	cin >> new_animal;
	
	return new node{ ('*' + new_animal) };
}

void play(node* thingy)
{
	if (thingy == nullptr)
	{
		cout << "NULLPTR" << endl;
		return;
	}
	cout << thingy->getSentence() << endl;
	if (thingy->isAnimal() && thingy->getNoChild() == nullptr)
	{
		string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no")
		{
			cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
			cin >> answer;
		}
		if (answer == "yes")
		{
			cout << "Huzzah!" << endl;
		}
		else
		{
			cout << "What were you thinking of?" << endl;
			string new_animal;
			cin >> new_animal;
			cout << "What is a question I can ask to differentiate it from " + thingy->getSentence() + "?" << endl;
			string new_question;
			cin.ignore();
			getline(cin, new_question);
			thingy->setNoChild(new node{ new_question });
			cout << "Is the answer to this question \"yes\" or \"no\"?" << endl;
			string yn;
			getline(cin, yn);
			if (yn == "yes")
			{
				thingy->getNoChild()->setYesChild(new node{ ("*" + new_animal) });
			}
			else
			{
				thingy->getNoChild()->setNoChild(new node{ ("*" + new_animal) });
			}
			
			return;
		}
	}
	else
	{
		string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no")
		{
			cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
			cin >> answer;
		}
		if (answer == "yes")
		{
			if (thingy->getYesChild() != nullptr)
			{
				play(thingy->getYesChild());
			}
			else
			{
				thingy->setYesChild(createAnimal());
			}
		}
		else
		{
			if (thingy->getNoChild() != nullptr)
			{
				play(thingy->getNoChild());
			}
			else
			{
				thingy->setNoChild(createAnimal());
			}
		}
	}
}

void readQuestionsHelper(ifstream& input, node* cur_node)
{
	if (input.is_open() && input.good())
	{
		string cur_entry;
		getline(input, cur_entry);
		cur_node->setNoChild(new node{ cur_entry });
		if (cur_node->getNoChild()->isAnimal() == false)
		{
			readQuestionsHelper(input, cur_node->getNoChild());
		}
		getline(input, cur_entry);
		cur_node->setYesChild(new node{ cur_entry });
		if (cur_node->getYesChild()->isAnimal() == false)
		{
			readQuestionsHelper(input, cur_node->getYesChild());
		}
	}
}

void writeFileHelper(ofstream& output, node* cur_node)
{
	if (cur_node != nullptr)
	{
		output << cur_node->getText() << endl;
		if (cur_node->getNoChild() != nullptr)
		{
			writeFileHelper(output, cur_node->getNoChild());
		}
		if (cur_node->getYesChild() != nullptr)
		{
			writeFileHelper(output, cur_node->getYesChild());
		}
	}
	else
	{
		cout << "NULLPTR" << endl;
	}
}

int main()
{
	node *root;

	cout << "*** ANIMAL GUESSING GAME ***" << endl;
	cout << "Would you like to import your questions from a file? (yes/no)" << endl;
	string answer;
	cin >> answer;
	while (answer != "yes" && answer != "no")
	{
		cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
		cin >> answer;
	}
	if (answer == "yes")
	{
		cout << "Which file would you like to import them from?" << endl;
		string file_name;
		cin.ignore();
		getline(cin, file_name);
		ifstream input;
		input.open(file_name);

		string first;
		getline(input, first);

		root = new node{ first };
		if (input.is_open() && input.good())
		{
			readQuestionsHelper(input, root);
		}
		else
		{
			cout << "File " << file_name << " not found. Running default game." << endl;
			root = new node{ "*dog?" };
		}
		input.close();
	}
	else
	{
		root = new node{ "*dog?" };
	}
	

	bool play_again = true;

	while (play_again == true)
	{
		play(root);
		cout << "Would you like to play again? (yes/no)" << endl;
		string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no")
		{
			cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
			cin >> answer;
		}
		if (answer == "no")
		{
			play_again = false;
		}
	}

	cout << "Would you like to export your questions to a file? (yes/no)" << endl;
	cin >> answer;
	while (answer != "yes" && answer != "no")
	{
		cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
		cin >> answer;
	}
	if (answer == "yes")
	{
		cout << "Which file would you like to export them to?" << endl;
		string file_name;
		cin.ignore();
		getline(cin, file_name);
		ofstream output;
		output.open(file_name);
		if (output.is_open() && output.good())
		{
			writeFileHelper(output, root);
		}
		output.close();
	}

	delete root;

	return 0;
}

