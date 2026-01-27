#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include <array>
#include <math.h>
#include <tuple>

double distance3D(std::tuple<double, double, double>& p1, std::tuple<double, double, double>& p2)
{
    double x1, y1, z1, x2, y2, z2;

    x1 = std::get<0>(p1);
    y1 = std::get<1>(p1);
    z1 = std::get<2>(p1);

    x2 = std::get<0>(p2);
    y2 = std::get<1>(p2);
    z2 = std::get<2>(p2);

    return std::sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2));
}

int main(int argc, char** argv)
{
    std::cout << "=== Game Coordinate System ===" << std::endl;

    if (argc < 2)
        std::cout << "No arguments supplided. Usage: a.out <x> <y> <z>" << std::endl;
    else
    {
        double x_spawn = 0, y_spawn = 0, z_spawn = 0;
        double x1 = 10, y1 = 20, z1 = 5;
        double x_unpack, y_unpack, z_unpack;
        std::tuple<double, double, double> spawn_point(std::make_tuple(x_spawn, y_spawn, z_spawn));
        std::tuple<double, double, double> p1(std::make_tuple(x1, y1, z1));
        std::tuple<double, double, double> parsed_tuple;
        std::vector<std::string> parsed_list;
        std::cout << "Position created: (" << x_spawn << ", " << y_spawn << ", " << z_spawn << ")";
        std::cout << std::endl;

        double distance = distance3D(spawn_point, p1);

        std::cout << "Distance between (" << x_spawn << ", " << y_spawn << ", " << z_spawn << ")";
        std::cout << " and (" << x1 << ", " << y1 << ", " << z1 << "): " << distance << std::endl;
        std::cout << "Parsing coordinates:";

        while(*++argv)
        {
            std::cout << " " << *argv;
            parsed_list.push_back(*argv);
        }
        std::cout << std::endl;

        try
        {
            for (auto& str: parsed_list)
                std::stod(str);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error parsing coordinates: invalid literal for int() with base 10: " << e.what();
            std::cout << std::endl;
        }

        parsed_tuple = std::make_tuple(
        std::stod(*parsed_list.begin()),
        std::stod(*std::next(parsed_list.begin())),
        std::stod(*std::next(parsed_list.begin(), 2))
        );
        double x_parsed = std::get<0>(parsed_tuple), y_parsed = std::get<1>(parsed_tuple), z_parsed = std::get<2>(parsed_tuple);

        std::cout << "Parsed position: (" << x_parsed << ", " << y_parsed << ", " << z_parsed << ")";
        std::cout << std::endl;

        distance = distance3D(spawn_point, parsed_tuple);

        std::cout << "Distance between (" << x_spawn << ", " << y_spawn << ", " << z_spawn << ")";
        std::cout << " and (" << x_parsed << ", " << y_parsed << ", " << z_parsed << ") " << distance << std::endl;

        std::array<std::string, 3> arr = {"asd, def, ghi"};
        std::cout << "Parsing invalid coordinates: ";
        for(auto& str: arr)
           std::cout << str << " ";

        std::cout << std::endl;
        /*
         * std::array<std::string, 3>::iterator itr = arr.begin();
        while (itr != arr.end())
        {
            std::cout << "Parsing invalid coordinates: " << *itr << " ";
            itr++;
        }
         */

        try
        {
            for(auto& str: arr)
                std::stod(str);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error parsing coordinates: invalid literal for int() with base 10: " << e.what();
            std::cout << std::endl;
        }

        std::cout << "Unpacking demonstration: " << std::endl;
        std::cout << "Player at x=" << x_parsed << " y=" << y_parsed << " z=" << z_parsed << std::endl;
        std::cout << "Coordinates: X=" << x_parsed << " Y=" << y_parsed << " Z=" << z_parsed << std::endl;
    }
    return 0;
}
