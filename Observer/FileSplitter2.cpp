class IProgress{
public:
    virtual void DoProgress(float value)=0;
    virtual ~IProgress()
};

class FileSplitter
{
    string m_filePath;
    int m_fileNumber;

    List<IProgress* > m_iprogresslist; // 抽象通知机制，支持多个观察者

public:
    FileSplitter(const string& filepath, int fileNumber) : 
        m_filePath(filepath), 
        m_fileNumber(fileNumber) {}
    
    void split() {
        
        // 1. 读取大文件

        // 2. 分批次向小文件中写入
        for (int i = 0; i < m_fileNumber; ++i) {
            onProgress(float(i + 1) / m_fileNumber); // 发送通知  
        }
    }
    
    void addIProgress(IProgress* iprogress) {
        m_iprogresslist.push_back(iprogress);    
    }

    void removeIProgress(IProgress* iprogress) {
        m_iprogresslist.remove(iprogress);    
    }

protected:
    void onProgress(float value) {
        List<IProgress*>:: itor = m_iprogresslist.begin();
        while(itor != m_iprogresslist.end() ) {
            (*itor)->DoProgress(value);
            itor++;    
        }
    }

};
