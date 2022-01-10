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
        static int assingLabel(); //create ground truth vector for generate algorithm
        void createClusterSet(); //create set to keep classes of whole data in format(data_id,assigned_class)
        
        void inferencev2();

        double CalculateEuclidean(const double,const double, const double, const double);

        int getK() const;
        int getNumberofTrainData() const;
        int getNumberofTestData() const;
        vector<Node> getTrainData() const;
        vector<Node> getTestData() const;
        vector<int> getPredictions() const;
        vector<int> getGroundTruth() const;
        set<pair<int,int>> getClusters() const;
        
        void printData(string); 
        void printGroundTruth() const;
        void printPredictions() const;
        void printClusters() const;

    private:
        const int k;
        static int numberTrainData;
        static int numberTestData;



        vector<Node> trainData; // train data points 
        vector<Node> testData; // test data points
        vector<int> groundTruth; // classes of train data points
        vector<int> predictions; // classes of test data points
        set<pair<int,int>> cluster; // classes of whole data in format of (data_id,classes)


};


#endif