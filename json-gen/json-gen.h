// json-gen.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>

struct Item
{
    std::string _name;
    int _value;
    std::vector<float> _fmeas;

    nlohmann::json Serialize();
};

struct ItemList
{

    std::vector<Item> _items;

    void AppendItem(Item &&item);
    void CreateNewItem(std::string &&name, int value, std::vector<float> fmeas);

    std::size_t Count() const;

    // get items from _items and clear vector
    const std::vector<Item> GetBufferedItems();
};
