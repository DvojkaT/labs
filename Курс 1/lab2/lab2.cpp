#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>
using namespace std;

double** NewArray(int N,int M);
int ArrSTOLB();
int ArrSTROK();
bool FillArr(double **arr,int N,int M);
void PrintArr(double** arr,int N,int M);
void DelArr(double** arr, int N, int M);
double opredl(double** arr,int N,int M);
void minor(double** arr,int N,int M, double &opred);
void chngln(double** arr,int N, int M,int k, double &opred);
bool Solve(double **arr, double *x, int N,int M,double &opred);
void otvet(double **arr,double *x,int N,int m,double opr);
void choose(double **arr,int N,int M);
void copy(double **&arr1,double **arr2,int N,int M);
bool obrat(double** arr,double **&reversed, int N, int M, double &opred);
void Mult(double** M1, double** M2, int n1, int m1, int n2, int m2);

int main(){
    double opred =1;
    int N = ArrSTROK();
    int M = ArrSTOLB();
    double** arr = NewArray(N,M);
    double* x = new double [N];
    double** rev = NewArray(N,N);
    double** arr2 = NewArray(N,M);
    choose(arr,N,M);
    PrintArr(arr,N,M);
    copy(arr,arr2,N,M);
    cout<<endl;
    Solve(arr,x,N,M,opred);
    PrintArr(arr,N,M);
    opred = opredl(arr,N,M);
    otvet(arr,x,N,M,opred);
    obrat(arr2,rev,N,M,opred);
    PrintArr(rev,N,N);
    //Mult(arr2,cop,N,M-1,N,N);
    DelArr(rev,N,N);
    DelArr(arr,N,M);
    DelArr(arr2,N,M);
    delete[] x;
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
            cout<<setw(15)<<arr[i][j];
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

double opredl(double** arr,int N,int M){
    double det=1;
    for (int i=0;i<N;i++){
        if (arr[i][i]==0) return 0;
        det*=arr[i][i]/pow(arr[i][i], N-1-i);
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

bool Solve(double **arr, double *x, int N,int M,double &opred){
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
  return true;
}

void otvet(double **arr,double *x,int N,int M,double opr){
    cout<<"Answer: ";
    for(int i=0; i<N;i++) cout<<x[i]<<"; "; 
    cout<<endl;
    cout<<"Opred: "<<opr<<endl;
}

void choose(double **arr,int N,int M){
    int ch;
    cout<<"1.File"<<endl<<"2.Random"<<endl<<"3.Gilbert"<<endl;
    cout<<"Choose variant: ";
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
         case 3:{
         for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
          if (j == (M - 1)) arr[i][j] = 1;
          else arr[i][j] = 1. / (i + j + 1);
      break;
    }
    }
}

void copy(double **&arr1,double **arr2,int N,int M){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            arr2[i][j]=arr1[i][j];
        }
}

bool obrat(double** arr,double **&reversed, int N, int M, double &opred){
  double *x = new double [N];
  bool metka=true;
  for(int i = 0; i < N; i++)
  {
    double** buff;
    buff = NewArray(N,M);
    copy(arr, buff, N, M);
    for(int j = 0; j < N; j++)
    {
      if (i == j) buff[j][M - 1] = 1;
      else buff[j][M - 1] = 0;
    }
    if (!Solve(buff,x,N,M,opred)) metka = false;
    for(int j = 0; j < N; j++)
      reversed[j][i] = x[j];
    DelArr(buff, N, M);
  }
  delete [] x;
  x = NULL;
  return metka;
}

void Mult(double** M1, double** M2, int n1, int m1, int n2, int m2)
{
  double** buff = NewArray(n1,m1);
  double S;
  if(m1 != n2)
  {
    cout << "error" << endl;
    DelArr(buff, n1, m2);
  }
  for(int i = 0; i < n1; i++)
    for(int j = 0; j < m2; j++)
    {
      S = 0;
      for(int k = 0; k < m1; k++)
        S += M1[i][k] * M2[k][j];
      buff[i][j] = S;
    }
  PrintArr(buff, n1, m2);
  DelArr(buff, n1, m2);
}