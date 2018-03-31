// CS-211 Spring 2018
// Eli Peters
// PA#4 node.h
#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class node
{
private:
	node* _yesChild = nullptr;
	node* _noChild = nullptr;

	bool _Animal;

	string _sentence;
	string _name = "";
	string _text;

public:
	node(string input="test")
	{
		_text = input;
		if (input.at(0) == '*')
		{
			_Animal = true;
			string temp = input.substr(1);
			switch (temp[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				_sentence = ("Is it an " + temp);
				break;
			default:
				_sentence = ("Is it a " + temp);
			}
		}
		else
		{
			_Animal = false;
			_sentence = input;
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

	string getSentence()
	{
		return _sentence;
	}

	bool isAnimal()
	{
		return _Animal;
	}

	~node()
	{
		if (_noChild != nullptr)
		{
			delete _noChild;
		}
		if (_yesChild != nullptr)
		{
			delete _yesChild;
		}
	}
};

#endif // !NODE_H
