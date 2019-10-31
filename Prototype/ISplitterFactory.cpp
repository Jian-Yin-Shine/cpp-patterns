
class ISplitter {
public:
    virtual void split()=0;
    virtual ISplitter* clone()=0;
    virtual ~ISplitter() {}
};


// 工厂接口
//class SplitterFactory {
//public:
//    virtual ISplitter* CreateSplitter()=0;
//    virtual ~SplitterFactory() {}
//};
