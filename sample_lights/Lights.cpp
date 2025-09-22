#include "Lights.h"

BitLight::BitLight() : BitField(0)
{
	BitField = TBitField(3);
	name = "";
}

TBitField BitLight::get_BitField() const { return BitField; }
void BitLight::set_counter(uint8_t state) 
{ 
	for (size_t i = 0; i < 3; i++) { BitField.ClrBit(i); }
	BitField.SetBit(state);
}
void BitLight::print_lights(ostream& out) const
{
	out << name << " lights: "; bool flag = false;
	if (BitField.GetBit(0)) { out << "Red"; flag = true; }
	if (BitField.GetBit(1))
	{
		if (flag) out << ", ";
		out << "Yellow"; flag = true;
	}
	if (BitField.GetBit(2))
	{
		if (flag) out << ", ";
		out << "Green";
	}
	out << endl;
}

void BitLight::switch_red() 
{ 
	if (BitField.GetBit(0)) 
	{ BitField.ClrBit(0); } 
	else { BitField.SetBit(0); }
}
void BitLight::switch_green()
{
	if (BitField.GetBit(2))
	{ BitField.ClrBit(2); }
	else { BitField.SetBit(2); }
}

bool BitLight::is_red() { return BitField.GetBit(0); }
bool BitLight::is_yellow() { return BitField.GetBit(1); }
bool BitLight::is_green() { return BitField.GetBit(2); }

// не является нестатическим элементом данных или базовым классом для класса

Bit_Car_Light::Bit_Car_Light(uint8_t state) 
{ 
	name = "Car_Light"; 
	BitField.SetBit(state);
}

void Bit_Car_Light::switch_light()
{
	if (this->is_red()) { BitField.ClrBit(0); BitField.SetBit(1); return; }
	if (this->is_yellow()) { BitField.ClrBit(1); BitField.SetBit(2); return; }
	BitField.ClrBit(2); BitField.SetBit(0);
}

void Bit_Car_Light::switch_yellow()
{
	if (BitField.GetBit(1))
	{ BitField.ClrBit(1); }
	else { BitField.SetBit(1); }
}

Bit_Human_Light::Bit_Human_Light(uint8_t state)
{ 
	name = "Human_Light";
	BitField.SetBit(state);
}

void Bit_Human_Light::switch_light()
{
	BitField = ~BitField;
	BitField.ClrBit(1);
}