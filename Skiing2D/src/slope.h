#pragma once

#include <list>
#include "tree.h"
#include "skier.h"

#define TREECOUNT 100

using namespace std;

class slope
{
    private:
        list<tree> *trees;
        skier* ski;
    public:
        slope(skier *ski);
        ~slope() { 
            if(trees!=NULL)
                delete trees;
        };
        void draw();
        void calc();
        void manageTrees();
};