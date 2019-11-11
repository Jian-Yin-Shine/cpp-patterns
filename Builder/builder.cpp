
class House {
    //...
};

class HouseBuilder {
public:
    House* GetResult() {
        return pHouse;
    }
    virtual ~HouseBuiler() {}
protected:
    
    House* pHouse;
    virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual void BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
};

class StoreHouse: public House {
    
};


class StoreHouseBuilder: public HouseBuilder {
protected:
    virtual void BuildPart1() {
        //
    }
    virtual void BuildPart2() {
        
    }
    virtual void BuildPart3() {
        
    }
    virtual void BuildPart4() {
        
    }
    virtual void BuildPart5() {
        
    }
};

class HouseDirector  {
public:
    HouseBuilder* pHouseBuilder;
    
    HouseDirector(HouseDirector* pHouseDirector) {
        this->pHouseBuilder = pHouseBuilder;
    }
    
    House* Construct() {
        pHouseBuilder->BuildPart1();
        
        for (int i = 0; i < 4; i++) {
            pHouseBuilder->BuildPart2();
        }
        
        bool flag = pHouseBuilder->BuildPart3();
        
        if(flag) {
            pHouseBuilder->BuildPart4();
        }
        
        pHouseBuilder->BuildPart5();
        
        return pHouseBuilder->GetResult();
        
    }
    
};

