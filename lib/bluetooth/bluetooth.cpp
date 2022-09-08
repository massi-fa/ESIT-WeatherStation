#include "bluetooth.h"

BluetoothSerial SerialBT;

namespace bluetooh{
    void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
        if(event == ESP_SPP_SRV_OPEN_EVT){
        Serial.println("Client Connected");
        }
        if(event == ESP_SPP_CLOSE_EVT ){
        Serial.println("Client disconnected");
        }
    }
    void setup(){
        SerialBT.register_callback(callback);
        if(!SerialBT.begin("ESP32-SENSOR")){
            Serial.println("An error occurred initializing Bluetooth");
        }else{
            Serial.println("Bluetooth initialized");
        }
    }
}
