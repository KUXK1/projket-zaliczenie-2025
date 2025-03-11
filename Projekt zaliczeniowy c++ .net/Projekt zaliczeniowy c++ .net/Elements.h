#pragma once
using namespace System;


ref class Elements
{
public:
	String^ id_num;	
	String^ Producent;
	String^ Mount_type;
	int Quantity;
	virtual array<String^>^ ToStringArray();
};

ref class Resistor : public Elements
{
public:
	float Resistance;
	float Power_Rating;
	Resistor(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_res, float arg_power);
	virtual array<String^>^ ToStringArray() override;
};

ref class Capacitor : public Elements
{
public:
	float Capacitance;
	float Voltage;
	Capacitor(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_cap, float arg_volt);
	array<String^>^ ToStringArray() override;
};

ref class Crystal_Oscillator : public Elements
{
public:
	float Frequency;
	Crystal_Oscillator(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_freq);
	array<String^>^ ToStringArray() override;
};

ref class Inductor : public Elements {
public:
	float Inductance;
	float Resistance;
	Inductor(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_ind, float arg_res);
	array<String^>^ ToStringArray() override;
};

ref class Microcontroller : public Elements
{
public:
	int Memory_RAM;
	int Memort_Flash;
	float Supply;
	Microcontroller(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, int arg_ram, int arg_flash, float arg_sup);
	array<String^>^ ToStringArray() override;
};

ref class Diode : public Elements
{
public:
	float Voltage;
	float Current;
	Diode(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_volt, float arg_cur);
	array<String^>^ ToStringArray() override;
};

