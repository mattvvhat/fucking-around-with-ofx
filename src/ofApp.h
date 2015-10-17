#pragma once

#include <list>

#include "ofMain.h"
#include "vvBuilding.h"
#include "GibberishMesh.h"
#include "Cluster.h"

class ofApp : public ofBaseApp{
    
protected:
    
    struct {
        ofVec3f  position;
        ofVec3f  direction;
        ofCamera cam;
    } view;
    
    s::vvBuilding building;
    std::list<s::vvBuilding> buildings;
    
    ofBoxPrimitive box;
    
    ofLight pointLight;
    ofLight directionalLight;
    ofLight orangeDirectionalLight;
    ofLight cyanDirectionalLight;
    ofLight ambientLight;
    ofMaterial material;
    
    vv::GibberishMesh mesh;
    vv::Cluster cluster;

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    void setLightOri(ofLight &light, ofVec3f rot);
};
