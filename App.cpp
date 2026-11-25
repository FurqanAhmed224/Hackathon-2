
#include "App.h"
    // this is the constructor that gives each app its information
App::App(string name, string information, string inference) {
    appName = name;
    informationCollected = information;
    possibleInference = inference;
}
    // these getters return the information for the app
string App::getAppName() {
    return appName;
}

string App::getInformationCollected() {
    return informationCollected;
}

string App::getPossibleInference() {
    return possibleInference;
}
