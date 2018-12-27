#include "FlightValueMap.h"

//Constructor
FlightValueMap::FlightValueMap() {
    this->initializeValues();
    this->initializeIndex();
}

/**
* The function initialize the map with all the valu on the xml
*/
void FlightValueMap::initializeValues() {
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/instrumentation/altimeter/pressure-alt-ft",
                                 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/encoder/indicated-altitude-ft", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/instrumentation/encoder/pressure-alt-ft",
                                 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("instrumentation/gps/indicated-altitude-ft",
                                 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/gps/indicated-vertical-speed", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/magnetic-compass/indicated-heading-deg", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->mapOfFlightValue.insert(pair<string, double>(
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
            0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/aileron", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/elevator", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/rudder", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/flight/flaps", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/controls/engines/engine/throttle", 0));
    this->mapOfFlightValue.insert(
            pair<string, double>("/engines/engine/rpm", 0));
}

/**
* The function initialize the map with all the path  and index by
* the order of the xml
*/
void FlightValueMap::initializeIndex() {

    this->mapOfIndexValue.insert(pair<double, string>(1,
                                                      "/instrumentation/airspeed-indicator/indicated-speed-kt"));
    this->mapOfIndexValue.insert(pair<double, string>(2,
                                                      "/instrumentation/altimeter/indicated-altitude-ft"));
    this->mapOfIndexValue.insert(pair<double, string>(3,
                                                      "/instrumentation/altimeter/pressure-alt-ft"));
    this->mapOfIndexValue.insert(pair<double, string>(4,
                                                      "/instrumentation/attitude-indicator/indicated-pitch-deg"));
    this->mapOfIndexValue.insert(pair<double, string>(5,
                                                      "/instrumentation/attitude-indicator/indicated-roll-deg"));
    this->mapOfIndexValue.insert(pair<double, string>(6,
                                                      "/instrumentation/attitude-indicator/internal-pitch-deg"));
    this->mapOfIndexValue.insert(pair<double, string>(7,
                                                      "/instrumentation/attitude-indicator/internal-roll-deg"));
    this->mapOfIndexValue.insert(pair<double, string>(8,
                                                      "/instrumentation/encoder/indicated-altitude-ft"));
    this->mapOfIndexValue.insert(pair<double, string>(9,
                                                      "/instrumentation/encoder/pressure-alt-ft"));
    this->mapOfIndexValue.insert(pair<double, string>(10,
                                                      "instrumentation/gps/indicated-altitude-ft"));
    this->mapOfIndexValue.insert(pair<double, string>(11,
                                                      "/instrumentation/gps/indicated-ground-speed-kt"));
    this->mapOfIndexValue.insert(pair<double, string>(12,
                                                      "/instrumentation/gps/indicated-vertical-speed"));
    this->mapOfIndexValue.insert(pair<double, string>(13,
                                                      "/instrumentation/heading-indicator/indicated-heading-deg"));
    this->mapOfIndexValue.insert(pair<double, string>(14,
                                                      "/instrumentation/magnetic-compass/indicated-heading-deg"));
    this->mapOfIndexValue.insert(pair<double, string>(15,
                                                      "/instrumentation/slip-skid-ball/indicated-slip-skid"));
    this->mapOfIndexValue.insert(pair<double, string>(16,
                                                      "/instrumentation/turn-indicator/indicated-turn-rate"));
    this->mapOfIndexValue.insert(pair<double, string>(17,
                                                      "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"));
    this->mapOfIndexValue.insert(
            pair<double, string>(18, "/controls/flight/aileron"));
    this->mapOfIndexValue.insert(
            pair<double, string>(19, "/controls/flight/elevator"));
    this->mapOfIndexValue.insert(
            pair<double, string>(20, "/controls/flight/rudder"));
    this->mapOfIndexValue.insert(
            pair<double, string>(21, "/controls/flight/flaps"));
    this->mapOfIndexValue.insert(
            pair<double, string>(22, "/controls/engines/engine/throttle"));
    this->mapOfIndexValue.insert(
            pair<double, string>(23, "/engines/engine/rpm"));
}

/**
 * The function receive a string of values and update the map
 */
void FlightValueMap::updateMap(string values) {
    int indexPath = 1;
    //Split the string to values
    char *charLine = const_cast<char *>(values.c_str());
    char *splitValues = strtok(charLine, ",");
    map<string, double>::iterator mapIter;

    for (int i = indexPath; i <= 23; i++) {
        string tempPath = this->mapOfIndexValue.find(i)->second;
        this->mapOfFlightValue.find(tempPath)->second = atof(splitValues);
        splitValues = strtok(NULL, ",");
    }
}


/**
 * The function returns the value of a given key
 */
double FlightValueMap::getValue(string key) {
    if (this->mapOfFlightValue.count(key)) {
        return this->mapOfFlightValue.find(key)->second;
    } else {
        throw "ERROR - no matchin value in map";
    }
}

/**
 * The function returns true if the key in the map else false
 */
bool FlightValueMap::isKeyInMap(string key) const {
    if (this->mapOfFlightValue.count(key)) {
        return true;
    }
    return false;
}