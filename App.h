
#ifndef APP_H
#define APP_H

#include <string>
using namespace std;

class App {

private:   
        // these variables store the information for one app                                     
    string appName;
    string informationCollected;
    string possibleInference;

public:
         // this constructor sets up the information when an App object is created
    App(string name, string information, string inference);

    string getAppName();
    string getInformationCollected();
    string getPossibleInference();

};

#endif
