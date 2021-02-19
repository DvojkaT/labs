#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int CheckFile();
double* NewArray(int);
void FillArray(double*, int);
void PrintArray(double*,int);
void menu(double*, int);
void t2(double*&,int&,int,double);
void t4(double*&,int&,int);
double CRNumber();

int main(){
double number;
int ArraySize=CheckFile();
if(!ArraySize){
    cout<<"File ERROR";
    return 0;
}
//Жирное меню
int pos;
double* arr=NewArray(ArraySize);
FillArray(arr,ArraySize);

    int choice;
    do{
    
        cout<<"Array: ";
        PrintArray(arr,ArraySize);
        cout<<"Choose task: ";cin>>choice;
        switch(choice){
            case 1:{
            number = CRNumber();
            t2(arr,ArraySize,ArraySize+1,number);
            break;
            }
            case 2:{
            number = CRNumber();
            t2(arr,ArraySize,1,number);
            break;
            }
            case 3:{
            cout<<"Choose position: ";cin>>pos;
            number = CRNumber();
            t2(arr,ArraySize,pos,number);
            break;
            }
            case 4:{
            t4(arr,ArraySize,ArraySize+1);
            break;
            }
            case 5:{
            t4(arr,ArraySize,1);
            break;
            }
            case 6:{
            cout<<"Choose position: ";cin>>pos;
            t4(arr,ArraySize,pos);
            break;
            }

    }
 }while(choice != 0);
 delete[] arr;
}


int CheckFile(){
int end;
int a=0;
ifstream file("File.txt");
while(file>>end)a++;
file.close();
return a;
}

double* NewArray(int a){
double* arr = new double[a];
return arr;
}

void FillArray(double* arr, int a){
    ifstream file("File.txt");
    for (int i=0;i<a;i++){
        file >> arr[i];
    }
    file.close();
}

void PrintArray(double* arr,int a){
    for(int i=0;i<a;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}


void t2(double*& arr,int &arraysize, int place, double number){
    place--;
    if (place>=0 && place<=arraysize+1){
        double* buff = new double[arraysize+1];
        for(int i=0;i<place;i++){
            buff[i] = arr[i];
        }
        buff[place]=number;
        arraysize++;
        for(int i=place+1;i<arraysize;i++){
           buff[i] = arr[i-1];
        }
        delete[] arr;
        arr=buff;
    }
    else(cout<<"Array ERROR");
}

void t4(double*& arr,int &arraysize, int place){
    place--;
    if (place>=0 && place<=arraysize+1){
        double* buff = new double[arraysize-1];
        for(int i=0;i<place;i++){
            buff[i] = arr[i];
        }
        arraysize--;
        for(int i=place;i<arraysize;i++){
           buff[i] = arr[i+1];
        }
        delete[] arr;
        arr=buff;
    }
    else(cout<<"Array ERROR");
}

double CRNumber(){
    double num;
    int pick;
    cout<<"1.Random number"<<endl<<"2.Write number"<<endl;
    cin>>pick;
    do{
        switch(pick){
            case 2:{
                cout<<"Write your number: "<<endl;
                cin>>num;
                return num;
            }
            case 1:{
            srand(time(0));
            num = -100+rand()%(200);
            return num;
            }
            case 3:{
                cout<<"ERROR, try again";
                break;
            }
        }    
    }while((pick != 1) || (pick != 2));
    return 0;
}