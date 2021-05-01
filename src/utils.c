#include <time.h>
#include <stdlib.h>

/** 
 * @param min - minimum value for range
 * @param max - maximum value for range
 * @return random double value between min and max 
*/
double randInRange(int min, int max)
{
    return min + (rand() * (double)(max - min) / RAND_MAX);
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

/** 
 * @param arr - 2D integer array
 * @param rows - number of rows
 * @param cols - number of columns
 * @return dynamically allocated copy of arr 
*/
int **copy2dArr(int **arr, int rows, int cols)
{
    int **copy = allocate2dArr(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            copy[i][j] = arr[i][j];
    return copy;
}

