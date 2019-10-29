
// 数据库访问相关的基类
class IDBConnection {
    virtual void ConnectionString(string) = 0;
};

// 工厂接口
class IDBConnectionFactory {
    virtual IDBConnection* CreateDBConnection()=0;
}

class IDBCommand {
    virtual void CommandText(string) = 0;
}

class IDBCommandFactory {
    virtual IDBCommand* CreateDBCommand()=0;
}

class IDBDataReader {
    
};

class IDataReaderFactory {
public:
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

// 具体工厂
class SqlConnectionFactory : public IDBConnectionFactory {
public:
    virtual IDBConnection* CreateIDBConnection() {
        return new SqlConnection;
    }
};

class SqlDBCommandFactory : public IDBCommandFactory {
public:
    virtual IDBCommand* CreateDBCommand() {
        return new SqlDBCommand;
    }
};

class SqlDataReader : public IDBDataReader {
    
};
class SqlDataReaderFactory : public IDataReaderFactory {
    
};


class EmployeeDAO{
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    
public:
    vector<EmployeeDO> GetEmployees(){
//        SqlConnection* connection = new SqlConnection();
        IDBConnection* connection =  dbConnectionFactory->CreateIDBConnection();
        connection->ConnectionString("...");
        
//        SqlCommand* command = new SqlCommand();
        IDBCommand* command = dbCommandFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); // 关联性
        
        
        IDBDataReader* reader = command->ExecuteReader(); // 关联性
        while (reader->Read()){
            
        }
        
    }
};

