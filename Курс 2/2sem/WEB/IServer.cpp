#include "IServer.h"
#include "MyServer.h"

IServer* CreateInstance()
{
    return new MyServer();
}