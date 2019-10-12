
class MainFrom : public Form
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progressBar;
    
    SplitterFactory* factory;
public:
    
    MainFrom(SplitterFactory* factory) {
        this->factory = factory;
    }
    
    void Button1_Click() {
        ISplitter* splitter =
            factory->CreateSplitter(); // 多态new
        splitter->split();
    }
};
