#include<iostream>
#include <sstream>
#include "flower.h"
#include "Rose_flower.h"
#include "Tulip_flower.h"
#include <random>
//static initialize
int flower::total_shop_flowers=0;
//methods
flower* flower::new_flower(const std::string& new_flower_name, int count)
{

    if(new_flower_name=="rose"||new_flower_name=="Rose")
        return new Rose(count);
    if(new_flower_name=="tulip"||new_flower_name=="Tulip")
        return new Tulip(count);
    throw(std::runtime_error("Unknown flower or flower type not in shop"));
}
flower* flower::new_flower(const std::string& new_flower_name)
{

    std::random_device rd; // nondeterminitic random seed
    std::mt19937 generate(rd());  // Mersenne Twister random number engine using specific seed
    std::uniform_int_distribution<> rand_int(1, 5); // distribution
    if(new_flower_name=="rose"||new_flower_name=="Rose")
        return new Rose(rand_int(generate));
    if(new_flower_name=="tulip"||new_flower_name=="Tulip")
        return new Tulip(rand_int(generate));
    throw(std::runtime_error("Unknown flower or flower type not in shop"));
}
int flower::get_total_shop_flowers() {
    return total_shop_flowers;
}
void flower::set_menu()
{
    int count;float price;
    std::stringstream in(
            "20\n"
            "20\n"
            "20\n"
            "20\n"

    );
    ///rose declarations
    //std::cout<<"Give rose price: ";
    in>>price;
    Rose::set_rose_price(price);
    //std::cout<<"Give rose count: ";
    in>>count;
    Rose::set_total_rose_count(count);

    ///tulip declarations
    //std::cout<<"Give tulip price: ";
    in>>price;
    Tulip::set_tulip_price(price);
    //std::cout<<"Give tulip count: ";
    in>>count;
    Tulip::set_total_tulip_count(count);
    //std::cout<<'\n';
}

//constructors
flower::flower(int chosen_count): chosen_flower_count(chosen_count){}
flower::flower(const flower&fl):chosen_flower_count(fl.chosen_flower_count){}
flower::~flower() {}



// functions that use the flower class
void print_info(const flower& fl){
    fl.print_flower_info();
}
float get_flower_price(const flower& fl)
{
    return fl.get_price();
}
