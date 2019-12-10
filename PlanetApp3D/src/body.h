#pragma once

#include "ofMain.h"

enum BodyType { Empty, Sun, Planet, Moon };

class body
{
    public:
        body() {};
        body(int distance, int size, float speed, ofColor*, BodyType);
        ~body() { 
            if(bodyColor!=NULL)
                delete bodyColor;
        };
        void draw();
        void calc();
        int getDistance() { return distance; }
        int getBodyCount() { return bodyCount; }
        body* getBodies() { return bodies; }

        // For step 3
        bool setBodyAttributes(int distance, int size, float speed, ofColor*);
    private:
//        string name;
		// BodyType for determining which type of body it is
		BodyType bodyType = Empty;

        int distance = 0;
        int size = 0;
        float speed = 0;
        glm::vec3 position;
        ofColor *bodyColor = NULL;
        ofMaterial material;
        // An array of bodies that can be attached to this body (planets, moons)
        body *bodies = NULL;
        int bodyCount = 0;

        bool createSolarSystem();
        void setBodyType(BodyType bt);

};