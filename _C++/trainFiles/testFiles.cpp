#include<iostream>
#include<fstream>



// int main()
// {
//     char autom[50];
//     int year;
//     double aprice, dprice;

//     std::ofstream outfile;
//     outfile.open("testFiles.txt");
//     outfile.clear();

//     std::cout << "Enter the make and the model of auto" << std::endl;
//     std::cin.getline(autom, 50);

//     std::cout << "Enter the year: ";
//     std::cin >> year;
//     std::cout << "Enter the price asking: ";
//     std::cin >> aprice;
//     dprice = 0.913*aprice;

//     std::cout << std::fixed;
//     std::cout.precision(2);
//     std::cout.setf(std::ios_base::showpoint);
//     std::cout << "Make and model " << autom << std::endl;
//     std::cout << "Year: " << year << std::endl;
//     std::cout << "Was asking $ " << aprice << std::endl;
//     std::cout << "Now asking $ " << dprice << std::endl;

//     outfile << std::fixed;
//     outfile.precision(2);
//     outfile.setf(std::ios_base::showpoint);
//     outfile << "Make and model " << autom << std::endl;
//     outfile << "Year: " << year << std::endl;
//     outfile << "Was asking $ " << aprice << std::endl;
//     outfile << "Now asking $ " << dprice << std::endl;
//     outfile.close();



//     return 0;
// }


// int main()
// {
//     std::ifstream fin;
//     fin.open("file.txt");

//     if(!fin.is_open()){
//         std::cerr << "Can not open ur file or it is not exist" << std::endl;
//         exit(EXIT_FAILURE);
//     }
//     char c[20];
//     std::string st;
//     while (!fin.eof()){
//         // st = "";
//         // fin >> st;
//         std::getline(fin, st);
//         std::cout << st << std::endl;
//     }

//     fin.close();


//     return 0;
// }


void pow(int &a, int &b)
{
    int tmp = 1;
    for (int i = 0; i < b; i++)
        tmp *= a;
    a = tmp;
}

int main()
{
    // system("touch lolo11.txt");
    // system("vim lolo11.txt");
    // system("i");
    // system("lol work");
    // system("Esc");


    // std::string file = "lolol.txt";
    // char c; c = getchar();

    // std::ofstream fout;
    // fout.open(file);

    // if (!fout.is_open())
    //     exit(EXIT_FAILURE);
    
    // fout << "Touch work mb!" << std::endl;

    int a = 2, b = 3;
    pow(a, b);
    std::cout << a << std::endl;

    return 0;
}