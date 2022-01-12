#ifndef VISUALIZE_H
#define VISUALIZE_H

#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Visualize{


    public:
        Visualize();
        ~Visualize();

        void draw(const vector<Node> &,const vector<Node> &,const vector<int> &,const vector<int> &);

        vector<int> getXcoord() const;
        vector<int> getYcoord() const;
        vector<int> getColors() const;
        vector<int> getSizes() const;


    public:
        vector<int> xCoordinates; // vector for features 1 of data
        vector<int> yCoordinates; // vector for features 2 of data
        vector<int> classColors; // keep class 
        vector<int> sizes; // keep size, smaller points are train data, biggers are test data.


};



#endif
