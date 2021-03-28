#include <iostream>
using namespace std;
#include <string>
#include<math.h>
#include <fstream>
#include<iomanip>

int main(){
    int n; //number of rows of matrix.
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
    }
    int i;
    double k;
    i = 0;
    inFile >> n;
    double arr[n][n+1];

    while (inFile){
        for (int i=0 ; i<n ; i++){
            for (int j=0; j<n+1 ; j++){
                inFile>>arr[i][j];
            }
    }
    }
    inFile.close();
    inFile.open("initialguess.txt");
    if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
    }
    float values[n];
    while (inFile){
        for (int i=0; i<n;i++){
            inFile>>values[i];
        }
    }
    
    //Gauss Siedel
    double e_tol = pow(10,-6);
    bool flag = true;
    for (int i=0;i<n;i++){
        double check =0 ;
        for (int j=0;j<n;j++){
            if (j!=i){
                check+=arr[i][j];
            }
        }
        if (arr[i][i]>=check){
            flag = true;
        }
        else{
            flag = false;
        }
        }
    if (flag == false){
        cout << "Matrix not diagonal dominant";
    }
    float err_new = 100;
    while (err_new > e_tol){
    float temp;
    float alp;
    for (int i=0;i<n;i++){
         temp = values[i];
         alp = 0;
        for (int j=0;j<n;j++){
            if (j!=i){
                alp+=arr[i][j]*values[j];
            }   
        }
        values[i] = (arr[i][n]-alp)/(arr[i][i]);
        err_new = (abs(values[i]-temp))/(temp);
    }

    }
    for (int i=0; i<n;i++){
        cout<<values[i]<<endl;
    }

    }

    
