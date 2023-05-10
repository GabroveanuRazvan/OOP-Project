
#ifndef POO_PROJECT_2_CLIENT_H
#define POO_PROJECT_2_CLIENT_H
#include "client_info.h"
#include "Shopping_cart.h"
class Client:public client_info,public Shopping_cart{ //derived from cleint_info and shopping_cart
    void abstract_method() override; // declare it so that it does not remain abstract
public:
    void print_whole_client_data() const ;
    Client(std::string first_name,std::string last_name,std::string address); // constructor with parameters
    ~Client();// custom destructor
};
#endif //POO_PROJECT_2_CLIENT_H
