#pragma once

#include "ofMain.h"

namespace vv {

class GibberishMesh {
protected:
    unsigned int nPoints;
    unsigned int nEdges;
    ofBoxPrimitive box;
    ofMesh mesh;
    
public:
    GibberishMesh():nPoints(0), nEdges(0) {
        setup();
    }
    
    GibberishMesh(unsigned int num_points, unsigned int num_edges):nPoints(num_points), nEdges(num_edges) {
        setup();
    }
    
    void setup() {
        mesh.setMode(OF_PRIMITIVE_TRIANGLES);
        mesh.enableColors();
        mesh.enableIndices();
        
        ofMeshFace face;
        face.setVertex(0, ofVec3f(1, 0, 0).getNormalized());
        face.setVertex(1, ofVec3f(0, 0, -1).getNormalized());
        face.setVertex(2, ofVec3f(0, 0, 1).getNormalized());

        mesh.addVertex(face.getVertex(0));
        mesh.addNormal(face.getFaceNormal());
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
        
        mesh.addVertex(face.getVertex(1));
        mesh.addNormal(face.getFaceNormal());
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
        
        mesh.addVertex(face.getVertex(2));
        mesh.addNormal(face.getFaceNormal());
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
        
        mesh.addIndex(0);
        mesh.addIndex(1);
        mesh.addIndex(2);
//        mesh.addIndex(2);
//        mesh.addIndex(2);
//        mesh.addIndex(0);
    }
    
    void update() {

    }
    
    void draw() {
        
        ofPushStyle();
        ofPushMatrix();
        ofRotate(90*ofGetElapsedTimef(), 1, 0, 0);
        mesh.draw();
        ofPopMatrix();
        ofPopStyle();
    }
};
    
}