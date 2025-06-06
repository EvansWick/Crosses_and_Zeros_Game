#include "Gamer.h"

void Gamer::SetField(GamerStatus mode, int m)
{
	if (mode == 0) status = Computer;
	else if (mode == 1) status = Player;
	else if (mode == 2) status = Player1;
	else status = Player2;

	mark = m;
}
