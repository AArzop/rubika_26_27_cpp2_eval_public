#include "LRUCache.h"

#include <iostream>

int main()
{
    LRUCache cache(2);

    cache.put(1, "A");
    cache.put(2, "B");

    std::cout << cache.get(1) << std::endl; // A

    cache.put(3, "C"); // Remove key 2

    std::cout << cache.get(2) << std::endl; // Empty
    std::cout << cache.get(3) << std::endl; // C

    cache.put(4, "D"); // Remove key 1

    std::cout << cache.get(1) << std::endl; // Vide
    std::cout << cache.get(4) << std::endl; // D

    return 0;
}
