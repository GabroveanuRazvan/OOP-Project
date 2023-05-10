

#ifndef POO_PROJECT_2_FLOWER_H
#define POO_PROJECT_2_FLOWER_H

class flower {
    friend class Bouquet; // for calling buy_flower function
    friend class Shopping_cart; // same as above
protected:
    int chosen_flower_count;
    static int total_shop_flowers;
    bool to_buy;
    virtual void buy_flower()=0;//sets the value of to_buy to True


public:
    //methods
    static flower* new_flower(const std::string& new_flower_name,int count);
    static flower* new_flower(const std::string& new_flower_name);
    static int get_total_shop_flowers() ;
    static void set_menu();
    virtual void print_flower_info() const=0; // make an upcast to it
    virtual float get_price()const=0;
    virtual flower* clone_flower() const=0;
    virtual void set_flower_count(int new_count)=0;
    //constructors
    flower()=delete; // deleted no parameters constructor
    explicit flower(int chosen_count);
    flower(const flower&fl); // copy constructor
    virtual ~flower()=0; // virtual destructor for static members of the flowers

};

//functions that use the flower class
void print_info(const flower& fl);
float get_flower_price(const flower& fl);
#endif //POO_PROJECT_2_FLOWER_H
