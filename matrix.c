#include "fdf.h"

void fill_data(t_for_matrix *matrix, t_stack **stack, t_fdf *fdf)
{
    int width = fdf->width;

    while (width--)
    {
        matrix[width].z.altitude = (*stack)->z->altitude;
        matrix[width].z.color = (*stack)->z->color;
        *stack = (*stack)->next;
    }
}

t_for_matrix **create_matrix(t_fdf *fdf, t_stack *stack)
{
    t_for_matrix **matrix;
    int height = fdf->height;
    int width = fdf->width;

    matrix = (t_for_matrix **)malloc(sizeof(t_for_matrix *) * (height + 1));
    if (!matrix)
        return (NULL);

    while (height-- > 0)
    {
        matrix[height] = (t_for_matrix *)malloc(sizeof(t_for_matrix) * width);
        if (!matrix[height])
            return (NULL);
        fill_data(matrix[height], &stack, fdf); // Используем matrix[height] здесь
    }

    matrix[fdf->height] = NULL; // Записываем NULL в конец массива

    return (matrix);
}
