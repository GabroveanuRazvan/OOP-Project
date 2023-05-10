#include<iostream>

#include "flower_count_exception.h"
#include "Rose_flower.h"

//static initialize
float Rose::rose_price = 0.0; //default set
int Rose::total_rose_count = 0; // default set
//methods
void Rose::buy_flower() {
    to_buy=true;
}
void Rose::set_rose_price(float price) {
    rose_price = price; // sets rose price
}

void Rose::set_total_rose_count(int rose_count) {
    total_rose_count = rose_count; // sets the roses count
    total_shop_flowers += total_rose_count; // adds to total flowers
}

void Rose::print_flower_info() const {
    std::cout << "Flower name: Rose \n";
    std::cout << "Price per flower: " << rose_price << '\n';
    std::cout << "Chosen roses count: " << chosen_flower_count << '\n';
}

int Rose::get_total_rose_count() {
    return total_rose_count;
}

float Rose::get_price() const {
    int temp_int = chosen_flower_count; // temporary int to store flower count
    auto temp_float = static_cast<float>(temp_int); // cast it to convert to float into a new variable
    return rose_price * temp_float;
}

Rose* Rose::clone_flower() const{
    return new Rose(*this);
}

void Rose::set_flower_count(int new_count){
    total_rose_count+=chosen_flower_count-new_count;
    total_shop_flowers += chosen_flower_count-new_count;
    chosen_flower_count=new_count;
}
//constructors
Rose::Rose(int chosen_count) : flower(chosen_count) {
    try { // tries to see if there are enough units in the shop
        if (total_rose_count < chosen_flower_count) //if there are not
            throw flower_count_error("Not enough roses on stock"); // throws flower_count_error
        to_buy=false;
        total_rose_count -= chosen_flower_count; // update total roses
        total_shop_flowers -= chosen_flower_count; // update total flowers
    } catch (const std::exception &e) { // catches the error
        std::cerr << e.what() << '\n'; // and print it to standart error output
        exit(1);
    }

}

Rose::Rose(const Rose &rose) : flower(rose) {
    try {// as above in the standard  one parameter constructor
        if (total_rose_count < chosen_flower_count)
            throw flower_count_error("Not enough roses on stock");
        to_buy=rose.to_buy;
        total_rose_count -= chosen_flower_count; // There will be 2 objects with the same propierties, but the flower count is solicited twice
        total_shop_flowers -= chosen_flower_count;
    } catch (const flower_count_error &error) {
        std::cerr << error.what() << '\n';
        exit(1);
    }

}

Rose::~Rose() {
    if (!to_buy) {
        total_rose_count += chosen_flower_count; // maybe modify later
        total_shop_flowers += chosen_flower_count;
    }
}
