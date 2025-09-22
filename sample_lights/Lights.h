#pragma once
#include "tbitfield.h"

class BitLight
{
protected:
	TBitField BitField;
	string name;
public:
	BitLight();
	virtual void switch_light() = 0;
	virtual TBitField get_BitField() const;
	virtual void set_counter(uint8_t state);
	virtual void print_lights(ostream& out) const;

	virtual void switch_red();
	virtual void switch_green();

	virtual bool is_red();
	virtual bool is_yellow();
	virtual bool is_green();
};

class Bit_Car_Light : public BitLight
{
public:
	Bit_Car_Light(uint8_t state);
	void switch_light();
	void switch_yellow();
};

class Bit_Human_Light : public BitLight
{
public:
	Bit_Human_Light(uint8_t state);
	void switch_light();
};