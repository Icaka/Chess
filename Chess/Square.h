#pragma once

class Square
{
private:
	char* position;
	short number;
public:
	Square();
	Square(const char*, short);
	~Square();
	Square& operator=(const Square&);

	void copy(const Square&);
	void clear();
	char* getPosition() const;
	short getNumber() const;

	void output();
};
