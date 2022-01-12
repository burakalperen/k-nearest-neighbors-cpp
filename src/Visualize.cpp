#include <iostream>
#include <vector>
#include "../include/Visualize.h"
#include "Node.h"
#include "matplot/matplot.h"

using namespace std;
using namespace matplot;

Visualize::Visualize(){
    cout << "Visualize object is created." << endl;
}

Visualize::~Visualize(){
    cout << "Visualize object is destroyed." << endl;
}

void Visualize::draw(const vector<Node> &train,const vector<Node> &test,const vector<int> &trainLabel, const vector<int> &testLabel)
{

    vector<int>::const_iterator trainLabelit = trainLabel.begin(); // keep train labels
    vector<int>::const_iterator testLabelit = testLabel.begin(); // keep test labels


    for(vector<Node>::const_iterator trainIt = train.begin();trainIt!=train.end();trainIt++){
        xCoordinates.push_back((*trainIt).getFeature1());
        yCoordinates.push_back((*trainIt).getFeature2());
        classColors.push_back(*trainLabelit);
        sizes.push_back(9);
        *trainLabelit++;
    }


    for(vector<Node>::const_iterator testIt = test.begin();testIt!=test.end();testIt++){
        xCoordinates.push_back((*testIt).getFeature1());
        yCoordinates.push_back((*testIt).getFeature2());
        classColors.push_back(*testLabelit);
        sizes.push_back(30);
        testLabelit++;
    }



    auto l = scatter(getXcoord(),getYcoord(),getSizes(),getColors());
    l->marker_face(true);
    show();

    string save_path = "plot.jpg";
    save(save_path);
    cout << "\n****************************" << endl;
    cout << "Plot saved: " << save_path << endl;    
    cout << "****************************" << endl;

}



//getter functions
vector<int> Visualize::getXcoord() const{
    return xCoordinates;
}

vector<int> Visualize::getYcoord() const{
    return yCoordinates;
}

vector<int> Visualize::getColors() const{
    return classColors;
}

vector<int> Visualize::getSizes() const{
    return sizes;
}











