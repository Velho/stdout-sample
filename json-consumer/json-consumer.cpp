#include "json-consumer.h"

#include <iostream>

int main(int argc, char *argv[])
{
    std::vector<nlohmann::json> objs{};
    nlohmann::json j;

    while (!std::cin.eof() && std::cin >> j >> std::ws)
        objs.push_back(j);

    std::cout << "Resulting objects: " << objs.size() << std::endl;

    return 0;
}
