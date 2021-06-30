#include<iostream>

int main()
{
	//std::cout<< (int)'$' << std::endl;
	//std::cout.put('$'); std::cout << std::endl;
	
	// std::cout << "\aEnter your code:____\b\b\b\b";
	// int code;
	// std::cin >> code;
	// std::cout << "\aYour code is " << code << std::endl;
	
	//std::cout << sizeof(wchar_t) << std::endl;

	int *pt = new int;
	*pt = 123;
	double *pd = new double;
	*pd = 123.332;

	std::cout << sizeof(*pt) << " " << sizeof(pt) << std::endl;
	std::cout << sizeof(*pd) << " " << sizeof(pd) << std::endl;


	return 0;
}
