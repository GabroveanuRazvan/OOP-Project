#include <iostream>
#include <typeinfo>
#include "Rose_flower.h"
#include "Tulip_flower.h"
#include "flower.h"
#include "Bouquet.h"
#include "Shopping_cart.h"
#include <sstream>
#include "Client.h"

auto ten_percent_discount = [](float price) { return price * 0.9; };
auto twenty_percent_discount = [](float price) { return price * 0.8; };
auto thirty_percent_discount = [](float price) { return price * 0.7; };
auto forty_percent_discount = [](float price) { return price * 0.6; };
auto fifty_percent_discount = [](float price) { return price * 0.5; };
auto sixty_percent_discount = [](float price) { return price * 0.4; };
auto seventy_percent_discount = [](float price) { return price * 0.3; };
auto eighty_percent_discount = [](float price) { return price * 0.2; };
auto ninety_percent_discount = [](float price) { return price * 0.1; };
int main() {


//    Client c("ana","are","mere");
//    c.add_to_cart(new Rose(10));
//    c.add_to_cart(new Bouquet);
//    c.cart_bouquet_at(0)->add_flower(new Tulip(5));
//    std::cout<<c.get_cart_price()<<'\n';
//    print_whole_client_data(&c);
//    std::cout<<apply_discount(c.get_cart_price(),fifty_percent_discount);
////    auto* c=new Shopping_cart;
////std::cout<<flower::get_total_shop_flowers()<<" ";
////c->add_to_cart(new Rose(15));
////c->add_to_cart(new Bouquet);
////c->cart_bouquet_at(0)->add_flower(new Tulip(10));
////std::cout<<Rose::get_total_rose_count()<<" ";
////delete c;
////    std::cout<<flower::get_total_shop_flowers()<<" ";
////std::cout<<Rose::get_total_rose_count()<<" ";
////////c.add_to_cart(a);
//////c.remove_bouquet(0);
//////c.print_cart_bouquets();
//////c.remove_bouquet(0);
//////c.remove_bouquet(0);
//////c.print_cart_bouquets();

flower::set_menu();
flower* ceva=flower::new_flower("rose",2);
std::cout<<ceva->get_price();
    return 0;
}
