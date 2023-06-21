/*        ***********L2-Activities**********
1. Data Parser:
   A data logger transmits the data in ascii format as shown below
   "S1-T:36.5-H:100-L:50"
   Write a function to populate all the data in an array of structure. The output should be like
   Sensor Info:
   ---------------------
   Sensor ID: S1
   Temperature: 36.5 C
   Humidity: 100
   Light Intensity: 50%
   ---------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_DATA_SIZE 100

struct SensorInfo {
    char sensorId[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseSensorData(const char *data, struct SensorInfo *sensorArray) {
    char sensorId[10];
    float temperature;
    int humidity;
    int lightIntensity;

    sscanf(data, "S%[^-]-T:%f-H:%d-L:%d", sensorId, &temperature, &humidity, &lightIntensity);

    strcpy(sensorArray->sensorId, sensorId);
    sensorArray->temperature = temperature;
    sensorArray->humidity = humidity;
    sensorArray->lightIntensity = lightIntensity;
}

int main() {
    char data[MAX_DATA_SIZE] = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensorArray;

    parseSensorData(data, &sensorArray);

    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensorArray.sensorId);
    printf("Temperature: %.1f C\n", sensorArray.temperature);
    printf("Humidity: %d\n", sensorArray.humidity);
    printf("Light Intensity: %d%%\n", sensorArray.lightIntensity);
    printf("---------------------\n");

    return 0;
}