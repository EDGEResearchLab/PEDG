#include <Arduino.h>

#include "pedge_encoder.h"

PEDGEEncoder::PEDGEEncoder():
    NMEA("PEDGE"),
    m_balloonId(),
    m_railPin(),
    m_tempPin(),
    m_pressurePin(),
    m_humidityPin(),
    m_batteryPin() {

}

void PEDGEEncoder::init(int balloonId, Stream* stream, int railPin, int tempPin, int pressurePin, int humidityPin, int batteryPin) {
    NMEA::init(stream);
    m_balloonId = balloonId;
    m_railPin = railPin;
    m_tempPin = tempPin;
    m_pressurePin = pressurePin;
    m_humidityPin = humidityPin;
    m_batteryPin = batteryPin;
};

/**
 * Perform a single character read if the stream is available.
 */
void PEDGEEncoder::tick() {
    NMEA::tick();
};

/**
 * Encode the read info into a $PEDGE string.
 */
String PEDGEEncoder::encode() {
    //Format: $PEDGE,ID<BalloonId>,<GPSDate>,<GPSTime>,<GPSLat>,<GPSLon>,<GPSAlt>,<GPSSpd>,<GPSCourse>,<GPSNumSats>,<Valid>,<GPSHDOP>,<A1>,<A2>,<A3>,<A4>,<A5>*<CKSUM>
    //  //Build the primary string out, omitting the '$' and '*' since they're not used for the checksum calcs
    String sentence = "PEDGE,ID" + String(balloonId()) + "," + String(date()) + "," + String(time()) + "," + String(latitude(), 6) + "," + String(longitude(), 6) + "," + String(altitude()) + "," + String(speed()) + "," + String(course()) + "," + String(satellites()) + "," + String(isValid()) + "," + String(hdop()) + "," + String(rail()) + "," + String(temperature()) + "," + String(pressure()) + "," + String(humidity()) + "," + String(battery()) + "," + String(cpm());
    return "$" + sentence + "*" + String(generateChecksum(&sentence), HEX);
};

int PEDGEEncoder::balloonId() {
    return m_balloonId; 
};

unsigned long PEDGEEncoder::date() {
    return m_tinyGps.date.value(); 
};

unsigned long PEDGEEncoder::time() {
    return m_tinyGps.time.value(); 
};

double PEDGEEncoder::latitude() {
    return m_tinyGps.location.lat(); 
};

double PEDGEEncoder::longitude() {
    return m_tinyGps.location.lng(); 
};

double PEDGEEncoder::altitude() {
    return m_tinyGps.altitude.meters(); 
};

double PEDGEEncoder::speed() {
    return m_tinyGps.speed.knots(); 
};

double PEDGEEncoder::course() {
    return m_tinyGps.course.deg(); 
};

int PEDGEEncoder::satellites() {
    return m_tinyGps.satellites.value(); 
};

int PEDGEEncoder::isValid() {
    return NMEA::isValid();
};

double PEDGEEncoder::hdop() {
    return m_tinyGps.hdop.value() / 100.0; 
};

int PEDGEEncoder::rail() {
    return analogRead(m_railPin); 
};

int PEDGEEncoder::temperature() {
    return analogRead(m_tempPin); 
};

int PEDGEEncoder::pressure() {
    return analogRead(m_pressurePin); 
};

int PEDGEEncoder::humidity() {
    return analogRead(m_humidityPin); 
};

int PEDGEEncoder::battery() {
    return analogRead(m_batteryPin); 
};

int PEDGEEncoder::cpm() {
    return 0; 
};
