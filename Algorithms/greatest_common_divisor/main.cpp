#include<iostream>
#include<cassert>
using namespace std;

//naive algo
int gcd1(int &a, int& b){
	int gcd = 1, max = (a > b ? a : b);		//чтобы не писать лишний код в случае если одно из чисел 0, так то нужно минимальное число

	for (int i = 2; i < max; i++){
		if (i % a == 0 && i % b == 0)
			gcd = i;
	}
	return gcd;
}

//Euclid Algo of gcd
long long euclid_gcd(long long a, long long b){
	if (a == 0) return b;
	if (b == 0) return a;
	if (a >= b) return euclid_gcd(a % b, b);
	if (a <= b) return euclid_gcd(a, b % a);
}

int main(){

	cout << euclid_gcd(64, 28) << endl;

	return 0;
}