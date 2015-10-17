#pragma once

namespace vv {

class Drawable {
    virtual void setup() = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
};

}