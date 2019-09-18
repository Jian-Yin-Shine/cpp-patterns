
class TaxStrategy {
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context) {
        return 1; 
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context) {
        return 2;
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context) {
        return 3;
    }
};

class FRTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context) {
        return 4;
    }
};

class SalesOrder{
private:
    TaxStrategy* strategy;
public:
    SalesOrder(StrategyFactory* strategyFactory){
        this->strategy = strategyFactory->NewStrategy();    
    }
    ~SalesOrder() {
        delete this->strategy;    
    }

    double CalculateTax() {
        Context context();
        double val = strategy->Calculate(context);
    }
};
