#include <iostream>
#include <string.h>
#include "../include/Node.h"

using namespace std;



ostream &operator<<(ostream &output, const Node &object)
{
    output << "(" << object.getId() << "," << object.getFeature1() << "," << object.getFeature2() << ")" << endl;
    return output;
}


Node::Node(int n, double x, double y):id(n),feature1(x),feature2(y)
{

}


Node::~Node(){

}



// get functions
int Node::getId() const{
    return id;
}

double Node::getFeature1() const{
    return feature1;
}

double Node::getFeature2() const{
    return feature2;
}



