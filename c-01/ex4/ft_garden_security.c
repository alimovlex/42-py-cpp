#include "SafePlant.h"

int main(int argc, char** argv)
{
    printf("=== Garden Security System ===\n");
    SafePlant rose;
    SafePlant_ctor(&rose ,"Rose", 25, 30);
    SafePlant_set_height(&rose, 25);
    SafePlant_set_age(&rose, 30);
    SafePlant_set_height(&rose, -5);
    printf("Current plant: ");
    SafePlant_get_info(&rose);
    SafePlant_dtor(&rose);
    return 0;
}
