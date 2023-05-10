//
// Created by Razvan Gabroveanu on 4/19/2023.
//

#ifndef POO_PROJECT_2_TULIP_FLOWER_H
#define POO_PROJECT_2_TULIP_FLOWER_H

#include "flower.h"

class Tulip : public flower {
    static float tulip_price;
    static int total_tulip_count;
    bool to_buy;
    void buy_flower() override;
    //private methods for static
    static void set_total_tulip_count(int tulip_count);

    static void set_tulip_price(float price);

public:
    friend class flower;

    //methods
    static int get_total_tulip_count();

    void print_flower_info() const override; // prints the name,price, and chosen count of the specific flower
    float get_price() const override;
    Tulip* clone_flower() const override;
    void set_flower_count(int new_count) override;
    //constructors
    Tulip() = delete;

    explicit Tulip(int chosen_count);

    Tulip(const Tulip &tulip);

    ~Tulip() override;
};

#endif //POO_PROJECT_2_TULIP_FLOWER_H
