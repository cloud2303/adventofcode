//
// Created by cloud on 2025/12/16.
//

#include <charconv>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <fmt/format.h>


int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    auto in{std::ifstream("02.txt")};
    if (!in)
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    std::string line;
    std::getline(in, line);

    auto vec = std::vector<long>();
    for (auto part : line | std::views::split(','))
    {
        auto dash = std::ranges::find(part, '-');
        if (dash == part.end())
        {
            continue;
        }
        long first = 0;
        long last = 0;
        std::from_chars(&*part.begin(), &*dash, first);
        std::from_chars(&*(dash + 1), &*part.end(), last);
        std::ranges::copy(std::views::iota(first, last), std::back_inserter(vec));
    }
    long cnt{};
    for (auto part : vec)
    {
        auto str = std::to_string(part);
        if (str.size() % 2 != 0)
        {
            continue;
        }
        auto mid = str.size() / 2;
        std::string_view leftSv{str.data(), mid};
        std::string_view rightSv{str.data() + mid, mid};

        if (leftSv == rightSv)
        {
            cnt += part;
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    fmt::print("{}\n", cnt);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "cost = " << ms.count() << " ms\n";
}
