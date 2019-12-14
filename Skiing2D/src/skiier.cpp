#include "skiier.h"
#include <iostream>

using namespace std;

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
        ofPushMatrix();
            ofTranslate(8.0, 25.0);
            ofRotateZDeg(this->angle-90);
            ofSetColor(ofColor::black);
            ofDrawRectangle(-8, -10, 5, 30);
            ofDrawRectangle( 3, -10, 5, 30);
        ofPopMatrix();
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

        // Show center point
        ofSetColor(ofColor::black);
        ofDrawCircle(8.0, 25.0, 0, 4.0);

    ofPopMatrix();

//    ofSetColor(ofColor::greenYellow);
//    ofDrawRectangle(this->damageRect);

}

void skiier::calc(bool bSkiLeft, bool bSkiRight)
{
    // Convert left or right movements to x/y coord
    if(bSkiLeft)
        this->angle += 3.0;
    if(bSkiRight)
        this->angle -= 3.0;

    if(this->angle > 135.0)
        this->angle = 135.0;
    if(this->angle < 45.0)
        this->angle = 45.0;

//    cout << this->angle << " " << (cosf(this->angle)*20)+(ofGetWindowWidth()/2.0) << endl;

    ofVec2f finalSpot(
        (cosf(this->angle)*250)+position.x, 
        200.0);

    // Get the steering force
//    ofVec2f finalSpot(ofGetWindowWidth()/2.0, 200.0);
    ofVec2f desired = finalSpot - position;
    desired = desired.normalize();
    desired = desired * 5.0; // Max speed [3 for now]
    ofVec2f steer = desired - velocity;
    steer = steer.limit(0.06);  // Max steer force
    // Update velocity
    velocity += steer;
    // Limit the speed and update the position
    velocity.limit(8.0);

    // for now don't change position, just feed the velocity
    // off for use in the slope
    position += velocity;
    position.y = 50;

    this->damageRect.set(position.x, position.y, 15, 40);

}