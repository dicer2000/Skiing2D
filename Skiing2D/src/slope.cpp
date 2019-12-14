#include "slope.h"
#include "skier.h"
#include <list>
#include <iostream>

slope::slope(skier* ski)
{
    // Make the tree object
    trees = new list<tree>();
    // set reference to original skier
    this->ski = ski; 
}

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
        t.setPosition( ofRandom(10.f, ofGetWidth()-10), ofGetHeight()+160);
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
    // 1/2 second?  Could control how quickly trees are added here
    if(ofGetFrameNum() % 30 == 0)
        manageTrees();

    // Calculate tree's next position.  Since we will be moving trees
    // and not the skier, send in the skier velocity (*-1)
    float yVel = ski->getYVelocity();

    if(trees != NULL && trees->size() > 0)
        for(auto it = trees->begin(); it != trees->end(); ++it)
        {
            it->calc(yVel);

            // Check for crashes into trees
            if(ski->damageRect.intersects(it->damageRect))
                it->setCrashIndex(60);
        }
}

