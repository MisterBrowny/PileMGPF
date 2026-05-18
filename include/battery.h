#ifndef BATTERY_H
#define	BATTERY_H

#define BATTERY_REFRESH_TIME    TDef1sec   

typedef struct StructBattery {
	unsigned long		Time;
}struBattery;

extern struBattery Battery;

void battery_refresh (void);

#endif	/* BATTERY_H */