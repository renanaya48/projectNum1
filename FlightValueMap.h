#include <map>
#include <string>
#include <iostream>
#include <string.h>

#ifndef PROJECTNUM1_FLIGHTVALUEMAP_H
#define PROJECTNUM1_FLIGHTVALUEMAP_H


using namespace std;

class FlightValueMap {
    //map of path and value
    map<string, double> mapOfFlightValue;
    //map of index to a parh by order
    map<double, string>mapOfIndexValue;


public:
    //Constructor
    FlightValueMap();

    /**
     * The function initialize the map with all the valu on the xml
     */
    void initializeValues();

    /**
     * The function initialize the map with all the path  and index by
     * the order of the xml
     */
    void initializeIndex();


    /**
     * The function receive a string of values and update the map
     */
    void updateMap(string values);

    /**
     * The function returns the value of a given key
     */
    double getValue(string key);

    /**
     * The function returns true if the key in the map else false
     */
    bool isKeyInMap(string key) const;

    ~FlightValueMap() {}

};


#endif //PROJECTNUM1_FLIGHTVALUEMAP_H