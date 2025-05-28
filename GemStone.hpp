#pragma once

#include "Stone.hpp"


/// @brief Базовый абстрактный класс для драгоценных камней
class GemStone: public Stone
{
    public:
    GemStone(): Stone() { };
    GemStone(unsigned int carat, unsigned int price): Stone(carat, price)  { }; 
    public:
    virtual ~GemStone() = default;
};