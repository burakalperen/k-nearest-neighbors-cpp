#ifndef KNN
#define KNN_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include "Node.h"

using namespace std;


class Knn{

    public:
        Knn();
        ~Knn();

        void createRandomData(); //create features between -5 and 5
        static int assingClass(); //create ground truth vector
        
        void createClusterSet(); //create set to keep data and classes in format(data_id,assigned_class)

        int getNumberofData() const;
        vector<Node> getData() const;
        vector<int> getGroundTruth() const;
        set<pair<int,int>> getClusters() const;
        void printData() const; 
        void printGroundTruth() const;
        void printClusters() const;

    private:
        static int numberOfdata;
        vector<Node> data; //keep data points 
        vector<int> groundTruth; //keep classes of data points
        set<pair<int,int>> cluster; // set keep in format of {data_id,assigned_class}


};


#endif