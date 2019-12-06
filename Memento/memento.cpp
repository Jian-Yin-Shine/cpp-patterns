
#include <iostream>
#include <string>

using namespace std;

class Memento
{
    string state;
    //...
public:
    Memento(const string& s) : state(s) { }
    string getState() const { return state; }
    void setState(const string& s) { state = s; }
};

class Originator {
    string state;
    // ...
public:
    Originator() { }
    Memento createMomento() {
        Memento m(state);
        return m;
    }
    
    void setMomento(const Memento& m) {
        state = m.getState();
    }
    
};

int main()
{
    Originator originator;
    
    // 捕捉对象状态，存储到备忘录
    Memento mem = originator.createMomento();
    
    // ... 改变orginator状态
    originator.setMomento(mem);
    
    return 0;
}
