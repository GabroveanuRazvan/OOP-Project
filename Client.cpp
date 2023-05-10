#include<iostream>
#include "Client.h"
//methods
void Client::abstract_method() {}
//constructors
void Client::print_whole_client_data() const {
    this->print_client_info();
    this->print_cart_contents();
}
Client::Client(std::string first_name,std::string last_name,std::string address):
        client_info(std::move(first_name),std::move(last_name),std::move(address)),Shopping_cart(){}
Client::~Client(){std::cout<<"Transaction done!";}