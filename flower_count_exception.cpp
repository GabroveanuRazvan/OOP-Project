#include<iostream>
#include "flower_count_exception.h"
//flower_count_error
flower_count_error::flower_count_error(const std::string &what_arg) : m_what_arg(what_arg) {}

const char *flower_count_error::what() const noexcept {
    return m_what_arg.c_str();
}

//bouquet_capacity_error

bouquet_capacity_error::bouquet_capacity_error(const std::string &what_arg) :m_what_arg(what_arg){}
const char* bouquet_capacity_error::what() const noexcept{
    return m_what_arg.c_str();
}

//same_flower_type_error

same_flower_type_error::same_flower_type_error(const std::string &what_arg):m_what_arg(what_arg) {}
const char* same_flower_type_error::what() const noexcept{
    return m_what_arg.c_str();
}