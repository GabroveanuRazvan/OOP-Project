#include<iostream>
#include "flower.h"
#include "Rose_flower.h"
#include "Tulip_flower.h"
//static initialize
int flower::total_shop_flowers=0;
//methods
int flower::get_total_shop_flowers() {
    return total_shop_flowers;
}
void flower::set_menu()
{
    int count;float price;

    ///rose declarations
    std::cout<<"Give rose price: ";
    std::cin>>price;
    Rose::set_rose_price(price);
    std::cout<<"Give rose count: ";
    std::cin>>count;
    Rose::set_total_rose_count(count);

    ///tulip declarations
    std::cout<<"Give tulip price: ";
    std::cin>>price;
    Tulip::set_tulip_price(price);
    std::cout<<"Give tulip count: ";
    std::cin>>count;
    Tulip::set_total_tulip_count(count);
    std::cout<<'\n';
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
