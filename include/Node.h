#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <string.h>

using namespace std;

class Node{

    friend ostream &operator<<(ostream &, const Node &); //operator overloading

    public:
        Node(int,double,double);
        ~Node();

        int getId() const;
        double getFeature1() const;
        double getFeature2() const;
        
    private:
        const int id;
        const double feature1;
        const double feature2;
        



};

#endif