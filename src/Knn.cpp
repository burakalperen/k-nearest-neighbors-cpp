#include <iostream>
#include <string.h>
#include <map>
#include <set>
#include "math.h"
#include "../include/Knn.h"

using namespace std;

Knn::Knn(int clusterNumber): k(clusterNumber),trainLabels(numberTrainData)
{
    
    generate(trainLabels.begin(),trainLabels.end(),assingLabel); // assign class for train data
    cout << "Knn constructer is called." << endl;
}


Knn::~Knn(){

    cout << "Knn object is destroyed." << endl;

}

void Knn::start(){
        createRandomData("train"); //create train data
        createRandomData("test"); // create test data
        
        printData("train");
        printData("test");
        
        inference();
}




void Knn::inference(){

    const vector<Node> &train = getTrainData();
    const vector<Node> &test = getTestData(); 
    const vector<int> &labels = getTrainLabels();

    multimap<double,int,less<double>> neighbors; // map sorted according to distance
    vector<int> classCounter(3,0); // keep class counters(how many are there classes for k neighbors)
    double distance;

    for(vector<Node>::const_iterator testIt = test.begin(); testIt!=test.end();testIt++)
    {
        //cout << "\nTest data id:" << (*testIt).getId() << endl;

        for(vector<Node>::const_iterator trainIt = train.begin(); trainIt!=train.end();trainIt++)
        {
            // cout << "\nTrain id: " << (*trainIt).getId() << endl;
            // cout << "Class label: " << labels.at((trainIt - train.begin())); 
            distance = CalculateEuclidean((*trainIt).getFeature1(),(*trainIt).getFeature2(),(*testIt).getFeature1(),(*testIt).getFeature2()); // calc euclidean distance
            if(neighbors.size() < k) // just push k number
            {
                neighbors.insert({distance,labels.at((trainIt - train.begin()))});
            }
            else
            {
                neighbors.insert({distance,labels.at((trainIt - train.begin()))}); // push new item
                neighbors.erase(prev(neighbors.end())); // delete last item, last item has maximum distance because of multimap sort(less<double>).

            }
        }

        // DEBUG
        // cout << "\nNeighbors map: " << endl;
        // for(multimap<double,int>::iterator it=neighbors.begin();it!=neighbors.end();it++)
        // {
        //     cout << "Class: " << (*it).second << " Dist: " << (*it).first << endl;
        // }

        multimap<double,int>::iterator it3 = neighbors.begin();
        while(it3!=neighbors.end())
        {
            classCounter[(*it3).second]++;
            it3++;
        }

       
        testLabels.push_back(max_element(classCounter.begin(),classCounter.end()) - classCounter.begin()); // get max frequency class from k neighbors.
        neighbors.clear(); // delete neigbors for next test sample
        fill(classCounter.begin(),classCounter.end(),0); // clear class counter vector

    }
    printTestLabels();

}


double Knn::CalculateEuclidean(const double &x1, const double &y1, const double &x2, const double &y2){
    /*

    Method to compute calculate euclidean distance between two points.
    @arg x1 first point x
    @arg y1 first point y
    @arg x2 second point x
    @arg y2 second point y  
    @returns euclidean distance

    */
    return sqrt( pow((x1-x2),2) + pow((y1-y2),2));
}

int Knn::assingLabel()
{
    /*
    Callback function for generate algorithm
    */

    static int i=0;
    int hold;
    if(i<10)
        hold = 0;
    else if(i<20)
        hold = 1;
    else if(i<30)
        hold = 2;
    i++;
    return hold;
}

void Knn::createRandomData(string who){

    /*
    Create random data features for train and test samples.
    */

    int identity;
    double x,y;
    int i;
    int n = 0;
    
    if(who == "train") i = 0, n=getNumberofTrainData();
    else if(who == "test") i = getNumberofTrainData(), n = getNumberofTrainData() + getNumberofTestData();    

    for (; i < n; i++)
    {
        identity = i;
        //x = (rand() % 9) - 4.0; // between -5 and 5
        //y = (rand() % 9) - 4.0;
        x = -5 + (double)(rand()) / ((double)(RAND_MAX / (10)));
        y = -5 + (double)(rand()) / ((double)(RAND_MAX / (10)));


        if(who == "train") trainData.push_back(Node(identity,x,y));
        else if(who == "test") testData.push_back(Node(identity,x,y));
    }

}


// GET FUNCTIONS

vector<Node> Knn::getTrainData() const
{
    return trainData;
}

vector<Node> Knn::getTestData() const
{
    return testData;
}

vector<int> Knn::getTrainLabels() const{
    return trainLabels;
}

vector<int> Knn::getTestLabels() const{
    return testLabels;
}


int Knn::getK() const{
    return k;
}

int Knn::getNumberofTrainData() const{

    return numberTrainData;
}

int Knn::getNumberofTestData() const{

    return numberTestData;
}



// PRINT FUNCTIONS
void Knn::printData(string who){
    vector <Node> tempData;
    if(who == "train") 
        tempData = getTrainData();
    else if(who == "test") 
        tempData = getTestData();

    cout << "\n" << who << " data:" << endl;
    for(vector<Node>::iterator it=tempData.begin(); it!=tempData.end();it++)
        cout << (*it); //operator overloading
}

void Knn::printTrainLabels() const{
    const vector<int> &localTrainLabels = getTrainLabels();
    cout << "\nTrain labels: " << endl;
    for(vector<int>::const_iterator it=localTrainLabels.begin();it!=localTrainLabels.end();it++)
        cout << *it << "\t"; //operator overloading
}

void Knn::printTestLabels() const{
    const vector<int> &localTestLabels = getTestLabels();
    const vector<Node> &testdata = getTestData();
    
    cout << "\nPredictions: \n";
    vector<Node>::const_iterator it2 = testdata.begin();
    for(vector<int>::const_iterator it = localTestLabels.begin();it!=localTestLabels.end();it++)
    {   
        cout << "Test id: " << (*it2).getId() << "\t"  << "Class:" << (*it) << endl;
        it2++;
    }
}
