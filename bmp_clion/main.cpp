#include"my_bmp.h"
// #include<iostream>
// #include<cstdlib>
// #include<cstdio>
// #include<fstream>
// #include<string>
// #include<cctype>
// #include"my_bmp_v3.h"

bool check(const char* file_name)
{
    checking_header a;
    std::ifstream fout (file_name, std::ifstream::binary);
    fout.read(reinterpret_cast<char*>(&a), sizeof(checking_header));
    std::cout << "header size: " << a.header_size << std::endl;
    if (a.header_size != 40)
        return false;
    else return true;
}


int main()
{
    // check_version_bmp* aa = new check_version_bmp;
    // std::ifstream ch("simpsonsvr.bmp", std::ifstream::binary);
    // ch.read((char*)aa, sizeof(check_version_bmp));

    // if (aa->header_size == 40)
    //     printf("Ok!");

    // int a =4;
    // double b = 5.5;
    // double cc = um>(a, b);
    // std::cout << cc << std::endl;

    // check_bmp* a = new check_bmp;

    // std::ifstream fout("simpsonsvr.bmp", std::ifstream::binary);
    // if(!fout.is_open()){
    //     std::cout << "ERROR open file" << std::endl;
    //     return 0;
    // }

    // fout.read((char*)a, sizeof(check_bmp));
    // std::cout << "Object created" << std::endl;
    // fout.close();

    // std::printf("signature:\t%x\t(%hu)\n", a->signature, a->signature);
    // std::printf("filesize:\t%x\t(%u)\n", a->file_size, a->file_size);
    // std::printf("reserved1:\t%x\t(%hu)\n", a->reserved1, a->reserved1);
    // std::printf("reserved2:\t%x\t(%hu)\n", a->reserved2, a->reserved2);
    // std::printf("pixelArrOffset:\t%x\t(%u)\n", a->offset_PA, a->offset_PA);

    // std::printf("headerSize:\t%x\t(%u)\n", a->header_size, a->header_size);


    // BMP_ a("simpsonsvr.bmp");

    const char* file_name = "simpsonsvr.bmp";
    if (!check(file_name))
    {
        std::cout << "Sorry, program support only bmp of 3rd version!" << std::endl;
        exit(EXIT_SUCCESS);
    }

    // bmp_v3* a = new bmp_v3(file_name);
    bmp_v3 a(file_name);
    a.info();

    // change_color_from_user(a);

    // a.exact_changement();

    // a->draw(400, 300, 200, false, 0, 0, 0);

    // a.copy_region(1500, 1000, 1700, 200, 200, 800);

    a.draw_frame(5, 60, 255, 0, 0);
    // a->__kkkk();

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

    a.save_changes("test_class.bmp");
    std::ofstream fout("test_class.bmp", std::ofstream::binary);

    fout << a;
    fout.close();

    // printf("%ld\n", sizeof(rgb*));
    // printf("%ld\n", sizeof(unsigned short));



    return 0;
}