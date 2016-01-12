#include <iostream>
using namespace std;

template <class T>
void print(const T& arg)
{
   cout << arg << ' ';
}



template <class ... Args>
void print_(Args ... args)
{
   cout << "Il y a " << sizeof...(args) << " elements:\n\t";
   print(args...);
}


template <class T, class ... Args>
void print(const T& arg, Args ... args)
{
   print(arg);
   print(args...);
}

template <class T>
void print_size(T&& arg)
{
   cout << sizeof(arg) << endl;
}

template <class T, class ... Args>
void print_size(T&& arg, Args &&... args)
{
   print_size(std::forward<T>(arg));
   print_size(std::forward<Args>(args)...);
}

struct X
{
   int f() const noexcept { return 3; };
};
struct Y
{
   int g() const noexcept { return 4; };
};
struct Z
{
   int h() const noexcept { return 5; };
};

template <class ... P>
struct Tapon : P...
{

};

int main()
{
   Tapon<X, Y, Z> ze_tapon;
   cout << ze_tapon.f() << ' ' << ze_tapon.g() << ' ' << ze_tapon.h() << ' ' << endl;
}