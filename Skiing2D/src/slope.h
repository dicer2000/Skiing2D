#pragma once

#include <list>
#include "tree.h"
#include "skiier.h"

#define TREECOUNT 100

using namespace std;

class slope
{
    private:
        list<tree> *trees;
        skiier* ski;
    public:
        slope(skiier *ski);
        ~slope() { 
            if(trees!=NULL)
                delete trees;
        };
        void draw();
        void calc();
        void manageTrees();
};