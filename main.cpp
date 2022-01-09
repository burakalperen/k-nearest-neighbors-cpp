#include <iostream>
#include <string.h>
#include <time.h>
#include "Knn.h"

using namespace std;

// Knn sınıfındaki data sayısını const yap.


int main(){

    int k = 3;

    Knn algo(k);

    algo.start();



    /* test on vector */
    // vector<int> a;
    // a.push_back(1);
    // a.push_back(12);
    // a.push_back(3);
    // a.push_back(5);

    // for (vector<int>::iterator it = a.begin();it!=a.end();it++)
    //     cout << *it  << " ";

    // a.erase(a.begin() +2);

    // cout << "******************\n";

    // for (vector<int>::iterator it = a.begin();it!=a.end();it++)
    //     cout << *it << " ";

    //********************************************************************

    /* test on set */
    // set<pair<int,int>> a;

    // pair<int,int> x = make_pair(0,3);
    // pair<int,int> y = make_pair(1,5);
    // pair<int,int> z = make_pair(2,4);

    // a.insert(x);
    // a.insert(y);
    // a.insert(z);

    
    // for(set<pair<int,int>>::iterator c = a.begin();c!=a.end();c++){
    //     cout << (*c).first << " ";
    // }

    // set<pair<int,int>>::iterator most = max_element(a.begin(),a.end());
    
    // cout << "Most first: " << (*most).first << endl;
    // cout << "Most second: " << (*most).second << endl;

    return 0;
}
