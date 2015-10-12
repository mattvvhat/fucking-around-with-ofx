#pragma once

#include "ofMain.h"

namespace vv {

class Piece {
protected:
    int width;
    int height;
    int depth;
    float t;
    float opacity;
    bool isDead;
    ofBoxPrimitive box;
    
public:
    Piece() :
        width(0),
        height(0),
        depth(0),
        isDead(false),
        t(0) {
    }
    
    Piece(int w, int h, int d) :
        width(w),
        height(h),
        depth(d),
        isDead(false),
        t(0) {
    }
    
    ~Piece() {
        isDead = true;
    }
    
    void setSize(const ofVec3f &size) {
        box.set(size[0], size[1], size[2]);
    }
    
    void setPosition(const ofVec3f &pos) {
        box.setPosition(pos);
    }
    
    void update() {
        if (!isDead) {
            t += 0.01;
        } else if (t >= 1.0) {
            t = 1.0;
            isDead = true;
        }
        
        opacity = 255 * t;
    }
    
    void draw() {
        box.draw();
    }
    
    void draw(ofMaterial mat) {
        mat.begin();
        box.draw();
        mat.end();
    }
};

}