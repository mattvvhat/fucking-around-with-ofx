#include "ofApp.h"

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofSetCircleResolution(64);
    
    view.cam.setNearClip(0.01f);
    view.cam.setFarClip(1000.0f);
    
    box.set(1, 1, 1);
    box.setPosition(ofVec3f(0, 0, 0));
    pointLight.setPointLight();
    
    material.setShininess(30.0);
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    material.setDiffuseColor(ofColor(255, 255, 255, 255));
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
}

void ofApp::update() {
    view.position = ofVec3f(0, 0, 0);
    view.cam.setPosition(ofVec3f(5, 5, 5));
    view.cam.lookAt(ofVec3f(0, 0, 0));
    
    float t = 3*ofGetElapsedTimef();
    pointLight.setPosition(5*cos(t), 5*sin(t), 5);

    building.setPieceSize(ofVec3f(1.0, 0.25, 1.0));
    building.setPosition(ofVec3f(0.0, 0.0, 0.0));
    building.update();
}

void ofApp::draw() {
    ofClear(33.0, 33.0, 33.0);
    ofSetColor(255, 255, 255);
    
    view.cam.begin();
    material.begin();
    pointLight.enable();
    
    building.draw();
    
    pointLight.disable();
    material.end();
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