#include <stdio.h>
#include <stdlib.h>


// int main()
// {
//     FILE* fs = fopen("file", "wb");

//     double t[5] = {23.5, 12.4, 34.5, 20, 3.4};
//     fwrite(t, sizeof(double), 5, fs);
//     fclose(fs);

//     FILE* fp = fopen("file", "rb");
//     double *d = (double*) malloc (5* sizeof(double));
//     fread(d, sizeof(double), 5, fp);
//     for (int i = 0; i < 5; i++)
//         printf("%.3lf ", d[i]);

//     printf("\n");

//     fclose(fs);

//     return 0;
// }

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


// int main()
// {
//     // FILE* fd = fopen("text.txt", "r");

//     char ch;
//     while ((ch = getchar()) != EOF)
//         putchar(ch);

//     printf("\n");

//     return 0;
// }


//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

//task 4 from book
// int main(int argc, char* argv[])
// {
//     FILE* fp;
    
//     if(argc == 1) fp = stdin;
//     if (argc == 2) 
//         if((fp = fopen(argv[1], "r")) == NULL){
//             fprintf(stderr, "Cant open %s. Bye\n", argv[1]);
//             exit(EXIT_FAILURE);
//         }
    

//     double num, res = 0;
//     int c = 0;
//     while (fscanf(fp, "%lf", &num) == 1)
//     {
//         res += num;
//         c++;
//     }

//     printf("%lf\n", res/c);


//     return 0;
// }


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// int check_symbol(char* str, char symbol);

// //task5 from book DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// int main(int argc, char* argv[])
// {
//     FILE* fp = fopen("text.txt", "r");

//     if (argc > 3){
//         fprintf(stderr, "You must enter %s <char_symbol> <filename>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     if (argc == 1 || argc == 2){
//         fprintf(stderr, "You must enter %s <char_symbol> <filename>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     if ((fp = fopen(argv[2], "r")) == NULL){
//         fprintf(stderr, "Error opening file %s\n", argv[2]);
//         exit(EXIT_FAILURE);
//     }

//     char symbol = argv[1][0];
//     char ch;
//     char *str = (char*) malloc (sizeof(char));
//     str[0] = '\0';
//     int size = 1, i = 0;

//     while ((ch = getc(fp)) != EOF)
//     {
//         if (i == 0 && ch == ' ' || (i == 0 && ch == '\n'))
//             continue;

//         str[i] = ch;
//         str = realloc(str, (size + 1)*sizeof(char));
//         str[i+1] = '\0';
//         ++size; ++i;

//         if (ch == '.' || ch == '!' || ch == '?')
//         {
//             if (check_symbol(str, symbol)){
//                 fprintf(stdout, "%s\n", str);
//                 free(str);
//                 str = (char*) malloc (sizeof(char));
//                 i = 0; size = 1;
//             }
//             else
//             {
//                 free(str);
//                 str = (char*) malloc (sizeof(char));
//                 i = 0; size = 1;
//             }
//         }
//     }


//     return 0;
// }

// int check_symbol(char* str, char symbol)
// {
//     while (*str)
//     {
//         if (*str++ == symbol)
//             return 1;
//     }
//     return 0;
// }


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//Из Упражнений по программированию (из книги)

#include<string.h>
#include<ctype.h>

// //task3 DONE
// int main()
// {
//     printf("Enter the filename of the source file: ");
    
//     char *src_file = (char*) malloc (40* sizeof(char));
//     fgets(src_file, 40, stdin);
//     src_file[strlen(src_file) -1] = '\0';

//     printf("Enter the filename of the destination file: ");

//     char* dest_file = (char*) malloc (40 * sizeof(char));
//     fgets(dest_file, 40, stdin);
//     dest_file[strlen(dest_file) - 1] = '\0';

//     FILE* sf = fopen(src_file, "r");
//     if (sf == NULL){
//         fprintf(stderr, "Cant open %s file!\n", src_file);
//         exit(EXIT_FAILURE);
//     }

//     FILE* df = fopen(dest_file, "w");
//     if (df == NULL){
//         fprintf(stderr, "Cant open %s file!\n", dest_file);
//         exit(EXIT_FAILURE);
//     }


//     char sym;

//     while ((sym = getc(sf)) != EOF)
//     {
//         // if (sym == '\n'){
//         //     fputc(sym, df);
//         //     continue;
//         // }
//         // if (isblank(sym)){
//         //     fputc(sym, df);
//         //     continue;
//         // }
//         // if (ispunct(sym)){
//         //     fputc(sym, df);
//         //     continue;
//         // }
//         // if (isdigit(sym)){
//         //     fputc(sym, df);
//         //     continue;
//         // }
//         // if (isalpha(sym)){
//             if (isupper(sym)){                     //можно и без кучи условий...))))
//                 fputc(sym, df);
//                 continue;
//             }
//             fputc(toupper(sym), df);
//         // }
//     }

//     if (feof(sf)){
//         fclose(sf);
//         fclose(df);
//     }


//     return 0;
// }


///////////////////////////////////////////////////
///////////////////////////////////////////////////

//task4 DONE
// int main(int argc, char* argv[])
// {
//     if (argc == 1){
//         fprintf(stderr, "You have to enter more datas: %s <filename1> <filename2> ... <filenameN>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     for (int i = 1; i < argc; i++)
//     {
//         FILE* sf = fopen(argv[i], "r");
//         char ch;
//         while ((ch = getc(sf)) != EOF)
//             putchar(ch);
//         if (feof(sf))
//             fclose(sf);
//         printf("\n");
//     }
//     printf("BYE!)\n");

//     return 0;
// }


////////////////////////////////////////////////////
////////////////////////////////////////////////////

//task7 DONE

// void clear_buf()
// {
//     int c;

//     while ( (c = getchar()) != '\n' && c != EOF ){}
// }

// int main(int argc, char* argv[])
// {
//     system("clear");

//     char *file1, *file2;

//     if (argc == 1)
//     {
//         printf("Так как вы не ввели файлы, можете ввести их названия сейчас.\n");
//         printf("Введите название первого файла: ");

//         file1 = (char*) malloc (30 * sizeof(char));
//         // scanf("%s", file1);
//         fgets(file1, 30, stdin);
//         file1[strlen(file1) -1] = '\0';

//         printf("Введите название второго файла: ");

//         file2 = (char*) malloc (30 * sizeof(char));
//         // scanf("%s", file2);
//         fgets(file2, 30, stdin);
//         file2[strlen(file2) -1] = '\0';

//         printf("Великолепно, вы ввели названия двух файлов: %s и %s\n", file1, file2);
//         printf("Все правильно? [y/n] ");
//         char yn;
//         yn = getchar();
//         clear_buf();
//         // scanf("%c", &yn);
//         if (yn == 'n')
//         {
//             printf("Какой файл был неправильно введен? [1/2] ");
//             char fs;
//             fs = getchar();
//             clear_buf();

//             if (fs == '1')
//             {
//                 int tr = 1;
//                 free(file1);
//                 while (tr)
//                 {
//                     printf("Введите название первого файла: ");

//                     file1 = (char*) malloc (30 * sizeof(char));
//                     scanf("%s", file1);
//                     clear_buf();

//                     printf("Название первого файла - %s. Правильно? [y/n] ", file1);
//                 _get:
//                     yn = getchar();
//                     clear_buf();
//                     if (yn == 'n')
//                     {
//                         free(file1);
//                         continue;
//                     }
//                     else if (yn == 'y')
//                         tr = 0;
//                     else{
//                         printf("Вводить y или n. Введите еще раз [y/n] ");
//                         goto _get;
//                     }
//                 }
//             }
//             else if (fs == '2')
//             {
//                 // int tr = 1;
//                 free(file2);
//                 while (1)
//                 {
//                     printf("Введите название второго файла: ");

//                     file2 = (char*) malloc (30 * sizeof(char));
//                     scanf("%s", file2);
//                     clear_buf();
//                     printf("Название второго файла - %s. Правильно? [y/n] ", file2);
//                 _get:
//                     yn = getchar();
//                     clear_buf();
//                     if (yn == 'n')
//                     {
//                         free(file1);
//                         continue;
//                     }
//                     else if (yn == 'y')
//                         break;
//                     else{
//                         printf("Вводить y или n. Введите еще раз [y/n] ");
//                         goto _get;
//                     }
//                 }
//             }
//         }
//     }
//     else if (argc == 2)
//     {
//         printf("Какой файл вы ввели в командной строке? [1/2] ");
//         char wht_f = getchar();
//         clear_buf();

//         while (1){
//             if (wht_f == '1')
//             {
//                 file1 = (char*) malloc (30 * sizeof(char));
//                 strcpy(file1, argv[1]);

//                 printf("Введите название второй строки: ");
//                 file2 = (char*) malloc (30 * sizeof(char));
//                 scanf("%s", file2);
//                 clear_buf();

//                 printf("Вы ввели %s. Правильно? [y/n] ", file2);
//                 char yn = getchar();
//                 clear_buf();

//                 while (yn != 'y')
//                 {
//                     free(file2);

//                     printf("Введите название второй строки: ");
//                     file2 = (char*) malloc (30 * sizeof(char));
//                     scanf("%s", file2);
//                     clear_buf();
                    
//                     printf("Вы ввели %s. Правильно? [y/n] ", file2);

//                     yn = getchar();
//                     clear_buf();
//                 }
//                 printf("Прекрасно!");
//                 break;
//             }
//             else if (wht_f == '2')
//             {
//                 file2 = (char*) malloc (30 * sizeof(char));
//                 strcpy(file2, argv[1]);

//                 printf("Введите название первой строки: ");
//                 file1 = (char*) malloc (30 * sizeof(char));
//                 scanf("%s", file1);
//                 clear_buf();

//                 printf("Вы ввели %s. Правильно? [y/n] ", file1);
//                 char yn = getchar();
//                 clear_buf();

//                 while (yn != 'y')
//                 {
//                     free(file1);

//                     printf("Введите название первой строки: ");
//                     file2 = (char*) malloc (30 * sizeof(char));
//                     scanf("%s", file2);
//                     clear_buf();

//                     printf("Вы ввели %s. Правильно? [y/n] ", file2);
//                     yn = getchar();
//                     clear_buf();
//                 }
//                 printf("Прекрасно!");
//                 break;
//             }
//             else
//             {
//                 printf("Введите значение еще раз [1/2] ");
//                 wht_f = getchar();
//                 clear_buf();
//             }
//         }
//     }
//     else
//     {
//         file1 = (char*) malloc (30 * sizeof(char));
//         file2 = (char*) malloc (30 * sizeof(char));

//         strcpy(file1, argv[1]);
//         strcpy(file2, argv[2]);
//     }

//     printf("Вы ввели названия 2-х файлов:\n1) %s\t2) %s\n", file1, file2);

//     FILE* f1, *f2;

//     f1 = fopen(file1, "r");
//     if (f1 == NULL){
//         fprintf(stderr, "Мы не смогли открыть файл %s. Перезапустите программу.", file1);
//         exit(EXIT_FAILURE);
//     }

//     f2 = fopen(file2, "r");
//     if (f2 == NULL){
//         fprintf(stderr, "Мы не смогли открыть файл %s. Перезапустите программу.", file2);
//         exit(EXIT_FAILURE);
//     }

//     char* str_f1 = (char*) malloc (256 * sizeof(char));
//     char* str_f2 = (char*) malloc (256 * sizeof(char));

//     while (fgets(str_f1, 256, f1) != NULL && fgets(str_f2, 256, f2) != NULL)
//     {
//         fputs(str_f1, stdout);
//         fputs(str_f2, stdout);
//         // puts("(1)");

//         free(str_f1); free(str_f2);

//         str_f1 = (char*) malloc (256 * sizeof(char));
//         str_f2 = (char*) malloc (256 * sizeof(char));
//     }

//     free(str_f1); free(str_f2);

//     if (feof(f1) && feof(f2))
//     {
//         fprintf(stdout, "\nПрограмма закончилась. Удачи!\n");
//         fclose(f1);
//         fclose(f2);

//         exit(EXIT_SUCCESS);
//     }
//     else if (feof(f1))
//     {
//         char ch;
//         while ((ch = fgetc(f2)) != EOF)
//         {
//             putchar(ch);
//         }
        
//         if (feof(f2)){
//             fprintf(stdout, "\nПрограмма закончилась. Удачи!\n");
//             fclose(f1);
//             fclose(f2);

//             exit(EXIT_SUCCESS);
//         }
//     }
//     else if (feof(f2))
//     {
//         char ch;
//         while ((ch = fgetc(f1)) != EOF)
//         {
//             fputc(ch, stdout);
//         }

//         if (feof(f1)){
//             fprintf(stdout, "\nПрограмма закончилась. Удачи!\n");
//             fclose(f1);
//             fclose(f2);

//             exit(EXIT_SUCCESS);
//         }
//     }

//     return 0;
// }


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

//work with DirPath
// int main(int argc, char* args[])
// {
//     FILE* file = fopen(args[1], "r");

//     char ch;
//     while ((ch = getc(file)) != EOF)
//         putchar(ch);

//     puts("Finish");
//     fclose(file);

//     return 0;
// }


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


