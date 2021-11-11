#include<iostream>
using namespace std;

//Slow algo
int fib_recursive(int n){
	if (n <= 1)
		return n;
	else
		return fib_recursive(n - 1) + fib_recursive(n - 2);
}

//faster algo
long long int fib_arr(int n){
	long long arr[n+1];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	return arr[n];
}

//without arr
long long fib_num(int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	int a = 0, b = 1, c = 0;

	for (int i = 2; i <= n; i++){
		c = a + b;
		a = b; b = c;
	}
	return c;
}

//task2
long long fib_num2(long long n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	long long a = 0, b = 1, c = 0;

	for (int i = 2; i <= n; i++){
		c = (a + b) % 10;
		a = b; b = c;
	}
	return c;
}

int main(){
	// cout << fib_recursive(100) << endl;
	
	cout << fib_num2(841645) << endl;

	return 0;
}