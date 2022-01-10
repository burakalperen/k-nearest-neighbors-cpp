#include <iostream>
#include <string>
#include <ctime>
#include "Knn.h"
#include <map>
using namespace std;

// Knn sınıfındaki data sayısını const yap.


int main(){

    int k = 5;

    Knn algo(k);

    algo.start();

    // int k = 3;
    // vector<int> test(k,0);
    // multimap<double,int,less<double>> ne;

    // ne.insert({3,0});
    // ne.insert({4,0});
    // ne.insert({5.2,2});
    // ne.insert({2.1,1});
    // ne.insert({5.2,2});
    // ne.insert({5.2,2});
    // ne.insert({5.2,2});



    // multimap<double,int>::iterator it = ne.begin();
    // while(it!=ne.end())
    // {
    //     test[(*it).second]++;
    //     it++;
    // }

    // for(vector<int>::iterator it1=test.begin();it1!=test.end();it1++)
    //     cout << *it1 << "\t";



    return 0;
}
