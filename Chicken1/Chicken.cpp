#include <iostream>
#include <cstring>

class Chicken
{
private:
    int age = 24;
    char *name = nullptr;

public:
    Chicken() {};
    Chicken(int _age) : age(_age) {};
    Chicken(int _age, const char *_name) : age(_age)
    {
        int len = strlen(_name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = _name[i];
    }
    Chicken(const Chicken &other)
    {
        age = other.age;
        if (other.name != nullptr)
        {
            int len = strlen(other.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = other.name[i];
        }
    }
    ~Chicken()
    {
        if (name != nullptr)
            delete[] name;
        name = nullptr;
    }
    void setAge(int _age)
    {
        age = _age;
    }
    void setName(char *_name)
    {
        if (name != nullptr)
        {
            delete[] name;
            name = nullptr;
        }
        int len = strlen(_name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = _name[i];
    }

    const std::string getName() const
    {
        return name;
    }

    const int &getAge() const
    {
        return age;
    }

    Chicken &operator=(const Chicken &other)
    {
        if (this == &other)
            return *this;
        age = other.age;
        if (other.name == nullptr)
        {
            name = nullptr;
            return *this;
        }
        if (name != nullptr)
        {
            delete[] name;
            name = nullptr;
        }
        int len = strlen(other.name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = other.name[i];

        return *this;
    }
};
int main()
{
    auto print = [](const Chicken &c)
    {
        std::cout << "Hi, everyone! My name is " << c.getName()
                  << ", I am " << c.getAge() << " years old." << std::endl;
    };
    Chicken c(24, "Kunkun");
    print(c);
    Chicken d;
    d = c;
    print(d);
    Chicken a = c;
    print(a);
    c.setName("Xukun Cai");
    print(c);
    print(a);
    print(d);
    Chicken b;
    b = d = c;
    print(b);
    print(d);
    return 0;
}