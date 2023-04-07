#include<iostream>
#include<restServer.h>
#include<regexDictionary.h>

using namespace std;
int main()
{
    
    RegexDictionary serverDict;

    serverDict.Add(".*","POST",[](){});
    serverDict.Add("[^.*]","GET",[](){});

    serverDict(".[123455]","PUT") = [](){ cout << "hello1" << endl;};
    serverDict(".[123456]","PUT") = [](){ cout << "hello2" << endl;};
    serverDict(".[123457]","PUT");
    serverDict(".[123456]","PUT");

    serverDict.Print();
    //funcDict.Add(regex(".*"),"agis",[](){});
    //funcDict.Print();
    serverDict(".[123456]","PUT")();




    return 0;
}