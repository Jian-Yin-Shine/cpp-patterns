
class NetworkState {
public:
    NetworkState* nNext;
    virtual void Operation1()=0;
    virtual void Operation2()=0;
    virtual void Operation3()=0;
    
    virtual ~NetworkState(){}
};

class OpenState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getINstance() {
        if (m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }
    
    void Operation1() {
        // ******
        pNext = CloseState::getINstance();
    }
    
    void Operation2() {
        // ......
        pNext = CloseState::getINstance();
    }
    
    void Operation3() {
        // $$$$$$
        pNext = CloseState::getINstance();
    }
};

class CloseState : public NetworkState {
    
};


class NetworkProcessor {
    NetworkState* pState;
public:
    void Operation1() {
        // ...
        pState->Operation1();
        pState = pState->pNext;
        // ...
    }
    
    void Operation2() {
        // ...
        pState->Operation2();
        pState = pState->pNext;
        // ...
    }
    
    
    void Operation3() {
        // ...
        pState->Operation3();
        pState = pState->pNext;
        // ...
    }
    
};
