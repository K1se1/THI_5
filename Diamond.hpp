#pragma once

#include "GemStone.hpp"
#include<iostream>

/// @brief Класс-реализация(ну типо) алмаза
class Diamond final: public GemStone
{
    public:
    Diamond(): GemStone() { };
    Diamond(unsigned int carat, unsigned int price): GemStone(carat, price)  { };
    virtual inline std::string GetInfo() override { return "Тип: Алмаз | Вес в каратах: "+std::to_string(GetSize())+" | Цена: "+std::to_string(GetPrice()) + " |"; } ;
    public:
    virtual ~Diamond() = default;
};
