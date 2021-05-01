#ifndef __UTILS_H__
#define __UTILS_H__

/** 
 * @param min - minimum value for range
 * @param max - maximum value for range
 * @return random double value between min and max 
*/
int randInRange(int min, int max);

/** 
 * @param rows - number of rows
 * @param cols - number of columns
 * @return dynamically allocated two dimensional integer array 
*/
int **allocate2dArr(int rows, int cols);

/** 
 * @param arr - 2D integer array
 * @param rows - number of rows
 * @param cols - number of columns
 * @return dynamically allocated copy of arr 
*/
int **copy2dArr(int **arr, int rows, int cols);

#endif