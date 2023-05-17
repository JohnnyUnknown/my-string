#pragma once

class myString
{
	size_t size;
	size_t capacity;
	char* str{ nullptr };
public:
	myString(size_t userSize);
	myString();
	myString(const char* text);

	myString(const myString& obj);
	myString(myString&& obj);

	myString& operator= (const myString& obj);
	myString& operator= (myString&& obj);
	char operator[] (size_t index) const;
	char& operator[] (size_t index);
	size_t operator() (char symbol);

	size_t length() const;
	friend long myStol(const myString& obj);

	friend std::istream& operator>>(std::istream& in, myString& text);
	friend std::ostream& operator<<(std::ostream& out, myString& text);

	~myString()
	{
		//delete[] str;
	}
};
