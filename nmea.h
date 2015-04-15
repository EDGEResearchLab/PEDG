#ifndef _NMEA_H_
#define _NMEA_H_

#include <Arduino.h>
#include <TinyGPS++.h>

class NMEA {
    public:
        const char* SENTENCE_ID;

        NMEA(const char* sentenceId, Stream& stream);

        virtual void tick();
        boolean isValid();

    protected:
        // Internally we use the TinyGPSPlus library to do
        // our NMEA Parsing.
        TinyGPSPlus m_tinyGps;

        // Generate a checksum per the NMEA specification.
        // Note that the sentence parameter should omit the
        // leading '$' and trailing '*xx'.
        int generateChecksum(const String* sentence);

    private:
        // We can read NMEA data off any valid object implementing
        // the Stream interface, not just Serial.
        Stream& m_stream;
};

#endif
