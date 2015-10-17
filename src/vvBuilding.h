#pragma once

#include <list>

#include "ofMain.h"
#include "vvPiece.h"

#define MAX_PIECES 100

namespace s {

class vvBuilding {
private:
    // Time
    float t;
    
    // Pieces
    std::list<vv::Piece> pieces_list;
    ofVec3f pieceSize;
    
public:
    vvBuilding():t(0) {
        ofSeedRandom();
        
        for (int i=0; i<MAX_PIECES; i++) {
            vv::Piece p;
            p.setSize(ofVec3f(1, 1, 1));
            p.setOffsetAngle(-M_PI/2.);
            p.setTime(-i/1.5);
            pieces_list.push_back(p);
        }
    }
    
    ~vvBuilding() {
    }
    
    void setPieceSize(const ofVec3f & dims) {
        pieceSize = dims;
        for (auto it=pieces_list.begin(); it != pieces_list.end(); ++it) {
            it->setSize(pieceSize);
        }
    }
    
    void setPosition(const ofVec3f & pos) {
        int i=0;
        for (auto it=pieces_list.begin(); it != pieces_list.end(); ++it, ++i) {
            float t = 1.1*(-.5 + i);
            ofVec3f piece_pos = pos;
            piece_pos[1] += pieceSize[1] * t;
            it->setPosition(piece_pos);
        }
    }
    
    void update() {
        for (auto it=pieces_list.begin(); it != pieces_list.end(); ++it) {
            it->update();
        }
    }
    
    void draw() {
        for (auto it=pieces_list.begin(); it != pieces_list.end(); ++it) {
            it->draw();
        }
    }
};

}