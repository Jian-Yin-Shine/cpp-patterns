
// 数据库访问相关的基类
class IDBConnection {
    virtual void ConnectionString(string) = 0;
};

class IDBCommand {
    virtual void CommandText(string) = 0;
}

class IDBDataReader {
    virtual void Read() = 0;
};

// 工厂接口
class IDBFactory {
public:
    virtual IDBConnection* CreateDBConnection()=0;
    virtual IDBCommand* CreateDBCommand()=0;
    virtual IDataReader* CreateDataReader() = 0;
};


// 具体类
// 支持SQL Server
class SqlConnection : public IDBConnection {
public:
    virtual void ConnectionString(string) {
        // ...
    }
};

class SqlDBCommand : public IDBCommand {
public:
    virtual void CommandText(string) {
        // ...
    }
};

class SqlDataReader : public IDBDataReader {
    virtual void Read() {
        // ...
    }
};

// 具体工厂
class SqlFactory : public IDBFactory {
public:
    virtual IDBConnection* CreateIDBConnection() {
        return new SqlConnection;
    }
    virtual IDBCommand* CreateDBCommand() {
        return new SqlDBCommand;
    }
    virtual IDataReader* CreateDataReader() {
        return new IDataReader;
    }
};



class EmployeeDAO{
//    IDBConnectionFactory* dbConnectionFactory;
//    IDBCommandFactory* dbCommandFactory;
    IDBFactory* dbFactory;
public:
    vector<EmployeeDO> GetEmployees(){
//        SqlConnection* connection = new SqlConnection();
        IDBConnection* connection =  dbFactory->CreateIDBConnection();
        connection->ConnectionString("...");
        
//        SqlCommand* command = new SqlCommand();
        IDBCommand* command = dbFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); // 关联性
        
        
        IDBDataReader* reader = command->ExecuteReader(); // 关联性
        while (reader->Read()){
            
        }
        
    }
};

