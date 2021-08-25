#include"my_bmp_v3.h"
// #include<iostream>
// #include<cstdio>
// #include<cctype>
// #include<cstdlib>
// #include<ctime>
// #include<fstream>
// #define _USE_MATH_DEFINES
// #include<cmath>
// #include <algorithm>
// #include"my_bmp_v3.h"

std::ostream& operator<<(std::ostream& fos, const bmp_v3& file_data)
{
    fos.write((char*)&file_data, sizeof(bmp_v3) - sizeof(rgb**));
    // fos.write((char*)&file_data, sizeof(file_header));
    // fos.write((char*)&file_data, sizeof(file_info_header));
    for (int i=0; i < file_data.fileInfoHeader.height; i++)
        fos.write((char*)file_data.pixels[i], file_data.fileInfoHeader.width * sizeof(rgb) + (file_data.fileInfoHeader.width * sizeof(rgb))%4);
    
    return fos;
}


std::ostream& operator<<(std::ostream& fos, const bmp_v3* file_data)
{
    fos.write((char*)file_data, sizeof(bmp_v3) - sizeof(rgb**));
    // fos.write((char*)file_data, sizeof(file_header));
    // fos.write((char*)file_data, sizeof(file_info_header));
    for (int i=0; i < file_data->fileInfoHeader.height; i++)
        fos.write((char*)file_data->pixels[i], file_data->fileInfoHeader.width * sizeof(rgb) + (file_data->fileInfoHeader.width * sizeof(rgb))%4);
    
    return fos;
}


void bmp_v3::save_changes(const char* new_file_name)
{
    std::ofstream fout(new_file_name, std::ofstream::binary);
    fout.write((const char*)this, sizeof(fileHeader));
    fout.write((const char*)this, sizeof(fileInfoHeader));
    for (int i = 0; i < fileInfoHeader.height; i++)
        fout.write((const char*)pixels[i], fileInfoHeader.width * sizeof(rgb) + (fileInfoHeader.width * sizeof(rgb))%4);
    fout.close();
}

bmp_v3::~bmp_v3(){
    for (int i = 0; i < fileInfoHeader.height; i++)
        delete [] pixels[i];
    delete [] pixels;
}

void bmp_v3::info()
{
    std::printf("signature:\t%x\t(%hu)\n", this->fileHeader.signature, this->fileHeader.signature);
    std::printf("filesize:\t%x\t(%u)\n", this->fileHeader.file_size, this->fileHeader.file_size);
    std::printf("reserved1:\t%x\t(%hu)\n", this->fileHeader.reserved1, this->fileHeader.reserved1);
    std::printf("reserved2:\t%x\t(%hu)\n", this->fileHeader.reserved2, this->fileHeader.reserved2);
    std::printf("pixelArrOffset:\t%x\t(%u)\n", this->fileHeader.offset_PA, this->fileHeader.offset_PA);

    std::printf("headerSize:\t%x\t(%u)\n", this->fileInfoHeader.header_size, this->fileInfoHeader.header_size);
    std::printf("width:     \t%x\t(%u)\n", this->fileInfoHeader.width, this->fileInfoHeader.width);
    std::printf("height:    \t%x\t(%u)\n", this->fileInfoHeader.height, this->fileInfoHeader.height);
    std::printf("planes:    \t%x\t(%hu)\n", this->fileInfoHeader.color_planes_num, this->fileInfoHeader.color_planes_num);
    std::printf("bitsPerPixel:\t%x\t(%hu)\n", this->fileInfoHeader.bits_for_pixel, this->fileInfoHeader.bits_for_pixel);
    std::printf("compression:\t%x\t(%u)\n", this->fileInfoHeader.compression, this->fileInfoHeader.compression);
    std::printf("imageSize:\t%x\t(%u)\n", this->fileInfoHeader.image_size, this->fileInfoHeader.image_size);
    std::printf("xPixelsPerMeter:\t%x\t(%u)\n", this->fileInfoHeader.X_ppm, this->fileInfoHeader.X_ppm);
    std::printf("yPixelsPerMeter:\t%x\t(%u)\n", this->fileInfoHeader.Y_ppm, this->fileInfoHeader.Y_ppm);
    std::printf("colorsInColorTable:\t%x\t(%u)\n", this->fileInfoHeader.colors_color_table, this->fileInfoHeader.colors_color_table);
    std::printf("importantColorCount:\t%x\t(%u)\n", this->fileInfoHeader.important_color, this->fileInfoHeader.important_color);
}



bmp_v3::bmp_v3(const char* file_name)
{
    std::ifstream fout(file_name, std::ifstream::binary);
    if(!fout.is_open()){
        fprintf(stderr, "Ошибка: файл %s не найден! Попробуйте снова.\n", file_name);
        exit(EXIT_FAILURE);
    }
    
    fout.read(reinterpret_cast<char*>(&fileHeader), sizeof(file_header));
    fout.read(reinterpret_cast<char*>(&fileInfoHeader), sizeof(file_info_header));


    // pixels = new rgb*[fileInfoHeader.height * sizeof(rgb*)];
    pixels = (rgb**) malloc (fileInfoHeader.height * sizeof(rgb*));
    for (int i = 0; i < fileInfoHeader.height; i++)
    {
        // pixels[i] = new rgb[fileInfoHeader.width * sizeof(rgb) + (fileInfoHeader.width * sizeof(rgb))%4];
        pixels[i] = (rgb*) malloc (fileInfoHeader.width * sizeof(rgb) + (fileInfoHeader.width * sizeof(rgb))%4);
        fout.read((char*)pixels[i], fileInfoHeader.width * sizeof(rgb) + (fileInfoHeader.width * sizeof(rgb))%4);
    }
    fout.close();
}

bmp_v3::bmp_v3()
{
    std::cout << "Object created" << std::endl;
}


void bmp_v3::exact_changement(uint8_t b_red, uint8_t b_green, uint8_t b_blue, uint8_t a_red, uint8_t a_green, uint8_t a_blue)
{
    for (int i = 0; i < fileInfoHeader.height; i++){
        for (int j = 0; j < fileInfoHeader.width; j++){
            if (pixels[i][j].red == (uint8_t)b_red && pixels[i][j].blue == (uint8_t)b_blue && pixels[i][j].green == (uint8_t)b_green)
            {
                this->set_Pixel(i, j, a_red, a_green, a_blue);
            }
        }
    }

}

void bmp_v3::draw_line(int x0, int y0, int x1, int y1, int maxX, int maxY, int thickness, uint8_t color_red, uint8_t color_green, uint8_t color_blue)
{
    ///////////////////////////////////////////////////////////////////
    int dx = (x1 - x0 >= 0 ? 1 : -1);
    int dy = (y1 - y0 >= 0 ? 1 : -1);

    int lengthX = abs(x1 - x0);
    int lengthY = abs(y1 - y0);

    int length = std::max(lengthX, lengthY);

    if (length == 0)
    {
        this->setPixel_line(x0, y0, thickness, maxX, maxY, color_red, color_green, color_blue);
        // this->set_Pixel(x0, y0);
    }

    if (lengthY <= lengthX)
    {
        // Начальные значения
        int x = x0;
        int y = y0;
        int d = -lengthX;

        // Основной цикл
        length++;
        while(length--)
        {
                this->setPixel_line(x, y, thickness, maxX, maxY, color_red, color_green, color_blue);
                // this->set_Pixel(x, y);
                x += dx;
                d += 2 * lengthY;
                if (d > 0) {
                    d -= 2 * lengthX;
                    y += dy;
                }
        }
    }
    else
    {
        // Начальные значения
        int x = x0;
        int y = y0;
        int d = -lengthY;

        // Основной цикл
        length++;
        while(length--)
        {
            this->setPixel_line(x, y, thickness, maxX, maxY, color_red, color_green, color_blue);
            // this->set_Pixel(x, y);
            y += dy;
            d += 2 * lengthX;
            if (d > 0) {
                d -= 2 * lengthY;
                x += dx;
            }
        }
    }
}


void bmp_v3::fill( int**matrix, uint8_t fill_red, uint8_t fill_green, uint8_t fill_blue)
{
    for (int y = 0; y < fileInfoHeader.height; y++)
        for (int x = 0; x < fileInfoHeader.width; x++)
            if(matrix[y][x] == 1)
                this->set_Pixel(y, x, fill_red, fill_green, fill_blue);

    return;
}

void bmp_v3::draw_hexagon_sq(int left_x, int left_y, int right_x, int right_y, bool fill, int thickness, uint8_t red, uint8_t green, uint8_t blue, uint8_t fill_red, uint8_t fill_green, uint8_t fill_blue)
{
    if (left_x <= 0 || left_y <= 0 || right_x <= 0 || right_y <= 0 || left_x >= fileInfoHeader.width || left_y >= fileInfoHeader.height || right_x >= fileInfoHeader.width || right_y >= fileInfoHeader.height
        || (left_y - right_y) < 0 || (right_x - left_x) < 0 )
    {
        std::cerr << "Ошибка: перепроверьте координаты! Попробуйте еще раз с другими координатами." << std::endl;
        exit(EXIT_FAILURE);
    }

    if (left_y - right_y == right_x - left_x){

        int centre_y = left_y - (left_y - right_y)/2;
        int centre_x = left_x + (right_x - left_x)/2;
        // this->set_Pixel(centre_y, centre_x, 0, 0, 0);
        int radius   = (left_y - right_y)/2;
        this->draw_hexagon_circ(centre_x, centre_y, radius, fill, thickness, red, green, blue, fill_red, fill_green, fill_blue);
    }
    else{
        std::cerr << "Это не квадрат! Попробуйте еще раз с другими координатами." << std::endl;
        exit(EXIT_FAILURE);
    }
}


void bmp_v3::draw_hexagon_circ(int x, int y, int radius, bool fill, int thickness, uint8_t red, uint8_t green, uint8_t blue, uint8_t fill_red, uint8_t fill_green, uint8_t fill_blue)
{
    if (radius == 0){
        fprintf(stderr, "Радиус равен нулю. Попробуйте снова.\n");
        exit(EXIT_FAILURE);
    }
    if (y + radius > fileInfoHeader.height || x + radius > fileInfoHeader.width || x < radius || y < radius){
        std::cerr << "Окружность выходит за пределы картинки! Попробуйте снова с другими координатами." << std::endl;
        exit(EXIT_FAILURE);
    }
    float angle_count = 6;
    double angle = 0;

    point *p = new point[(int)angle_count];

    for(int i = 0; i <= angle_count; i++)
    {
        p[i].x = std::round(x + radius*std::cos(angle * M_PI / 180));       //in bitmap is x coordinate
        p[i].y = std::round(y + radius*std::sin(angle * M_PI / 180));       //in bitmap is y coordinate
        angle += 360 / angle_count;
    }

    if (fill){

        int **matrix = new int*[fileInfoHeader.height];
        for (int i = 0; i < fileInfoHeader.height; i++){
            matrix[i] = new int[fileInfoHeader.width];
            for (int j = 0; j < fileInfoHeader.width; j++)
                matrix[i][j] = 0;
        }

        for (int y = 0; y < fileInfoHeader.height; y++)
            for (int x = 0; x < fileInfoHeader.width; x++)
                if ((p[0].x - x) * (p[1].y - p[0].y) - (p[1].x - p[0].x) * (p[0].y - y) > 0 && (p[1].x - x) * (p[2].y - p[1].y) - (p[2].x - p[1].x) * (p[1].y - y) > 0 &&
                    (p[2].x - x) * (p[3].y - p[2].y) - (p[3].x - p[2].x) * (p[2].y - y) > 0 && (p[3].x - x) * (p[4].y - p[3].y) - (p[4].x - p[3].x) * (p[3].y - y) > 0 &&
                    (p[4].x - x) * (p[5].y - p[4].y) - (p[5].x - p[4].x) * (p[4].y - y) > 0 && (p[5].x - x) * (p[6].y - p[5].y) - (p[6].x - p[5].x) * (p[5].y - y) > 0 ||
                    (p[0].x - x) * (p[1].y - p[0].y) - (p[1].x - p[0].x) * (p[0].y - y) < 0 && (p[1].x - x) * (p[2].y - p[1].y) - (p[2].x - p[1].x) * (p[1].y - y) < 0 &&
                    (p[2].x - x) * (p[3].y - p[2].y) - (p[3].x - p[2].x) * (p[2].y - y) < 0 && (p[3].x - x) * (p[4].y - p[3].y) - (p[4].x - p[3].x) * (p[3].y - y) < 0 &&
                    (p[4].x - x) * (p[5].y - p[4].y) - (p[5].x - p[4].x) * (p[4].y - y) < 0 && (p[5].x - x) * (p[0].y - p[5].y) - (p[0].x - p[5].x) * (p[5].y - y) < 0)
                    matrix[y][x] = 1;

        this->fill(matrix, fill_red, fill_green, fill_blue);
        for (int i = 0; i < fileInfoHeader.height; i++)
            delete [] matrix[i];
        delete [] matrix;
    }
    
    for (int i = 0; i < angle_count; i++){
        this->draw_line(p[i].y, p[i].x, p[i+1].y, p[i+1].x, y+radius+thickness, x+radius+thickness, thickness, red, green, blue);
    }

    delete [] p;
}


void bmp_v3::copy_region(int x_left_top_point, int y_left_top_point, int x_right_bottom_point, int y_right_bottom_point, int x_cpy, int y_cpy)
{
    int x_count = x_right_bottom_point - x_left_top_point;              //разница по оси х, в бмп по у
    int y_count = y_left_top_point - y_right_bottom_point;              //разница по оси у

    if (y_count > y_cpy || x_left_top_point > x_right_bottom_point || y_left_top_point < y_right_bottom_point || x_left_top_point >= fileInfoHeader.width ||
        y_left_top_point >= fileInfoHeader.height || y_left_top_point <= 0 || y_right_bottom_point <= 0 || x_right_bottom_point <= 0 || x_left_top_point <= 0 ||
        x_cpy <= 0 || y_cpy <= 0 || x_cpy + x_count >= fileInfoHeader.width || x_cpy >= fileInfoHeader.width || y_cpy >= fileInfoHeader.height ||
        x_right_bottom_point >= fileInfoHeader.width || y_right_bottom_point >= fileInfoHeader.height)
    {
        std::cout << "Координаты выходят за пределы картинки! Попробуйте еще раз с другими координатами." << std::endl;
        exit(EXIT_FAILURE);
    }

    rgb** cpy = new rgb*[y_count];                                      //выделение памяти под двумерный массив пикселей, куда копируются данные блока
    for (int i = 0; i < y_count; i++)
        cpy[i] = new rgb[x_count];

    for (int i = y_right_bottom_point, x = 0; i < y_left_top_point; i++, x++)
    {
        for (int j = x_left_top_point, y = 0; j < x_right_bottom_point; j++, y++)
        {
            cpy[x][y].red = pixels[i][j].red;
            cpy[x][y].green = pixels[i][j].green;
            cpy[x][y].blue = pixels[i][j].blue;
        }
    }

    for (int x = y_cpy - y_count, i = 0; x < y_cpy; x++, i++)
    {
        for (int y = x_cpy, j = 0; y < x_cpy + x_count; y++, j++)
        {
            pixels[x][y].red = cpy[i][j].red;
            pixels[x][y].green = cpy[i][j].green;
            pixels[x][y].blue = cpy[i][j].blue;
        }
    }

    for (int i = 0; i < y_count; i++)
        delete [] cpy[i];
    delete [] cpy;
}

void bmp_v3::draw_line_for_triangle(int x0, int y0, int x1, int y1, uint8_t red, uint8_t green, uint8_t blue)
{
    int dx = (x1 - x0 >= 0 ? 1 : -1);
    int dy = (y1 - y0 >= 0 ? 1 : -1);

    int lengthX = abs(x1 - x0);
    int lengthY = abs(y1 - y0);

    int length = std::max(lengthX, lengthY);

    if (length == 0)
    {
        this->set_Pixel(x0, y0, red, green, blue);
        // this->set_Pixel(x0, y0);
    }

    if (lengthY <= lengthX)
    {
        // Начальные значения
        int x = x0;
        int y = y0;
        int d = -lengthX;

        // Основной цикл
        length++;
        while(length--)
        {
                this->set_Pixel(x, y, red, green, blue);
                // this->set_Pixel(x, y);
                x += dx;
                d += 2 * lengthY;
                if (d > 0) {
                    d -= 2 * lengthX;
                    y += dy;
                }
        }
    }
    else
    {
        // Начальные значения
        int x = x0;
        int y = y0;
        int d = -lengthY;

        // Основной цикл
        length++;
        while(length--)
        {
            this->set_Pixel(x, y, red, green, blue);
            // this->set_Pixel(x, y);
            y += dy;
            d += 2 * lengthX;
            if (d > 0) {
                d -= 2 * lengthY;
                x += dx;
            }
        }
    }

}


void bmp_v3::draw_frame(uint16_t mode, int frame_width, uint8_t color_red, uint8_t color_green, uint8_t color_blue)
{
    if (mode <= 0 || mode > 5)
    {
        fprintf(stderr, "Ошибка: введен неправильный режим для рамки узора. Пересмотрите инструкцию.\n");
        exit(EXIT_FAILURE);
    }
    if (frame_width <= 0)
    {
        fprintf(stderr, "Ширина для рамки меньше или равна нулю! Попробуйте снова.\n");
        exit(EXIT_FAILURE);
    }
    else if (frame_width >= fileInfoHeader.width || frame_width >= fileInfoHeader.height)
    {
        fprintf(stderr, "Ширина превышает значение высоты или ширины! Попробуйте снова.\n");
        exit(EXIT_FAILURE);
    }
    switch(mode)
    {
        case 1:
            // std::cout << "Just a typical frame!" << std::endl;

            for (int i = 0, k = fileInfoHeader.height - frame_width; i < frame_width && k < fileInfoHeader.height; i++, k++)
                for (int j = 0; j < fileInfoHeader.width; j++)
                {
                    this->set_Pixel(i, j, color_red, color_green, color_blue);
                    this->set_Pixel(k, j, color_red, color_green, color_blue);
                }
            for (int i = frame_width; i < fileInfoHeader.height - frame_width; i++)
                for (int j = 0, k = fileInfoHeader.width - frame_width; j < frame_width && k < fileInfoHeader.width; j++, k++){
                    this->set_Pixel(i, j, color_red, color_green, color_blue);
                    this->set_Pixel(i, k, color_red, color_green, color_blue);
                }
            break;
        
        case 2:
            for(int j = 0; j < fileInfoHeader.width; j++)
                if (j % 20 >= 10 || j % 20 == 0){
                    this->set_Pixel(0, j, color_red, color_green, color_blue);
                    this->set_Pixel(fileInfoHeader.height - 1, j, color_red, color_green, color_blue);
                }

            for (int i = 1, k = fileInfoHeader.height - frame_width; i < frame_width && k < fileInfoHeader.height - 1; i++, k++)
                for (int j = 0; j < fileInfoHeader.width; j++)
                    if (j % 10 == 0){
                        this->set_Pixel(i, j, color_red, color_green, color_blue);
                        this->set_Pixel(k, j, color_red, color_green, color_blue);
                    }
            for (int j = 0; j < fileInfoHeader.width; j++)
                if (j % 20 < 10){
                    this->set_Pixel(frame_width -1 , j, color_red, color_green, color_blue);
                    this->set_Pixel(fileInfoHeader.height - frame_width, j, color_red, color_green, color_blue);
                }

            for (int i = 0; i < fileInfoHeader.height; i++)    
                if (i % 20 >= 10){
                    this->set_Pixel(i, 0, color_red, color_green, color_blue);
                    this->set_Pixel(i, fileInfoHeader.width - 1, color_red, color_green, color_blue);
                }

            for (int i = 0; i < fileInfoHeader.height; i++)
                for (int j = 0, k = fileInfoHeader.width - frame_width; j < frame_width && k < fileInfoHeader.width; j++, k++)
                    if (i % 10 == 0){
                        this->set_Pixel(i, j, color_red, color_green, color_blue);
                        this->set_Pixel(i, k, color_red, color_green, color_blue);
                    }
            for (int i = 0; i < fileInfoHeader.height; i++)
                if (i % 20 < 10){
                    this->set_Pixel(i, frame_width, color_red, color_green, color_blue);
                    this->set_Pixel(i, fileInfoHeader.width - frame_width, color_red, color_green, color_blue);
                }

            break;
        case 3:{
            // point tr_points[150];
            point* tr_points = new point[1];
            int count_points = 0;
            for (int i = 0; i < fileInfoHeader.width; i++)
            {
                for (int j = 0; j < frame_width; j++)
                {
                    if (j == frame_width-1 && i % (50-1) == 24  || j == 0 && i % (50-1) == 0)
                    {
                        tr_points[count_points++] = {j, i};
                        tr_points = (point*) realloc (tr_points, (count_points+1)*sizeof(point));
                    }
                }
            }
            tr_points[count_points] = {0, (int)fileInfoHeader.width-1};
            for (int i = 0; i < count_points; i++)
                this->draw_line_for_triangle(tr_points[i].x, tr_points[i].y, tr_points[i+1].x, tr_points[i+1].y, color_red, color_green, color_blue);
            delete [] tr_points;
            for (int i = 0; i < fileInfoHeader.width; i++)
                this->set_Pixel(0, i, color_red, color_green, color_blue);

            tr_points = new point[1];
            count_points = 0;
            for (int i = 0; i < fileInfoHeader.width; i++)
                for (int j = fileInfoHeader.height - 1; j > fileInfoHeader.height - frame_width-2; j--)
                    if (j == fileInfoHeader.height - 1 && i % (50-1) == 0 || j == fileInfoHeader.height - frame_width-1 && i % (50-1) == 24)
                    {
                        tr_points[count_points++] = {j, i};
                        tr_points = (point*) realloc (tr_points, (count_points+1)*sizeof(point));
                    }
            tr_points[count_points] = {(int)fileInfoHeader.height-1, (int)fileInfoHeader.width-1};
            for (int i = 0; i < count_points; i++)
                this->draw_line_for_triangle(tr_points[i].x, tr_points[i].y, tr_points[i+1].x, tr_points[i+1].y, color_red, color_green, color_blue);
            delete [] tr_points;
            for (int i = 0; i < fileInfoHeader.width; i++)
                this->set_Pixel(fileInfoHeader.height-1, i, color_red, color_green, color_blue);

            tr_points = new point[1];
            count_points = 0;
            for (int i = 0; i < fileInfoHeader.height; i++)
                for (int j = 0; j < frame_width; j++)
                    if (j == 0 && i % (50-1) == 0 || j == frame_width-1 && i % (50-1) == 24)
                    {
                        tr_points[count_points++] = {i, j};
                        tr_points = (point*) realloc (tr_points, (count_points+1)*sizeof(point));
                    }
            tr_points[count_points] = {(int)fileInfoHeader.height-1, frame_width-1};
            for (int i = 0; i < count_points; i++)
                this->draw_line_for_triangle(tr_points[i].x, tr_points[i].y, tr_points[i+1].x, tr_points[i+1].y, color_red, color_green, color_blue);
            delete [] tr_points;
            for (int i = 0; i < fileInfoHeader.height; i++)
                this->set_Pixel(i, 0, color_red, color_green, color_blue);

            tr_points = new point[1];
            count_points = 0;
            for (int i = 0; i < fileInfoHeader.height; i++)
                for (int j = fileInfoHeader.width-frame_width-1; j < fileInfoHeader.width; j++)
                    if (j == fileInfoHeader.width-frame_width-1 && i % (50-1) == 0 || j == fileInfoHeader.width-1 && i % (50-1) == 24)
                    {
                        tr_points[count_points++] = {i, j};
                        tr_points = (point*) realloc (tr_points, (count_points+1)*sizeof(point));
                    }
            tr_points[count_points] = {(int)fileInfoHeader.height-1, (int)fileInfoHeader.width-1};
            for (int i = 0; i < count_points; i++)
                this->draw_line_for_triangle(tr_points[i].x, tr_points[i].y, tr_points[i+1].x, tr_points[i+1].y, color_red, color_green, color_blue);
            delete [] tr_points;
            for (int i = 0; i < fileInfoHeader.height; i++)
                this->set_Pixel(i, 0, color_red, color_green, color_blue);
            for (int i = 0; i < fileInfoHeader.height; i++)
                this->set_Pixel(i, fileInfoHeader.width - 1, color_red, color_green, color_blue);

            break;}
        
        case 4:{ //sine wave

            double angle = 0;
            int k = 5;
            for (k; fileInfoHeader.width%k != 0;k++);
            std::cout << k << std::endl;
            int c = 0;
            point* m = new point[1];
            int f, i;
            for (i = 0, f = 0; i < fileInfoHeader.width; i += k, f++)
            {
                m[f].y = std::round(frame_width*std::sin(angle*M_PI/180));
                // std::cout << m[f].y << std::endl;
                m[f].x = i;
                c++;
                m = (point*) realloc(m, (c+1) * sizeof(point));
                angle += 30;
                if (angle == 210) angle = 30;

            }
            m[f] = {(int)fileInfoHeader.width -1, 0};
            for (int i = 0; i < c; i++)
            {
                this->draw_line(m[i].y, m[i].x, m[i+1].y, m[i+1].x, 0, 0, 1, color_red, color_green, color_blue);
            }
            delete [] m;

            c = 0;
            m = new point[1];
            angle = 180;
            for (i = 0, f = 0; i < fileInfoHeader.width; i += k, f++)
            {
                m[f].y = std::round(frame_width*std::sin(angle*M_PI/180));
                // std::cout << m[f].y << std::endl;
                m[f].y += fileInfoHeader.height-1;
                m[f].x = i;
                c++;
                m = (point*) realloc(m, (c+1) * sizeof(point));
                angle += 30;
                if (angle == 390) angle = 210;

            }
            m[f] = {(int)fileInfoHeader.width -1, (int)fileInfoHeader.height-1};
            for (int i = 0; i < c; i++)
            {
                this->draw_line(m[i].y, m[i].x, m[i+1].y, m[i+1].x, 0, 0, 1, color_red, color_green, color_blue);
            }

            c = 0;
            m = new point[1];
            angle = 180;
            for (i = 0, f = 0; i < fileInfoHeader.height; i += k, f++)
            {
                m[f].x = std::round(frame_width*std::sin(angle*M_PI/180));
                // std::cout << m[f].x << std::endl;
                m[f].x += fileInfoHeader.width-1;
                m[f].y = i;
                c++;
                m = (point*) realloc(m, (c+1) * sizeof(point));
                angle += 30;
                if (angle == 390) angle = 210;

            }
            m[f] = {m[f-1].x + k, (int)fileInfoHeader.height-1};
            for (int i = 0; i < c; i++)
            {
                this->draw_line(m[i].y, m[i].x, m[i+1].y, m[i+1].x, 0, 0, 1, color_red, color_green, color_blue);
            }

            c = 0;
            m = new point[1];
            angle = 180;
            for (i = 0, f = 0; i < fileInfoHeader.height; i += k, f++)
            {
                m[f].x = std::round(frame_width*std::sin(angle*M_PI/180));
                // std::cout << m[f].y << std::endl;
                // m[f].y += height-1;
                m[f].y = i;
                c++;
                m = (point*) realloc(m, (c+1) * sizeof(point));
                angle += 30;
                if (angle == 210) angle = 30;

            }
            m[f] = {m[f-1].x - k, (int)fileInfoHeader.height-1};
            for (int i = 0; i < c; i++)
            {
                this->draw_line(m[i].y, m[i].x, m[i+1].y, m[i+1].x, 0, 0, 1, color_red, color_green, color_blue);
            }

            break;}


        case 5:{                //circles

            int half_frw = frame_width/2;
            int rx = half_frw, ry = 0, x, y;
            double angle = 0;

            // bottom part
            while (ry < fileInfoHeader.width + half_frw)
            {
                for (int i = 0; i < 360; i++)
                {
                    x = std::round(rx + half_frw*std::cos(angle*M_PI/180));                      //okruzhnost parametricheskim sposobom
                    y = std::round(ry + half_frw*std::sin(angle*M_PI/180));
                    angle++;
                    if (y < fileInfoHeader.width && y >= 0)
                        set_Pixel(x, y, color_red, color_green, color_blue);
                }
                // this->_fill(rx, ry+2, 0, 0, 0, color_red, color_green, color_blue);
                ry += half_frw;
            }

            //top part
            rx = fileInfoHeader.height - half_frw - 1, ry = 0;
            angle = 0;
            while (ry < fileInfoHeader.width + half_frw)
            {
                for (int i = 0; i < 360; i++)
                {
                    x = std::round(rx + half_frw*std::cos(angle*M_PI/180));                      //okruzhnost parametricheskim sposobom
                    y = std::round(ry + half_frw*std::sin(angle*M_PI/180));
                    angle++;
                    if (y < fileInfoHeader.width && y >= 0)
                        set_Pixel(x, y, color_red, color_green, color_blue);
                }
                ry += half_frw;
            }
            

            // //left part
            rx = 0, ry = half_frw;
            angle = 0;
            while (rx < fileInfoHeader.height + half_frw)
            {
                for (int i = 0; i < 360; i++)
                {
                    x = std::round(rx + half_frw*std::cos(angle*M_PI/180));                      //okruzhnost parametricheskim sposobom
                    y = std::round(ry + half_frw*std::sin(angle*M_PI/180));
                    angle++;
                    if (x < fileInfoHeader.height && x >= 0)
                        set_Pixel(x, y, color_red, color_green, color_blue);
                }
                rx += half_frw;
            }

            // //right part
            rx = fileInfoHeader.height-1, ry = fileInfoHeader.width - half_frw - 1;
            angle = 0;
            while (rx > -half_frw)
            {
                for (int i = 0; i < 360; i++)
                {
                    x = std::round(rx + half_frw*std::cos(angle*M_PI/180));                      //okruzhnost parametricheskim sposobom
                    y = std::round(ry + half_frw*std::sin(angle*M_PI/180));
                    angle++;
                    if (x < fileInfoHeader.height && x >= 0)
                        set_Pixel(x, y, color_red, color_green, color_blue);
                }
                rx -= half_frw;
            }


            break;
        }

        default:
            std::cout << "In developing, choose something else!" << std::endl;
            break;
    }
}



// void bmp_v3::merge_pics(const char* file_name2)
// {
//     bmp_v3 sec_pic(file_name2);

//     int new_w = fileInfoHeader.width + 
// }


void merge_pics(bmp_v3 &a, bmp_v3 &b, const char* save_file)
{
    std::ofstream fout(save_file, std::ifstream::binary);

    // unsigned int new_w = a.fileInfoHeader.width + b.fileInfoHeader.width;
    // unsigned int new_h = a.fileInfoHeader.height + b.fileInfoHeader.height;
    // uint mHeight = (a.fileInfoHeader.height > b.fileInfoHeader.height ? a.fileInfoHeader.height : b.fileInfoHeader.height);
    uint mHeight = a.fileInfoHeader.height  + b.fileInfoHeader.height;
    // uint mHeight = ;
    uint mWidth = (a.fileInfoHeader.width > b.fileInfoHeader.width ? a.fileInfoHeader.width : b.fileInfoHeader.width);
    // uint mWidth = a.fileInfoHeader.width + b.fileInfoHeader.width;


    file_header newFH = {a.fileHeader.signature, (mWidth * sizeof(rgb) + (mWidth*3)%4) *mHeight, 0, 0, a.fileHeader.offset_PA};
    file_info_header newFIH = {
                a.fileInfoHeader.header_size,
                mWidth,
                mHeight,
                a.fileInfoHeader.color_planes_num,
                a.fileInfoHeader.bits_for_pixel,
                0,
                0,
                0, 0, 0, 0};

    rgb aa[2000];
    for (int i = 0; i < 2000; i++){
        aa[i].red = 255;
        aa[i].green = 255;
        aa[i].blue = 255;
    }

    uint d_a_w = mWidth - a.fileInfoHeader.width;
    uint d_b_w = mWidth - b.fileInfoHeader.width;



    // rgb ss[mHeight][mWidth];

    // for (int i =0; i < mHeight; i++)
    //         for (int j = 0; j < mWidth; j++){
    //             ss[i][j].red = 255;
    //             ss[i][j].green = 255;
    //             ss[i][j].blue = 255;}


    // if (a.fileInfoHeader.width > b.fileInfoHeader.width){
    //     for (int i = 0; i < mHeight; i += 2 )
    //         for (int j = 0; j < mWidth; j++){
    //             ss[i][j].red = a.pixels[i][j].red;
    //             ss[i][j].green = a.pixels[i][j].green;
    //             ss[i][j].blue = a.pixels[i][j].blue;
    //         }
    //     for (int i = 1; i < mHeight; i+=2){
    //         for (int j = 0; j < b.fileInfoHeader.width; j++){
    //                 ss[i][j].red = b.pixels[i][j].red;
    //                 ss[i][j].green = b.pixels[i][j].green;
    //                 ss[i][j].blue = b.pixels[i][j].blue;
    //         }
    //     }
    // }
    // else if (a.fileInfoHeader.width < b.fileInfoHeader.width){
    //     for (int i =0; i < mHeight; i+=2)
    //         for (int j = 0; j < mWidth; j++){
    //             ss[i][j].red = b.pixels[i][j].red;
    //             ss[i][j].green = b.pixels[i][j].green;
    //             ss[i][j].blue = b.pixels[i][j].blue;
    //     }
    //         for (int i = 1; i < mHeight; i+=2){
    //     for (int j = 0; j < a.fileInfoHeader.width; j++){
    //             ss[i][j].red = a.pixels[i][j].red;
    //             ss[i][j].green = a.pixels[i][j].green;
    //             ss[i][j].blue = a.pixels[i][j].blue;
    //     }
    // }
    // }

    // printf("!!!!!!!!!!!!!!!!!!!!\n");

    // for (int i = 1; i < mHeight; i+=2){
    //     for (int j = 0; j < mWidth; j++){
    //             ss[i][j].red = b.pixels[i][j].red;
    //             ss[i][j].green = b.pixels[i][j].green;
    //             ss[i][j].blue = b.pixels[i][j].blue;
    //     }
    // }

    
    // for (int i = 0; i < mHeight; i++){
    //     for (int j = 0; j < mWidth; j++){
    //         fout.write((char*)ss[i], mWidth* sizeof(rgb) + (mWidth * sizeof(rgb))%4);
    //     }
    // }



    // int mHeight = (a.fileInfoHeader.height > b.fileInfoHeader.height ? a.fileInfoHeader.height : b.fileInfoHeader.height);
    // int mWidth = (a.fileInfoHeader.width > b.fileInfoHeader.width ? a.fileInfoHeader.width : b.fileInfoHeader.width);
    fout.write((char*)&newFH, sizeof(file_header));
    fout.write((char*)&newFIH, sizeof(file_info_header));




    // for (int i = 0; i < mHeight; i++){
    //         fout.write((char*)ss[i], mWidth* sizeof(rgb) + (mWidth * sizeof(rgb))%4);
    // }






    for (int i = 0; i < mHeight; i++){
        fout.write((char*)a.pixels[i], a.fileInfoHeader.width * sizeof(rgb) + (a.fileInfoHeader.width * sizeof(rgb))%4);
        if (d_a_w != 0)
            fout.write((char*)aa, d_a_w * sizeof(rgb)  + (d_a_w* sizeof(rgb))%4);
        fout.write((char*)b.pixels[i], b.fileInfoHeader.width * sizeof(rgb) + (b.fileInfoHeader.width * sizeof(rgb))%4);
        if (d_b_w != 0)
            fout.write((char*)aa, d_b_w * sizeof(rgb)  + (d_b_w* sizeof(rgb))%4);
    }






    // printf("%d\n", mHeight);

    // if (a.fileInfoHeader.height > b.fileInfoHeader.height)
    // {
    //     for (int i = 0; i < b.fileInfoHeader.height; i++){
    //         fout.write((char*)a.pixels[i], a.fileInfoHeader.width * sizeof(rgb) + (a.fileInfoHeader.width * sizeof(rgb))%4);
    //         if (d_a_w != 0)
    //             fout.write((char*)aa, d_a_w * sizeof(rgb)  + (d_a_w* sizeof(rgb))%4);
    //         fout.write((char*)b.pixels[i], b.fileInfoHeader.width * sizeof(rgb) + (b.fileInfoHeader.width * sizeof(rgb))%4);
    //         if (d_b_w != 0)
    //             fout.write((char*)aa, d_b_w * sizeof(rgb)  + (d_b_w* sizeof(rgb))%4);
    //     }

    //     for (int i = b.fileInfoHeader.height; i < a.fileInfoHeader.height; i++){
    //         fout.write((char*)a.pixels[i], a.fileInfoHeader.width * sizeof(rgb) + (a.fileInfoHeader.width * sizeof(rgb))%4);
    //     }
    // } else if (b.fileInfoHeader.height > a.fileInfoHeader.height)
    // {
    //     for (int i = 0; i < a.fileInfoHeader.height; i++){
    //         fout.write((char*)a.pixels[i], a.fileInfoHeader.width * sizeof(rgb) + (a.fileInfoHeader.width * sizeof(rgb))%4);
    //         if (d_a_w != 0)
    //             fout.write((char*)aa, d_a_w * sizeof(rgb)  + (d_a_w* sizeof(rgb))%4);
    //         fout.write((char*)b.pixels[i], b.fileInfoHeader.width * sizeof(rgb) + (b.fileInfoHeader.width * sizeof(rgb))%4);
    //         if (d_b_w != 0)
    //             fout.write((char*)aa, d_b_w * sizeof(rgb)  + (d_b_w* sizeof(rgb))%4);
    //     }

    //     for (int i = a.fileInfoHeader.height; i < b.fileInfoHeader.height; i++){
    //         fout.write((char*)a.pixels[i], a.fileInfoHeader.width * sizeof(rgb) + (a.fileInfoHeader.width * sizeof(rgb))%4);
    //     }
    // }



    fout.close();
}