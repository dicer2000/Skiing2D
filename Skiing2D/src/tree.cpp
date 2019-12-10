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
        ofSetColor(ofColor::darkGreen);
        ofDrawRectangle(200, 30, 35, 60);

    ofPopMatrix();


}

void tree::calc()
{
    ofVec2f p(0, 3);
    position -= p;


}

void tree::setPosition(float x, float y)
{
    position.set(x, y);
}


