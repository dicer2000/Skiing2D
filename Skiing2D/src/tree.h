#pragma once

#include "ofMain.h"

class tree
{
    private:

        ofVec2f position;
        ofColor *treeColor = NULL;
        int crashIndex = 0;

    public:
        tree() {};
        tree(ofColor*);
        ~tree() { 
            if(treeColor!=NULL)
                delete treeColor;
        };
        void setPosition(float x, float y);
        void draw();
        void calc(float);
        float getY() { return position.y; };

        ofRectangle damageRect;
        void setCrashIndex(int nCrashIndex) { crashIndex = nCrashIndex; };
};