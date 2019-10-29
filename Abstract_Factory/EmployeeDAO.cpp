
class EmployeeDAO{
    
public:
    vector<EmployeeDO> GetEmployees(){
        SqlConnection* connection = new SqlConnection();
        connection->ConnectionString("...");
        
        SqlCommand* command = new SqlCommand();
        command->CommandText("...");
        command->SetConnection(connection); // 关联性
        
        SqlDataReader* reader = command->ExecuteReader(); // 关联性
        while (reader->Read()){
            
        }
        
    }
};

