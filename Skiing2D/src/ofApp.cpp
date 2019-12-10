#include "ofApp.h"
#include "skiier.h"
#include "slope.h"

ofApp::~ofApp()
{
    if(player1!=NULL)
        delete player1;
    if(slope1!=NULL)
        delete slope1;
}

//--------------------------------------------------------------
void ofApp::setup(){

    // Setup the window params
    ofSetWindowTitle("Skiier 2D");

    ofSetVerticalSync(true);
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.


    // Create my skiier
    this->player1 = new skiier(new ofColor(222,40,222));

    // Create a tree
    this->slope1 = new slope();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    player1->draw();
    player1->calc();

    slope1->draw();
    slope1->calc();

//    tree1->draw();
//    tree1->calc();
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