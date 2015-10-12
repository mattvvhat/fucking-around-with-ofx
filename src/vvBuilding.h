#pragma once

#include "ofMain.h"

#include "vvPiece.h"

namespace s {

class vvBuilding {
private:
    // Time
    float t;
    
    // Pieces
    vv::Piece pieces[6];
    ofVec3f pieceSize;
    
public:
    vvBuilding():t(0) {
        for (int i=0; i<6; i++) {
            pieces[i].setSize(ofVec3f(1, 1, 1));
        }
    }
    
    ~vvBuilding() {
    }
    
    void setPieceSize(const ofVec3f & dims) {
        pieceSize = dims;
        for (int i=0; i<6; i++) {
            pieces[i].setSize(pieceSize);
        }
    }
    
    void setPosition(const ofVec3f & pos) {
        for (int i=0; i<6; i++) {
            float t = 1.1*(-.5 + i);
            ofVec3f piece_pos = pos;
            piece_pos[1] = pieceSize[1] * t;
            pieces[i].setPosition(piece_pos);
        }
    }
    
    void update() {
        for (int i=0; i<6; i++) {
            pieces[i].update();
        }
    }
    
    void draw() {
        for (int i=0; i<6; i++) {
            pieces[i].draw();
        }
    }
};

}