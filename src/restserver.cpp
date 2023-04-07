#include<restServer.h>


void RestServer::AddMethod(regex pattern, string httpMethod, function<void()> handler)
{
    //methods[pattern][httpMethod] = handler;

}


void RestServer::RunMethod(regex pattern, string httpMethod) const
{

}