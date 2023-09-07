#include "LG.hpp"
#include <iostream>

LocalizacaoGeografica::LocalizacaoGeografica(float latitude, float longitude){
  this->_latitude = latitude;
  this->_longitude = longitude;
}

LocalizacaoGeografica::LocalizacaoGeografica(){}