#include<iostream>
#include<mine.hpp>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	// int a = 3, b = 99;

	// mine::swap<int>(a, b);
	// cout << a << " " << b << endl;

	srand(time(0));
	int arr[1000];
	for (int i = 0; i < 1000; ++i)
	{
		arr[i] = rand() % 1000;
	}
	for (int i = 0; i < 1000; ++i)
	{
		cout << arr[i] << endl;
	}
	cout << endl;

	mine::selection_sort<int>(arr, 1000);

	for (int i = 0; i < 1000; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}