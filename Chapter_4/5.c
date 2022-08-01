#include <stdio.h>

int main()
{
    float speed;
    float size;
    printf ("Введите скорость загрузки в мегабайтах в секунду:");
    scanf ("%f", &speed);
    printf ("\nВведите размер файла в мегабайтах:");
    scanf ("%f", &size);
    float speed_bit = speed*8;
    float download = size/speed;
    printf ("\nПри скорости загрузки %f мегабит в секунду файл размером %.2f мегабайт загружается за %.2f секунд", speed_bit, size, download);
}