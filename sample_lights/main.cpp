#include "BitRoad.h"

int main()
{
	BitRoad r = BitRoad();
	for (int i = 0; i < 6; i++)
	{
		r.switch_all(); r.print_all(cout);
	}
	return 0;
}