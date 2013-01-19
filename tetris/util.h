#ifndef TETRIS_UTIL
  #define TETRIS_UTIL

  #define TETRIS_LEFT 0
  #define TETRIS_RIGHT 1
  #define TETRIS_DOWN 2

  #define TETRIS_SHAPE_I 0
  #define TETRIS_SHAPE_J 1
  #define TETRIS_SHAPE_L 2
  #define TETRIS_SHAPE_O 3
  #define TETRIS_SHAPE_S 4
  #define TETRIS_SHAPE_T 5
  #define TETRIS_SHAPE_Z 6

  class Point {
    float _x;
    float _y;

  public:
    Point() { _x = 0; _y = 0; }
    Point(float x, float y) { _x = x; _y = y; }

    float getX() { return _x; }
    void setX(float x) { _x = x; }
    float getY() { return _y; }
    void setY(float y) { _y = y; }
  };

  class Rectangle {
    float _x;
    float _y;
    float _w;
    float _h;

  public:
    Rectangle() {
      _x = 0;
      _y = 0;
      _w = 0;
      _h = 0;
    }

    Rectangle(float x, float y, float w, float h) {
      _x = x;
      _y = y;
      _w = w;
      _h = h;
    }

    void operator=(Rectangle r) {
      _x = r.getX();
      _y = r.getY();
      _w = r.getW();
      _h = r.getH();
    }

    float getX() { return _x; }
    void setX(float x) { _x = x; }
    float getY() { return _y; }
    void setY(float y) { _y = y; }
    float getW() { return _w; }
    void setW(float w) { _w = w; }
    float getH() { return _h; }
    void setH(float h) { _h = h; }

    bool containsPoint(Point p) {
      return containsPoint(p.getX(), p.getY());
    }

    bool containsPoint(float x, float y) {
      return _x <= x && _x + _w >= x && _y <= y && _y + _h >= y;
    }

    bool collidesWith(Rectangle target) {
      return containsPoint(target.getX(), target.getY()) ||
          containsPoint(target.getX() + target.getW(), target.getY()) ||
          containsPoint(target.getX(), target.getY() + target.getH()) ||
          containsPoint(target.getX() + target.getW(), target.getY() + target.getH()) ||
          target.containsPoint(_x, _y) ||
          target.containsPoint(_x + _h, _y) ||
          target.containsPoint(_x, _y + _h) ||
          target.containsPoint(_x + _h, _y + _h);
    }
  };
#endif
