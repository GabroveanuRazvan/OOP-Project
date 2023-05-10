//
// Created by Razvan Gabroveanu on 4/19/2023.
//

#ifndef POO_PROJECT_2_FLOWER_COUNT_EXCEPTION_H
#define POO_PROJECT_2_FLOWER_COUNT_EXCEPTION_H

class flower_count_error : public std::exception {
public:
    explicit flower_count_error(const std::string &what_arg);

    const char *what() const noexcept override;

private:
    std::string m_what_arg;
};


class bouquet_capacity_error: public std::exception{
public:
    explicit bouquet_capacity_error(const std::string &what_arg);

    const char* what() const noexcept override;
private:
    std::string m_what_arg;
};


class same_flower_type_error: public std::exception{
public:
    explicit same_flower_type_error(const std::string &what_arg);

    const char* what() const noexcept override;
private:
    std::string m_what_arg;
};
#endif //POO_PROJECT_2_FLOWER_COUNT_EXCEPTION_H
