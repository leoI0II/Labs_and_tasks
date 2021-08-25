#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <limits.h>

// void is_in();
// int nSquare();
// int get_max(int a, int b, int c);
// int get_max(int x[]);
// double discriminant(float x, float y, float z);

// void is_in(float x, float y){
// 	//double x, y;
// 	//scanf("%lf %lf\n", &x, &y);
// 	if((pow(("%.4f", x), 2) + pow(("%.4f", y), 2) >= 1.0001) && (("%.4f", x) <= 1.0001) && 
// 	(("%.4f", y) <= 1.0001) && (("%.4f", x) >= 0) && (("%.4f", y) >= 0)){
// 		printf("true\n");
// 	} else {
// 		printf("false\n");
// 	}
// }

// int nSquare(){
// 	int N;
// 	scanf("%d", &N);
// 	if (N > 1){
// 		for(int i = 1; i < N; i++){
// 			printf("%d\n", i*i);
// 		}
// 	}
// }

// int get_max(int x[]){
// 	int max = 0;
// 	for(int i = 0; i < 15; ++i){
// 		scanf("%d", &x[i]);
// 		if(x[i] > max) max = x[i];
// 	} return max;
// }

// int get_max(int a, int b, int c){
// 	if (a > b && a > c) return a;
// 	else if (b > a && b > c) return b;
// 	else return c;
// }

// double discriminant(float x, float y, float z){
//     return sqrt(pow(y, 2) + (-4)*x*z);
// }


int main(){
	// float a, b, c;
	// float d;
	// scanf("%f %f %f", &a, &b, &c);
	// d = discriminant(a, b, c);
	// printf("%f\n", d);
	// return 0;

	//double a = 3.1234567890;
	//double b = 3.12345678901;
	//int n = 123;
	//printf(":%20.8f::%96.8f:\n", a, b);
	//printf("%-25.10f%6X")
	// int a = 5;
	// while(a % 4){
	// 	printf("%d ", ++a);
	// }
	//printf("%d\n", get_max(1, 2, 3));
	// int c;
	// c = getchar(); // putchar(c);
	// while(c != EOF) {
	// 	putchar(c);
	// 	c = getchar();
	// }
	// printf("%d\n", EOF);
	// int nc, nl = 0;
	// while((nc = getchar()) != EOF) if (nc == '\t') ++nl;
	// printf("%d\n", nl);
	// int list[15];
	// printf("%d\n", get_max(list));

	// int n;
	// scanf("%d", &n);
	
	// if (n > 1){
	// 	for(int i = 1; i < n; i++){
	// 		if (i == 1) printf("%d/pre>\n", i*i);
	// 		printf("%d\n", i*i);
	// 	}
	// }
	//nSquare();
	// double x1, y1;
	// scanf("%lf %lf", &x1, &y1);
	// is_in(x1, y1);
	//printf("%lld\n", LLONG_MAX);
	long unsigned int N, i = 1;
	scanf("%lu", &N);
	
	if(N > 1){
		while(i < N){
			if (i == 1) {
			    printf("%lu/pre>\n", i*i);
				i++;
			} else {
    			printf("%lu\n", i*i);
    			i++; }
		}
	} else if(N == 1) printf("%lu/pre>\n", i*i);
	
	
	return 0;
}







