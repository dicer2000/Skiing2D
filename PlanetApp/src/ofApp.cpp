#include "ofApp.h"

#define PLANET_COUNT 9
//--------------------------------------------------------------
void ofApp::setup(){

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
    s = new body(0, 20, 0.0f, new ofColor(248,222,126));
    planets = new body[PLANET_COUNT];
    int mDist = 60;    // Distance between planets
    planets[0].setBodyAttributes(   // Mercury
            mDist, 
            ofMap(10, 0, 99, 5, 25), // Body Size
            ofMap(107082, 0, 110000, .01, .02), // Body Velocity
            new ofColor(155,155,155));
    planets[1].setBodyAttributes(   // Venus
            planets[0].getDistance()+mDist, 
            ofMap(35, 0, 99, 5, 25), // Body Size
            ofMap(78337, 0, 110000, .01, .02), // Body Velocity
            new ofColor(106,31,17));
    planets[2].setBodyAttributes(   // Earth
            planets[1].getDistance()+mDist, 
            ofMap(35, 0, 99, 5, 25), // Body Size
            ofMap(66615, 0, 110000, .01, .02), // Body Velocity
            new ofColor(36,47,124));
    planets[3].setBodyAttributes(   // Mars
            planets[2].getDistance()+mDist, 
            ofMap(25, 0, 99, 5, 25), // Body Size
            ofMap(53858, 0, 110000, .01, .02), // Body Velocity
            new ofColor(200,87,35));
    planets[4].setBodyAttributes(   // Jupiter
            planets[3].getDistance()+mDist, 
            ofMap(99, 0, 99, 5, 25), // Body Size
            ofMap(29236, 0, 110000, .01, .02), // Body Velocity
            new ofColor(149,127,111));
    planets[5].setBodyAttributes(   // Saturn
            planets[4].getDistance()+mDist, 
            ofMap(75, 0, 99, 5, 25), // Body Size
            ofMap(21675, 0, 110000, .01, .02), // Body Velocity
            new ofColor(220,170,85));
    planets[6].setBodyAttributes(   // Uranus
            planets[5].getDistance()+mDist, 
            ofMap(45, 0, 99, 5, 25), // Body Size
            ofMap(15233, 0, 110000, .01, .02), // Body Velocity
            new ofColor(157, 177, 183));
    planets[7].setBodyAttributes(   // Neptune
            planets[6].getDistance()+mDist, 
            ofMap(45, 0, 99, 5, 25), // Body Size
            ofMap(12146, 0, 110000, .01, .02), // Body Velocity
            new ofColor(132,152,177));
    planets[8].setBodyAttributes(   // Pluto
            planets[7].getDistance()+mDist, 
            ofMap(10, 0, 99, 5, 25), // Body Size
            ofMap(10700, 0, 110000, .01, .02), // Body Velocity
            new ofColor(63,42,23));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    // Background black
    ofBackground(0,0,0);

    // Use this for the first iteration (putting sun in middle)
    /*
    ofSetColor(248,222,126);
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofDrawCircle(0, 0, 6);
    */
        // Translate to the center
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

        // Draw the sun
        s->draw();

        // Draw the planet(s)
        // Step 2
//        p->draw();

        // Step 3
        for(int i=0; i < PLANET_COUNT; i++)
        {
            planets[i].draw();
        }

    ofPopMatrix();

    // Update all the physics
    // Step 2
//    p->calc();

    // Step 3
    for(int i=0; i < PLANET_COUNT; i++)
    {
        planets[i].calc();
    }

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