#pragma once

#include <ArduinoJson.h>
#include <PZEM004Tv30.h>

const int pzemTxPin = 17;
const int pzemRxPin = 5;

JsonDocument getElectricalPower()
{
    JsonDocument doc;
    PZEM004Tv30 pzem(Serial2, pzemTxPin, pzemRxPin);

    doc["voltage"] = pzem.voltage();
    doc["current"] = pzem.current();
    doc["power"] = pzem.power();
    doc["energy"] = pzem.energy();
    doc["frequency"] = pzem.frequency();
    doc["pf"] = pzem.pf();

    return doc;
}

void resetEnergyConsumption()
{
    PZEM004Tv30 pzem(Serial2, pzemRxPin, pzemTxPin);
    pzem.resetEnergy();
}