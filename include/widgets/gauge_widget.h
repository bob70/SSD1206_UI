#ifndef _GAUGE_WIDGET_H_
#define _GAUGE_WIDGET_H_

#define BLACK 0
#define WHITE 1
#define INVERSE 2

#include "widgets/oled_widget.h"

class GaugeWidget : public OledWidget {

  using OledWidget::OledWidget;
  public :
    bool draw();
    bool setValue(float value);

  protected :
    void _drawInnerGauge();
    float _oldValue;
    float _value;
};

#endif
