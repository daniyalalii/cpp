#include <iostream>
using namespace std;
class book
{
private:
    string title;
    int pages;

public:
    book(string t, int p) : title(t), pages(p) {};
    void showData()
    {
        cout << "----------------------" << endl;
        cout << "Book Name: " << title << endl;
        cout << "Pages: " << pages << endl;
    }
};
class Library
{
private:
    book *books;

public:
    Library(book *b) : books(b) {}
    void showLibrary()
    {
        cout << "Library has following books: " << endl;
        books->showData();
    }
};

int main()
{
    book b1("Object Oriented Programming", 1023);
    book b2("Data Structures and Algorithm", 987);
    Library lib(&b1);
    lib.showLibrary();
    cout << "-------------------------" << endl;
    cout << "Books class: " << endl;
    b2.showData();
    return 0;
}