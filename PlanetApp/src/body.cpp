#include "body.h"

#define PLANET_COUNT 9


body::body(int distance, int size, float speed, ofColor* color, BodyType bodyType)
{
//    this->name = name;
    this->distance = distance;
    this->size = size;
    glm::vec2 vPos(0, distance * -1);
    this->position = vPos;
    this->speed = speed;
    this->bodyColor = color;
    this->bodyType = bodyType;

    // Create a array of daughter bodies
    createSolarSystem();
}

void body::draw()
{
    // Draw the planet
    ofPushMatrix();
        ofSetColor(*bodyColor);
        ofTranslate(this->position);
        ofDrawCircle(0, 0, this->size);

        //ofDrawBitmapString("Planet", 0, 20);

        // Draw any daughter bodies
        for(int i=0; i < this->getBodyCount(); i++)
            this->bodies[i].draw();

    ofPopMatrix();
}

void body::calc()
{
    // Calculate the next position of this body
    float x = cos( ofGetFrameNum() * this->speed ) * this->distance;
    float y = sin( ofGetFrameNum() * this->speed ) * this->distance;
    //    float a = ofRadToDeg(atan2(y, x));
    this->position.x = x;
    this->position.y = y;
    
    for(int i=0; i < this->getBodyCount(); i++)
        this->bodies[i].calc();
}

// Set the attributes of a body
bool body::setBodyAttributes(int distance, int size, float speed, ofColor* color)
{
    this->distance = distance;
    this->size = size;
    glm::vec2 vPos(0, distance * -1);
    this->position = vPos;
    this->speed = speed;
    this->bodyColor = color;
    return true;
}

void body::setBodyType(BodyType bt) 
{ 
    this->bodyType = bt;
    createSolarSystem();
}

// Create the planets that will be in our solar system
bool body::createSolarSystem()
{
    int mDist = 0;
    switch (this->bodyType)
    {
    case SolarSystem:
        this->bodyCount = 9;
        // Create the planets that will be within this solar system
        bodies = new body[this->bodyCount];
        mDist = 60;    // Distance between planets
        bodies[0].setBodyAttributes(   // Mercury
                mDist, 
                ofMap(10, 0, 99, 5, 25), // Body Size
                ofMap(107082, 0, 110000, .01, .02), // Body Velocity
                new ofColor(155,155,155));
        bodies[1].setBodyAttributes(   // Venus
                bodies[0].getDistance()+mDist, 
                ofMap(35, 0, 99, 5, 25), // Body Size
                ofMap(78337, 0, 110000, .01, .02), // Body Velocity
                new ofColor(106,31,17));
        bodies[2].setBodyAttributes(   // Earth
                bodies[1].getDistance()+mDist, 
                ofMap(35, 0, 99, 5, 25), // Body Size
                ofMap(66615, 0, 110000, .01, .02), // Body Velocity
                new ofColor(36,47,124));
        bodies[2].setBodyType(Moon);
        bodies[3].setBodyAttributes(   // Mars
                bodies[2].getDistance()+mDist, 
                ofMap(25, 0, 99, 5, 25), // Body Size
                ofMap(53858, 0, 110000, .01, .02), // Body Velocity
                new ofColor(200,87,35));
        bodies[4].setBodyAttributes(   // Jupiter
                bodies[3].getDistance()+mDist, 
                ofMap(99, 0, 99, 5, 25), // Body Size
                ofMap(29236, 0, 110000, .01, .02), // Body Velocity
                new ofColor(149,127,111));
        bodies[4].setBodyType(Moon);
        bodies[5].setBodyAttributes(   // Saturn
                bodies[4].getDistance()+mDist, 
                ofMap(75, 0, 99, 5, 25), // Body Size
                ofMap(21675, 0, 110000, .01, .02), // Body Velocity
                new ofColor(220,170,85));
        bodies[6].setBodyAttributes(   // Uranus
                bodies[5].getDistance()+mDist, 
                ofMap(45, 0, 99, 5, 25), // Body Size
                ofMap(15233, 0, 110000, .01, .02), // Body Velocity
                new ofColor(157, 177, 183));
        bodies[7].setBodyAttributes(   // Neptune
                bodies[6].getDistance()+mDist, 
                ofMap(45, 0, 99, 5, 25), // Body Size
                ofMap(12146, 0, 110000, .01, .02), // Body Velocity
                new ofColor(132,152,177));
        bodies[8].setBodyAttributes(   // Pluto
                bodies[7].getDistance()+mDist, 
                ofMap(10, 0, 99, 5, 25), // Body Size
                ofMap(10700, 0, 110000, .01, .02), // Body Velocity
                new ofColor(63,42,23));
        break;
    case Moon:
        this->bodyCount = 1;
        // Create the planets that will be within this solar system
        bodies = new body[this->bodyCount];
        mDist = 20;    // Distance between planets
        bodies[0].setBodyAttributes(   // Mercury
                mDist + size, 
                ofMap(3, 0, 99, 5, 25), // Body Size
                ofMap(110000, 0, 110000, .01, .02), // Body Velocity
                new ofColor(155,155,155));
        break;
    default:
        this->bodyCount = 0;
        this->bodies = NULL;
        break;
    }
    return true;
}