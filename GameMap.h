#pragma once

#include <algorithm>
#include <vector>

struct Vector2
{
	int x, y;
};
class GameMap
{
	int** map;
	Vector2 Size;
	int length; // Length for win

public:
	GameMap();
	GameMap(Vector2, int);
	GameMap(int, int, int);
	~GameMap();

	bool setPosition(Vector2, int);
	bool isEmpty(Vector2);
	bool isEmpty(int, int);
	void setMap(Vector2, int);
	void setMap(int, int, int);
	int getValue(Vector2);
	int getValue(int, int);
	int getLength() { return this->length; }
	Vector2 getSize() { return Size; }
	int CheckList(std::vector<int> a);
	int CheckingWin();
	bool CanMove();
	Vector2 GetCenter();
};

