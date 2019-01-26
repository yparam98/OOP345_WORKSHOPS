/*
program: Text.cpp
programmer: yathavan, parameshwaran
date: January 21, 2019
description: workshop 2 in lab portion
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "Text.h"

using namespace std;

namespace sict
{
	Text::Text()
	{
		numOfStringsCurrentlyStored = 0;
		strArray = nullptr;
	}

	Text::Text(const char * incomingStr)
	{
		ifstream fileptr(incomingStr);
		int lineCount = 0;
		string bufferOne;
		if (fileptr.is_open())
		{
			while (!fileptr.eof() && fileptr.good()) 
			{
				getline(fileptr, bufferOne, '\n'); 
				bufferOne.clear(); 
				lineCount++; 
			}
			numOfStringsCurrentlyStored = (lineCount-1);
			if (fileptr.eof()) 
			{
				fileptr.clear();
				fileptr.seekg(0, fileptr.beg);
			}
			
			strArray = new string[lineCount];
			int index = 0;
			while (!fileptr.eof() && fileptr.good()) 
			{
				getline(fileptr, strArray[index], '\n'); 
				index++; 
			}
		}
	}

	Text::Text(const Text & incomingTextObj) 
	{
		strArray = nullptr;
		*this = incomingTextObj; 		
	}

	Text & Text::operator=(const Text & incomingObj) 
	{
		if (this != &incomingObj) 
		{
			this->numOfStringsCurrentlyStored = incomingObj.numOfStringsCurrentlyStored; 
			delete[]this->strArray;
			this->strArray = nullptr;
			this->strArray = new string[incomingObj.strArray->length()]; 
			for (int index = 0; index < incomingObj.strArray->length(); index++)
			{
				this->strArray[index] = incomingObj.strArray[index];
			}
		}
		return *this;
	}

	Text::~Text()
	{	
		delete[]this->strArray;
		this->strArray = nullptr;
	}

	size_t Text::size() const
	{
		return (this->numOfStringsCurrentlyStored);
	}
}


