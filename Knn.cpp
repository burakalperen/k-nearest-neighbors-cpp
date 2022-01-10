#include <iostream>
#include <string.h>
#include <map>
#include "math.h"
#include "Knn.h"
using namespace std;

typedef pair<int,int> intpair;


int Knn::numberTrainData = 5;
int Knn::numberTestData = 3;



Knn::Knn(int k): k(k),groundTruth(numberTrainData)
{

    generate(groundTruth.begin(),groundTruth.end(),assingLabel);
    cout << "Knn constructer is called." << endl;


}


Knn::~Knn(){

    cout << "Knn destructor is called." << endl;

}

void Knn::start(){
        createRandomData("train"); //create train data
        createRandomData("test"); // create test data
        
        printData("train");
        printData("test");
        printGroundTruth();
        cout << "\n********************" << endl;

        createClusterSet();

        inferencev2();
        printClusters();
}




void Knn::inferencev2(){


    vector<Node> train = getTrainData();
    vector<Node> test = getTestData(); 
    vector<int> labels = getGroundTruth();

    multimap<double,int,less<double>> neighbors;
    vector<int> classCounter;
    double distance;

    for(vector<Node>::iterator testIt = test.begin(); testIt!=test.end();testIt++)
    {
        cout << "\nTest data id:" << (*testIt).getId() << endl;

        for(vector<Node>::iterator trainIt = train.begin(); trainIt!=train.end();trainIt++)
        {
            cout << "\nTrain id: " << (*trainIt).getId() << endl;
            distance = CalculateEuclidean((*trainIt).getX(),(*trainIt).getY(),(*testIt).getX(),(*testIt).getY());
            cout << "Distance: " << distance << endl;
            if(neighbors.size() < k)
            {
                neighbors.insert({distance,labels.at((trainIt - train.begin()))});
            }
            else
            {
                neighbors.insert({distance,labels.at((trainIt - train.begin()))});
                neighbors.erase(prev(neighbors.end()));

            }
        }

        cout << "\nNeighbors map: " << endl;
        for(multimap<double,int>::iterator it=neighbors.begin();it!=neighbors.end();it++)
        {
            cout << "Class: " << (*it).second << " Dist: " << (*it).first << endl;
        }

        for(int i = 0; i<k; i++)
        {   
            int counter = 0;
            for(multimap<double,int>::iterator it=neighbors.begin(); it!= neighbors.end(); it++)
            {   
                if((*it).second == i)
                {
                    counter++;
                }
            }

            classCounter.push_back(counter);

        }

        for(vector<int>::iterator it2 = classCounter.begin();it2!=classCounter.end();it2++)
            cout << *it2 << "\t"; 

        predictions.push_back(max_element(classCounter.begin(),classCounter.end()) - classCounter.begin());


        printPredictions();
        // cout << "\nPredictions vector: " << endl;
        // for(vector<int>::iterator it3 = predictions.begin();it3!=predictions.end();it3++)
        //     cout << *it3 << "\t"; 

        neighbors.clear();
        classCounter.clear();


    }

}


double Knn::CalculateEuclidean(const double x1, const double y1, const double x2, const double y2){
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
    static int i=0;
    int hold;
    if(i<2)
        hold = 0;
    else if(i<3)
        hold = 1;
    else if(i<30)
        hold = 2;
    i++;
    return hold;
}

void Knn::createRandomData(string inf){

    int identity;
    double x,y;
    int i;
    int n = 0;
    
    if(inf == "train") i = 0, n=getNumberofTrainData();
    else if(inf == "test") i = getNumberofTrainData(), n = getNumberofTrainData() + getNumberofTestData();    

    for (; i < n; i++)
    {
        identity = i;
        x = (rand() % 9) - 4; // between -5 and 5
        y = (rand() % 9) - 4;

        if(inf == "train") trainData.push_back(Node(identity,x,y));
        else if(inf == "test") testData.push_back(Node(identity,x,y));
    }

}

void Knn::createClusterSet() {

    vector<int> tempGroundTruth = getGroundTruth();
    vector<Node> tempData = getTrainData();

    vector<int>::iterator groundIt = tempGroundTruth.begin();
    for(vector<Node>::iterator it=tempData.begin();it!=tempData.end();it++)
    {
        intpair x =  make_pair((*it).getId(),*groundIt);
        cluster.insert(x);
        groundIt++;
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

vector<int> Knn::getGroundTruth() const{
    return groundTruth;
}

vector<int> Knn::getPredictions() const{
    return predictions;
}

set<pair<int,int>> Knn::getClusters() const{
    return cluster;
}

int Knn::getNumberofTrainData() const{

    return numberTrainData;
}

int Knn::getNumberofTestData() const{

    return numberTestData;
}

int Knn::getK() const{
    return k;
}

// PRINT FUNCTIONS
void Knn::printData(string dec){
    vector<Node> tempData;
    
    if(dec == "train") 
        tempData = getTrainData();
    else if(dec == "test") 
        tempData = getTestData();

    cout << "\n" << dec << " data:" << endl;
    for(vector<Node>::iterator it=tempData.begin(); it!=tempData.end();it++)
        cout << "(" <<(*it).getId() << "," << (*it).getX() << "," << (*it).getY() << ")" << endl; 

}


void Knn::printGroundTruth() const{
    vector<int> tempGroundTruth = getGroundTruth();
    cout << "\nTrain labels: " << endl;
    for(vector<int>::iterator it=tempGroundTruth.begin();it!=tempGroundTruth.end();it++)
        cout << *it << "\t";
}


void Knn::printPredictions() const{
    vector<int> tempPredictions = getPredictions();
    cout << "\nPredictions: \n";
    for(vector<int>::iterator it = tempPredictions.begin();it!=tempPredictions.end();it++)
        cout << (*it) << "\t";
}


void Knn::printClusters() const{
    set<pair<int,int>> tempCluster = getClusters();
    cout << "\nAll data and labels: "<< endl;
    for(set<pair<int,int>>::iterator it=tempCluster.begin();it!=tempCluster.end();it++)
    {
        cout << "Id: " << (*it).first << "\t" << "Class: " << (*it).second << endl;  
    }
}
