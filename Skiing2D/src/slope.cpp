#include "slope.h"

#include <list>


// Check through all the trees and make sure they
// havent gone off the screen and that there is at
// least TREECOUNT present at all times
void slope::manageTrees()
{
    // prune any trees above top of screen
    if(trees->size() > 0) // && trees[0].getX() < 0.0f)
    {
        tree t = trees->front();
        if(t.getY() < 0.0f)
            trees->pop_front();
    }

    // Add trees if needed
    if(trees->size() < TREECOUNT)
    {
        // make new tree
        tree t;
        t.setPosition( ofRandom(10.f, ofGetWidth()-10), ofGetHeight()+60);
        trees->push_back(t);
    }
}

void slope::draw()
{
    if(trees != NULL && trees->size() > 0)
        for(auto it = trees->begin(); it != trees->end(); ++it)
            it->draw();
}

void slope::calc()
{
    // Cut and plant trees, but only every
    // 60000 frames
    if(ofGetFrameNum() % 30 == 0)
        manageTrees();
    // Calculate their next position
    if(trees != NULL && trees->size() > 0)
        for(auto it = trees->begin(); it != trees->end(); ++it)
            it->calc();

}