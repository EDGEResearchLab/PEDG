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

* `$PEDGM`: Sentence Identifier
* `M<Id>`: Node Identifier
* `<GPSDate>`: GPS Date DDMMYY
* `<GPSTime>`: GPS Time HHMMSSCC
* `<GPSLat>`: Decimal Degrees
* `<GPSLon>`: Decimal Degrees
* `<GPSAlt>`: Meters
* `<GPSSpd>`: Knots
* `<GPSCourse>`: Degrees
* `<Message>`: Custom message (max characters: TODO)
* `<Checksum>`: NMEA Checksum

## PEDGD: TODO

## PEDGC: TODO

## PEDGA: TODO

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

// Define whatever piece of the library you need, in our example we will be the encoder (Balloon Unit).
// Note that on construction, you need to tell the library which Serial it should be reading the GPS from.
// Here it is attached to Serial1, Port 19 for Rx.
// It is worth noting that there is an overloaded constructor for this as well, which allows initialization
// with analog pins to use for gathering sensor data.  That would look like this, assuming you set the
// sensor pins to constants:
//      PEDGEEncoder encoder(BALLOON_ID, Serial1, RAIL_PIN, TEMP_PIN, PRESSURE_PIN, HUMIDITY_PIN, BATTERY_PIN);
PEDGEEncoder encoder(BALLOON_ID, Serial1);

void setup() {
    // The library will not presume anything for your serial device, so the setup
    // still needs to initialize the port and set the baud (and any other params)
    Serial1.begin(9600);

    // Just reading the data is boring, you want to see your work be alive,
    // in this case we will just write it to the PC.
    Serial.begin(9600);
}

// As a simple example, we will simply read GPS data for ~5seconds and then publish the generated
// $PEDGE sentence to the computer via the programming port.
void loop() {
    unsigned long start = millis();
    // Read GPS data for ~5 seconds.
    while ((millis() - start) < 5000) {
        // Calling .tick() is very important, this will tell the
        // encoder to read a byte from the serial port, building
        // the GPS location information on each call. Calling it
        // for at least a second continuously should be enough for
        // a full data set.
        encoder.tick();
    }

    // Print the result to the computer port, check it out in your serial  monitor!
    Serial.println(encoder.encode());
}
```
