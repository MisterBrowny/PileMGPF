#ifndef MODBUS_H
#define MODBUS_H

#define GLOBAL_STATE_BATTERY_VOLTAGE_UNDER_30_V		1
#define GLOBAL_STATE_BATTERY_CELL_UNDER_3_V			2
#define GLOBAL_STATE_BATTERY_OK						3

typedef struct StructStatut {
	uint16_t global_state;               // registre 0
	uint16_t battery_voltage;			 // register 1 : tension de la batterie en mV
	uint16_t battery_cell[8];            // register [2:10] : tension de chaque batterie cell en mV
}struStatut;

#define DEF_HOLD_REG    (sizeof(struStatut) / 2)

typedef struct StructModbus {
	union {
        struStatut  state;
        uint16_t    holdingRegisters[DEF_HOLD_REG];
    };
}struModbus;

extern struModbus Modbus;

void modbus_init (void);
void modbus_refresh (void);

#endif