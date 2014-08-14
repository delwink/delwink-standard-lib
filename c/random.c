#include <stdlib.h>
#include "random.h"

/**
 * Returns a random integer between two values.
 */
int get_random(int top, int bottom)
{
    return bottom + (rand() % top - bottom) + 1;
}
