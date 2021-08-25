//1)

// #include <stdio.h>
// #include <stdlib.h>

// long long sum(long a,long b){
//     return (long long)(a + b);    
// }

// void test(){
//     const long a = 23333333231;
//     const long b = -23333333231;
//     const long c = 10987654321;
//     assertEqual(sum(12345678910, 10987654321), a);
//     assertEqual(sum(-12345678910, -10987654321), b);
//     assertEqual(sum(0, 10987654321), c);
// }

// int main()
// {
//     long a, b;
//     scanf("%ld%ld", &a, &b);
    
//     test();
//     long long result = sum(a, b);
//     printf("%ld",result);
//     return 0;
// }

//////////////////////////////////////////////////////////
//2)

// #include <stdio.h>
// #include <stdlib.h>

// int count(long a)
// {
//     int c = 0;
    
//     while(a > 0) 
//     {
//         c += a & 0x01;
//         a = a >> 1;
        
//     }
//     return c;
// }

// void test()
// {
//     assertEqual(count(0b0), 0);
//     assertEqual(count(0b1), 1);
//     assertEqual(count(0b100000000000), 1);
//     assertEqual(count(0b101011001010011), 8);
// }

// int main()
// {
//     long a;
//     scanf("%ld", &a);

//     test();

//     int res = count(a);
//     printf("%d", res);
//     return 0;
// }

///////////////////////////////////////////////////////////
//3)

// #include <stdio.h>
// #include <stdlib.h>

// float pow_(int a,int b){
//     if (a == 0)
//         return 0;
//     if (a == 1)
//         return 1;
//     if (b == 1)
//         return (float)a;
//     if (b == 0)
//         return 1;

//     float x = a;
//     float z = a;

//     for(int i = 1; i < abs(b); i++)
//         z *= x;
//     if (b < 0)
//         z = 1/z;
//     return z;
// }

// void test()
// {

//     assertEqual(pow_(0, 20), 0);
//     assertEqual(pow_(1, 20), 1);
//     assertEqual(pow_(2, 3), 8);
//     assertEqual(pow_(10, 3), 1000);
//     assertEqual(pow_(1000, 0), 1);
//     assertEqual(pow_(1000, 1), 1000);
//     assertEqual(pow_(10, -1), (float)1/10);
//     assertEqual(pow_(10, -2), (float)1/100);
// }

// int main()
// {
//     int a,b;
//     scanf("%d%d", &a, &b);
//     test();

//     float res = pow_(a, b);
//     printf("%f",res);
//     return 0;
// }

/////////////////////////////////////////////////////////////
//4)

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int count(const char* n)
// {
//     char* s = malloc(sizeof(char) * (strlen(n)+1));
//     strcpy(s, n);
//     char* word[100];
    
//     char* pch;
//     pch = strtok(s, " ");
//     int i = 0;
//     while (pch != NULL)
//     {
//         word[i]=pch;
//         i++;
//         pch = strtok(NULL, " ");
//     }

//     int max = 0;
//     for (int j = 0; j < i; j++)
//     {
//         int z = 0;
//         for (int k = j; k < i; k++)
//             if(strcmp(word[j], word[k]) == 0)
//                 z++;
//         if(z > max)
//             max = z;
//     }
//     return max;
// }

// // void test()
// // {
// //     char* s1 = "123 321 123 321 123 321 456 654 123";
// //     char* s2 = "123";
// //     char* s3 = "123 123 123";
// //     char* s4 = "123 321 456";
// //     assertEqual(count(s1), 4);
// //     assertEqual(count(s2), 1);
// //     assertEqual(count(s3), 3);
// //     assertEqual(count(s4), 1);
// // }

// int main()
// {
//     char str[200];
//     fgets(str, 200, stdin);

//     // test();

//     int res = count(str);
//     printf("%d", res);
//     return 0;
// }
