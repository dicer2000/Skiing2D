#pragma once

#include <list>
#include "tree.h"

#define TREECOUNT 100

using namespace std;

class slope
{
    private:
        list<tree> *trees;

    public:
        slope() { trees = new list<tree>(); };
        ~slope() { 
            if(trees!=NULL)
                delete trees;
        };
        void draw();
        void calc();
        void manageTrees();
};