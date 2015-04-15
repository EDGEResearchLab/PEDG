#ifndef _PEDGM_PARSER_H_
#define _PEDGM_PARSER_H_

#include "nmea.h"
#include "pedgm_definition.h"

class PEDGMParser: public NMEA, public PEDGMDefinition {
    public:
        PEDGMParser(Stream& stream);
        
        String messageId();
        unsigned long date();
        unsigned long time();
        double latitude();
        double longitude();
        double altitude();
        double speed();
        double course();
        String message();

    private:
        TinyGPSCustom m_messageId;
        TinyGPSCustom m_date;
        TinyGPSCustom m_time;
        TinyGPSCustom m_latitude;
        TinyGPSCustom m_longitude;
        TinyGPSCustom m_altitude;
        TinyGPSCustom m_speed;
        TinyGPSCustom m_course;
        TinyGPSCustom m_message;
};

#endif //_PEDGM_PARSER_H_
