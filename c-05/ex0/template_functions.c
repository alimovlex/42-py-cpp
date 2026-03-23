//
// Created by robot on 3/12/26.
//

#include "template_functions.h"

void iterate_any(void* data, bool* checker, char* str)
{
    char *ptr = NULL;
    int num = 0;
    int *arr = (int*)data;
    if (!arr)
    {
        sprintf("All elements have to be integers\n", "%s", str);
        *checker = false;
        return;
    }
    while(*arr)
    {
        num = (int)*arr;
        if (!num)
        {
            *checker = false;
            return;
        }
        //*ptr = (int)*arr + '0';
        sprintf(ptr,"%d", num);
        strcat(str, ptr);
        arr++;
    }
    *checker = true;
}

/*
size_t get_size(const std::any& data)
{
    if (auto vec = std::any_cast<std::vector<int>>(&data))
        return vec->size();
    else if (auto str = std::any_cast<std::string>(&data))
        return str->size();
    else
        return 0;
}
*/