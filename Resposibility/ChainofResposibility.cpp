#include <iostream>
#include <string>

using namespace std;

enum class RequestType {
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};


class Request
{
    string description;
    RequestType reqType;
public:
    Request(const string& desc, RequestType type) : description(desc), reqType(type) { }
    RequestType getReqType() const { return reqType; }
    
    const string& getDescription() const { return description; }
    
};

class ChainHandler {
    ChainHandler* nextChain;
    void sendReqestToNextHandler(const Request& req) {
        if (nextChain != nullptr)
            nextChain->handle(req);
    }
    
protected:
    virtual bool canHandlerRequest(const Request& req) = 0;
    virtual void processReques(const Request& req) = 0;
    
public:
    ChainHandler() { nextChain = nullptr; }
    void setNextChain(ChainHandler* next) { nextChain = next; }
    
    void handle(const Request& req) {
        if (canHandlerRequest(req))
            processReques(req);
        else
            sendReqestToNextHandler(req);
    }
    
};

class Handler1 : public ChainHandler {
protected:
    bool canHandlerRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }
    
    void processReques(const Request& req) override {
        cout << "Handler1 is handle request: " << req.getDescription() << endl;
    }
};


class Handler2 : public ChainHandler {
protected:
    bool canHandlerRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }
    
    void processReques(const Request& req) override {
        cout << "Handler2 is handle request: " << req.getDescription() << endl;
    }
    
};

class Handler3 : public ChainHandler {
protected:
    bool canHandlerRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }
    
    void processReques(const Request& req) override {
        cout << "Handler3 is handle request: " << req.getDescription() << endl;
    }
    
};


int main()
{
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);
    
    Request req("process task ... ", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}
