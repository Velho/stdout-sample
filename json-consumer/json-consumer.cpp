#include "json-consumer.h"

#include <iostream>

int main(int argc, char *argv[])
{
    nlohmann::json j;
    std::cin >> j;

    std::cout << "Count: " << j.size() << std::endl;
    std::cout << j.dump();

    return 0;
}
