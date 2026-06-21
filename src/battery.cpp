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
    sprintf(string_test, "ANALOG_MB_1_2 =%u", Modbus.state.battery_cell[0]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_3, DefNbMesureBat);
    Modbus.state.battery_cell[1] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_3 =%u", Modbus.state.battery_cell[1]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_4, DefNbMesureBat);
    Modbus.state.battery_cell[2] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[1] - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_4 =%u", Modbus.state.battery_cell[2]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_5_6, DefNbMesureBat);
    Modbus.state.battery_cell[3] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[2] - Modbus.state.battery_cell[1] - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_5_6 =%u", Modbus.state.battery_cell[3]);
	SERIAL_DEBUG(string_test);

    temp = moy_analog(ANALOG_MB_7, DefNbMesureBat);
    Modbus.state.battery_cell[4] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[3] - Modbus.state.battery_cell[2] - Modbus.state.battery_cell[1] - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_7 =%u", Modbus.state.battery_cell[4]);
	SERIAL_DEBUG(string_test);
    
    temp = moy_analog(ANALOG_MB_8, DefNbMesureBat);
    Modbus.state.battery_cell[5] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[4] - Modbus.state.battery_cell[3] - Modbus.state.battery_cell[2] - Modbus.state.battery_cell[1] - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_8 =%u", Modbus.state.battery_cell[5]);
	SERIAL_DEBUG(string_test);    
    
    temp = moy_analog(ANALOG_MB_9, DefNbMesureBat);
    Modbus.state.battery_cell[6] = (uint16_t) (temp * CONVERSION_BATT * 1000) - Modbus.state.battery_cell[5] - Modbus.state.battery_cell[4] - Modbus.state.battery_cell[3] - Modbus.state.battery_cell[2] - Modbus.state.battery_cell[1] - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_9 =%u", Modbus.state.battery_cell[6]);
	SERIAL_DEBUG(string_test);    
    
    temp = moy_analog(ANALOG_MB_10, DefNbMesureBat);
    Modbus.state.battery_voltage = (uint16_t) (temp * CONVERSION_BATT * 1000);
    Modbus.state.battery_cell[7] = Modbus.state.battery_voltage - Modbus.state.battery_cell[6] - Modbus.state.battery_cell[5] - Modbus.state.battery_cell[4] - Modbus.state.battery_cell[3] - Modbus.state.battery_cell[2] - Modbus.state.battery_cell[1] - Modbus.state.battery_cell[0];
    sprintf(string_test, "ANALOG_MB_10 =%u", Modbus.state.battery_cell[7]);
	SERIAL_DEBUG(string_test); 

    sprintf(string_test, "battery_voltage =%u", Modbus.state.battery_voltage);
	SERIAL_DEBUG(string_test);

    if (Modbus.state.battery_voltage <= 30000)
    {
        Modbus.state.global_state = GLOBAL_STATE_BATTERY_VOLTAGE_UNDER_30_V;
        pixel_set (PIXEL_NUM_STATE, DEF_COLOR_UNDER_30V_R, DEF_COLOR_UNDER_30V_G, DEF_COLOR_UNDER_30V_B);
    }
    else if (   (Modbus.state.battery_cell[0] <= 3000)
             || (Modbus.state.battery_cell[1] <= 3000)
             || (Modbus.state.battery_cell[2] <= 3000)
             || (Modbus.state.battery_cell[3] <= 3000)
             || (Modbus.state.battery_cell[4] <= 3000)
             || (Modbus.state.battery_cell[5] <= 3000)
             || (Modbus.state.battery_cell[6] <= 3000)
             || (Modbus.state.battery_cell[7] <= 3000))
    {
        Modbus.state.global_state = GLOBAL_STATE_BATTERY_CELL_UNDER_3_V;
        pixel_set (PIXEL_NUM_STATE, DEF_COLOR_UNDER_3V_R, DEF_COLOR_UNDER_3V_G, DEF_COLOR_UNDER_3V_B);
    }
    else
    {
        Modbus.state.global_state = GLOBAL_STATE_BATTERY_OK;
        pixel_set (PIXEL_NUM_STATE, DEF_COLOR_OK_R, DEF_COLOR_OK_G, DEF_COLOR_OK_B);
    }
}