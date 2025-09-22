#include "BitRoad.h"

BitRoad::BitRoad()
{
	car_light = new Bit_Car_Light(2);
	human_light = new Bit_Human_Light(0);
}

void BitRoad::switch_all()
{
	if (!(car_light->get_BitField().GetBit(1)))
		human_light->switch_light();
	car_light->switch_light();
}

void BitRoad::print_all(ostream& out)
{
	out << endl;
	car_light->print_lights(out);
	human_light->print_lights(out);
}

void BitRoad::reset()
{
	car_light->set_counter(1 << 2);
	human_light->set_counter(1 << 0);
}