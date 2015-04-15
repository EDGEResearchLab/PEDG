#ifndef _PEDGM_DEFINITION_H_
#define _PEDGM_DEFINITION_H_

#include <Arduino.h>

// Marker interface for anything that claims to deal with PEDGM sentences.
class PEDGMDefinition {
    public:
        static constexpr const char* SENTENCE_ID = "PEDGM";

        virtual String messageId() = 0;
        virtual unsigned long date() = 0;
        virtual unsigned long time() = 0;
        virtual double latitude() = 0;
        virtual double longitude() = 0;
        virtual double altitude() = 0;
        virtual double speed() = 0;
        virtual double course() = 0;
        virtual String message() = 0;
};

#endif //_PEDGM_DEFINITION_H_
