#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }
        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
                name= nullptr;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }

    Chicken& operator=(const Chicken& other){
        if(this== &other) return *this;
        delete[] name;
        age=other.age;
        if(other.name==nullptr){
            name=nullptr;
            return *this;       }
        int len = strlen(other.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = other.name[i];
       
        return *this;
        }
     
};
int main()
{
    Chicken c(24, "Kunkun");
    Chicken d;
    d=c;
    std::cout << "Hi, everyone! My name is " << c.getName() << ", I am " << c.getAge() << " years old." << std::endl;
     std::cout << "Hi, everyone! My name is " << d.getName() << ", I am " << d.getAge() << " years old." << std::endl;
    return 0;
}