#include "widgets/gauge_widget.h"
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
#include <tgmath.h>

bool GaugeWidget::draw() {
  //printf("Draw gauge %d %d %d %d\n", x(0), y(0), x(0), y(40) );
  int widthDec = _width - 1;
  int heightDec = _height - 1;
  _displayDrv->drawLine(x(0), y(0), x(0), y(heightDec), WHITE);
  _displayDrv->drawLine(x(0), y(heightDec), x(widthDec), y(heightDec), WHITE);
  _displayDrv->drawLine(x(0), y(heightDec), x(widthDec), y(heightDec), WHITE);
  _displayDrv->drawLine(x(widthDec), y(heightDec), x(widthDec), y(0), WHITE);

  _drawInnerGauge();
  _dirty = false;
  return true;
}



void GaugeWidget::_drawInnerGauge() {
  int oldHeight = roundf((_height - 1) * _oldValue);
  int height = roundf((_height - 2) * _value);
  _displayDrv->fillRect(x(2), y(_height - 2 - oldHeight), _width - 4, height, BLACK);
  _displayDrv->fillRect(x(2), y(_height - 2 - height), _width - 4, height, WHITE);
}

bool GaugeWidget::setValue(float value) {
  if (value < -0.01 || value > 1.01 || _oldValue == value)
    return false;
  //printf("Set Value %f\n", value);
  //if (value == 0.5)
    //printf("OK VALUE\n");
  _oldValue = _value;
  _value = value;
  _dirty = true;
  //_drawInnerGauge();
  //_displayDrv->display();

  return true;
}

