// 业务操作
class Stream {
public:
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    
    virtual ~Stream(){}
    
};


// 主体类
class FileStream: public Stream {
public:
    virtual char Read(int number) {
        // 读文件流
    }
    virtual void Seek(int position) {
        // 定位文件流
    }
    virtual void Write(char data) {
        // 写文件流
    }
    
};

class NetworkStream: public Stream {
public:
    virtual char Read(int number) {
        // 读网络流
    }
    virtual void Seek(int position) {
        // 定位网络流
    }
    virtual void Write(char data) {
        // 写网络流
    }
};

class MemoryStream : public Stream{
public:
    virtual char Read(int number) {
        // 读内存流
    }
    virtual void Seek(int position) {
        // 定位内存流
    }
    virtual void Write(char data) {
        // 写内存流
    }
    
};

// 扩展操作
class CrytoFileStream : public FileStream {
public:
    virtual char Read(int number) {
        // 额外的加密操作
        FileStream::Read(number);  // 读文件流
    }
    virtual void Seek(int position) {
        // 额外的加密操作
        FileStream::Seek(position);
        // 额外的加密操作
    }
    virtual void Write(char data) {
        // 额外的加密操作
        FileStream::Write(data);
        // 额外的加密操作
    }
};

class CrytoNetworkStream : public NetworkStream {
public:
    virtual char Read(int number) {
        // 额外的加密操作
        NetworkStream::Read(number);  // 读文件流
    }
    virtual void Seek(int position) {
        // 额外的加密操作
        NetworkStream::Seek(position);
        // 额外的加密操作
    }
    virtual void Write(char data) {
        // 额外的加密操作
        NetworkStream::Write(data);
        // 额外的加密操作
    }
};


class CrytoMemoryStream : public MemoryStream {
public:
    virtual char Read(int number) {
        // 额外的加密操作
        MemoryStream::Read(number);  // 读文件流
    }
    virtual void Seek(int position) {
        // 额外的加密操作
        MemoryStream::Seek(position);
        // 额外的加密操作
    }
    virtual void Write(char data) {
        // 额外的加密操作
        MemoryStream::Write(data);
        // 额外的加密操作
    }
};

class BufferedFileStream : public FileStream {
    // ...
};

class BufferedNetworkStream : public NetworkStream{
    // ...
};

class BufferedMemoryStream : public MemoryStream {
    // ...
};

class CrytoBufferedFileStream : public FileStream {
public:
    virtual char Read(int number) {
        // 额外的加密操作
        // 额外的缓冲操作
        FileStream::Read(number);  // 读文件流
    }
    virtual void Seek(int position) {
        // 额外的加密操作
        // 额外的缓冲操作
        FileStream::Seek(position);
        // 额外的加密操作
        // 额外的缓冲操作
    }
    virtual void Write(char data) {
        // 额外的加密操作
        // 额外的缓冲操作
        FileStream::Write(data);
        // 额外的加密操作
        // 额外的缓冲操作
    }
}

void Process() {
    // 编译时装配
    CrytoFileStream *fs1 = new CrytoFileStream();
    BufferedFileStream *fs2 = new BufferedFileStream();
    CrytoBufferedFileStream *f3 = new CrytoBufferedFileStream();
}




