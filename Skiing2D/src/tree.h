#pragma once

#include "ofMain.h"

class tree
{
    private:

        ofVec2f position;
        ofColor *treeColor = NULL;

    public:
        tree() {};
        tree(ofColor*);
        ~tree() { 
            if(treeColor!=NULL)
                delete treeColor;
        };
        void setPosition(float x, float y);
        void draw();
        void calc();
        float getY() { return position.y; };

};