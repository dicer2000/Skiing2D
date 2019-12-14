#pragma once

#include "ofMain.h"

class skiier
{
    private:

        float speed = 0;
        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;
        ofColor *bibColor = NULL;
        float angle = 90.0;
        bool bSkiierGoing = true;

    public:


        skiier() {};
        skiier(ofColor*);
        ~skiier() { 
            if(bibColor!=NULL)
                delete bibColor;
        };
        void draw();
        void calc(bool bSkiLeft, bool bSkiRight);
        float getYVelocity() { return velocity.y; };
        bool getSkiierGoing() { return bSkiierGoing; };
        void setSkiierGoing(bool skiierGoing) { bSkiierGoing = skiierGoing; };

        ofRectangle damageRect;
};