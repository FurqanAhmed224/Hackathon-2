
#include "App.h"

App::App(string name, string information, string inference) {
    appName = name;
    informationCollected = information;
    possibleInference = inference;
}

string App::getAppName() {
    return appName;
}

string App::getInformationCollected() {
    return informationCollected;
}

string App::getPossibleInference() {
    return possibleInference;
}
