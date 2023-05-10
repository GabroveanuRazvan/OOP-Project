#include<iostream>
#include "client_info.h"
#include "Client.h"
//methods
void client_info::change_first_name(const std::string &name){
    this->first_name=name;
}
void client_info::change_last_name(const std::string& name){
    this->last_name=name;
}
void client_info::change_address(const std::string& adr){
    this->address=adr;
}
void client_info::print_client_info() const {
    std::cout<<"Client info: "<<"\n\n";
    std::cout<<"First name: "<<first_name.c_str()<<'\n';
    std::cout<<"Last name: "<<last_name.c_str()<<'\n';
    std::cout<<"Address: "<<address.c_str()<<"\n\n";
}
//constructors
client_info::client_info(std::string first_name, std::string last_name, std::string address):
    first_name(std::move(first_name)),last_name(std::move(last_name)),address(std::move(address)) {}
//outside methods that use clinet_info
void print_whole_client_data(client_info* client) {
    auto new_client=dynamic_cast<Client*>(client); // new pointer to Client, using dynamic cast
    if(new_client) // if the cast was succesfull
        new_client->print_whole_client_data(); // prints data
}
