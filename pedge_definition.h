#ifndef _PEDGE_DEFINITION_H_
#define _PEDGE_DEFINITION_H_

// Marker interface for anything that claims to deal with PEDGE sentences.
class PEDGEDefinition {
    public:
        virtual int balloonId() = 0;
        virtual unsigned long date() = 0;
        virtual unsigned long time() = 0;
        virtual double latitude() = 0;
        virtual double longitude() = 0;
        virtual double altitude() = 0;
        virtual double speed() = 0;
        virtual double course() = 0;
        virtual int satellites() = 0;
        virtual int isValid() = 0;
        virtual double hdop() = 0;
        virtual int rail() = 0;
        virtual int temperature() = 0;
        virtual int pressure() = 0;
        virtual int humidity() = 0;
        virtual int battery() = 0;
        virtual int cpm() = 0;
};

#endif //_PEDGE_DEFINITION_H_
