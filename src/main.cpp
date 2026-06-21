#include "includes.h"

const uint8_t SLAVE_ID = 220;       // ← CHANGE CE NUMÉRO pour chaque NANO (200 à 220)

void setup() {
  
  // Init les entrées / sorties
	hw_config();

  // Init pixel
  pixel_init();

  // Init modbus
  modbus_init();
}

void loop() {
  modbus_refresh();
  if (TempsSup(Battery.Time, BATTERY_REFRESH_TIME))
  {
    Battery.Time = millis();
    battery_refresh();
  }
  
}

