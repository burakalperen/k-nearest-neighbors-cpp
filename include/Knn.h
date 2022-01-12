#ifndef KNN_H
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
        void inference(); // inference member function to call necessary functions
        double CalculateEuclidean(const double &,const double &, const double &, const double &);
        
        int getK() const; 
        int getNumberofTrainData() const; 
        int getNumberofTestData() const; 
        
        // getter functions
        vector<Node> getTrainData() const;
        vector<Node> getTestData() const;
        vector<int> getTrainLabels() const;
        vector<int> getTestLabels() const;
        
        // print functions
        void printData(string); 
        void printTrainLabels() const;
        void printTestLabels() const;

    private:
        const int k; // number of cluster 
        static const int numberTrainData = 30; // number of train samples
        static const int numberTestData = 10; //number of test samples

        vector<Node> trainData; // train data points 
        vector<Node> testData; // test data points
        vector<int> trainLabels; // classes of train data points
        vector<int> testLabels; // predictions
};


#endif