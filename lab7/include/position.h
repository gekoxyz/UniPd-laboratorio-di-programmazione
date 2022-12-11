#ifndef POSITION_H 
#define POSITION_H

#include <sstream>

class position {
public:
    position() {}
    position(int x, int y) {
        x_ = x;
        y_ = y;
    }
    int x() { return x_; }
    int y() { return y_; }

    std::string to_string() {
        std::stringstream ss;
        ss << ("(" + std::to_string(x_) + ", " + std::to_string(y_) + ")");
        return ss.str();
    }
private:
    int x_;
    int y_;
};

#endif