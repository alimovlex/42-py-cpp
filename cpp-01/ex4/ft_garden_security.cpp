#include <iostream>
#include <string>

class SafePlant
{
public:
void set_height(int new_height)
{
    if (new_height < 0)
    {
        std::cout << "Invalid operation attempted: " << new_height << "cm [REJECTED]";
        std::cout << std::endl;
        std::cout << "Security: Negative height rejected" << std::endl;
    }
    else
    {
        this->height = new_height;
        std::cout << "Height updated: " << this->height << "cm [OK]" << std::endl;
    }
}

void set_age(int new_age)
{
    if (new_age < 0)
    {
        std::cout << "Invalid operation attempted: " << new_age << "days [REJECTED]";
        std::cout << std::endl;
        std::cout << "Security: Negative age rejected" << std::endl;
    }
    else
    {
        this->age = new_age;
        std::cout << "Age updated: " << this->age << "days [OK]" << std::endl;
    }
}

int get_height() { return height; }
int get_age() { return age; }
void get_info() { std::cout << name << ": " << height << "cm, " << age << " days\n"; }

SafePlant(std::string name, int height, int age):
name(name), height(height), age(age)
{
    // this->name = name;
    // this->height = height;
    // this->age = age;
    std::cout << "Plant Created: " << this->name << std::endl;
}

private:
std::string name;
int height;
int age;
};

int main()
{
    std::cout << "=== Garden Security System ===" << std::endl;
    SafePlant rose = SafePlant("Rose", 25, 30);
    rose.set_height(25);
    rose.set_age(30);
    rose.set_height(-5);
    std::cout << std::endl;
    std::cout << "Current plant: ";
    rose.get_info();
    return 0;
}
