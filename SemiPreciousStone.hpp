#pragma once

#include "Stone.hpp"


/// @brief Базовый абстрактный класс для полудрагоценных камней
class SemiPreciousStone: public Stone
{
    public:
    SemiPreciousStone(): Stone() { };
    SemiPreciousStone(unsigned int carat, unsigned int price): Stone(carat, price) { };
    public:
    virtual ~SemiPreciousStone() = default;

};