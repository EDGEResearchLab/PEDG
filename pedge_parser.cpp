#include "pedge_parser.h"

PEDGEParser::PEDGEParser(Stream& stream):
    NMEA(PEDGEDefinition::SENTENCE_ID, stream),
    m_balloonId(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 1),
    m_date(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 2),
    m_time(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 3),
    m_latitude(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 4),
    m_longitude(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 5),
    m_altitude(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 6),
    m_speed(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 7),
    m_course(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 8),
    m_satellites(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 9),
    m_isValid(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 10),
    m_hdop(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 11),
    m_rail(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 12),
    m_temperature(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 13),
    m_pressure(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 14),
    m_humidity(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 15),
    m_battery(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 16),
    m_cpm(m_tinyGps, PEDGEDefinition::SENTENCE_ID, 17) {
        /* Ignored */
    };

int PEDGEParser::balloonId() {
    return String(m_balloonId.value()).toInt();
};

unsigned long PEDGEParser::date() {
    return (unsigned long)(String(m_date.value()).toFloat());
};

unsigned long PEDGEParser::time() {
    return (unsigned long)(String(m_time.value()).toFloat());
};

double PEDGEParser::latitude() {
    return abs(String(m_latitude.value()).toFloat());
};

double PEDGEParser::longitude() {
    return abs(String(m_longitude.value()).toFloat());
};

double PEDGEParser::altitude() {
    return String(m_altitude.value()).toFloat();
};

double PEDGEParser::speed() {
    return String(m_speed.value()).toFloat();
};

double PEDGEParser::course() {
    return String(m_course.value()).toFloat();
};

int PEDGEParser::satellites() {
    return String(m_satellites.value()).toInt();
};

int PEDGEParser::isValid() {
    return String(m_isValid.value()).toInt();
};

double PEDGEParser::hdop() {
    return String(m_hdop.value()).toFloat();
};

int PEDGEParser::rail() {
    return String(m_rail.value()).toInt();
};

int PEDGEParser::temperature() {
    return String(m_temperature.value()).toInt();
};

int PEDGEParser::pressure() {
    return String(m_pressure.value()).toInt();
};

int PEDGEParser::humidity() {
    return String(m_humidity.value()).toInt();
};

int PEDGEParser::battery() {
    return String(m_battery.value()).toInt();
};

int PEDGEParser::cpm() {
    return String(m_cpm.value()).toInt();
};
