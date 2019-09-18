#include "template2_lib.cpp"
#include <iostream>

using namespace std;

class Application : public Library
{
protected:
    virtual bool Step2() {
        cout << "override Step2" << endl;
        return true;
    }
    
    virtual bool Step4() {
        cout << "override Step4" << endl;    
        return true;
    }
};

int main() 
{
    Library *pLib = new Application();
    pLib->Run();
    
    delete pLib;
    return 0;    
}
