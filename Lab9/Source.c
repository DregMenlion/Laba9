#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main(void)
{
    int width, height, top;
    int row, x, xmin, left, right;
    char symbol;

    setlocale(LC_ALL, "RUS");

    printf("Введите символ для рисования: ");
    if (scanf(" %c", &symbol) != 1)
    {
        printf("Ошибка ввода символа.\n");
        return 1;
    }

    printf("Введите ширину основания и высоту (целые числа от 2): ");
    if (scanf("%d%d", &width, &height) != 2 || width < 2 || height < 2)
    {
        printf("Ошибка ввода размеров.\n");
        return 1;
    }

    printf("Введите положение верхней вершины относительно левого края основания.\n");
    printf("Левый край - 0, правый край - %d: ", width - 1);
    if (scanf("%d", &top) != 1)
    {
        printf("Ошибка ввода положения вершины.\n");
        return 1;
    }

    xmin = 0;
    if (top < 0)
        xmin = top;

    for (row = 0; row < height; row++)
    {
        left = (int)((double)top * (height - 1 - row) / (height - 1));
        right = (int)(((double)top * (height - 1 - row)
            + (width - 1.0) * row) / (height - 1));

        for (x = xmin; x <= right; x++)
        {
            if (x >= left)
                printf("%c", symbol);
            else
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
