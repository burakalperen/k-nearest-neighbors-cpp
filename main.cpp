#include <iostream>
#include <string.h>
#include <time.h>
#include "Knn.h"

using namespace std;

// Knn sınıfındaki data sayısını const yap.


int main(){



    Knn algo;
    algo.createRandomData();
    algo.printData();

    cout << "********************" << endl;

    algo.printGroundTruth();

    cout << "\n********************" << endl;
    algo.createClusterSet();
    algo.printClusters();

    return 0;
}
