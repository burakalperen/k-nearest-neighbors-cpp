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
        Knn(int);
        ~Knn();


        void start();
        void createRandomData(string); //create features between -5 and 5
        static int assingClass(); //create ground truth vector
        void createClusterSet(); //create set to keep data and classes in format(data_id,assigned_class)
        

        int getNumberofTrainData() const;
        int getNumberofTestData() const;
        vector<Node> getTrainData() const;
        vector<Node> getTestData() const;
        int getK() const;


        vector<int> getGroundTruth() const;
        set<pair<int,int>> getClusters() const;
        
        void inference();
        double CalculateEuclidean(const double,const double, const double, const double);

        void printData(string); 
        void printGroundTruth() const;
        void printClusters() const;

    private:
        const int k;
        static int numberTrainData;
        static int numberTestData;
        vector<Node> trainData; // train data points 
        vector<Node> testData; // test data points
        vector<int> groundTruth; //keep classes of train data points
        set<pair<int,int>> cluster; // set keep all assigned classes in format of {data_id,assigned_class}


};


#endif