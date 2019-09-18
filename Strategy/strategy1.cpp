enum TaxBase {
    CN_Tax;
    US_Tax;
    DE_Tax;
    FR_Tax;
};

class SalesOrder {
    TaxBase tax;
public:
    double CalculateTax() {
        if(tax == CN_Tax) {
            return 1;     
        }
        else if (tax == US_Tax) {
            return 2;
        }
        else if (tax == DE_Tax) {
            return 3;
        }
        else if (tax == FR_Tax) {
            return 4;
        }
    }
};

