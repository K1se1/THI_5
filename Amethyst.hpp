#pragma once

#include "SemiPreciousStone.hpp"
#include<iostream>

/// @brief  Класс-реализация аметиста
class Amethyst final: public SemiPreciousStone
{
    public:
    Amethyst(): SemiPreciousStone() { };
    Amethyst(unsigned int carat, unsigned int price): SemiPreciousStone(carat, price)  { };
    virtual inline std::string GetInfo() override { return "Тип: Аметист | Вес в каратах: "+std::to_string(GetSize())+" | Цена: "+std::to_string(GetPrice()) + " |";  };
    public:
    virtual ~Amethyst() = default;
};
