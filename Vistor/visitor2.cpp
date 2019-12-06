#include <iostream>

using namespace std;

class Vistor;

class Element
{
public:
    virtual void accept(Vistor& vistor) = 0;    // 第一次动态调用
    
    virtual void Func1() = 0;
    
    virtual void Func2(int data) = 0;
    virtual void Func3(int data) = 0;
    // ...
    
    virtual ~Element() { }
};

class ElementA : public Element
{
public:
    void Fun1() override {
        // ...
    }
    void Func2(int data) override {
        // ...
    }
    
    void accept(Vistor& vistor) override {
        vistor.vistorElementA(*this);
    }
    
};


class ElementB : public Element
{
public:
    void Fun1() override {
        // ...
    }
    void Func2(int data) override {
        // ...
    }
    
    void accept(Vistor& vistor) override {
        vistor.vistorElementB(*this);   // 第二次动态调用
    }
};

class Vistor {
public:
    virtual void vistorElementA(ElementA& element) = 0;
    virtual void vistorElementB(ElementB& element) = 0;
};


// ============================
// 新需求
class Vistor1 : public Vistor {
public:
    void vistorElementA(ElementA& element) override {
        cout << "Visitor1 is processing ElementA" << endl;
    }
    void vistorElementB(ElementB& element) override {
        cout << "Visitor1 is processing ElementB" << endl;
    }
};

class Vistor2 : public Vistor {
public:
    void vistorElementA(ElementA& element) override {
        cout << "Visitor2 is processing ElementA" << endl;
    }
    void vistorElementB(ElementB& element) override {
        cout << "Visitor2 is processing ElementB" << endl;
    }
};


int main()
{
    Vistor2 vistor;
    ElementB elementB;
    
    elementB.accept(vistor);
    
    return 0;
}
