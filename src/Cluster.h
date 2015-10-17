#pragma once

#include "ofMain.h"

namespace vv {

class Cluster {
protected:
    unsigned int nPoints;
    unsigned int nEdges;
    
    unsigned int width;
    unsigned int height;
    unsigned int depth;
    
    ofMesh mesh;
    ofVec3f position;
    
public:
    Cluster() {
        set(0, 0);
    }
    
    Cluster(unsigned int num_points, unsigned int num_edges) {
        set(num_points, num_edges);
    }
    
    void setSize(unsigned int w, unsigned  int h, unsigned int d) {
        width = w;
        height = h;
        depth = d;
    }
    
    void set(unsigned int num_points, unsigned int num_edges) {
        nPoints = num_points;
        nEdges = num_edges;
        
//        mesh.clearIndices();
//        mesh.clearColors();
//        mesh.clearVertices();
        mesh.setMode(OF_PRIMITIVE_LINES);
        
        for (int i=0; i<nPoints; i++) {
            
            mesh.addColor(ofFloatColor(1., 1., 1.));
            mesh.addVertex(ofVec3f(ofRandom(-(float)width/2., (float)width/2.),
                                   ofRandom(-(float)height/2., (float)height/2.),
                                   ofRandom(-(float)depth/2., (float)depth/2.)));
        }
        
        for (int i=0; i<nEdges; i++) {
            int start = (int) ofRandom(nPoints);
            int end = (int) ofRandom(nPoints);
            mesh.addIndex(start);
            mesh.addIndex(end);
        }
    }
    
    void update() {
//        set(nPoints, nEdges);
    }
    
    void draw() {
        
        ofPushStyle();
        ofPushMatrix();
        ofSetLineWidth(.25);
        
        ofRotate(90*ofGetElapsedTimef(), 1, -5, +3);
        mesh.draw();
        
        ofPopMatrix();
        ofPopStyle();
    }
};
    
}