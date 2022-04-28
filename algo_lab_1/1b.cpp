//Construct large data sets taking random numbers from normal distribution (ND)
#include <stdio.h>
#include <time.h>   //for random seed
#include <stdlib.h> //for rand() and srand()

const int total_no_of_elements = 10e6;
const int MAX = 100;
const int sub_ele= 10;

int main()
{
    srand(time(0));

    char filename[30] = "NormalDst.txt";
    FILE *fp;
    fp=fopen(filename,"w");

    for (int i = 0; i < total_no_of_elements; i++)
    {
        int sum = 0;
        for (int j = 0; j < sub_ele; j++)
        {
            sum += rand() % (MAX / sub_ele);
        }
        fprintf(fp, "%d\n", sum);
    }
    fclose(fp);
    return 0;
}