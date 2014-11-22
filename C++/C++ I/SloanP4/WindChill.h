// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanP4/WindChill.h

double askForTemperature();
double askForWindSpeed();
int validateTempWS(double temp, double windsp);
double calcWindchill(double temp, double windsp);
int determineFrostbiteTimes(double temp, double windsp);