#ifndef LOG_H
#define LOG_H

#include "Data.hpp"
#include <string.h>

class Log{

public:
Log(std::string, std::string, Data, std::string);
virtual void printLog() = 0;
Data getData();
std::string getUsuario();

protected:
std::string _userName;
std::string _userEmail;
Data _data;
std::string _entidadeAcessada;

};

#endif
