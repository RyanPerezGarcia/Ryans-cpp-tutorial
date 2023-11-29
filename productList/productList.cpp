#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() 
{
    std::ifstream file("..\\productentry\\products.csv");

    if (!file.is_open()) 
    {
        std::cout << "Unable to open file\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string id, description, quantity, price;

        std::getline(ss, id, ',');
        std::getline(ss, description, ',');
        std::getline(ss, quantity, ',');
        std::getline(ss, price, ',');

        double totalValue = std::stoi(quantity) * std::stod(price);

        std::cout << "ID: " << id << "  "
            << "Desc:" << description << "  "
            << "Quantity:" << quantity << "  "
            << "Price:" << price << "  "
            << "TotalValue: " << totalValue << "\n\n";
    }

    file.close();
    return 0;
}