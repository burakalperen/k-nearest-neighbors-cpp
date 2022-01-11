#include <iostream>
#include <string.h>
#include "Node.h"

using namespace std;



ostream &operator<<(ostream &output, const Node &object)
{
    output << "(" << object.getId() << "," << object.getX() << "," << object.getY() << ")" << endl;
    return output;
}


Node::Node(int n, double x, double y):id(n),x(x),y(y)
{

}


Node::~Node(){

}



// get functions
int Node::getId() const{
    return id;
}

double Node::getX() const{
    return x;
}

double Node::getY() const{
    return y;
}

void Node::print() const{
    cout << "(" << getId() << "," << getX() << "," << getY() << ")" << endl; 
    //cout << 
}


