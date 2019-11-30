#include "ofMain.h"

class body
{
    public:
        body() {};
        body(int distance, int size, float speed, ofColor*);
        ~body() { 
            if(bodyColor!=NULL)
                delete bodyColor;
        };
        void draw();
        void calc();
        int getDistance() { return distance; }

        // For step 3
        bool setBodyAttributes(int distance, int size, float speed, ofColor*);
    private:
//        string name;
        int distance = 0;
        int size = 0;
        float speed = 0;
        glm::vec2 position;
        ofColor *bodyColor = NULL;
};