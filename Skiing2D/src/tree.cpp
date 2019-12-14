#include "tree.h"

tree::tree(ofColor* treeColor)
{
    this->treeColor = treeColor;
}


void tree::draw()
{
    ofPushMatrix();
        ofTranslate(this->position);

        // Set the tree color
        // If it has been crashed into, turn red for a second
        if(crashIndex > 0)
        {
            crashIndex--;
            ofSetColor(ofColor::darkRed);
        }
        else
            ofSetColor(ofColor::darkGreen);

        ofDrawTriangle(0,-100,-25,60,25,60);
//        ofDrawRectangle(200, 30, 35, 60);

        ofSetColor(ofColor::yellow);
        ofDrawCircle(0,0,2);

    ofPopMatrix();

//    ofSetColor(ofColor::greenYellow);
//    ofDrawRectangle(this->damageRect);

}

void tree::calc(float yVel)
{
    // Make a new vector using the speed of the skiier * -1
    // This moves the trees in the opposite direction of him
    ofVec2f p(0, yVel);
    position -= p;

    // Setup the damage box
    this->damageRect.set(position.x-20, position.y, 40, 60);
}

void tree::setPosition(float x, float y)
{
    position.set(x, y);
}


