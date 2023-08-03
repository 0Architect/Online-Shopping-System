#include <iostream>
#include <string>

using std::string;

class Product
{
    private:
        int productId;
        string productName;
        double price;
        string productType;

    protected:
        Product(int id, const string& pname, double price, const string& type)
         : productId(id), productName(pname), price(price), productType(type){}

    public:
        virtual void displayProductionInfo()
        {
            std::cout << "Product Information: " << '\n';
            std::cout << "Product Type: " << productType << '\n';
            std::cout << "Product ID: " << productId << '\n';
            std::cout << "Product Name: " << productName << '\n';
            std::cout << "Price: $" << price << '\n';
        }
};

class Electronics : public Product
{
    private:
        int ram;
        int quality;

    public:
        Electronics(int id, const string& pname, double price, int ram, int quality)
         : Product(id, pname, price, "Electronics"), ram(ram), quality(quality){}

        void displayProductionInfo()
        {
            Product::displayProductionInfo();
            std::cout << "RAM: " << ram << "gb\n";
            std::cout << "Quality: " << quality << '\n';
        }
};

class Clothing : public Product
{
    private:
        int size;
        string color;

    public:
        Clothing(int id, const string& pname, double price, int size, const string& color)
         : Product(id, pname, price, "Clothing"), size(size), color(color){}

        void displayProductionInfo()
        {
            Product::displayProductionInfo();
            std::cout << "Size: " << size << '\n';
            std::cout << "Color: " << color << '\n';
        }
};

class Books : public Product
{
    private:
        int pages;
        string author;

    public:
        Books(int id, const string& pname, double price, int pages, const string& author)
         : Product(id, pname, price, "Books"), pages(pages), author(author){}

        void displayProductionInfo()
        {
            Product::displayProductionInfo();
            std::cout << "pages: " << pages << '\n';
            std::cout << "author: " << author << '\n';
        }
};

int main()
{
    int choice, productId, productPrice, item2, item3;
    string productName, item1;

    std::cout << "Choose a product type: " << '\n';
    std::cout << "1. Electronics" << '\n';
    std::cout << "2. Clothing" << '\n';
    std::cout << "3. Books" << '\n';
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    Product *pointer = nullptr;

    std::cout << '\n' << "Enter product Id: "; std::cin >> productId;
    std::cout << "Enter product name: "; std::cin >> productName;
    std::cout << "Enter product price: "; std::cin >> productPrice;

    if(choice == 1)
    {
    std::cout << "Enter product RAM: "; std::cin >> item2;
    std::cout << "Enter product Quality: "; std::cin >> item3;

    pointer = new Electronics(productId, productName, productPrice, item2, item3);
    }

    else if(choice == 2)
    {
    std::cout << "Enter product size: "; std::cin >> item2;
    std::cout << "Enter product color: "; std::cin >> item1;

    pointer = new Clothing(productId, productName, productPrice, item2, item1);
    }

    else if(choice == 3)
    {
    std::cout << "Enter product pages: "; std::cin >> item2;
    std::cout << "Enter product author: "; std::cin >> item1;

    pointer = new Books(productId, productName, productPrice, item2, item1);
    }

    std::cout << '\n';
    pointer->displayProductionInfo();

    return 0;
}