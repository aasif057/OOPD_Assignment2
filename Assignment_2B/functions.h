#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

void splitLine(const std::string &line, std::string fields[], int fieldCount);
bool isNumeric(const std::string &str);
void splitCSVLine(const std::string &line, std::string fields[], int fieldCount);
void splitString(const std::string &input, std::string fields[], int fieldCount);
bool isValidUserName(const std::string &userName);
std::string getField(const std::string &line, int fieldIndex);

#endif // FUNCTIONS_H
