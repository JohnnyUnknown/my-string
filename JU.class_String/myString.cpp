#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include "myString.h"

myString::myString(size_t userSize) : size{ userSize }, capacity{ userSize + 20 }, str{ new char[userSize] {} } {}


myString::myString() : myString(80) {}


myString::myString(const char* text)
{
	size = strlen(text);
	capacity = strlen(text);
	str = new char[size] + 1;
	for (size_t i = 0; i < size + 1; i++)
	{
		str[i] = text[i];
	}
}


myString::myString(const myString& obj) : size{ obj.size }, capacity{ obj.capacity }, str{ new char[obj.size] {} }
{
	strcpy(str, obj.str);
}


myString::myString(myString&& obj) : size{ obj.size }, capacity{ obj.capacity }, str{ obj.str }
{
	obj.size = 0;
	obj.capacity = 0;
	obj.str = nullptr;
}


myString& myString::operator= (const myString& obj)
{
	if (this == &obj) return *this;
	//if (str != nullptr) delete[] str;
	strcpy(str, obj.str);
	return *this;
}


myString& myString::operator= (myString&& obj)
{
	if (this != &obj)
	{
		delete[] str;
		size = obj.size;
		capacity = obj.capacity;
		str = obj.str;
		obj.size = 0;
		obj.capacity = 0;
		obj.str = nullptr;
	}
	return *this;
}


std::istream& operator>>(std::istream& in, myString& text)
{
	size_t cap = 1;
	size_t index = 0;
	char* new_str = new char[cap + 1];
	
	do
	{
		if (index > cap - 1)
		{
			char* temp = new char[index];
			for (size_t i = 0; i < index; i++)
				temp[i] = new_str[i];
			delete[] new_str;

			cap += 20;
			new_str = new char[cap];
			for (size_t i = 0; i < index; i++)
				new_str[i] = temp[i];
			delete[] temp;
		}
		new_str[index] = in.get();
	} while (new_str[index++] != '\n');

	new_str[index - 1] = '\0';

	//text = myString(new_str);			// Это решение изящнее

	text.size = index;
	text.capacity = cap;
	text.str = new char[cap];
	strcpy(text.str, new_str);
	return in;
}


std::ostream& operator<<(std::ostream& out, myString& text)
{
	out << text.str;
	return out;
}


char myString::operator[] (size_t index) const
{
	assert(index >= 0 and index < size and "Index is out of range!");
	return str[index];
}


char& myString::operator[] (size_t index)
{
	assert(index >= 0 and index < size and "Index is out of range!");
	return str[index];
}


size_t myString::operator() (char symbol)
{
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] == symbol)
			return i;
	}
	return -1;
}


size_t myString::length() const
{
	return size;
}


long  myStol(const myString& obj)
{
	long num = 0;
	for (long i = 0; i < obj.size; i++)
	{
		if (obj.str[i] == 44 && num > 0) break;
		else if (obj.str[i] >= 48 && obj.str[i] <= 57)
		{
		num *= 10;
		num += (int)obj.str[i] - 48;
		}
	}
	if (num != 0) return num;
}