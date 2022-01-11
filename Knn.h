#ifndef KNN
#define KNN_H

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Node.h"

using namespace std;


class Knn{

    public:
        Knn(int);
        ~Knn();

        void start();
        void createRandomData(string); //create features between -5 and 5
        static int assingLabel(); // method to assign train labels for generate algorithm
        void inference();
        double CalculateEuclidean(const double &,const double &, const double &, const double &);
        
        int getK() const;
        int getNumberofTrainData() const;
        int getNumberofTestData() const;
        vector<Node> getTrainData() const;
        vector<Node> getTestData() const;
        vector<int> getTrainLabels() const;
        vector<int> getTestLabels() const;
        
        void printData(string); 
        void printTrainLabels() const;
        void printTestLabels() const;

    private:
        const int k;
        static const int numberTrainData;
        static const int numberTestData;

        vector<Node> trainData; // train data points 
        vector<Node> testData; // test data points
        vector<int> trainLabels; // classes of train data points
        vector<int> testLabels; // predictions


};


#endif