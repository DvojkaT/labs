#include <iostream>
#include "MyServer.h"
using namespace std;

void MyServer::Func(){
    cout<<a+b;
};

MyServer::MyServer()
{
    a = 3;
    b = 3;
};

MyServer::~MyServer(){};