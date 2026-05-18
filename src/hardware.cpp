#include "includes.h"



void hw_config (void)
{
	// Liaison série debug/download
	Serial.begin(115200);

	SERIAL_DEBUG("Hardware config begins");

	// SORTIES
	// pilote LED_SPARE
	pinMode(LED_SPARE, OUTPUT);
	digitalWrite(LED_SPARE, HIGH);

	// ENTREES ANALOG
	pinMode(ANALOG_MB_1_2, INPUT); 	// A7
	pinMode(ANALOG_MB_3, INPUT); 	// A6
	pinMode(ANALOG_MB_4, INPUT); 	// A5
	pinMode(ANALOG_MB_5_6, INPUT); 	// A4
	pinMode(ANALOG_MB_7, INPUT); 	// A3
	pinMode(ANALOG_MB_8, INPUT); 	// A2
	pinMode(ANALOG_MB_9, INPUT); 	// A1
	pinMode(ANALOG_MB_10, INPUT); 	// A0
	
	SERIAL_DEBUG("Hardware config ends");
}
