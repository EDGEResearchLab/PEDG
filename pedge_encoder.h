#ifndef _PEDGE_ENCODER_H_
#define _PEDGE_ENCODER_H_

#include "nmea.h"
#include "pedge_definition.h"

// Handle reading serial data and encoding the readings to a valid
// $PEDGE Sentence.
class PEDGEEncoder: public PEDGEDefinition, private NMEA {
    public:
        /**
         * @param balloonId: Unique ID for the node
         * @param stream: Stream interface to read GPS data from.
         *
         * This CTOR assumes EDGE default port assignments for BEACONNet,
         * if you don't have the analog pins attached - just ignore the
         * output of the parser library.
         */
    	PEDGEEncoder(int balloonId, Stream& stream);
        /**
         * @param stream: Stream interface to read GPS data from
         * @param railPin: Pin to read the Rail Voltage from
         * @param tempPin: Pin to read the temperature from
         * @param pressurePin: Pin the pressure sensor is attached to
         * @param humidityPin: Pin to read the humidity sensor
         * @param batteryPin: Pin to read the battery info from
         */
        PEDGEEncoder(int balloonId, Stream& stream, int railPin, int tempPin, int pressurePin, int humidityPin, int batteryPin);

        /**
         * Method to kick off a read cycle, this will check if the
         * stream is available and read a byte, handling appropriately.
         * This should be called with some regularity to get up-to-date data.
         */
    	void tick();
    	String encode();
        int balloonId();
        unsigned long date();
        unsigned long time();
        double latitude();
        double longitude();
        double altitude();
        double speed();
        double course();
        int satellites();
        int isValid();
        double hdop();
        int rail();
        int temperature();
        int pressure();
        int humidity();
        int battery();
        int cpm();

    private:
        // Ballon Identifier, this should be unique per balloon.
        int m_balloonId;
        // Analog Pin Assignments
        int m_railPin;
        int m_tempPin;
        int m_pressurePin;
        int m_humidityPin;
        int m_batteryPin;
};

#endif //_PEDGE_ENCODER_H_
