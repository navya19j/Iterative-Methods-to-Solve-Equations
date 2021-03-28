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

        ofstream myfile1;
        myfile1.open("output1.txt");

    

    float val[n];
    int q=0;
    while (q<25){
        float err_1 = 0;
        float temp[n];
        float alp;
        for (int i=0;i<n;i++){
            alp = 0;
            for (int j=0;j<n;j++){
                if (j!=i){
                    alp+=arr[i][j]*values[j];
                }   
            }
            val[i] = (arr[i][n]-alp)/(arr[i][i]);
        }
        for (int k=0;k<n;k++){
            temp[k] = values[k];
            values[k] = val[k];
            err_1 += pow((abs(values[k]-temp[k])/values[k]),2);
        }
        q+=1;
        myfile1 << std::fixed;
        myfile1 << setprecision(10);
        myfile1 << "Error at iter " << q << " :" << sqrt(err_1) <<endl;
    }
}
