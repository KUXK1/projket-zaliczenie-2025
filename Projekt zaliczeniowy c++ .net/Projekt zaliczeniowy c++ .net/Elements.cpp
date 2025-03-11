#include "Elements.h"

Resistor::Resistor(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_res, float arg_power) {
	id_num = arg_id_num;
	Producent = arg_producent;
	Mount_type = arg_Mount;
	Quantity = arg_quant;
	Resistance = arg_res;
	Power_Rating = arg_power;
}

Capacitor::Capacitor(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_cap, float arg_volt) {
	id_num = arg_id_num;
	Producent = arg_producent;
	Mount_type = arg_Mount;
	Quantity = arg_quant;
	Capacitance = arg_cap;
	Voltage = arg_volt;
}

Crystal_Oscillator::Crystal_Oscillator(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_freq) {
	id_num = arg_id_num;
	Producent = arg_producent;
	Mount_type = arg_Mount;
	Quantity = arg_quant;
	Frequency = arg_freq;
};

Microcontroller::Microcontroller(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, int arg_ram, int arg_flash, float arg_sup){
	id_num = arg_id_num;
	Producent = arg_producent;
	Mount_type = arg_Mount;
	Quantity = arg_quant;
	Memory_RAM = arg_ram;
	Memort_Flash = arg_flash;
	Supply = arg_sup;
}

Inductor::Inductor(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_ind, float arg_res){
	id_num = arg_id_num;
	Producent = arg_producent;
	Mount_type = arg_Mount;
	Quantity = arg_quant;
	Inductance = arg_ind;
	Resistance = arg_res;
}

Diode::Diode(String^ arg_id_num, String^ arg_producent, String^ arg_Mount, int arg_quant, float arg_volt, float arg_cur){
	id_num = arg_id_num;
	Producent = arg_producent;
	Mount_type = arg_Mount;
	Quantity = arg_quant;
	Voltage = arg_volt;
	Current = arg_cur;
}

array<String^>^ Elements::ToStringArray()
{
	return nullptr;
}

array<String^>^ Resistor::ToStringArray() {
	return gcnew array<String^> {
		"Resistor",
		id_num,
			Producent,
			Mount_type,
			Quantity.ToString(),
			Resistance.ToString() + " Ohm",
			Power_Rating.ToString() + " W"
	};
}

array<String^>^ Capacitor::ToStringArray() {
	return gcnew array<String^> {
		"Capacitor",
		id_num,
			Producent,
			Mount_type,
			Quantity.ToString(),
			Capacitance.ToString() + " F",
			Voltage.ToString() + " V"
	};
}

array<String^>^ Crystal_Oscillator::ToStringArray() {
	return gcnew array<String^> {
		"Crystal_Oscillator",
		id_num,
			Producent,
			Mount_type,
			Quantity.ToString(),
			Frequency.ToString() + " Hz"
	};
}

array<String^>^ Inductor::ToStringArray() {
	return gcnew array<String^> {
		"Inductor",
		id_num,
			Producent,
			Mount_type,
			Quantity.ToString(),
			Inductance.ToString() + " H",
			Resistance.ToString() + " Ohm"
	};
}

array<String^>^ Microcontroller::ToStringArray() {
	return gcnew array<String^> {
		"Microcontroller",
		id_num,
			Producent,
			Mount_type,
			Quantity.ToString(),
			Memory_RAM.ToString() + " KB",
			Memort_Flash.ToString() + " KB",
			Supply.ToString() + " V"
	};
}

array<String^>^ Diode::ToStringArray() {
	return gcnew array<String^> {
		"Diode",
		id_num,
			Producent,
			Mount_type,
			Quantity.ToString(),
			Voltage.ToString() + " V",
			Current.ToString() + " A"
	};
}
