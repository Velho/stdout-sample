// json-gen.cpp : Defines the entry point for the application.
//

#include "json-gen.h"

#include <limits>
#include <random>

// #include <Windows.h>
// #include <synchapi.h>
#include "win-wrapper.h"

// ___ struct Item ___

nlohmann::json Item::Serialize()
{
    nlohmann::json j = {{"name", _name}, {"value", _value}, {"fmeas", _fmeas}};

    return j;
}

// ___ struct Item ___

// ___ struct ItemList ___

void ItemList::AppendItem(Item &&item)
{
    _items.push_back(item);
}

void ItemList::CreateNewItem(std::string &&name, int value, std::vector<float> fmeas)
{
}

std::size_t ItemList::Count() const
{
    return _items.size();
}

const std::vector<Item> ItemList::GetBufferedItems()
{
    const std::vector<Item> items{_items};
    _items.clear();

    return items;
}

// ___ struct ItemList ___

void OutputItems(ItemList &itemlist)
{
    auto buffered_items = itemlist.GetBufferedItems();

    for (auto &item : buffered_items)
    {
        std::cout << item.Serialize();
        std::cout << std::flush;
    }
    // std::flush(std::cout);
}

std::random_device dev;

std::vector<float> GetFSampled()
{
    std::vector<float> ret;

    std::mt19937 gen{dev()};
    std::uniform_real_distribution<> dist(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());

    for (int n = 0; n < 4; ++n)
    {
        ret.push_back(dist(gen));
    }
    return ret;
}

std::string GetName()
{
    static std::string names[] = {"Silver Sword",       "Magic Elixir",   "Ancient Scroll",  "Potion of Invisibility",
                                  "Dragon Scale Armor", "Enchanted Ring", "Starlight Staff", "Phoenix Feather Wand",
                                  "Crystal Amulet",     "Golden Crown"};

    std::mt19937 gen{dev()};
    std::uniform_int_distribution<> dist(0, 10);

    return names[dist(gen)];
}

int GetValue()
{
    std::mt19937 gen{dev()};
    std::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    return dist(gen);
}

Item GetRandomizedItem()
{
    auto name = GetName();
    auto float_values = GetFSampled();
    auto value = GetValue();
    return Item{name, value, float_values};
}

// get buffer count
// randomize 10..20 as buffered items count
int GetBufferCount()
{
    std::mt19937 gen{dev()};
    std::uniform_int_distribution<> dist(10, 20);

    return dist(gen);
}

int main(int argc, char *argv[])
{
    bool running = true;
    bool buffered = false;
    int buffered_count = GetBufferCount();
    int buffered_items = 0;
    int buffer_wrap = 0; // wrapped around

    ItemList item_list;

    while (running)
    {
        // create struct with randomized data
        auto item = GetRandomizedItem();

        // buffer set amount of objects
        item_list.AppendItem(std::move(item));

        if (buffered_items >= buffered_count)
        {
            // print buffered json objects to stdout
            OutputItems(item_list);

            buffered_items = 0;
            buffered_count = GetBufferCount();
            buffer_wrap += 1;

            SystemSleep(1000);
        }

        buffered_items += 1;

        // sent x10 quit for now
        if (buffer_wrap >= 10)
        {
            running = false;
        }
    }

    return 0;
}
