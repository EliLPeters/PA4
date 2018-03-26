
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "node.h"

using namespace std;

void traverse(node* thingy)
{
	if (thingy == nullptr)
	{
		cout << "NULLPTR" << endl;
		return;
	}
	if (thingy->isAnimal())
	{
		cout << "Is it a " << thingy->getText() << "?" << endl;
		string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no")
		{
			cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
		}
		if (answer == "yes")
		{
			cout << "Huzzah!" << endl;
		}
		else
		{
			cout << "Boo!" << endl;
		}
	}
	else
	{
		cout << thingy->getText() << endl;
		string answer;
		cin >> answer;
		while (answer != "yes" && answer != "no")
		{
			cout << "Sorry, I didn't understand what you said. (yes/no)" << endl;
		}
		if (answer == "yes")
		{
			traverse(thingy->getYesChild());
		}
		else
		{
			traverse(thingy->getNoChild());
		}
	}
}

int main()
{
	// CODE FOR CHECKIN
	node *root = new node{"Does it walk on four legs?"};
	root->setNoChild(new node{ "Does it fly?" });
	root->getNoChild()->setNoChild(new node{ "*centipede" });
	root->getNoChild()->setYesChild(new node{ "*bird" });
	root->setYesChild(new node{"Does it purr"});
	root->getYesChild()->setYesChild(new node{ "*cat" });
	root->getYesChild()->setNoChild(new node{ "*dog" });

	traverse(root);

	return 0;
}

