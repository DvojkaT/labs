#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

double** NewArray(int N,int M);
int ArrSTOLB();
int ArrSTROK();
bool FillArr(double **arr,int N,int M);
void PrintArr(double** arr,int N,int M);
void DelArr(double** arr, int N, int M);
double opred(double** arr,int N,int M);
void minor(double** arr,int N,int M, double &opred);
void chngln(double** arr,int N, int M,int k, double &opred);
void Solve(double **arr, double *x, int N,int M,double &opred);
void otvet(double *x,int N, double opred);
void choose(double **arr,int N,int M);

int main(){
    double opred =1;
    int N = ArrSTROK();
    int M = ArrSTOLB();
    double** arr = NewArray(N,M);
    double* x = new double [N];
    choose(arr,N,M);
    PrintArr(arr,N,M);
    cout<<endl;
    Solve(arr,x,N,M,opred);
    PrintArr(arr,N,M);
    otvet(x,N,opred);
    DelArr(arr,N,M);
    return 0;   
}

int ArrSTROK(){
    int t;
    cout<<"Enter amount of lines: ";
    cin>>t;
    return t;
}

int ArrSTOLB(){
    int t;
    cout<<"Enter amount of columns: ";
    cin>>t;
    return t;
}

bool FillArr(double **arr,int N,int M){
    ifstream f("File.txt");
    if(!f) return false;
    for (int i = 0; i < N; i++)
        for(int j=0; j < M;j++)
            f>>arr[i][j];
    f.close();
    return true;
}

double** NewArray(int N,int M){
    double** arr = new double* [N];
    for (int i = 0; i <= N-1; i++)
    {
        arr[i] = new double [M];
    }
    return arr;
}

void PrintArr(double** arr,int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}

void DelArr(double** arr, int N, int M){
    for(int i = 0; i<N; i++){
        delete[] arr[M];
    }
    delete[] arr;
}

double opred(double** arr,int N,int M){
    double det=1;
    for (int i=0;i<N;i++){
        if (arr[i][i]==0) return 0;
        det*=arr[i][i]/pow(arr[i][i], N-i-1);
    }
    return det;
}

void minor(double** arr,int N,int M, double &opred){
    for(int i=0;i<N;i++){
        if(arr[i][i]==0) chngln(arr,N,M,i,opred);
        for(int j=i+1;j<N;j++){
            for(int k=i+1;k<M;k++){
                arr[j][k]=arr[i][i]*arr[j][k] - arr[i][k]*arr[j][i];
            }
        }
        for(int j =i+1;j<N;j++){
            arr[j][i]=0;
        }
    }
}

void chngln(double** arr,int N, int M,int k, double &opred){
    double t;
    for(int i=k+1;i<N;i++){
        if (arr[i][k]!=0){
            for(int j=0;j<M;j++){
                t=arr[k][j];
                arr[k][j]=arr[i][j];
                arr[i][j]=t;
            }
            opred*=-1;
            break;
        }
    }
}

void Solve(double **arr, double *x, int N,int M,double &opred){
    minor(arr,N,M,opred);
  double res = 0;
  for(int i = N - 1; i >= 0; i--)
  {
    res = 0;
    for(int j = i + 1; j <= N - 1; j++)
      res = res - x[j] * arr[i][j];
    res += arr[i][N];
    x[i] = res / arr[i][i];
  }
}

void otvet(double *x,int N,double opred){
    cout<<"Answer: ";
    for(int i=0; i<N;i++) cout<<x[i]<<"; "; 
    cout<<endl;
    cout<<"Opred: "<<opred;
}

void choose(double **arr,int N,int M){
    int ch;
    cout<<"Choose variants";
    cin>>ch;
    switch(ch)
    {
        case 1:{
                ifstream f("File.txt");
                for (int i = 0; i < N; i++)
                for(int j=0; j < M;j++)
                f>>arr[i][j];
                f.close();
                break;
        }
        case 2:{
            srand(time(0));
            for(int i=0;i<N;i++)
                for(int j=0;j<M;j++){
                    arr[i][j] = -10 + rand() % 10;
                }
            break;
        }
    }
}