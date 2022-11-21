#include"my_bmp_v3.h"
#include<getopt.h>
#include<unistd.h>

void check(const char* file_name)
{
    checking_header a;
    std::ifstream fout (file_name, std::ifstream::binary);
    if (!fout.is_open())
    {
    	fprintf(stderr, "Ошибка: %s не открывается! Возможно, файла не существует!\nПопробуйте еще раз!\n", file_name);
    	exit(1);
    }
    fout.read(reinterpret_cast<char*>(&a), sizeof(checking_header));
    
    if (a.signature != 0x4D42)
    {
        fprintf(stderr, "Ошибка: %s не является bmp файлом!\n", file_name);
        exit(EXIT_FAILURE);
    }
    // std::cout << "header size: " << a.header_size << std::endl;
    if (a.header_size != 40){
        // return 1;
        fprintf(stderr, "Ошибка: программа поддерживает изображения bmp только 3-й версии!\n");
        exit(EXIT_FAILURE);
    }
    else if (a.compression != 0){
        // return 2;
        fprintf(stderr, "Ошибка: программа не поддерживает сжатые файлы!\n");
        exit(EXIT_FAILURE);
    }
}

void check_color_value(const char* value)
{
    if (value[0] == '-')
    {
        fprintf(stderr, "Цвет не может быть отрицательным!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; value[i]; i++)
        if (isalpha(value[i]) || ispunct(value[i])){
            fprintf(stderr, "Ошибка: Проверьте, правильно ли вы вводите значения цветов.\nПересмотрите инструкцию к программе!\n");
            exit(EXIT_FAILURE);
        }
    // return 0;
}

void check_value(const char* value)
{    
    if (value[0] == '-')
    {
        fprintf(stderr, "В этой программе значения не могут быть отрицательными! Попробуйте еще раз!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; value[i]; i++)
        if (isalpha(value[i]) || ispunct(value[i])){
            fprintf(stderr, "Ошибка: Проверьте, правильно ли вы вводите значения или команды.\nПересмотрите инструкцию к программе!\n");
            exit(EXIT_FAILURE);
        }
}


struct user_choice
{
    bool info;
    int func_ch;
    int hex_mode;
    int left_top_x;
    int left_top_y;
    int right_bottom_x;
    int right_bottom_y;
    int dest_left_top_x;
    int dest_left_top_y;
    int centre_x;
    int centre_y;
    int radius;
    int line_thick;
    rgb color;
    bool fill;
    rgb fill_color;
    rgb new_color;
    int frame_mode;
    rgb pattern_color;
    int f_w;
    // int merge;
    const char* source_file_name;
    const char* dest_file_name;
    const char* second_file;
};



int main(int argc, char** argv)
{
    user_choice USER;

    int c;
    while(true)
    {
        // opterr = 0;
        static struct option long_options[] = 
            {
                { "info",               no_argument,        0, 'i' },
                { "help",               no_argument,        0, 'h' },
                { "hexagon",            no_argument,        0, 'X' },
                { "circle_centre",      required_argument,  0, 'C' },
                { "radius",             required_argument,  0, 'l' },
                { "top_coords",         required_argument,  0, 't' },
                { "bottom_coords",      required_argument,  0, 'b' },
                { "line_thickness",     required_argument,  0, 'L' },
                { "color",              required_argument,  0, 'c' },
                { "fill",               required_argument,  0, 'f' },
                { "fill_color",         required_argument,  0, 'F' },
                { "copy_region",        no_argument,        0, 'R' },
                { "region_coords",      required_argument,  0, 'r' },
                { "change_color",       no_argument,        0, 'A' },
                { "new_color",          required_argument,  0, 'N' },
                { "frame_pattern",      required_argument,  0, 'P' },
                { "pattern_color",      required_argument,  0, 'T' },
                { "frame_width",        required_argument,  0, 'W' },
                { "source_file",        required_argument,  0, 'S' },
                { "dest_file",          required_argument,  0, 'D' },
                { "merge",              no_argument,        0, 'M' },
                { "second",             required_argument,  0, 'B' },
                { 0, 0, 0, 0}
            };
        static int option_ind = 0;
        c = getopt_long(argc, argv, "ihXc:l:t:b:L:C:f:F:Rr:AN:P:T:W:S:D:MB:", long_options, &option_ind);
        if (c == -1)
            break;
        switch(c)
        {
            case 'i':
                // printf("its check1\n");
                USER.info = 1;
                break;
            
            case 'h':
                // printf("its check2\n");
                printf("Программа может модифицировать изображения ТОЛЬКО .bmp формата и причем ТОЛЬКО 3-й версии.\n");
                printf("(В конце можно посмотреть пример использования программы.\n");
                printf("Использование: ./prog [опции]\nОпции:\n");
                printf("  --info\t\t(короткий ключ -i)\n\t\tВыводит информацию об изображении.\n\n");
                printf("  --help\t\t(короткий ключ -h)\n\t\tВыводит данную информацию.\n\n");
                printf("  --hexagon\t\t(короткий ключ -X)\n\t\tНе требует параметров. Функция рисует шестиугольник: либо с помощью окружности, либо с помощью квадрата.\n");
                printf("\t\tДля окружности нужно задать координаты центра и ее радиус (опции --circle_centre (-C) и --radius (-l)\n");
                printf("\t\tЧтобы задать квадрат, нужно воспользоваться опциями --top_coords (-t) и --bottom_coords (-b)\n");
                printf("\t\tТакже, можно задать цвет линии шестиугольника с помощью опции --color (-c). По умолчанию цвет черный.\n\n");
                printf("  --circle_centre\t\t(короткий ключ -C)\n\t\tТребует 2 параметра: координату X и координату Y\n");
                printf("\t\tНужна для рисования шестиугольника.\n\n");
                printf("  --radius\t\t(короткий ключ -l)\n\t\tТребует один параметр: радиуc для окружности.\n\n");
                printf("  --top_coords\t\t(короткий ключ -t)\n\t\tТребует два параметра: левую верхнюю координату по оси OX и по оси OY\n\n");
                printf("  --bottom_coords\t\t(короткий ключ -b)\n\t\tТребует два параметра: правую нижнюю координату по оси OX и по оси OY\n\n");
                printf("  --line_thickness\t\t(короткий ключ -L)\n\t\tТребует один параметр: толщину линии.\n\n");
                printf("  --color\t\t(короткий ключ -c)\n\t\tТребуется 3 параметра: красный цвет, зеленый цвет и синий цвет.(цвета вводить от 0 до 255) По умолчанию черный цвет.\n");
                printf("\t\tМожно использовать для задания цветов линии или для изначальных пикселей для функции --change_color (-A).\n\n");
                printf("  --fill\t\t(короткий ключ -f)\n\t\tЗаливка шестиугольника\n\t\tТребует один параметр: 0 - если без заливки (по умолчанию), 1 - если залитая фигура.\n\n");
                printf("  --fill_color\t\t(короткий ключ -F)\n\t\tВыбор цвета заливки шестиугольника\n\t\tТребуется 3 параметра: красный цвет, зеленый цвет и синий цвет.(цвета вводить от 0 до 255) По умолчанию черный цвет.\n\n");
                printf("  --copy_region\t\t(короткий ключ -R)\n\t\tНе требует параметров. Функция копирует область изображения и переставляет в другое место.\n");
                printf("\t\tЧтобы использовать функцию нужно воспользоваться опциями --top_coords (-t) и --bottom_coords (-b) для задания копируемой области.\n");
                printf("\t\tС помощью опции --region_coords (-r) нужно задать координаты левого верхнего угла области назначения.\n\n");
                printf("  --region_coords\t\t(короткий ключ -r)\n\t\tТребует два параметра: координаты (X, Y) левого верхнего угла области назначеия для функции копирования области изображения.\n\n");
                printf("  --change_color\t\t(короткий ключ -A)\n\t\tОпция не требует параметров. Функция меняет все пиксели заданного цвета на пиксели нового цвета.\n");
                printf("\t\tЧтобы задать цвет, который вы хотите заменить, воспользуйтесь опцией --color (-c). Для задания нового цвета используйте опцию --new_color (-N).\n\n");
                printf("  --new_color\t\t(короткий ключ -N)\n\t\tОпции требуется три параметра: красный цвет, зеленый цвет и синий цвет.(цвета вводить от 0 до 255) По умолчанию черный цвет.\n\n");
                printf("  --frame_pattern\t\t(короткий ключ -P)\n\t\tОпция требует один параметр: узор (от 1 до 5). Функция рисует рамку ввиде узора:\n");
                printf("\t\t1) Обычная рамка заданного пользователем цвета.\n\t\t2) Узор прямоугольный зиг-заг.\n\t\t3) Узор ввиде треугольников.\n\t\t");
                printf("4) Узор половинчатая синусоидная волна.\n\t\t5) Узор круги.\n");
                printf("\t\tУзор рисуется по всему пириметру с шириной входа внутрь изображения и цветом, которые можно задать с помощью опций\n\t\t");
                printf("--frame_width (-W) для ширины и --pattern_color (-T) для цвета узора, соответственно.\n\n");
                printf("  --pattern_color\t\t(короткий ключ -P)\n\t\tОпция для задания цвета рамки узора.\n\t\tТребует три параметра: красный цвет, зеленый цвет и синий цвет.(цвета вводить от 0 до 255)\n\n");
                printf("  --frame_width\t\t(короткий ключ -W)\n\t\tОпция требует один параметр: ширина рамки узора.\n\n");
                printf("  --source_file\t\t(короткий ключ -S)\n\t\tТребует строку с названием файла для изменения, либо путь до этого файла соответственно.\n\n");
                printf("  --dest_file\t\t(короткий ключ -D)\n\t\tОпция требует одну строку с путем или названием файла, куда будут сохраняться изменения.\n\n");
                printf("\n\nВсе параметры команд должны вводиться через пробел!\nПо умолчанию, все цвета являются черными, но если вы захотите ввести свой цвет, то надо будет вводить 3 значния, как просят того опции!\n");
                printf("\nПример запуска программы:\n\t./prog -X --circle_centre 250 250 --radius 50 --line_thickness 3 --color 255 0 0 -S simpson.bmp -D test_changes.bmp\n");
                return 0;
                break;
            
            case 'X':{
                USER.func_ch = 1;
                break;}
            
            case 'C':{
                check_value(optarg);
                USER.centre_x = atoi(optarg);
                check_value(argv[optind]);
                USER.centre_y = atoi(argv[optind]);
                USER.hex_mode = 1;
                break;}
            
            case 'l':{
                check_value(optarg);
                USER.radius = atoi(optarg);
                break;}
            
            case 't':{
                check_value(optarg);
                USER.left_top_x = atoi(optarg);
                check_value(argv[optind]);
                USER.left_top_y = atoi(argv[optind]);
                USER.hex_mode = 2;
                break;}
            
            case 'b':{
                check_value(optarg);
                USER.right_bottom_x = atoi(optarg);
                check_value(argv[optind]);
                USER.right_bottom_y = atoi(argv[optind]);
                break;}

            case 'L':{
                check_value(optarg);
                USER.line_thick = atoi(optarg);
                break;}

            case 'c':{
                check_color_value(optarg);
                USER.color.red = atoi(optarg);
                check_color_value(argv[optind]);
                USER.color.green = atoi(argv[optind]);
                check_color_value(argv[optind+1]);
                USER.color.blue = atoi(argv[optind+1]);

                if (USER.color.red > 255 || USER.color.red < 0 || USER.color.green < 0
                    || USER.color.green > 255 || USER.color.blue < 0 || USER.color.blue > 255)
                    {
                        fprintf(stderr, "Ошибка: Значения цветов принимаются от 0 до 255!\nПересмотрите инструкцию!\n");
                        exit(EXIT_FAILURE);
                    }
                break;}

            case 'f':{
                check_value(optarg);
                int a = atoi(optarg);
                if (a != 0 && a != 1){
                    fprintf(stderr, "Ошибка: --fill (-f) требует параметр 0 или 1.\n");
                    exit(EXIT_FAILURE);
                }
                USER.fill = a;
                break;}

            case 'F':{
                check_color_value(optarg);
                USER.fill_color.red = atoi(optarg);
                check_color_value(argv[optind]);
                USER.fill_color.green = atoi(argv[optind]);
                check_color_value(argv[optind+1]);
                USER.fill_color.blue = atoi(argv[optind+1]);

                if (USER.fill_color.red > 255 || USER.fill_color.red < 0 || USER.fill_color.green < 0
                    || USER.fill_color.green > 255 || USER.fill_color.blue < 0 || USER.fill_color.blue > 255)
                    {
                        fprintf(stderr, "Ошибка: Значения цветов принимаются от 0 до 255!\nПересмотрите инструкцию!\n");
                        exit(EXIT_FAILURE);
                    }
                break;}

            case 'R':{
                USER.func_ch = 2;
                break;}

            case 'r':{
                check_value(optarg);
                USER.dest_left_top_x = atoi(optarg);
                check_value(argv[optind]);
                USER.dest_left_top_y = atoi(argv[optind]);
                break;}

            case 'A':{
                USER.func_ch = 3;
                break;}

            case 'N':{
                check_color_value(optarg);
                USER.new_color.red = atoi(optarg);
                check_color_value(argv[optind]);
                USER.new_color.green = atoi(argv[optind]);
                check_color_value(argv[optind+1]);
                USER.new_color.blue = atoi(argv[optind+1]);

                if (USER.new_color.red > 255 || USER.new_color.red < 0 || USER.new_color.green < 0
                    || USER.new_color.green > 255 || USER.new_color.blue < 0 || USER.new_color.blue > 255)
                    {
                        fprintf(stderr, "Ошибка: Значения цветов принимаются от 0 до 255!\nПересмотрите инструкцию!\n");
                        exit(EXIT_FAILURE);
                    }
                break;}

            case 'P':{
                USER.func_ch = 4;
                check_value(optarg);
                USER.frame_mode = atoi(optarg);
                break;}
            
            case 'T':{
                check_color_value(optarg);
                USER.pattern_color.red = atoi(optarg);
                check_color_value(argv[optind]);
                USER.pattern_color.green = atoi(argv[optind]);
                check_color_value(argv[optind+1]);
                USER.pattern_color.blue = atoi(argv[optind+1]);

                if (USER.pattern_color.red > 255 || USER.pattern_color.red < 0 || USER.pattern_color.green < 0
                    || USER.pattern_color.green > 255 || USER.pattern_color.blue < 0 || USER.pattern_color.blue > 255)
                    {
                        fprintf(stderr, "Ошибка: Значения цветов принимаются от 0 до 255!\nПересмотрите инструкцию!\n");
                        exit(EXIT_FAILURE);
                    }
                break;}
            
            case 'W':{
                check_value(optarg);
                USER.f_w = atoi(optarg);
                break;}

            case 'S':{
                USER.source_file_name = optarg;
                break;}

            case 'D':{
                USER.dest_file_name = optarg;
                break;}

            case 'M':{
                USER.func_ch = 5;
                // USER.second_file = optarg;
                break;
            }

            case 'B':{
                USER.second_file = optarg;
                break;
            }


            case '?':
            default:
                printf("Ошибка: опции не существует! Посмотрите инструкцию (--help/-h) и попробуйте снова.\n");
                exit(EXIT_FAILURE);
            
        }
        option_ind++;
    }
    
    
    if (USER.source_file_name == NULL || USER.dest_file_name == NULL){
        fprintf(stderr, "Ошибка: вы не ввели опцию сохранения в файл (или путь) или сам исходный файл! Попробуйте еще раз. Посмотрите инструкцию --help (-h).\n");
        exit(EXIT_FAILURE);
    }

    long len1 = std::strlen(USER.source_file_name);
    if ( !((USER.source_file_name[len1-1] == 'p' || USER.source_file_name[len1-1] == 'P') && (USER.source_file_name[len1-2] == 'm' || USER.source_file_name[len1-2] == 'M') && 
        (USER.source_file_name[len1-3] == 'b' || USER.source_file_name[len1-3] == 'B') && (USER.source_file_name[len1 -4] == '.')))
        {
            fprintf(stderr, "Ошибка: вы ввели имя или путь не к bmp файлу! Попробуйте снова. Посмотрите инструкцию --help (-h).\n");
            exit(EXIT_FAILURE);
        }

    long len2 = std::strlen(USER.dest_file_name);
    if ( !((USER.dest_file_name[len2-1] == 'p' || USER.dest_file_name[len2-1] == 'P') && (USER.dest_file_name[len2-2] == 'm' || USER.dest_file_name[len2-2] == 'M') && 
        (USER.dest_file_name[len2-3] == 'b' || USER.dest_file_name[len2-3] == 'B') && (USER.dest_file_name[len2 -4] == '.')))
        {
            fprintf(stderr, "Ошибка: вы ввели имя или путь не к bmp файлу! Посмотрите инструкцию --help (-h).\n");
            exit(EXIT_FAILURE);
        }

    check(USER.source_file_name);

    bmp_v3 pic(USER.source_file_name);

    if (USER.info)
        pic.info();

    if (USER.func_ch == 0)
    {
    	printf("Вы не выбрали ни одной функции!\n");
    	exit(1);
    }

    switch(USER.func_ch)
    {
        case 0:{
            printf("Вы не выбрали ни одной функции! Сохраняем данные в файл %s\n", USER.dest_file_name);
            std::ofstream fout(USER.dest_file_name, std::ifstream::binary);
            fout << pic;
            break;}

        case 1:{
            if (USER.hex_mode == 1)
            {
                pic.draw_hexagon_circ(USER.centre_x, USER.centre_y, USER.radius, USER.fill, USER.line_thick, USER.color.red, USER.color.green, USER.color.blue, USER.fill_color.red, USER.fill_color.green, USER.fill_color.blue);
            }
            else if (USER.hex_mode == 2)
            {
                pic.draw_hexagon_sq(USER.left_top_x, USER.left_top_y, USER.right_bottom_x, USER.right_bottom_y, USER.fill, USER.line_thick, USER.color.red, USER.color.green, USER.color.blue, USER.fill_color.red, USER.fill_color.green, USER.fill_color.blue);
            }
            else{
                printf("Вы не ввели ни одной координаты для создания шестиугольника. Идет сохранение данных в новый файл!\n");
            }
            std::ofstream fout(USER.dest_file_name, std::ifstream::binary);
            fout << pic;
            break;}
        
        case 2:{
            pic.copy_region(USER.left_top_x, USER.left_top_y, USER.right_bottom_x, USER.right_bottom_y, USER.dest_left_top_x, USER.dest_left_top_y);
            std::ofstream fout(USER.dest_file_name, std::ifstream::binary);
            fout << pic;

            break;}

        case 3:{
            pic.exact_changement(USER.color.red, USER.color.green, USER.color.blue, USER.new_color.red, USER.new_color.green, USER.new_color.blue);
            std::ofstream fout(USER.dest_file_name, std::ifstream::binary);
            fout << pic;

            break;}

        case 4:{
            pic.draw_frame(USER.frame_mode, USER.f_w, USER.pattern_color.red, USER.pattern_color.green, USER.pattern_color.blue);
            std::ofstream fout(USER.dest_file_name, std::ifstream::binary);
            fout << pic;

            break;}

        case 5:{
            bmp_v3 b(USER.second_file);

            merge_pics(pic, b, USER.dest_file_name);

            break;
        }
    }

    return 0;
}
