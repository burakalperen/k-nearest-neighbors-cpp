#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
#include "Knn.h"
#include <set>
#include <map>
#include <algorithm>
using namespace std;

/*
    labelları set yap -> generate kullanamıyoruz
    throw exception geliştir ++
    operator overloading ++
    görselleştirme

*/

int callback(int a,int b){
    return a + b;
}



int main(){

    int k; // number of neighbors

    try{
        cout << "Enter k:";
        cin >> k;
        if(k>0){
            Knn algo(k);
            algo.start();
        }
        else
            throw invalid_argument("K value must be greate than 0.");
    }
    catch(invalid_argument &e){
        cout << "Exception: " << e.what() << endl;
        return 0;
    }


    // vector<int> foo;
    // vector<int> bar;
    // vector<int> result;

    // foo.push_back(10);
    // foo.push_back(20);
    // foo.push_back(30);

    // bar.push_back(5);
    // bar.push_back(5);
    // bar.push_back(5);

    // // bar.resize(foo.size());
    // result.resize(foo.size());
    
    // transform (foo.begin(), foo.end(), bar.begin(), result.begin(),callback);

    // for(vector<int>::iterator it=result.begin();it!=result.end();it++)
    //     cout << *it;

    



    return 0;
}
