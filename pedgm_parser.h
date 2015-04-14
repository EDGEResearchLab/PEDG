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
        TinyGPSCustom m_messageId; (m_tinyGps, "PEDGM", 1);
        TinyGPSCustom m_date; (m_tinyGps, "PEDGM", 2);
        TinyGPSCustom m_time; (m_tinyGps, "PEDGM", 3);
        TinyGPSCustom m_latitude; (m_tinyGps, "PEDGM", 4);
        TinyGPSCustom m_longitude; (m_tinyGps, "PEDGM", 5);
        TinyGPSCustom m_altitude; (m_tinyGps, "PEDGM", 6);
        TinyGPSCustom m_speed; (m_tinyGps, "PEDGM", 7);
        TinyGPSCustom m_course; (m_tinyGps, "PEDGM", 8);
        TinyGPSCustom m_message; (m_tinyGps, "PEDGM", 9);
};

#endif //_PEDGM_PARSER_H_

        
};

#endif //_PEDGM_PARSER_H_
