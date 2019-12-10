#include "skiier.h"


skiier::skiier(ofColor* bibColor)
{
//        glm::vec2 vPos(0, distance * -1);
        this->position.x = ofGetWindowWidth()/2.0;
        this->position.y = 50; //ofGetWindowHeight()/3.0;

        this->bibColor = bibColor;
}


void skiier::draw()
{
    // Draw the planet
    ofPushMatrix();
        ofTranslate(this->position);

        // Shadow
        ofSetColor(ofColor(30,30,30,50));
        ofDrawEllipse(8, 35, 20, 30);
        // Skiis
        ofSetColor(ofColor::black);
        ofDrawRectangle(0, 25, 5, 20);
        ofDrawRectangle(10, 25, 5, 20);
        // Body
        ofSetColor(*bibColor);
        ofDrawRectangle(0, 0, 15, 30);
        // arms
        ofSetColor(ofColor::gray);
        ofDrawRectangle(-2,0, 5, 20);
        ofDrawRectangle(12,0, 5, 20);
        // head
        ofSetColor(ofColor::brown);
        ofDrawEllipse(8, -5, 12, 13);
    ofPopMatrix();
}

void skiier::calc()
{
    // Get the steering force
    ofVec2f finalSpot(ofGetWindowWidth()/2.0, 200.0);
    ofVec2f desired = finalSpot - position;
    desired = desired.normalize();
    desired = desired * 3.0; // Max speed [3 for now]
    ofVec2f steer = desired - velocity;
    steer = steer.limit(0.02);  // Max steer force
    // Update velocity
    velocity += steer;
    // Limit the speed and update the position
    velocity.limit(3.0);
    position += velocity;

}