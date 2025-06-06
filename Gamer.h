#pragma once

enum GamerStatus {
	Computer = 0,
	Player,
	Player1,
	Player2

};

class Gamer
{
	GamerStatus status;
	int mark;

public:
	Gamer() {}
	~Gamer() {}

	void SetField(GamerStatus mode, int m);
	int getMark() { return this->mark; }
	GamerStatus getStatus() { return this->status; }
};

