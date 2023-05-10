#ifndef POO_PROJECT_2_BOUQUET_H
#define POO_PROJECT_2_BOUQUET_H
#include "flower.h"
#include "Rose_flower.h"
#include "Tulip_flower.h"
#include <vector>
class Bouquet{
    friend class Shopping_cart;

    const static int bouquet_capacity=2; // will always be equal with the number of distinct flower classes
    std::vector<flower*> bq; // pointer to the array of flowers
    bool same_flower_type(const flower& fl); //returns true if there is in the bouquet another flower of the same type
    void buy_bouquet(); //sets to to_buy value of each flower to true
public:
    //methods
    void add_flower(flower* new_flower);
    void remove_flower(int index);
    void print_bouquet_content()  const;
    float get_bouquet_price() const;
    Bouquet();// no parameter constructor
    ~Bouquet(); // destructor, deallocates memory
    //operators
    //constructors
    flower* operator[](int index); //gets the flower at index
};
#endif //POO_PROJECT_2_BOUQUET_H
