#include "pedgm_parser.h"

PEDGMParser::PEDGMParser(Stream& stream):
    NMEA("PEDGM", stream),
    m_messageId(m_tinyGps, SENTENCE_ID, 1),
    m_date(m_tinyGps, SENTENCE_ID, 2),
    m_time(m_tinyGps, SENTENCE_ID, 3),
    m_latitude(m_tinyGps, SENTENCE_ID, 4),
    m_longitude(m_tinyGps, SENTENCE_ID, 5),
    m_altitude(m_tinyGps, SENTENCE_ID, 6),
    m_speed(m_tinyGps, SENTENCE_ID, 7),
    m_course(m_tinyGps, SENTENCE_ID, 8),
    m_message(m_tinyGps, SENTENCE_ID, 9) {

}

String PEDGMParser::messageId() {
    return m_messageId.value();
};

unsigned long PEDGMParser::date() {
    return (unsigned long)(String(m_date.value()).toFloat());
};

unsigned long PEDGMParser::time() {
    return (unsigned long)(String(m_time.value()).toFloat());
};

double PEDGMParser::latitude() {
    return abs(String(m_latitude.value()).toFloat());
};

double PEDGMParser::longitude() {
    return abs(String(m_longitude.value()).toFloat());
};

double PEDGMParser::altitude() {
    return String(m_altitude.value()).toFloat();
};

double PEDGMParser::speed() {
    return String(m_speed.value()).toFloat();
};

double PEDGMParser::course() {
    return String(m_course.value()).toFloat();
};

String PEDGMParser::message() {
    return String(m_message.value());
};
