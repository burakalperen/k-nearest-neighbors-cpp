#include <iostream>
#include <string.h>
#include <map>
#include <set>
#include "math.h"
#include "Knn.h"
using namespace std;

int Knn::numberTrainData = 10;
int Knn::numberTestData = 5;

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
        // printGroundTruth();
        // cout << "\n********************" << endl;
        // inference();
}




void Knn::inference(){

    vector<Node> train = getTrainData();
    vector<Node> test = getTestData(); 
    vector<int> labels = getGroundTruth();

    multimap<double,int,less<double>> neighbors;
    vector<int> classCounter(3,0);
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

        multimap<double,int>::iterator it3 = neighbors.begin();
        while(it3!=neighbors.end())
        {
            classCounter[(*it3).second]++;
            it3++;
        }

        cout << "Class numbers: " << endl;
        for(vector<int>::iterator it2 = classCounter.begin();it2!=classCounter.end();it2++)
            cout << *it2 << "\t"; 

        predictions.push_back(max_element(classCounter.begin(),classCounter.end()) - classCounter.begin());
        printPredictions();
        neighbors.clear();
        fill(classCounter.begin(),classCounter.end(),0);

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
    if(i<3)
        hold = 0;
    else if(i<6)
        hold = 1;
    else if(i<30)
        hold = 2;
    i++;
    return hold;
}

void Knn::createRandomData(string who){

    int identity;
    double x,y;
    int i;
    int n = 0;
    
    if(who == "train") i = 0, n=getNumberofTrainData();
    else if(who == "test") i = getNumberofTrainData(), n = getNumberofTrainData() + getNumberofTestData();    

    for (; i < n; i++)
    {
        identity = i;
        x = (rand() % 9) - 4; // between -5 and 5
        y = (rand() % 9) - 4;

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

vector<int> Knn::getGroundTruth() const{
    return groundTruth;
}

vector<int> Knn::getPredictions() const{
    return predictions;
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
    vector<Node> tempData;
    
    if(who == "train") 
        tempData = getTrainData();
    else if(who == "test") 
        tempData = getTestData();

    cout << "\n" << who << " data:" << endl;
    for(vector<Node>::iterator it=tempData.begin(); it!=tempData.end();it++)
        (*it).print(); 

}

void Knn::printGroundTruth() const{
    vector<int> tempGroundTruth = getGroundTruth();
    cout << "\nTrain labels: " << endl;
    for(vector<int>::iterator it=tempGroundTruth.begin();it!=tempGroundTruth.end();it++)
        cout << *it << "\t";
}

void Knn::printPredictions() const{
    vector<int> tempPredictions = getPredictions();
    vector<Node> testdata = getTestData();
    
    cout << "\nPredictions: \n";
    vector<Node>::iterator it2 = testdata.begin();
    for(vector<int>::iterator it = tempPredictions.begin();it!=tempPredictions.end();it++)
    {   
        cout << "Test id: " << (*it2).getId() << "\t"  << "Class:" << (*it) << endl;
        it2++;
    }
}
