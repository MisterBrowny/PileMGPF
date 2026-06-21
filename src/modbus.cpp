#include "includes.h"

#include <ModbusRTUSlave.h>
#include <SoftwareSerial.h>

#define DEF_TEST_MODBUS     0

#if DEF_TEST_MODBUS
    #define MODBUS_REFRESH_TIME       2000 // ms
    static uint64_t     modbus_test_time;
    static struStatut   modbus_test;

#endif

#define RS485_RX_PIN        7         // D7 RX_5V → RXD du MAX485
#define RS485_TX_PIN        6         // D6 TX_5V → TXD du MAX485

#define BAUDRATE            9600


struModbus Modbus;


// Création d'un port soft série
SoftwareSerial mySerial(RS485_RX_PIN, RS485_TX_PIN);

// Création de l'objet Modbus
ModbusRTUSlave modbus(mySerial);

void modbus_init (void) 
{
    SERIAL_DEBUG("Start Modbus RTU Slave ID = " + String(SLAVE_ID));

    // Configuration UART2 pour RS485
    mySerial.begin(BAUDRATE);

    // Initialisation Modbus
    modbus.begin(SLAVE_ID, BAUDRATE, SERIAL_8N1);
    modbus.configureHoldingRegisters(Modbus.holdingRegisters, DEF_HOLD_REG); 

    Serial.println("Modbus Slave ready !");
}

#if DEF_TEST_MODBUS
    void modbus_app_test(void)
    {
        if (TempsSup(modbus_test_time,MODBUS_REFRESH_TIME))
        {
            modbus_test_time = millis();

            modbus_test.global_state ++;
            if (modbus_test.global_state > GLOBAL_STATE_BATTERY_OK)
            {
                modbus_test.global_state = GLOBAL_STATE_BATTERY_VOLTAGE_UNDER_30_V;
            }
            modbus_test.battery_voltage += 1024;
            if (modbus_test.battery_voltage > 42000)    { modbus_test.battery_voltage = 0; }
            for(int i = 0; i < 8; i ++)
            {
                modbus_test.battery_cell[i] += 50 + i * 10;
                if (modbus_test.battery_cell[i] > 4500)    { modbus_test.battery_cell[i] = 2000; }
            }        
        }
        memcpy(&Modbus, &modbus_test, sizeof(struModbus));
    }
#endif

void modbus_refresh (void) 
{
    #if DEF_TEST_MODBUS
        modbus_app_test();
    #endif
    modbus.poll();   // ← indispensable, traite toutes les demandes du maître
}
