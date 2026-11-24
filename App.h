
#ifndef APP_H
#define APP_H

#include <string>
using namespace std;

class App {

private:
    string appName;
    string informationCollected;
    string possibleInference;

public:
    App(string name, string information, string inference);

    string getAppName();
    string getInformationCollected();
    string getPossibleInference();

};

#endif
