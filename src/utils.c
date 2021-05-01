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
