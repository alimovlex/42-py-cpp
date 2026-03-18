#include <stdio.h>
#include <threads.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("=== Welcome to My Garden ===\n");
    char *name = "Rose";
    char *height = "25cm";
    char *age = "30 days";
    printf("Plant: %s\n", name);
    printf("Height: %s\n", height);
    printf("Age: %s\n", age);
    printf("=== End of Program ===\n");

    return 0;
}
