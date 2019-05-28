#pragma once

class Square
{
private:
	char* position;
	short number;
	bool visible;
	char color;
public:
	Square();
	Square(const char*, short, bool, char);
	~Square();
	Square& operator=(const Square&);

	void copy(const Square&);
	void clear();
	char* getPosition() const;
	short getNumber() const;
	bool ifVisible() const;
	char getColor() const;
};
