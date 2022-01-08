#include <iostream>
#include <string.h>
#include "Node.h"

using namespace std;



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




