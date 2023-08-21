#pragma once

#include <nlohmann/json.hpp>

struct Item
{
    std::string _name;
    int _value;
    std::vector<float> _fmeas;

    void Deserialize(nlohmann::json &j);
};
