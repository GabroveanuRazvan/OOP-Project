#include<iostream>

#include "flower_count_exception.h"
#include "Tulip_flower.h"

//static initialize
float Tulip::tulip_price = 0.0; //default set
int Tulip::total_tulip_count = 0; // default set
//methods
void Tulip::buy_flower() {
    to_buy=true;
}
void Tulip::set_tulip_price(float price) {
    tulip_price = price; // sets tulip price
}

void Tulip::set_total_tulip_count(int tulip_count) {
    total_tulip_count = tulip_count; // sets the tulips count
    total_shop_flowers += total_tulip_count; // adds to total flowers
}

void Tulip::print_flower_info() const {
    std::cout << "Flower name: Tulip \n";
    std::cout << "Price per flower: " << tulip_price << '\n';
    std::cout << "Chosen tulips count: " << chosen_flower_count << '\n';
}

int Tulip::get_total_tulip_count() {
    return total_tulip_count;
}

float Tulip::get_price() const {
    int temp_int = chosen_flower_count; // temporary int to store flower count
    auto temp_float = static_cast<float>(temp_int); // cast it to convert to float into a new variable
    return temp_float * tulip_price;
}

Tulip* Tulip::clone_flower() const{
    return new Tulip(*this);
}


void Tulip::set_flower_count(int new_count){
    total_tulip_count+=chosen_flower_count-new_count;
    total_shop_flowers += chosen_flower_count-new_count;
    chosen_flower_count=new_count;
}
//constructors
Tulip::Tulip(int chosen_count) : flower(chosen_count) {
    try { // tries to see if there are enough units in the shop
        if (total_tulip_count < chosen_flower_count) //if there are not
            throw flower_count_error("Not enough tulips on stock"); // throws flower_count_error
        to_buy=false;
        total_tulip_count -= chosen_flower_count; // update total tulips
        total_shop_flowers -= chosen_flower_count; // update total flowers
    } catch (const std::exception &e) { // catches the error
        std::cerr << e.what() << '\n'; // and print it to standart error output
        exit(1);
    }

}

Tulip::Tulip(const Tulip &tulip) : flower(tulip) {
    try {// as above in the standard  one parameter constructor
        if (total_tulip_count < chosen_flower_count)
            throw flower_count_error("Not enough tulips on stock");
        to_buy=false;
        total_tulip_count -= chosen_flower_count; // There will be 2 objects with the same propierties, but the flower count is solicited twice
        total_shop_flowers -= chosen_flower_count;
    } catch (const flower_count_error &error) {
        std::cerr << error.what() << '\n';
        exit(1);
    }

}

Tulip::~Tulip() {
    if(!to_buy)
    {
        total_tulip_count += chosen_flower_count; // maybe modify later
        total_shop_flowers += chosen_flower_count;
    }

}