#include <iostream>
#include <string.h>
#include <time.h>
#include "Knn.h"

using namespace std;

// Knn sınıfındaki data sayısını const yap.


int main(){

    // int k = 3;

    // Knn algo(k);

    // algo.start();

    vector<int> a;
    a.push_back(1);
    a.push_back(12);
    a.push_back(3);
    a.push_back(5);

    for (vector<int>::iterator it = a.begin();it!=a.end();it++)
        cout << *it  << " ";

    a.erase(a.begin() +2);

    cout << "******************\n";

    for (vector<int>::iterator it = a.begin();it!=a.end();it++)
        cout << *it << " ";




    return 0;
}
