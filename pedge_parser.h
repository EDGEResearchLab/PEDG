#ifndef _PEDGE_PARSER_H_
#define _PEDGE_PARSER_H_

#include "nmea.h"
#include "pedge_definition.h"

class PEDGEParser: public NMEA, public PEDGEDefinition {
    public:
        PEDGEParser(Stream& stream);

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
        TinyGPSCustom m_balloonId;
        TinyGPSCustom m_date;
        TinyGPSCustom m_time;
        TinyGPSCustom m_latitude;
        TinyGPSCustom m_longitude;
        TinyGPSCustom m_altitude;
        TinyGPSCustom m_speed;
        TinyGPSCustom m_course;
        TinyGPSCustom m_satellites;
        TinyGPSCustom m_isValid;
        TinyGPSCustom m_hdop;
        TinyGPSCustom m_rail;
        TinyGPSCustom m_temperature;
        TinyGPSCustom m_pressure;
        TinyGPSCustom m_humidity;
        TinyGPSCustom m_battery;
        TinyGPSCustom m_cpm;
};

#endif //_PEDGE_PARSER_H_
