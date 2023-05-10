

#ifndef POO_PROJECT_2_ROSE_FLOWER_H
#define POO_PROJECT_2_ROSE_FLOWER_H
#include "flower.h"

class Rose : public flower {
    static float rose_price;
    static int total_rose_count;

    void buy_flower() override;
    //private methods for static
    static void set_total_rose_count(int rose_count);

    static void set_rose_price(float price);

public:
    friend class flower;

    //methods
    static int get_total_rose_count();

    void print_flower_info() const override; // prints the name,price, and chosen count of the specific flower
    float get_price() const override;
    Rose* clone_flower() const override;
    void set_flower_count(int new_count) override;

    //constructors
    Rose() = delete;

    explicit Rose(int chosen_count);

    Rose(const Rose &rose);

    ~Rose() override;
};

#endif //POO_PROJECT_2_ROSE_FLOWER_H
