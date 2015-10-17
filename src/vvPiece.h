#pragma once

#include "ofMain.h"

#define MAX_OFFSET 1.0

namespace vv {

class Piece {
protected:
    int width;
    int height;
    int depth;
    float offset;
    float offsetAngle;
    float t;
    float opacity;
    bool isDead;
    ofVec3f position;
    ofBoxPrimitive box;
    
public:
    Piece() :
        width(0),
        height(0),
        depth(0),
        isDead(false),
        offset(MAX_OFFSET),
        t(0) {
    }
    
    Piece(int w, int h, int d) :
        width(w),
        height(h),
        depth(d),
        offset(MAX_OFFSET),
        isDead(false),
        t(0) {
    }
    
    ~Piece() {
        isDead = true;
    }
    
    void setTime(float time_offset) {
        t = time_offset;
    }
    
    void setOffsetAngle(float theta) {
        offsetAngle = theta;
    }
    
    void setSize(const ofVec3f &size) {
        box.set(size[0], size[1], size[2]);
    }
    
    void setPosition(const ofVec3f &pos) {
        position = pos;
    }
    
    void update() {
        if (t < 0) {
            opacity = 1+t;
        }
        if (t >= 1.0) {
            t = 1.0;
            isDead = true;
        } else if (!isDead) {
            t += 0.05;
        }
        
        ofVec3f shiftVec = ofVec3f((1-t)*sin(offsetAngle),
                                   0,
                                   (1-t)*cos(offsetAngle)
                                   );
        
        
        box.setPosition(position + shiftVec);
        
        opacity = 255 * t;
    }
    
    void draw() {
        if (t >= 0) {
            ofPushStyle();
            ofSetColor(255, 255, 255, opacity);
            box.draw();
            ofPopStyle();
        }
    }
    
    void draw(ofMaterial mat) {
        mat.begin();
        box.draw();
        ofPopStyle();
        mat.end();
    }
};

}