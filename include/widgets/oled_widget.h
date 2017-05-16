#ifndef _OLED_WIDGET_H_
#define _OLED_WIDGET_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "STM32_SSD1206.h"
#include "gfxfont.h"

struct OledClientArea {
  int relX;
  int relY;
  int width;
  int height;
};

class IOledDisplayDrv {
  public:
    virtual void
      drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),
      drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
      drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
      drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
      fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
      drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
      drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
        uint16_t color),
      fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
      fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
        int16_t delta, uint16_t color),
      drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t color),
      fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
        int16_t x2, int16_t y2, uint16_t color),
      drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
        int16_t radius, uint16_t color),
      fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
        int16_t radius, uint16_t color),
      drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
        int16_t w, int16_t h, uint16_t color),
      drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
        int16_t w, int16_t h, uint16_t color, uint16_t bg),
      drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
        int16_t w, int16_t h, uint16_t color),
      drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
        int16_t w, int16_t h, uint16_t color, uint16_t bg),
      drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
        int16_t w, int16_t h, uint16_t color),
      drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
        uint16_t bg, uint8_t size),
      setCursor(int16_t x, int16_t y),
      setTextColor(uint16_t c),
      setTextColor(uint16_t c, uint16_t bg),
      setTextSize(uint8_t s),
      setTextWrap(bool w),
      setRotation(uint8_t r),
      cp437(bool x=true),
      setFont(const GFXfont *f = 0),
      getTextBounds(char *string, int16_t x, int16_t y,
        int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);

      virtual ~IOledDisplayDrv();
};


class Widget {
  public :

    virtual bool isDirty();
    virtual void addChild(Widget* child, int relX, int relY);
    virtual bool draw();
    virtual void declareDirty();
    virtual void _setAbsPos(int x, int y);
};

class OledWidget : public Widget{
  public:

    OledWidget(int width, int height, int nbMaxChildren, bool focusable, STM32_SSD1306* displayDrv);
    bool isDirty();
    void addChild(Widget* child, int relX, int relY);
    bool draw();
    void _setAbsPos(int x, int y);
    void declareDirty();
  protected :
    short int x(short int x);
    short int y(short int y);
    bool _focusable;
    int _absX;
    int _absY;
    OledClientArea _clientArea;

    int _width;
    int _height;

    STM32_SSD1306* _displayDrv;
    bool _dirty;

    Widget** _children;
    Widget*  _parent;
    int _nbMaxChildren;
    int _lastChildIdx;
    void _setClientArea();
    void _setParent(Widget* parent);
};



#endif
