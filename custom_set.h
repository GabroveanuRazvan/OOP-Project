//
// Created by Razvan Gabroveanu on 5/10/2023.
//

#ifndef POO_PROJECT_2_CUSTOM_SET_H
#define POO_PROJECT_2_CUSTOM_SET_H
#include<vector>
#include<algorithm>
template <typename T>
class custom_set{
private:
    std::vector<T> elements;
public:
    //methods
    void insert(const T& new_element);
    void remove(const T& old_element);
    bool is_contained(const T& element);
    size_t size() const;
    //constructors
    custom_set();
    explicit custom_set(const std::vector<T>& new_elements);
};

//methods
template<typename T>
bool custom_set<T>::is_contained(const T& element)
{
    if(find(elements.begin(),elements.end(),element)!=element.end())
        return true;
    return false;
}
template<typename T>
void custom_set<T>::remove(const T&old_element)
{
    auto old_iterator=std::find(elements.begin(),elements.end(),old_element);
    if(old_iterator!=elements.end())
        elements.erase(old_iterator);

}
template<typename T>
void custom_set<T>::insert(const T& new_element)
{
    if(find(elements.begin(),elements.end(),new_element)==elements.end())
        elements.push_back(new_element);
}
template<typename T>
size_t custom_set<T>::size() const{return elements.size();}
//constructors
template<typename T>
custom_set<T>::custom_set(): elements(){}
template<typename T>
custom_set<T>::custom_set(const std::vector<T>& new_elements){
    for( const auto & new_element:new_elements)
        this->insert(new_element);
}
#endif //POO_PROJECT_2_CUSTOM_SET_H
