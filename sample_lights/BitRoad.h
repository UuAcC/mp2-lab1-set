#pragma once
#include "Lights.h"

class BitRoad
{
	Bit_Car_Light* car_light;
	Bit_Human_Light* human_light;
public:
	BitRoad();
	void switch_all();
	void print_all(ostream& out);
	void reset();
};