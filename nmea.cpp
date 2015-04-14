#include "nmea.h"

NMEA::NMEA(String sentenceId):
    SENTENCE_ID(sentenceId),
    m_stream(NULL),
    m_tinyGps() {

};

void NMEA::init(Stream* stream) {
    m_stream = stream;
};

void NMEA::tick() {
    if (m_stream->available()) {
        m_tinyGps.encode(m_stream->read());
    }
};

boolean NMEA::isValid() {
    return m_tinyGps.location.isValid();
};

int NMEA::generateChecksum(const String* sentence) {
    int chk = 0;
    for (int i = 0, len = (*sentence).length(); i < len; i++) {
        chk ^= (unsigned char)(*sentence)[i];
    }
    return chk;
};
