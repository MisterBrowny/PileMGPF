#include "includes.h"

struBattery Battery;

uint32_t moy_analog (uint8_t pin, uint32_t nb_mesure)
{
	uint32_t temp = 0;
	uint32_t i = 0;

	for (i = 0; i < nb_mesure; i ++)
	{	
		temp += analogRead(pin);
	}

	temp = (uint32_t) ((float) temp / (float) nb_mesure);
	
	return temp;
}

void battery_refresh (void)
{
    bool        error_batt = false;
	uint32_t 	temp = 0;
	char 		string_test[25];

    temp = moy_analog(ANALOG_MB_1_2, DefNbMesureBat);
    Modbus.state.battery_cell[0] = (uint16_t) (temp * CONVERSION_BATT * 1000);
    sprintf(string_test, "ANALOG_MB_1_2 =%d", Modbus.state.battery_cell[0]);
	SERIAL_DEBUG(string_test);

    sprintf(string_test, "temp =%u", temp);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_3, DefNbMesureBat);
    Modbus.state.battery_cell[1] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_3 =%d", Modbus.state.battery_cell[1]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_4, DefNbMesureBat);
    Modbus.state.battery_cell[2] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[1];
    sprintf(string_test, "ANALOG_MB_4 =%d", Modbus.state.battery_cell[2]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_5_6, DefNbMesureBat);
    Modbus.state.battery_cell[3] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[2];
    sprintf(string_test, "ANALOG_MB_5_6 =%d", Modbus.state.battery_cell[3]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_7, DefNbMesureBat);
    Modbus.state.battery_cell[4] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[3];
    sprintf(string_test, "ANALOG_MB_7 =%d", Modbus.state.battery_cell[4]);
	SERIAL_DEBUG(string_test);
    
    temp = moy_analog(ANALOG_MB_8, DefNbMesureBat);
    Modbus.state.battery_cell[5] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[4];
    sprintf(string_test, "ANALOG_MB_8 =%d", Modbus.state.battery_cell[5]);
	SERIAL_DEBUG(string_test);    
    
    temp = moy_analog(ANALOG_MB_9, DefNbMesureBat);
    Modbus.state.battery_cell[6] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[5];
    sprintf(string_test, "ANALOG_MB_9 =%d", Modbus.state.battery_cell[6]);
	SERIAL_DEBUG(string_test);    
    
    temp = moy_analog(ANALOG_MB_10, DefNbMesureBat);
    Modbus.state.battery_voltage = (uint16_t) (temp * CONVERSION_BATT * 1000);
    Modbus.state.battery_cell[7] = Modbus.state.battery_voltage - Modbus.state.battery_cell[6];
    sprintf(string_test, "ANALOG_MB_10 =%d", Modbus.state.battery_cell[7]);
	SERIAL_DEBUG(string_test); 

    sprintf(string_test, "battery_voltage =%d", Modbus.state.battery_voltage);
	SERIAL_DEBUG(string_test);
}