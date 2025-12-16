#include <charconv>
#include <ranges>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream in("01.txt");
    if (!in)
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    int current = 50;
    int times{0};
    std::string line;
    while (std::getline(in, line))
    {
        auto cmd = line[0];
        int steps;
        auto [p,ec] = std::from_chars(line.data() + 1, line.data() + line.size(), steps);
        if (ec != std::errc{}) continue;

        int dir = cmd == 'L' ? -1 : 1;
        times += steps / 100;

        int rem = steps % 100;

        int pos = current;
        for (int i = 0; i < rem; ++i)
        {
            pos = (pos + dir + 100) % 100;
            if (pos == 0) times++;
        }
    }
    std::cout << times << std::endl;


    return 0;
}
