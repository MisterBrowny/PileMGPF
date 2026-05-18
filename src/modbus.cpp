#include "includes.h"

#include <ModbusRTUSlave.h>
#include <SoftwareSerial.h>



#define RS485_RX_PIN      7         // D7 RX_5V → RXD du MAX485
#define RS485_TX_PIN      6         // D6 TX_5V → TXD du MAX485

#define BAUDRATE          9600


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

// void modbus_app_test(void)
// {
//     if (TempsSup(modbus_test_time,MODBUS_REFRESH_TIME))
//     {
//         modbus_test_time = millis();
//         SERIAL_DEBUG(Modbus.holdingRegisters[0]);
//         SERIAL_DEBUG(Modbus.holdingRegisters[1]);
//         SERIAL_DEBUG(Modbus.holdingRegisters[2]);
//         SERIAL_DEBUG(Modbus.holdingRegisters[3]);
//         SERIAL_DEBUG(Modbus.holdingRegisters[4]);
//         // global_state ++;
//         // if (global_state > MODBUS_STATE_PROG)
//         // {
//         //     global_state = MODBUS_STATE_END;
//         // }
//         // test_analog_cnt ++;
//         // if (test_analog_cnt >= MODBUS_ANALOG_NB_VALUE)
//         // {
//         //     test_analog_cnt = 0;
//         // }
//         // Modbus.state.analog[0] = test_analog[test_analog_cnt];
//         // Modbus.state.analog[1] = test_analog[test_analog_cnt];
//         // holdingRegisters[0] = global_state;
//         // holdingRegisters[1] = Modbus.state.analog[0];
//         // holdingRegisters[2] = Modbus.state.analog[1];
//         // holdingRegisters[3] ++;
//         // holdingRegisters[4] ++;
//         // holdingRegisters[5] ++;
//         // holdingRegisters[6] ++;
//         // holdingRegisters[7] ++;
//         // holdingRegisters[8] ++;
//         // holdingRegisters[9] ++;
//         // holdingRegisters[10] ++;
//         // holdingRegisters[11] ++;
//     }   
// }

void modbus_refresh (void) 
{
    //modbus_app_test();
    modbus.poll();   // ← indispensable, traite toutes les demandes du maître
}
