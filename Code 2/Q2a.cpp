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
    ofstream myfile;
        myfile.open("output.txt");
        
    int p=0;
    while (p<25){
    float temp;
    float alp;
    float err_new;
    float err = 0;
    for (int i=0;i<n;i++){
        temp = values[i];
        alp = 0;
        for (int j=0;j<n;j++){
            if (j!=i){
                alp+=arr[i][j]*values[j];
            }   
        }
        values[i] = (arr[i][n]-alp)/(arr[i][i]);
        err_new = (abs(values[i]-temp)/values[i]);
        err+=pow(err_new,2);
        }
        p+=1;
        myfile << std::fixed;
        myfile << setprecision(10);
        myfile << "Error at iter " << p << " :" << sqrt(err) <<endl;
    }
    myfile.close();

    
    }

    
