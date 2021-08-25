#include<stdio.h>
#include<stdlib.h>

#pragma pack(push, 1)
typedef struct bmpfileHeader
{
    unsigned short signature;
    unsigned int file_size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_PA;
} BMPFH;

typedef struct bitmapfileHeaderInfo
{
    unsigned int header_size;
    unsigned int widhth;
    unsigned int height;
    unsigned short color_planes_num;
    unsigned short bits_for_pixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int X_ppm;
    unsigned int Y_ppm;
    unsigned int colors_color_table;
    unsigned int important_color;
} BMPI;

typedef struct rgb
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;
#pragma pack(pop)

void print_bmp_headerInfo(BMPFH* header)
{
    printf("signature:\t%x\t(%hu)\n", header->signature, header->signature);
    printf("filesize:\t%x\t(%u)\n", header->file_size, header->file_size);
    printf("reserved1:\t%x\t(%hu)\n", header->reserved1, header->reserved1);
    printf("reserved2:\t%x\t(%hu)\n", header->reserved2, header->reserved2);
    printf("pixelArrOffset:\t%x\t(%u)\n", header->offset_PA, header->offset_PA);
}

void printInfoHeader(BMPI* header){
    printf("headerSize:\t%x\t(%u)\n", header->header_size, header->header_size);
    printf("width:     \t%x\t(%u)\n", header->widhth, header->widhth);
    printf("height:    \t%x\t(%u)\n", header->height, header->height);
    printf("planes:    \t%x\t(%hu)\n", header->color_planes_num, header->color_planes_num);
    printf("bitsPerPixel:\t%x\t(%hu)\n", header->bits_for_pixel, header->bits_for_pixel);
    printf("compression:\t%x\t(%u)\n", header->compression, header->compression);
    printf("imageSize:\t%x\t(%u)\n", header->image_size, header->image_size);
    printf("xPixelsPerMeter:\t%x\t(%u)\n", header->X_ppm, header->X_ppm);
    printf("yPixelsPerMeter:\t%x\t(%u)\n", header->Y_ppm, header->Y_ppm);
    printf("colorsInColorTable:\t%x\t(%u)\n", header->colors_color_table, header->colors_color_table);
    printf("importantColorCount:\t%x\t(%u)\n", header->important_color, header->important_color);
}

int main()
{
    FILE* file = fopen("FLAG_B24.BMP", "rb");
    if (!file) exit(EXIT_FAILURE);

    // printf("%ld %ld\n", sizeof(BMPFH), sizeof(BMPI));

    BMPFH *file_header = (BMPFH*) malloc (sizeof(BMPFH));
    BMPI *file_info = (BMPI*) malloc (sizeof(BMPI));

    fread(file_header, 1, sizeof(BMPFH), file);
    print_bmp_headerInfo(file_header);
    fread(file_info, 1, sizeof(BMPI), file);
    printInfoHeader(file_info);

    RGB** pixels = (RGB**) malloc (file_info->height * sizeof(RGB*));
    for (size_t i = 0; i < file_info->height; i++){
        pixels[i] = (RGB*) malloc (file_info->widhth * sizeof(RGB) + (file_info->widhth * sizeof(RGB))%4);
        fread(pixels[i], 1, file_info->widhth * sizeof(RGB) + (file_info->widhth * sizeof(RGB))%4, file);
    }

    unsigned char choice;
    unsigned int num;
// link11:
//     printf("Enter a color you would like to change - (r/g/b): ");
//     scanf("%c", &choice);
//     getchar();
//     printf("Enter what count you would like to change: ");
//     scanf("%d", &num);
//     getchar();
//     // printf("%c %d\n", choice, num);

//     switch (choice)
//     {
//     case 'r':
//         for (size_t i = 0; i < file_info->height; i++){
//             for (size_t j = 0; j < file_info->widhth ; j++){
//                 pixels[i][j].red = num;
//             }
//         }
//         break;
//     case 'b':
//         for (size_t i = 0; i < file_info->height; i++){
//             for (size_t j = 0; j < file_info->widhth; j++){
//                 pixels[i][j].blue = num;
//             }
//         }
//         break;
//     case 'g':
//         for (size_t i = 0; i < file_info->height; i++){
//             for (size_t j = 0; j < file_info->widhth; j++){
//                 pixels[i][j].green = num;
//             }
//         }
//         break;
//     default:
//         puts("Try again!");
//         goto link11;
//     }

    for (size_t i = 0; i < 1; i++){
        for (size_t j = 0; j < 10; j++){
                pixels[i][j].green = 255;
                pixels[i][j].red = 255;
                pixels[i][j].blue = 255;
        }
    }


    fclose(file);

    unsigned int old_wid = file_info->widhth;
    unsigned int old_heigth = file_info->height;

    FILE* new_file = fopen("lul.bmp", "wb");
    fwrite(file_header, 1, sizeof(BMPFH), new_file);
    fwrite(file_info, 1, sizeof(BMPI), new_file);

    for (size_t i = 0; i < old_heigth; i++)
        fwrite(pixels[i], 1, old_wid * sizeof(RGB) + (old_wid * sizeof(RGB))%4, new_file);

    fclose(new_file);


    return 0;
}