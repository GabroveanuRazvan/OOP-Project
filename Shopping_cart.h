

#ifndef POO_PROJECT_2_SHOPPING_CART_H
#define POO_PROJECT_2_SHOPPING_CART_H
#include "flower.h"
#include "Rose_flower.h"
#include "Tulip_flower.h"
#include "Bouquet.h"
#include <vector>
#include <functional>
class Shopping_cart{
    std::vector<Bouquet*> bouquets;
    std::vector<flower*> flowers;
    const static int flowers_capacity=2; // will always be equal with the number of distinct flower classes
    bool same_flower_type(const flower& fl); //returns true if there is in the flowers another flower of the same type
    void buy_cart_contents();//sets the to_buy value of each flower in the shopping cart to true, bouquets included
public:
    //methods
    void add_to_cart(Bouquet* chosen_bouquet);
    void add_to_cart(flower* new_flower);
    void remove_cart_flower(int index);
    void remove_cart_bouquet(int index);
    float get_cart_price() const;
    Bouquet* cart_bouquet_at(int index);

    void print_cart_bouquets() const;
    void print_cart_flowers()  const;
    void print_cart_contents() const;
    //constructors
    Shopping_cart();
    ~Shopping_cart();// for memory
};
//methods that use shopping_cart
extern float apply_discount(float price,const std::function<float(float)>& discount_function);


#endif //POO_PROJECT_2_SHOPPING_CART_H
