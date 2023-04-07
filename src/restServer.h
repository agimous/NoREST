#ifndef RESTSERVER
#define RESTSERVER

#include<map>
#include<regex>

using namespace std;

typedef map<pair<regex, string>, function<void()>> ServerAPI;

class RestServer
{
    ServerAPI methods;

public:
    //TODO: Fix arguments with const, &, &&, etc.
    void AddMethod(regex pattern, string httpMethod,function<void()>);
    void RemoveMethod(regex pattern, string httpMethod);
    void RunMethod(regex pattern, string httpMethod) const;
    

    

};

#endif
