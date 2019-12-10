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
        int angle;

    public:


        skiier() {};
        skiier(ofColor*);
        ~skiier() { 
            if(bibColor!=NULL)
                delete bibColor;
        };
        void draw();
        void calc();


};