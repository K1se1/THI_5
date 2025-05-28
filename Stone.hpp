#pragma once


/// @brief Базовый абстрактный класс для камней
#include <string>
class Stone
{
    public:
    virtual inline unsigned int GetSize() { return carat_;};
    virtual inline unsigned int GetPrice() { return price_; };
    virtual inline std::string GetInfo() = 0;
    virtual ~Stone() = default;
    public:
    Stone(): Stone(0, 0) { };
    Stone(unsigned int carat, unsigned int price): carat_(carat), price_(price) { }; 
    private:
    unsigned int carat_;
    unsigned int price_;

};
