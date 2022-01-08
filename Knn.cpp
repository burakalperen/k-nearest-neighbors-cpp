#include <iostream>
#include <string.h>
#include "Knn.h"
using namespace std;

typedef pair<int,int> intpair;


int Knn::numberOfdata = 10;

Knn::Knn(): groundTruth(numberOfdata)
{

    generate(groundTruth.begin(),groundTruth.end(),assingClass);
    cout << "Knn constructer is called." << endl;


}


Knn::~Knn(){

    cout << "Knn destructor is called." << endl;

}

int Knn::assingClass()
{
    static int i=0;
    int hold;
    if(i<3)
        hold = 1;
    else if(i<7)
        hold = 2;
    else if(i<10)
        hold = 3;
    i++;
    return hold;
}

void Knn::createRandomData(){

    int identity;
    double x,y;

    for (int i=0;i<getNumberofData();i++)
    {

        identity = i;
        x = (rand() % 9) - 4; // between -5 and 5
        y = (rand() % 9) - 4;

        data.push_back(Node(identity,x,y));
        //Node *ptr = new Node(i,x,y);
        //data.push_back(*ptr);
        //delete ptr;
    }

}

vector<Node> Knn::getData() const
{
    return data;
}

int Knn::getNumberofData() const{

    return numberOfdata;
}

void Knn::printData() const{

    vector<Node> tempData;
    tempData = getData();
    for(vector<Node>::iterator it=tempData.begin(); it!=tempData.end();it++)
        cout << "(" <<(*it).getId() << "," << (*it).getX() << "," << (*it).getY() << ")" << endl; 

}

void Knn::createClusterSet() {

    vector<int> tempGroundTruth = getGroundTruth();
    vector<Node> tempData = getData();

    vector<int>::iterator groundIt = tempGroundTruth.begin();
    for(vector<Node>::iterator it=tempData.begin();it!=tempData.end();it++)
    {
        intpair x =  make_pair((*it).getId(),*groundIt);
        cluster.insert(x);
        groundIt++;
    }

}

vector<int> Knn::getGroundTruth() const{
    return groundTruth;
}

void Knn::printClusters() const{
    set<pair<int,int>> tempCluster = getClusters();

    for(set<pair<int,int>>::iterator it=tempCluster.begin();it!=tempCluster.end();it++)
    {
        cout << "Id: " << (*it).first << "\t" << "Class: " << (*it).second << endl;  
    }
}

set<pair<int,int>> Knn::getClusters() const{
    return cluster;
}


void Knn::printGroundTruth() const{
    vector<int> tempGroundTruth = getGroundTruth();

    for(vector<int>::iterator it=tempGroundTruth.begin();it!=tempGroundTruth.end();it++)
        cout << *it << "\t";
}