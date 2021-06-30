#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <inttypes.h>
#include <dirent.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t signature;
    uint32_t filesize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixelArrOffset;
} BitmapFileHeader;

typedef struct {
    uint32_t headerSize;
    uint32_t width;
    uint32_t height;

    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    uint32_t xPixelsPerMeter;
    uint32_t yPixelsPerMeter;
    uint32_t colorsInColorTable;
    uint32_t importantColorCount;
} BitmapInfoHeader;

typedef struct {
    uint8_t b;
    uint8_t g;
    uint8_t r;
} RGB;
#pragma pack(pop)

typedef struct {
    BitmapFileHeader FileHeader;
    BitmapInfoHeader InfoHeader;
    RGB **arr;
} Headers;

void printFileHeader(Headers bmp){
    printf("signature:\t%x (%hu)\n", bmp.FileHeader.signature, bmp.FileHeader.signature);
    printf("filesize:\t%x (%u)\n", bmp.FileHeader.filesize, bmp.FileHeader.filesize);
    printf("reserved1:\t%x (%hu)\n", bmp.FileHeader.reserved1, bmp.FileHeader.reserved1);
    printf("reserved2:\t%x (%hu)\n", bmp.FileHeader.reserved2, bmp.FileHeader.reserved2);
    printf("pixelArrOffset:\t%x (%u)\n", bmp.FileHeader.pixelArrOffset, bmp.FileHeader.pixelArrOffset);
}

void printInfoHeader(Headers bmp){
    printf("headerSize:\t%x (%u)\n", bmp.InfoHeader.headerSize, bmp.InfoHeader.headerSize);
    printf("width:     \t%x (%u)\n", bmp.InfoHeader.width, bmp.InfoHeader.width);
    printf("height:    \t%x (%u)\n", bmp.InfoHeader.height, bmp.InfoHeader.height);
    printf("planes:    \t%x (%hu)\n", bmp.InfoHeader.planes, bmp.InfoHeader.planes);
    printf("bitsPerPixel:\t%x (%hu)\n", bmp.InfoHeader.bitsPerPixel, bmp.InfoHeader.bitsPerPixel);
    printf("compression:\t%x (%u)\n", bmp.InfoHeader.compression, bmp.InfoHeader.compression);
    printf("imageSize:\t%x (%u)\n", bmp.InfoHeader.imageSize, bmp.InfoHeader.imageSize);
    printf("xPixelsPerMeter:\t%x (%u)\n", bmp.InfoHeader.xPixelsPerMeter, bmp.InfoHeader.xPixelsPerMeter);
    printf("yPixelsPerMeter:\t%x (%u)\n", bmp.InfoHeader.yPixelsPerMeter, bmp.InfoHeader.yPixelsPerMeter);
    printf("colorsInColorTable:\t%x (%u)\n", bmp.InfoHeader.colorsInColorTable, bmp.InfoHeader.colorsInColorTable);
    printf("importantColorCount:\t%x (%u)\n", bmp.InfoHeader.importantColorCount, bmp.InfoHeader.importantColorCount);
}

typedef struct{
    int startX, startY;
    int endX, endY;
    int radius;
    int centerX, centerY;
    int thick_line; 
    int value;
    int vertical, horizontal;
    char *color;
    char *line_color;
    char *fill;
    int circleFlag;
    int fillFlag;
    int fix;
    int fixValue;

} UserValues;

Headers Read_BMP_File(char *FileName){
    Headers bmp;
    FILE *f = fopen(FileName, "rb");

    fread(&bmp.FileHeader, 1, sizeof(BitmapFileHeader), f);
    if(bmp.FileHeader.signature != 0x4D42){
        printf("Ошибка: %s не является BMP файлом!\n", FileName);
        exit(1);
    }

    fread(&bmp.InfoHeader.headerSize, sizeof(bmp.InfoHeader.headerSize), 1, f);

    //bmp основная версия
    if(bmp.InfoHeader.headerSize >= 12){
        fread(&bmp.InfoHeader.width, sizeof(bmp.InfoHeader.width), 1, f);
        fread(&bmp.InfoHeader.height, sizeof(bmp.InfoHeader.height), 1, f);
        fread(&bmp.InfoHeader.planes, sizeof(bmp.InfoHeader.planes), 1, f);
        fread(&bmp.InfoHeader.bitsPerPixel, sizeof(bmp.InfoHeader.bitsPerPixel), 1, f);
    }

    // bmp v1
    if(bmp.InfoHeader.headerSize >= 40){
        fread(&bmp.InfoHeader.compression, sizeof(bmp.InfoHeader.compression), 1, f);
        fread(&bmp.InfoHeader.imageSize, sizeof(bmp.InfoHeader.imageSize), 1, f);
        fread(&bmp.InfoHeader.xPixelsPerMeter, sizeof(bmp.InfoHeader.xPixelsPerMeter), 1, f);
        fread(&bmp.InfoHeader.yPixelsPerMeter, sizeof(bmp.InfoHeader.yPixelsPerMeter), 1, f);
        fread(&bmp.InfoHeader.colorsInColorTable, sizeof(bmp.InfoHeader.colorsInColorTable), 1, f);
        fread(&bmp.InfoHeader.importantColorCount, sizeof(bmp.InfoHeader.importantColorCount), 1, f);
    }

    if(bmp.InfoHeader.headerSize >= 52) {
        printf("Версия данного BMP файла не поддерживается!!\n");
        exit(1);
    }

    unsigned int H = bmp.InfoHeader.height;
    unsigned int W = bmp.InfoHeader.width;

    RGB **arr = malloc(H*sizeof(RGB*));
    for(int i=0; i<H; i++){
        arr[i] = malloc(W * sizeof(RGB) + (W*3)%4);
        fread(arr[i],1,W * sizeof(RGB) + (W*3)%4,f);
    }
    bmp.arr = arr;
    fclose(f);
    return bmp;
}

void Write_BMP_File(char *FileName, Headers bmp){

    unsigned int H = bmp.InfoHeader.height;
    unsigned int W = bmp.InfoHeader.width;
    FILE *ff = fopen(FileName, "wb");

    fwrite(&bmp.FileHeader, sizeof(BitmapFileHeader), 1, ff);
    fwrite(&bmp.InfoHeader, sizeof(BitmapInfoHeader), 1, ff);

    // write pixel array
    unsigned int w = (W) * sizeof(RGB) + ((W)*3)%4;
    for(int i=0; i<H; i++){
        fwrite(bmp.arr[i],1,w,ff);
    }
    fclose(ff);
}

//---------------------------------------------------------------------------
void Groundmoves(Headers bmp, UserValues Values){

    if(Values.fix == 0){
    	Values.thick_line = 1;
    }	
    int count = 0;
    int r = 0; int g = 0; int b = 0; // цвет прямоугольника
    if(strcmp(Values.color, "red")==0){r=255;}
    if(strcmp(Values.color, "blue")==0){b=255;}
    if(strcmp(Values.color, "green")==0){g=255;}
    if(strcmp(Values.color, "yellow")==0){r=255; g=255;}
    if(strcmp(Values.color, "purple")==0){r=255; b=255;}
    if(strcmp(Values.color, "white")==0){r=255; b=255; g=255;}
    if(strcmp(Values.color, "black")==0){r=0; g=0; b=0;}
    if(strcmp(Values.color, "cyan")==0){r=0; g=255; b=255;}

    int r1 = 0; int g1 = 0; int b1 = 0; // цвет линии
    if(strcmp(Values.line_color, "red")==0){r1=255;}
    if(strcmp(Values.line_color, "blue")==0){b1=255;}
    if(strcmp(Values.line_color, "green")==0){g1=255;}
    if(strcmp(Values.line_color, "yellow")==0){r1=255; g1=255;}
    if(strcmp(Values.line_color, "purple")==0){r1=255; b1=255;}
    if(strcmp(Values.line_color, "white")==0){r1=255; b1=255; g1=255;}
    if(strcmp(Values.line_color, "black")==0){r1=0; g1=0; b1=0;}
    if(strcmp(Values.line_color, "cyan")==0){r1=0; g1=255; b1=255;}

    int fatness = Values.thick_line;
    int H = bmp.InfoHeader.height;
    unsigned int W = bmp.InfoHeader.width;

    int **box = calloc(H,sizeof(int*));
    for(int k=0; k<H; k++) {
        box[k] = calloc(W,sizeof(int));
    }

    for(int p=0; p<H; p++){
        for(int w=0; w<W; w++){
            if(bmp.arr[p][w].r == r && bmp.arr[p][w].g == g && bmp.arr[p][w].b == b){
                box[p][w] = 1;
            }
        }
    }

    for(int x=0; x<W; x++){
        for(int y=0; y<H; y++){
            if(box[y][x] == 1){
                int xx = x;
                int yy = y;
                while(yy<H-1 && box[yy][x]==1){
                    yy++;
                }
                yy=yy-y;
                while (xx<W-1 && box[y][xx]==1){
                    xx++;
                }
                xx=xx-x;
                if(fatness*2+1>xx || fatness*2+1>yy){
                    count++;
                    break;
                }
                int check = 0;
                for(int u=x+1; u<xx+x; u++){
                    for(int e=y+1; e<yy+y; e++){
                        if(box[e][u] != 1){
                            check = 1;
                        }
                    }
                }
                for(int n=x; n<=xx+x; n++){
                    for(int m=y; m<=yy+y; m++){
                        box[m][n] = 0;

			if(check == 0){
                        	if(n>=x && n<x+fatness && m>=y && m<=y+yy-1 || m>=y && m<y+fatness && n>=x && n<=x+xx-1 ||
                           	n<=x+xx-1 && n>x+xx-1-fatness && m>=y && m<=y+yy-1 || m<=y+yy-1 && m>y+yy-1-fatness && n>=x && n<=x+xx-1){
                            	box[m][n] = 2;
                        	}
                        }	
                    }
                }

            }
        }
    }

    if(count>0){
    	printf("Невозможно обвести некоторые прямоугольники с заданной толщиной, так как они слишком малы либо толщина линии слишком большая!\n");
    }	

    for(int p=0; p<H; p++){
        for(int w=0; w<W; w++){
            if(box[p][w] == 2){
                bmp.arr[p][w].b = b1;
                bmp.arr[p][w].r = r1;
                bmp.arr[p][w].g = g1;
            }
        }
    }
}

//----------------------------------------------------------------------

void DrawCircle(Headers bmp, UserValues Values){

    int r1 = 0; int g1 = 0; int b1 = 0;
    if(strcmp(Values.line_color, "red")==0){r1=255;}
    if(strcmp(Values.line_color, "blue")==0){b1=255;}
    if(strcmp(Values.line_color, "green")==0){g1=255;}
    if(strcmp(Values.line_color, "yellow")==0){r1=255; g1=255;}
    if(strcmp(Values.line_color, "purple")==0){r1=255; b1=255;}
    if(strcmp(Values.line_color, "white")==0){r1=255; b1=255; g1=255;}
    if(strcmp(Values.line_color, "black")==0){r1=0; g1=0; b1=0;}
    if(strcmp(Values.line_color, "cyan")==0){r1=0; g1=255; b1=255;}

    int r2 = 0; int g2 = 0; int b2 = 0;
    if(Values.fillFlag != 0){
	 if(strcmp(Values.fill, "red")==0){r2=255;}
	 if(strcmp(Values.fill, "blue")==0){b2=255;}
	 if(strcmp(Values.fill, "green")==0){g2=255;}
	 if(strcmp(Values.fill, "yellow")==0){r2=255; g2=255;}
	 if(strcmp(Values.fill, "purple")==0){r2=255; b2=255;}
	 if(strcmp(Values.fill, "white")==0){r2=255; b2=255; g2=255;}
	 if(strcmp(Values.fill, "black")==0){r2=0; g2=0; b2=0;}
	 if(strcmp(Values.fill, "cyan")==0){r2=0; g2=255; b2=255;}
    }

    if(Values.fix == 0){
    	Values.thick_line = 1;
    }	

    int H = bmp.InfoHeader.height;
    int W = bmp.InfoHeader.width;
    int r=0; int R=0; int a=0; int b=0;

    if(Values.circleFlag == 1) {
        r = Values.radius;
        R = Values.radius + Values.thick_line;

        a = Values.centerX;
        b = Values.centerY;

    }
    else if(Values.circleFlag == 2 &&  (Values.startX!=0 || Values.startY!=0 || Values.endX!=0 || Values.endY!=0)){
        int x1 = Values.startX; int y1 = Values.startY; int x2 = Values.endX; int y2 = Values.endY;
        if((x2<x1) || (y2>y1)){
            printf("Координаты введены неверно.\n");
            return;
        }
        if(x2-x1 != y1-y2){
            printf("Введённые координаты не образуют квадрат.\n");
            return;
        }
        r = (x2-x1)/2;
        R = r + Values.thick_line;
        a = x1 + r;
        b = y1 - r;
    }
    else{
        printf("Неправильно указаны значения аргументов. Перейдите в раздел help, с помощью команды --help\n");
        return;
    }
    if(a<R || b<R || b+R>H || a+R>W){
        printf("Окружность не помещается в картинку.\n");
        return;
    }
    for(int x=a-R; x<=a+R; x++){
        for(int y=b-R; y<=b+R; y++){
            if(((x-a)*(x-a)+(y-b)*(y-b) < R*R)&&((x-a)*(x-a)+(y-b)*(y-b) >= r*r)) {
                bmp.arr[y][x].g = g1;
                bmp.arr[y][x].r = r1;
                bmp.arr[y][x].b = b1;
            }
        }
    }
    if(Values.fillFlag != 0){
    	for(int x=a-R; x<=a+R; x++){
            for(int y=b-R; y<=b+R; y++){
                if((x-a)*(x-a)+(y-b)*(y-b) < r*r){
                    bmp.arr[y][x].g = g2;
                    bmp.arr[y][x].b = b2;
                    bmp.arr[y][x].r = r2;
                 }
             }
        }            
    }
}

//----------------------------------------------------------------------

void RGBFilter(Headers bmp, UserValues Values){

    if(Values.fixValue == 0){
    	printf("Вы не ввели значение компоненты. Введите ключ --value(-v) и аргумент.\n");
    	return;
    }

    if(Values.value!=0 && Values.value!=255){
        printf("Будьте внимательны, нужно выбрать либо значение 0, либо 255 :)\n");
        return;
    }

    int H = bmp.InfoHeader.height;
    int W = bmp.InfoHeader.width;
    if(strcmp(Values.color, "red")==0){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++)
                bmp.arr[i][j].r = Values.value;
        }
    }
    else if(strcmp(Values.color, "green")==0){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++)
                bmp.arr[i][j].g = Values.value;
        }
    }
    else if(strcmp(Values.color, "blue")==0){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++)
                bmp.arr[i][j].b = Values.value;
        }
    }
    else{
    	printf("Такой компоненты не существует. Вы можете выбрать из следующих компонент: red, green, blue.\n");
    }	

}

//-------------------------------------------------------------------

void PartingImage(Headers bmp, UserValues Values){

    if(Values.fix == 0){
    	Values.thick_line = 1;
    }	

    int X = Values.vertical - 1;
    int Y = Values.horizontal - 1;
    int wLine = Values.thick_line;

    if(X<0) X=0;
    if(Y<0) Y=0;

    int r = 0; int g = 0; int b = 0;
    if(strcmp(Values.color, "red")==0){r=255;}
    if(strcmp(Values.color, "blue")==0){b=255;}
    if(strcmp(Values.color, "green")==0){g=255;}
    if(strcmp(Values.color, "yellow")==0){r=255; g=255;}
    if(strcmp(Values.color, "purple")==0){r=255; b=255;}
    if(strcmp(Values.color, "white")==0){r=255; b=255; g=255;}
    if(strcmp(Values.color, "black")==0){r=0; g=0; b=0;}
    if(strcmp(Values.color, "cyan")==0){r=0; g=255; b=255;}


    int H = bmp.InfoHeader.height;
    int W = bmp.InfoHeader.width;

    if(X*wLine>W-X+1 || Y*wLine>H-Y+1){
    	printf("Введённые данные не позволяют разделить изображение. \nВызовите команду --info, чтобы узнать больше информации об изображении.\n");
    	return;
    }	

    int yparts = (H-(Y*wLine))/(Y+1);
    int check = (yparts + 1)*(Y+1)+wLine*Y;
    if(H>=check){
        yparts++;
    }
    int yshift = yparts;
    while (Y){
        for(int i = yshift; i<yshift+wLine; i++){
            for(int j=0; j<W; j++){
                bmp.arr[i][j].g = g;
                bmp.arr[i][j].r = r;
                bmp.arr[i][j].b = b;
            }
        }
        yshift = yshift+wLine+yparts;
        Y--;
    }
    //int xparts = (W-(X*wLine))/(X+1)+1;
    //int xshift = xparts;
    int xparts = (W-(X*wLine))/(X+1);
    check = (xparts + 1)*(X+1)+wLine*X;
    if(W>=check){
    	xparts++;
    }	
    int xshift = xparts;
    while(X){
        for(int i = 0; i<H; i++){
            for(int j=xshift; j<xshift+wLine; j++){
                bmp.arr[i][j].g = g;
                bmp.arr[i][j].r = r;
                bmp.arr[i][j].b = b;
            }
        }
        xshift = xshift+wLine+xparts;
        X--;
    }

}

//-----------------------------------------------------------------------

void openFolders(char *path, char *searchName, int *found){

    DIR *dir = opendir(path);
    char *nextPath = malloc(300*sizeof(char));
    strcpy(nextPath, path);

    if(dir){
        struct dirent *de = readdir(dir);
        while(de){
            if(de->d_type == DT_DIR && strcmp(de->d_name, ".")!=0 && strcmp(de->d_name, "..")!=0) {
                int len = strlen(path);
                strcat(nextPath, "/");
                strcat(nextPath, de->d_name);

                openFolders(nextPath, searchName, found);
                nextPath[len] = '\0';
            }
            if(strcmp(de->d_name, searchName)==0){
                (*found) = 1;
                return;
            }
            de = readdir(dir);
        }
    }
    closedir(dir);
    free(nextPath);

}
//-----------------------------------------------------------------------

int main(int argc, char **argv){

    static int function_flag = 0;
    char *FileName = argv[argc-1];
    char *check = strstr(FileName, ".bmp");
    int found = 0; 
    openFolders("/home/brokkko", FileName, &found);
    if(found == 0 && strcmp(FileName, "--help")!=0 && strcmp(FileName, "--help")!=0 && strcmp(FileName, "-h")!=0 &&
    	strcmp(FileName, "--info")!=0 && strcmp(FileName, "-i")!=0){
    	printf("Файл с таким именем не найден: либо же Вы ввели неверно имя файла, либо же забыли ввести имя файла.\n");
    	return 0;
    }
    Headers bmp;
    char *NewFileName = FileName;

    UserValues Values = {0};
    int c;
    while(1) {
        static struct option long_options[] =
                {{"help",        no_argument,       0, 'h'},
                 {"info",        no_argument,       0, 'i'},
                 {"Rectangle",  no_argument,       0, 'R'},
                 {"Circle",  no_argument,       0, 'C'},
                 {"Filter",   no_argument,       0, 'F'},
                 {"Parting",     no_argument,       0, 'P'},
                 {"color",      required_argument, 0, 'c'},
                 {"start",       required_argument, 0, 's'},
                 {"end",         required_argument, 0, 'e'},
                 {"radius",      required_argument, 0, 'r'},
                 {"thick_line",  required_argument, 0, 't'},
                 {"fill",        required_argument,       0, 'f'},
                 {"vertical",    required_argument,       0, 'x'},
                 {"horizontal",  required_argument,       0, 'y'},
                 {"value",  required_argument,       0, 'v'},
                 {"center",        required_argument, 0, 'z'},
		 {"line_color", required_argument, 0, 'l'},
                 {"save",        required_argument, 0, 'S'},
                 {0,0,0,0}

                };
        static int option_index = 0;
        c = getopt_long(argc, argv, "hiRCFPc:s:e:r:t:f:x:y:v:z:l:S:", long_options, &option_index);
        if (c == -1)
            break;
        switch(c){
            case 'h':
                function_flag = 0;
                printf("--info\n\tНе требует аргументов, сокращенный ключ: -i.\n\tПредоставляет информацию об изображении.\n\n");
		printf("--help\n\tНе требует аргументов, сокращенный ключ: -h.\n\tВыводит список возможных команд и информацию о них.\n\n");
		printf("--Rectangle\n\tНе требует аргументов, сокращенный ключ: -R.\n\tНаходит все прямоугольники заданного цвета и обводит их линией.\n\tЦвет по умолчанию: чёрный."
       	"\n\tПараметры: цвет прямоугольника, цвет линии, толщина линии.\n\n");
		printf("--Circle\n\tНе требует аргументов, сокращенный ключ: -C.\n\tРисует окружность."
       	"\n\tПараметры: координаты левой верхней точки и координаты правой нижней точки "
       	"\n\tлибо координаты центра и  радиус окружности, толщина линии, цвет линии."
       	"\n\tДополнительные параметры: заливка окружности.\n\n");
		printf("--Filter\n\tНе требует аргументов, сокращенный ключ: -F.\n\tУстанавливает значение rgb-компоненты либо в 0, либо в 255 для всего изображения."
       	"\n\tПараметры: цвет, значение компоненты(0 или 255). \n\n");
		printf("--Parting\n\tНе требует аргументов, сокращенный ключ: -P.\n\tРазделяет изображение на N*M частей."
       	"\n\tПараметры: количество линий по “оси” X, количество линий по “оси” Y, цвет (линий), толщина линий.\n\n");
		printf("--color\n\tСокращенный ключ: -c.\n\tАргументы: <цвет>.\n\tВозможные цвета: red, blue, green, yellow, purple, cyan, white, black.\n\n");
		printf("--start\n\tСокращенный ключ: -s.\n\tАргументы: <координата левой верхней точки по X> <координата левой верхней точки по Y>.\n\n");
		printf("--end\n\tСокращенный ключ: -e.\n\tАргументы: <координата правой нижней точки по X> <координата нижней правой точки по Y>.\n\n");
		printf("--radius\n\tСокращенный ключ: -r.\n\tАргументы: <радиус окружности>.\n\n");
		printf("--thick_line\n\tСокращенный ключ: -t.\n\tАргументы: <толщина линии>.\n\n");
		printf("--fill\n\tСокращенный ключ: -f.\n\tАргументы: <цвет заливки>.\n\tВозможные цвета: red, blue, green, yellow, purple, cyan, white, black.\n\n");
		printf("--vertical\n\tСокращенный ключ: -x.\n\tАргументы: <количество частей по “оси” Y>.\n\n");
		printf("--horizontal\n\tСокращенный ключ: -y.\n\tАргументы: <количество частей по “оси” X>.\n\n");
		printf("--value\n\tСокращенный ключ: -v.\n\tАргументы: <значение компоненты>.\n\n");
		printf("--center\n\tСокращенный ключ: -z.\n\tАргументы: <координата центра по “оси” X> <координата центра по “оси” Y>.\n\n");
		printf("--line_color\n\tСокращенный ключ: -l.\n\tАргументы: <цвет линии>.\n\tВозможные цвета: red, blue, green, yellow, purple, cyan, white, black.\n\n");
		printf("--save\n\tСокращенный ключ:  -S.\n\tАргументы: <имя сохраняемого файла>.\n\n");
		printf("!В конце строки нужно указать имя файла, который Вы хотите обработать.\n");
                break;
            case 'i':
            	if(strcmp(FileName, "--info")==0 || strcmp(FileName, "-i")==0){
            		printf("Вы не ввели название файла.\n");
    			break;
     		}			
                else{
                	printf("Информация об изображении:\n");
                	bmp = Read_BMP_File(FileName);
                	printFileHeader(bmp);
                	printInfoHeader(bmp);
                }	
                break;
            break;
            case 'R':
                function_flag = 1;
                break;
            case 'C':
                function_flag = 2;
                break;
            case 'F':
                function_flag = 3;
                break;
            case 'P':
                function_flag = 4;
                break;

            case 'c':
                Values.color = optarg;
                break;
            case 'v':
                Values.value = atoi(optarg);
                Values.fixValue = 1;
                break;
	    case 't':
		Values.thick_line = atoi(optarg);
		Values.fix = 1;
		break;
	    case 'l':
		Values.line_color = optarg;	
	        break;
	    case 's':
		if(optind > argc){
		    printf("Недостаточно аргументов.\n");	
                    break;
                }
		Values.startX = atoi(optarg);
		Values.startY = atoi(argv[optind]);
		Values.circleFlag = 2;
                break;
	    case 'e':
		if(optind > argc){
		   printf("Недостаточно аргументов.\n");
	           break;
                }
		Values.endX = atoi(optarg);
		Values.endY = atoi(argv[optind]);
		break;
	    case 'x':
		Values.vertical = atoi(optarg);
		break;
	    case 'y':
		Values.horizontal = atoi(optarg);
		break;
	    case 'z':
		if(optind > argc){
		   printf("Недостаточно аргументов\n");
   		   break;
		}
		Values.centerX = atoi(optarg);
		Values.centerY = atoi(argv[optind]);
		Values.circleFlag = 1;
		break;
	    case 'r':
		Values.radius = atoi(optarg);
		break;	
	    case 'f':
	    	Values.fill = optarg;
	    	Values.fillFlag = 1;
	    	break;
	    case 'S':
	    	NewFileName = optarg;
	    	break; 			
            default:
                printf("Неверный аргумент.\n");
                return 0;
        }
        option_index++;

    }
    switch (function_flag) {
	 case 1:
	    if(Values.line_color == NULL || Values.color == NULL){
	    	printf("Недостаточно аргументов. Проверьте, указали ли Вы ключи --color(-c) и --line_color(-l).\n");
	    	return 0;
	    }	
	    if(Values.color == NULL){
	    	printf("Вы не ввели ключ для цвета. Используйте --color(-c).\n");
	    	return 0;
	    }
	    bmp = Read_BMP_File(FileName);
	    Groundmoves(bmp, Values);
	    Write_BMP_File(NewFileName, bmp);
	    break;
	 case 2:
	    if(Values.color != NULL){
	    	printf("Вы использовали не тот ключ. Попробуйте --line_color(-l) либо --fill(-f), если Вы хотели залить окружность.\n");
	    	return 0;
	    }	
	    if(Values.line_color == NULL){
	    	printf("Вы не ввели ключ для цвета. Используйте --line_color(-l).\n");
	    	return 0;
	    }
	    bmp = Read_BMP_File(FileName);
	    DrawCircle(bmp, Values);
	    Write_BMP_File(NewFileName, bmp);
	    break;   
	 case 3:
	    if(Values.line_color != NULL){
	    	printf("Вы использовали не тот ключ. Попробуйте --color(-c).\n");
	    	return 0;
	    }	
	    if(Values.color == NULL){
	    	printf("Вы не ввели ключ для цвета. Используйте --color(-c).\n");
	    	return 0;
	    }
	    bmp = Read_BMP_File(FileName);
            RGBFilter(bmp, Values);
	    Write_BMP_File(NewFileName, bmp);
            break;
	 case 4:
	    if(Values.line_color != NULL){
	    	printf("Вы использовали не тот ключ. Попробуйте --color(-c).\n");
	    	return 0;
	    }
	    if(Values.color == NULL){
	    	printf("Вы не ввели ключ для цвета. Используйте --color(-c).\n");
	    	return 0;
	    }
	    bmp = Read_BMP_File(FileName);
	    PartingImage(bmp, Values);
	    Write_BMP_File(NewFileName, bmp);
	    break;

         default:
                printf("Функция не выбрана.\n");      

    }

    return 0;
}