#include <iostream>
#include "TVector.h"

int main()
{
    TVector<int> vector(5);

    vector[0] = 10;
    vector[1] = 20;
    vector[2] = 30;
    vector[3] = 40;
    vector[4] = 50;

    for (auto it = vector.begin(); it != vector.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    auto it = vector.begin();

    std::cout << *(it + 2) << std::endl;

    it += 2;

    std::cout << *it << std::endl;

    it -= 1;

    std::cout << *it << std::endl;

    return 0;
}