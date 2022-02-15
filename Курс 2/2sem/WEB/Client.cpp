#include "IServer.h"

int main()
{
    IServer* s= CreateInstance();
    s->Func();
    return 0;
};