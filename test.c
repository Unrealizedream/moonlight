#include <stdio.h>

int findindex(const int * array, int size)
{
    int max = array[0];
    int returnvalue = 0;
    for (int i = 0; i < size; i++)
    { 
        if (max < array[i])
        {
            max = array[i];
            returnvalue = i;
        }
    }
    return returnvalue;


}

int main()
{
    int data[5] = {61, 74, 43, 21, 6};
    int indexofmax = findindex(data, sizeof(data)/sizeof(int));
    printf ("最大值第一次出线的索引位置是：%d\n",indexofmax);
    printf("最大值是:%d\n",data[indexofmax]);
    return 0;








    return 0;
}