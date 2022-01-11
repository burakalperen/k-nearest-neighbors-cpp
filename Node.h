#ifndef NODE
#define NODE_H


#include <iostream>
#include <string.h>

using namespace std;

class Node{

    friend ostream &operator<<(ostream &, const Node &);

    public:
        Node(int,double,double);
        ~Node();

        int getId() const;
        double getX() const;
        double getY() const;
        
        void print() const;

    private:
        const int id;
        const double x;
        const double y;
        



};

#endif