//Construct large data sets taking random numbers from uniform distribution (UD)
#include<iostream>
#include<stdlib.h>
#include<time.h>
const int total_no_of_elements = 10e6;
const int MAX= 100;

int main()
{
    srand(time(0));
    char filename[40] = "UniformDst.txt";
    FILE *fp;
    fp = fopen(filename, "w");
    for (int i = 0; i < total_no_of_elements; i++)
    {
        fprintf(fp, "%d\n", rand() % MAX);
    }
    fclose(fp);
    return 0;
}