#include <stdio.h>
#include "IServer.h"

class MyServer : public IServer
{
    private:
    int a,b;
    public:
    void Func();
    MyServer();
    ~MyServer();
};