#include <time.h>
#include <stdlib.h>

/** 
 * @param min - minimum value for range
 * @param max - maximum value for range
 * @return random double value between min and max 
*/
double randInRange(int min, int max)
{
    return min + (double)(rand() / (double)(RAND_MAX + 1.0) * (max - min + 1));
}

/** 
 * @param rows - number of rows
 * @param cols - number of columns
 * @return dynamically allocated two dimensional integer array 
*/
int **allocate2dArr(int rows, int cols)
{
    int **arr = (int **)calloc(sizeof(int *), rows);
    for (int i = 0; i < rows; i++)
        arr[i] = (int *)calloc(sizeof(int), cols);
    return arr;
}


