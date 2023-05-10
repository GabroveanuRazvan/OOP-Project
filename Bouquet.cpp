#include<iostream>
#include<typeinfo>
#include "flower_count_exception.h"
#include <algorithm>
#include "Bouquet.h"
#include "custom_set.h"
//methods
void Bouquet::buy_bouquet() { //sets to to_buy value of each flower to true
    for(const auto & current_flower:bq)
    {
        current_flower->buy_flower();
    }
}
bool Bouquet::same_flower_type(const flower &new_flower) {
    for (const auto& current_flower: bq) { //iterates through bq and searches using RTTI if the new_flower type is the same ase another type in bq
        if (typeid(*current_flower) == typeid(new_flower))
            return true; //returns true
    }
    return false;//or false
}

void Bouquet::add_flower(flower* new_flower) {
    try {
        if (bq.size() == bouquet_capacity)  // if the max capacity is reached
            throw bouquet_capacity_error("Bouquet capacity at maximum"); //throws this error
        else{
            custom_set<std::shared_ptr<flower>> bouquet_clone(bq);
            if (bouquet_clone.size()!=bq.size()) // if the new flower has already been added
                throw same_flower_type_error("Same flower type already added in bouquet"); // throws another exception
        }
        bq.push_back(std::shared_ptr<flower>(new_flower)); // if everything is correct the new flower is added
        std::sort(bq.begin(),bq.end(),[](const std::shared_ptr<flower>& f1,const std::shared_ptr<flower>& f2){return f1->chosen_flower_count<f2->chosen_flower_count;});
    } catch (const std::exception &exception1) { //catches one error
        std::cerr << exception1.what() << '\n'; // prints it

        if(typeid(exception1)==typeid(bouquet_capacity_error(""))) // verifies if the type of the new flower is already in the bouquet
            try{
                if (this->same_flower_type(*new_flower)) // if the new flower has already been added
                    throw same_flower_type_error("Same flower type already added in bouquet"); // throws another exception
            }catch(const std::exception &exception2){
                std::cerr << exception2.what() << '\n'; // prints it
                exit(1);// interupts the program
            }
        exit(1); // interupts the program
    }
}
void Bouquet::remove_flower(int index){ //removes flower on index i
    try{
        if(index<0||index>=bq.size())
            throw std::out_of_range("Removal Bouquet index out of range"); //throws out of range exception if index not in range
        bq.erase(bq.begin()+index);
        std::sort(bq.begin(),bq.end(),[](const std::shared_ptr<flower>& f1,const std::shared_ptr<flower>& f2){return f1->chosen_flower_count<f2->chosen_flower_count;});
    }catch(const std::exception&e){
        std::cerr<<e.what()<<'\n'; //catches it and prints it to standart error output
        exit(1);
    }
}

void Bouquet::print_bouquet_content() const {
    int i=1;
    std::cout<<"Bouquet contents: "<<"\n\n";
    for(const auto& flower:bq)
    {
        std::cout<<"Flower "<<i<<":"<<'\n';
        i++;
        flower->print_flower_info();
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

float Bouquet::get_bouquet_price() const {
    float bouquet_price = 0.0;
    for(const auto& current_flower:bq) // iterates throuqh bq vector and adds the price of each flower to the final price
    {
        bouquet_price+=current_flower->get_price();
    }
    return bouquet_price;
}

//constructors
Bouquet::Bouquet() : bq() {}  // no parameter constructor
//operators
std::shared_ptr<flower> Bouquet::operator[](int index)
{
    try{
        if(index<0||index>bq.size())
            throw std::out_of_range("Bouquet index out of range"); // verifies if the index is valid
        return bq[index]; //returns the current element that is a pointer
    }catch(const std::exception&e) //throws exception otherwise
    {
        std::cerr<<e.what()<<'\n';
        exit(1); //exits after the exception is treated
    }

}
