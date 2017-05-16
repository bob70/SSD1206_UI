#include "widgets/oled_widget.h"

OledWidget::OledWidget(int width, int height, int nbMaxChildren, bool focusable, STM32_SSD1306 *displayDrv) {
  _width = width;
  _height = height;
  _displayDrv = displayDrv;
  _dirty = true;
  _focusable = focusable;
  _nbMaxChildren = nbMaxChildren;
  _lastChildIdx = 0;
  _absX = 0;
  _absY = 0;
  _children = (Widget**) malloc(sizeof(Widget*) * _nbMaxChildren);
  _parent = NULL;
  printf("Malloc %d\n", sizeof(Widget*) * _nbMaxChildren);
  _setClientArea();
}

void OledWidget::_setParent(Widget* parent) {
  _parent = parent;
}

void OledWidget::_setClientArea() {
  _clientArea.relX = 0;
  _clientArea.relY = 0;
  _clientArea.width = _width - 3;
  _clientArea.height = _height - 3;
}

short int OledWidget::x(short int x) {
  return x + _clientArea.relX + _absX;
}

short int OledWidget::y(short int y) {
  return y + _clientArea.relY + _absY;
}

bool OledWidget::isDirty() {
  return _dirty;
}

void OledWidget::declareDirty() {
  _dirty = true;
}

void OledWidget::addChild(Widget* child, int relX, int relY) {
  //assert(_nbMaxChildren > 0);
  _children[_lastChildIdx++] = child;
  child->_setAbsPos(relX + _clientArea.relX + _absX, relY + _clientArea.relY + _absY);
}

bool OledWidget::draw() {
  bool isDrawEffective = false;
  for (int idx = 0; idx < _lastChildIdx; idx++) {
    if (_children[idx]->isDirty()) {
      _children[idx]->draw();
      isDrawEffective = true;
    }
  }
  _dirty = false;
  return isDrawEffective;
}

void OledWidget::_setAbsPos(int x, int y) {
  _absX = x;
  _absY = y;
  if (_parent != NULL)
    _parent->declareDirty();
  _dirty = true;
}

