#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Planets");
    ofSetCircleResolution(50);
    ofSetVerticalSync(true);
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.

    // Background black
    ofBackground(0,0,0);

    // Step 1 - just a sun statically drawn in the middle */

    /* Step 2 - just a planet and sun object
    s = new body(0, 20, 0.0f, new ofColor(248,222,126));
    p = new body(60, 8, .02f, new ofColor(36, 119, 119));
    */

   /* Step 3 - sun with array of planet bodies
    s = new body(0, 20, 0.0f, new ofColor(248,222,126));
    planets = new body[PLANET_COUNT];
    int mDist = 30;
    for(int i=0; i < PLANET_COUNT; i++)
    {
        planets[i].setBodyAttributes(i*30+mDist, rand()%20+5, rand()%20*.001, new ofColor(248,222,126));
    }
    */

    /* Step 4 - Using the map function
    s = new body(0, 20, 0.0f, new ofColor(248,222,126));
    planets = new body[PLANET_COUNT];
    int mDist = 100;    // Give the sun some distance
    for(int i=0; i < PLANET_COUNT; i++)
    {
        planets[i].setBodyAttributes(
            i*30+mDist, 
            ofMap(rand()%100, 0, 99, 5, 15), // Map Size
            ofMap(rand()%100, 0, 99, .01, .02), //rand()%20*.001, // Map Velocity
            new ofColor(
                ofMap(rand()%100, 0, 99, 0, 254),   // Red
                ofMap(rand()%100, 0, 99, 0, 254),   // Green
                ofMap(rand()%100, 0, 99, 0, 254)));  // Blue
    }
    */

    // Step 5 - Creating planets like our solor system
    // Our one-and-only Sun
    s = new body(0, 20, 0.0f, new ofColor(248,222,126), SolarSystem);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{

        // Translate to the center
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

        // Draw the sun
        s->draw();

    ofPopMatrix();

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