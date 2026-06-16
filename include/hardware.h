#ifndef HARDWARE_H
#define	HARDWARE_H

// /!\ SLAVE_ID est à modifier par ESP32 dans PyronuMGPF.cpp 

extern const uint8_t SLAVE_ID;

// ENTREES ANALOG
#define ANALOG_MB_10        A0          // Lecture tension Battery 10       [min 30V, max 40V]
#define ANALOG_MB_9         A1          // Lecture tension Battery 9        [min 27V, max 36V]
#define ANALOG_MB_8         A2          // Lecture tension Battery 8        [min 24V, max 32V]
#define ANALOG_MB_7         A3          // Lecture tension Battery 7        [min 21V, max 28V]
#define ANALOG_MB_5_6       A4          // Lecture tension Battery 5&6      [min 18V, max 24V]
#define ANALOG_MB_4         A5          // Lecture tension Battery 4        [min 12V, max 16V]
#define ANALOG_MB_3         A6          // Lecture tension Battery 3        [min 9V, max 12V]
#define ANALOG_MB_1_2       A7          // Lecture tension Battery 1&2      [min 6V, max 8V]     

// SORTIES
#define LED_RGB             2           // NumPin WS2812B
#define LED_SPARE           12          // NumPin LED_SPARE D2


// ANALOG
#define CONVERSION_ADC	    (float) (5.0f / 1023.0f)		// 5 / 1023

// Valeur pour récupérer la tension batterie
#define PONT_DIVISEUR	    (float) (22000.0f / (22000.0f + 18000.0f + 150000.0f))

#define CONVERSION_BATT     (float) (CONVERSION_ADC / PONT_DIVISEUR)

#define DefNbMesureBat      1

void hw_config(void);

#endif	/* HARDWARE_H */

