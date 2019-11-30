#include "body.h"


body::body(int distance, int size, float speed, ofColor* color)
{
//    this->name = name;
    this->distance = distance;
    this->size = size;
    glm::vec2 vPos(0, distance * -1);
    this->position = vPos;
    this->speed = speed;
    this->bodyColor = color;
}

void body::draw()
{
    ofPushMatrix();
        ofSetColor(*bodyColor);
        ofTranslate(this->position);
        ofDrawCircle(0, 0, this->size);
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
}