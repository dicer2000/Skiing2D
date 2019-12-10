#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Planets");
    ofSetCircleResolution(50);
    ofSetVerticalSync(true);
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    ofEnableDepthTest();

    // Background black
    ofBackground(0,0,0);

//    ofEnableAlphaBlending();    // Allow alpha blending

    // Step 5 - Creating planets like our solor system
    // Our one-and-only Sun
    s = new body(0, 20, 0.0f, new ofColor(248,222,126), Sun);

    light.setPointLight();
//    light.setPosition(0,0,0);
//    light.enable();

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofEnableDepthTest();
    ofEnableLighting();
    light.enable();

    cam.begin();

    ofPushMatrix();


        // Draw the sun
        s->draw();   

    ofPopMatrix();

    cam.end();

    light.disable();
    ofDisableLighting();
    ofDisableDepthTest();

    // Recalc everything
    s->calc();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}