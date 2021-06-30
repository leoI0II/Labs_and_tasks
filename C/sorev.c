// #include <stdio.h>
// #include <math.h>

// int main(){
// //task1
//     // int num;
//     // scanf("%d", &num);
//     // printf("%d\n", (int)pow(5, num)%100);

// //task2
//     // int n, sum = 0;
//     // scanf("%d", &n);
//     // for(int i = 1; i <= n; i++){
//     //     if(i % 2) sum -= i;
//     //     else sum += i;
//     // }

//     // printf("%d\n", sum);

// //task3

//     int nums[2], day = 0;
//     for(int i =  0; i < 2; i++){
//         scanf("%d", &nums[i]);
//     }
//     int j = 1, n = nums[0];
//     while( n > 0 ){
//         n -= 1;
//         day += 1;
//         if (day == nums[1] * j){
//             n += 1;
//             j += 1;
//         }
//     }
//     printf("%d\n", day);


//     return 0;
// }





// #include <iostream>
// using namespace std;
// bool odd(int n) {
//     bool f = true;
//     if (n == 1 || n == 0) f = false;
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//             f = false;
//     }
//     if (f) return true;
//     else return false;
// }
// int main() {
//     int a[501][501];
//     int n, m;
//     cin >> n >> m;
//     if (n <= 500 && m <= 500 && n >= 1 && m >= 1) {
//         bool f1 = false, f2 = false;
//         for (int i = 0; i < n; i++) {
//             int k = 0;
//             for (int j = 0; j < m; j++) {
//                 cin >> a[i][j];
//                 if (odd(a[i][j]) == 1) k++;
//             }
//             if (k == m) {
//                 f1 = true;
//             }
//         }
//         for (int j = 0; j < m; j++) {
//             int h = 0;
//             for (int i = 0; i < n; i++) {
//                 if (odd(a[i][j]) == 1) h++;
//             }
//             if (h == n) {
//                 f2 = true;
//                 break;
//             }
//         }
//         if (f1 == true || f2 == true) cout << 0;
//         else {
//             int min = INT_MAX, now = 0;
//             bool f3 = false, f4 = false;
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < m; j++) {
//                     int b = a[i][j];
//                     while (odd(b) != 1) {
//                         now++;
//                         b++;
//                     }
//                 }
//                 if (now <= min) min = now;
//                 now = 0;
//                 break;
//             }
//             if (!f3) {
//                 for (int j = 0; j < m; j++) {
//                     for (int i = 0; i < n; i++) {
//                         int c = a[i][j];
//                         while (odd(c) != true) {
//                             now++;
//                             c ++;
//                         }
//                     }
//                     if (now <= min) min = now;
//                     now = 0;
//                     break;
//                 }
//             }
//             cout << min;
//         }
//     }
//     return 0;
// }




#include <stdio.h>

int main(){
    int a[10];

    for (int i = 0 ; i < 10 ; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10 ; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int j = 9; j >= 0; j--){
        printf("%d ", a[j]);
    }


    return 0;
}