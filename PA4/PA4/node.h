#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>;

using namespace std;

class node
{
private:
	node* _yesChild = nullptr;
	node* _noChild = nullptr;

	bool _Animal;

	string _text;

public:
	node(string input="test")
	{
		if (input.at(0) == '*')
		{
			_Animal = true;
			_text = input.substr(1);
		}
		else
		{
			_Animal = false;
			_text = input;
		}
	}

	node* getYesChild()
	{
		return _yesChild;
	}

	node* getNoChild()
	{
		return _noChild;
	}

	void setYesChild(node* input)
	{
		_yesChild = input;
	}

	void setNoChild(node* input)
	{
		_noChild = input;
	}

	string getText()
	{
		return _text;
	}

	bool isAnimal()
	{
		return _Animal;
	}

	~node()
	{
		delete _yesChild;
		delete _noChild;
	}
};

#endif // !NODE_H
