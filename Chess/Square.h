#pragma once

class Square
{
private:
	char* position;
	short number;
	char color;
	char occupiedBy;
public:
	Square();
	Square(const char*, short, char);
	~Square();
	Square& operator=(const Square&);

	void copy(const Square&);
	void clear();
	char* getPosition() const;
	short getNumber() const;
	char getColor() const;
	void output();
	char getOccupacy() const;
	void setOccupacy(const char);
};
