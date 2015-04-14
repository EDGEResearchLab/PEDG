## PEDG

This repo houses the edge arduino libraries for our proprietary NMEA-Compatible sentences.

Many of these sentence definitions are in process of being finalized.

## PEDGE: Telemetry and sensor data

Format:

* `$PEDGE`: Sentence Identifier
* `ID<BalloonId>`: Beacon/Balloon/Unit Identifier
* `<GPSDate>`: GPS Date DDMMYY
* `<GPSTime>`: GPS Time HHMMSSCC
* `<GPSLat>`: Decimal Degrees
* `<GPSLon>`: Decimal Degrees
* `<GPSAlt>`: Meters
* `<GPSSpd>`: Knots
* `<GPSCourse>`: Degrees
* `<GPSNumSats>`: Number of total satellites connected
* `<GPSValid>`: Our marker that the reading was valid
* `<GPSHDOP>`: Dilusion of precision
* `<A1>`: Sensor data 1 - Rail
* `<A2>`: Sensor data 2 - Temperature (C)
* `<A3>`: Sensor data 3 - Pressure (kPh)
* `<A4>`: Sensor data 4 - Humidity
* `<A5>`: Sensor data 5 - Battery
* `*<CKSUM>`: NMEA Checksum

## PEDGM: Broadcast message

## PEDGD

## PEDGC

## PEDGA

## Installation

* Either download the `.zip` (right side of the page) or clone this repo
* In Arduino:
    1. Sketch > Include Library > Add .ZIP Library (note: Select this no matter which way you downloaded the lib)
    2. Navigate to either the .ZIP or the top level directory, select it and select `Choose`.
    3. Now simply `#include <edge.h>` (or a specific header you need)

## Examples

It's generally best to only include what libraries you need, but if you need to use all the EDGE PEDG\* items, we provided a header of headers file: `edge.h`.

```
// Note that we depend on TinyGPS++, so you will need to also include it
#include <TinyGPS++.h>
#include <edge.h>

// The BEACONNet Node must have a node id, easier to set this to
// a constant than to need to remember the magic number 11.
const int BALLOON_ID = 11;

// Define whatever piece you want to use, in this case the Encoder (air side) for PEDGE sentences
PEDGEEncoder encoder;

void setup() {
    // We have attached a GPS unit to our Serial1 Rx Port (Pin 19 on the Due)
    // As a result, it needs to be configured for the anticipated Baud rate
    Serial1.begin(9600);

    // Since in our example we will want to see the data, also initialize the
    // PC connection serial line.
    Serial.begin(9600);

    // Finally, we need to initialize the encoder to give it the information needed
    // specifically, which serial it should listen on, and which pins our analog sensors
    // are attached to (if you don't have the sensors, you can put in the same values or all 0's -
    // you will just see junk data for those values)
    // If you are unfamiliar with the `&Serial1` syntax, it is simply passing the memory
    // location of the serial port object to read from, rather than making a copy.
    encoder.init(BALLOON_ID, &Serial1, A7, A8, A9, A10, A11);
}

// As a simple example, we will simply read GPS data for ~5seconds
// and then publish it to the computer via the programming port
void loop() {
    unsigned long start = millis();
    while ((millis() - start) < 5000) {
        // Calling .tick() is very important, this will tell the
        // encoder to read a byte from the serial port and hold onto
        // it, building the GPS location information on each call.
        // Calling it for at least a second continuously should be
        // enough for a full data set.
        encoder.tick();
    }

    // Print the result to the computer port, check it out in your serial
    // monitor!
    Serial.println(encoder.encode());
}
```
