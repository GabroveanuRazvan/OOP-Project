
#ifndef POO_PROJECT_2_CLIENT_INFO_H
#define POO_PROJECT_2_CLIENT_INFO_H
class client_info{
protected:
    std::string first_name;
    std::string last_name;
    std::string address;
    virtual void abstract_method()=0; // dummy method, just for making it abstract
public:
    //methods
    void change_first_name(const std::string& name);
    void change_last_name(const std::string& name);
    void change_address(const std::string& address);
    void print_client_info() const ;
    //constructors
    client_info()=delete;
    client_info(std::string first_name,std::string last_name,std::string address); // client initialization

};
void print_whole_client_data(client_info* client);
#endif //POO_PROJECT_2_CLIENT_INFO_H
