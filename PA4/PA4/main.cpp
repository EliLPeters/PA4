
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "node.h"

using namespace std;

int main()
{
	node *root = new node{"Does it walk on four legs?"};
	root->setNoChild(new node{ "Does it fly?" });
	root->getNoChild()->setNoChild(new node{ "*centipede" });
	root->getNoChild()->setYesChild(new node{ "*bird" });
	root->setYesChild(new node{"Does it purr"});
	root->getYesChild()->setYesChild(new node{ "*cat" });
	root->getYesChild()->setNoChild(new node{ "*dog" });

	
	

	return 0;
}

