#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<string>
#include<cctype>
#include"my_bmp.h"

int main()
{
    // int a =4;
    // double b = 5.5;
    // double cc = um>(a, b);
    // std::cout << cc << std::endl;

    BMP_ a("sample.bmp");

    // change_color_from_user(a);

    // a.exact_changement();

    a.draw(900, 600, 100);

    // std::string a;
    // std::getline(std::cin, a);
    // std::cout << a << std::endl;
    // std::getline(std::cin, a);
    // std::cout << a << std::endl;
    // a.clear();
    // std::cout << a << std::endl;


    // printf("%ld\n", sizeof(a));

    // a.change_color(0, 255, 255);
    // a.change_red_color(0);

    // a.save_changes("test_class.bmp");
    std::ofstream fout("test_class.bmp", std::ofstream::binary);

    fout << a;
    fout.close();

    // printf("%ld\n", sizeof(rgb*));
    // printf("%ld\n", sizeof(unsigned short));



    return 0;
}