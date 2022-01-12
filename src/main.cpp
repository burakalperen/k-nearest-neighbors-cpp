#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
#include "../include/Knn.h"
#include "../include/Visualize.h"
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

    srand(time(NULL));

    int k; // number of neighbors


    // if we set 
    // try{
    //     cout << "Enter k:";
    //     cin >> k;
    //     if(k>0){
    //        cout << "Algorithm is starting." << endl;  
    //     }
    //     else
    //         throw invalid_argument("K value must be greate than 0.");
    // }
    // catch(invalid_argument &e){
    //     cout << "Exception: " << e.what() << endl;
    //     return 0;
    // }

    k = 3;

    Knn algo(k); //create object for knn algoritm
    algo.start(); // do inference
    Visualize visualizer; // create object for visualizition the inference results.
    visualizer.draw(algo.getTrainData(),algo.getTestData(),algo.getTrainLabels(), algo.getTestLabels()); // draw plot
    

    
    



    return 0;
}
