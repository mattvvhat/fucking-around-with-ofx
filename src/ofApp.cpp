#include "ofApp.h"

#include "GibberishMesh.h"
#include "Cluster.h"

#define NUM_BUILDINGS 5

void ofApp::setup() {
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    
    view.cam.setNearClip(0.01f);
    view.cam.setFarClip(1000.0f);

    cluster.setSize(3, 3, 3);
    cluster.set(70, 200);

    
    box.set(1, 1, 1);
    box.setPosition(ofVec3f(0, 0, 0));
    pointLight.setPointLight();
    
    material.setShininess(30.0);
    material.setSpecularColor(ofColor(1.0, 1.0, 1.0));
    material.setDiffuseColor(ofColor(0.4, 0.4, 0.4, 1.0));
    material.setAmbientColor(ofColor(0.1, 0.1, 0.1));
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    
    ambientLight.setAmbientColor(ofFloatColor(0.1, 0.1, 0.1));
    
    directionalLight.setDiffuseColor(ofFloatColor(0.5, 0.5, 0.5));
    directionalLight.setDirectional();

    
    for (int i=0; i < NUM_BUILDINGS; i++) {
        s::vvBuilding b;
        b.setPieceSize(ofVec3f(1.0, 0.25, 1.0));
        b.setPosition(ofVec3f(-NUM_BUILDINGS/2.+NUM_BUILDINGS*(i/(float) NUM_BUILDINGS)+i*1.01, -5.0, 0.0));
//        buildings.push_back(b);
    }
}

void ofApp::update() {
    view.position = ofVec3f(0, 0, 0);
    
    // view.cam.setupPerspective();
    view.cam.setPosition(ofVec3f(0, 0, 7));
    view.cam.lookAt(ofVec3f(0, 0, 0));
    
    mesh.update();
    cluster.update();
    
    float t = 3*ofGetElapsedTimef();
    pointLight.setPosition(5, 5, 5);
    
    for (auto it=buildings.begin(); it != buildings.end(); ++it) {
        it->update();
    }
    
    setLightOri(directionalLight, ofVec3f(0, -120, 0));
    ambientLight.setAmbientColor(ofFloatColor(0.1, 0.1, 0.5));
}

void ofApp::draw() {
    ofEnableDepthTest();
    ofClear(33, 33, 33);
    ofSetColor(255, 255, 255);
    
    view.cam.begin();
    material.begin();
    
    // pointLight.enable();
    ambientLight.enable();
    directionalLight.enable();

    //  for (auto it=buildings.begin(); it != buildings.end(); ++it) {
    //       it->draw();
    //  }
    
    cluster.draw();
    
    directionalLight.disable();
    ambientLight.disable();
    
    // pointLight.disable();
    // material.end();
    view.cam.end();
}

void ofApp::keyPressed(int key){
}

void ofApp::keyReleased(int key){
}

void ofApp::mouseMoved(int x, int y ){
}

void ofApp::mouseDragged(int x, int y, int button){
}

void ofApp::mousePressed(int x, int y, int button){
}

void ofApp::mouseReleased(int x, int y, int button){
}

void ofApp::windowResized(int w, int h){
}

void ofApp::gotMessage(ofMessage msg){
}

void ofApp::dragEvent(ofDragInfo dragInfo){
}

void ofApp::setLightOri(ofLight &light, ofVec3f rot) {
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light.setOrientation(q);
}