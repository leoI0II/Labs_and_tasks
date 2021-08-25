#ifndef MY_BMP_H
#define MY_BMP_H
#include<string>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<ctime>
#include<fstream>
#define _USE_MATH_DEFINES
#include<cmath>
#include <algorithm>
#pragma pack(push, 1)

struct checking_header
{
    unsigned short signature;
    unsigned int   file_size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int   offset_PA;
    unsigned int   header_size;
    unsigned int   width;
    unsigned int   height;
    unsigned short color_planes_num;
    unsigned short bits_for_pixel;
    unsigned int   compression;
    unsigned int   image_size;
    unsigned int   X_ppm;
    unsigned int   Y_ppm;
    unsigned int   colors_color_table;
    unsigned int   important_color; 
};

struct file_header
{
    unsigned short signature;
    unsigned int   file_size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int   offset_PA;
};

struct file_info_header
{
    unsigned int   header_size;
    unsigned int   width;
    unsigned int   height;
    unsigned short color_planes_num;
    unsigned short bits_for_pixel;
    unsigned int   compression;
    unsigned int   image_size;
    unsigned int   X_ppm;
    unsigned int   Y_ppm;
    unsigned int   colors_color_table;
    unsigned int   important_color;    
};

struct rgb
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

class bmp_v3
{
private:
    file_header fileHeader;
    file_info_header fileInfoHeader;


    rgb** pixels;

    void change_red_color(unsigned int _red)
    {
        for (int i = 0; i < fileInfoHeader.height; i++)
            for (int j = 0; j < fileInfoHeader.width; j++)
                pixels[i][j].red = _red;
    }

    void change_blue_color(unsigned int _blue)
    {
        for (int i = 0; i < fileInfoHeader.height; i++)
            for (int j = 0; j < fileInfoHeader.width; j++)
                pixels[i][j].blue = _blue;
    }

    void change_green_color(unsigned int _green)
    {
        for (int i = 0; i < fileInfoHeader.height; i++)
            for (int j = 0; j < fileInfoHeader.width; j++)
                pixels[i][j].green = _green;
    }

    void set_Pixel(int x, int y, uint8_t change_red, uint8_t change_green, uint8_t change_blue){
        pixels[x][y].green = change_green;
        pixels[x][y].red = change_red;
        pixels[x][y].blue = change_blue;
    }
    void setPixel_line(int coor_x, int coor_y, int thickness, int maxX, int maxY, uint8_t red, uint8_t green, uint8_t blue)
    {
        pixels[coor_x][coor_y].green = green;
        pixels[coor_x][coor_y].red = red;
        pixels[coor_x][coor_y].blue = blue;

        if (thickness <= 1) return;
        if (coor_x - 1 >= 0) this->setPixel_line(coor_x - 1, coor_y, thickness-1, maxX, maxY, red, green, blue);
        if (coor_y - 1 >= 0) this->setPixel_line(coor_x, coor_y - 1, thickness-1, maxX, maxY, red, green, blue);
        if (coor_x + 1 < maxX) this->setPixel_line(coor_x + 1, coor_y, thickness-1, maxX, maxY, red, green, blue);
        if (coor_y + 1 < maxY) this->setPixel_line(coor_x, coor_y + 1, thickness-1, maxX, maxY, red, green, blue);
        return;
    }

    void draw_line(int x0, int y0, int x1, int y1, int maxX, int maxY, int thickness, uint8_t color_red, uint8_t color_green, uint8_t color_blue);
    // void fill(int centre_x, int centre_y, uint8_t source_red, uint8_t source_green, uint8_t source_blue, uint8_t change_red, uint8_t change_green, uint8_t change_blue);
    void fill( int**matrix, uint8_t fill_red, uint8_t fill_green, uint8_t fill_blue);
    void _fill(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t r_l, uint8_t g_l, uint8_t b_l);
    void draw_line_for_triangle(int x0, int y0, int x1, int y1, uint8_t red, uint8_t green, uint8_t blue);
    // void set_pixel_line_for_triangle(int x, int y, uint8_t red, uint8_t green, uint8_t blue);


public:
    bmp_v3(const char* file_name);
    bmp_v3();
    ~bmp_v3();
    void save_changes(const char* new_file_name);
    void change_color(const std::string& choice, const std::string& change);
    // void exact_changement(uint8_t b_red, uint8_t b_green, uint8_t b_blue, uint8_t a_red, uint8_t a_green, uint8_t a_blue);
    void exact_changement(uint8_t b_red, uint8_t b_green, uint8_t b_blue, uint8_t a_red, uint8_t a_green, uint8_t a_blue);
    // void draw(int x, int y, int radius, bool fill, uint8_t red, uint8_t green, uint8_t blue);
    void draw_hexagon_circ(int x, int y, int radius, bool fill, int thickness, uint8_t red, uint8_t green, uint8_t blue, uint8_t fill_red, uint8_t fill_green, uint8_t fill_blue);
    void draw_hexagon_sq(int left_x, int left_y, int right_x, int right_y, bool fill, int thickness, uint8_t red, uint8_t green, uint8_t blue, uint8_t fill_red, uint8_t fill_green, uint8_t fill_blue);
    void info();

    void copy_region(int x_left_top_point, int y_left_top_point, int x_right_bottom_point, int y_right_bottom_point, int x_cpy, int y_cpy);

    void draw_frame(uint16_t mode, int frame_width, uint8_t color_red, uint8_t color_green, uint8_t color_blue);
    void merge_pics(const char* file_name2);

    friend std::ostream& operator<<(std::ostream& fos, const bmp_v3& file_data);
    friend std::ostream& operator<<(std::ostream& fos, const bmp_v3* file_data);
    friend void change_color_from_user(bmp_v3& a);
    friend void merge_pics(bmp_v3 &a, bmp_v3 &b, const char* save_file);

    // friend void Draw(bmp_v3 &a);
    
};
#pragma pack(pop)

// unsigned char bitextract(const unsigned int byte, const unsigned int mask);

struct point
{
    int x, y;
};

#endif /* MY_BMP_H */
