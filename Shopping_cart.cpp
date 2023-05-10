#include<iostream>
#include <typeinfo>
#include "Shopping_cart.h"
#include "flower_count_exception.h"

//methods
void Shopping_cart::buy_cart_contents() {
    for(const auto& current_flower:flowers)
        current_flower->buy_flower();
    for(const auto& current_bouquet:bouquets)
        current_bouquet->buy_bouquet();
}
bool Shopping_cart::same_flower_type(const flower &new_flower) {
    for (const auto& current_flower: flowers) {
        if (typeid(*current_flower) == typeid(new_flower))
            return true;
    }
    return false;
}

void Shopping_cart::add_to_cart(Bouquet* chosen_bouquet) {
    bouquets.push_back(std::shared_ptr<Bouquet>(chosen_bouquet));
}

void Shopping_cart::add_to_cart(flower* new_flower) {
    try {
        if (flowers.size() == flowers_capacity)  // if the max capacity is reached
            throw bouquet_capacity_error("Shopping cart flowers capacity at maximum"); //throws this error
        else if (this->same_flower_type(*new_flower)) // if the new flower has already been added
            throw same_flower_type_error("Same flower type already added in shopping cart flowers"); // throws another exception
        flowers.push_back(std::shared_ptr<flower>(new_flower)); // if everything is correct the new flower is added
        std::sort(flowers.begin(),flowers.end(),[](const std::shared_ptr<flower>& f1,const std::shared_ptr<flower>& f2){return f1->chosen_flower_count<f2->chosen_flower_count;});
    } catch (const std::exception &exception1) { //catches one error
        std::cerr << exception1.what() << '\n'; // prints it

        if(typeid(exception1)==typeid(bouquet_capacity_error(""))) // verifies if the type of the new flower is already in the bouquet
            try{
                if (this->same_flower_type(*new_flower)) // if the new flower has already been added
                    throw same_flower_type_error("Same flower type already added in shopping cart flowers"); // throws another exception
            }catch(const std::exception &exception2){
                std::cerr << exception2.what() << '\n'; // prints it
                exit(1);// interupts the program
            }
        exit(1); // interupts the program
    }
}

void Shopping_cart::remove_cart_flower(int index){ //removes flower on index i
    try{
        if(index<0||index>=flowers.size())
            throw std::out_of_range("Removal shopping cart flower index out of range"); //throws out of range exception if index not in range
        flowers.erase(flowers.begin()+index);
        std::sort(flowers.begin(),flowers.end(),[](const std::shared_ptr<flower>& f1,const std::shared_ptr<flower>& f2){return f1->chosen_flower_count<f2->chosen_flower_count;});
    }catch(const std::exception&e){
        std::cerr<<e.what()<<'\n'; //catches it and prints it to standart error output
        exit(1);
    }
}
void Shopping_cart::remove_cart_bouquet(int index) {
    try{
        if(index<0||index>=bouquets.size())
            throw std::out_of_range("Removal shopping cart bouquet index out of range"); //throws out of range exception if index not in range
        bouquets.erase(bouquets.begin()+index);
    }catch(const std::exception&e){
        std::cerr<<e.what()<<'\n'; //catches it and prints it to standart error output
        exit(1);
    }
}
float Shopping_cart::get_cart_price() const {
    float cart_price=0.0;
    for(const auto& current_flower:flowers)
    {
        cart_price+= get_flower_price(*current_flower);
    }
    for(const auto& current_bouquet:bouquets)
    {
        cart_price+=current_bouquet->get_bouquet_price();
    }
    return cart_price;
}
std::shared_ptr<Bouquet> Shopping_cart::cart_bouquet_at(int index) { // the same as a [] operator, but just for bouquet
    try{
        if(index<0||index>=bouquets.size())
            throw std::out_of_range("The bouquet at specified index is out of range");
        return bouquets[index]; //returns the bouquet pointer if the index is valid
    }catch(const std::exception&e) // throws exception otherwise
    {
        std::cerr<<e.what()<<"\n";
        exit(1); //exits the code after exception is treated
    }

}

void Shopping_cart::print_cart_bouquets() const {
    int i=1;
    std::cout<<"Bouquets of the shopping cart: "<<"\n\n";
    for(  const auto& current_bouquet:bouquets)
    {
        std::cout<<"Bouquet "<<i<<"\n\n";
        i++;
        current_bouquet->print_bouquet_content();
    }
}

void Shopping_cart::print_cart_flowers() const {
    int i=1;
    std::cout<<"Flowers in the shopping cart: "<<"\n\n";
    for(const auto& flower:flowers)
    {
        std::cout<<"Flower "<<i<<":"<<'\n';
        i++;
        flower->print_flower_info();
        std::cout<<'\n';
    }
    std::cout<<'\n';
}
void Shopping_cart::print_cart_contents() const {
    this->print_cart_flowers();
    this->print_cart_bouquets();
}
//constructors
Shopping_cart::Shopping_cart():flowers(),bouquets(){} // shopping cart starts as empty

//methods that use shopping_cart
float apply_discount(float price,const std::function<float(float)>& discount_function)
{
    return discount_function(price);
}
