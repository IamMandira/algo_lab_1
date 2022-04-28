//randomized quick sort
//randomized quick sort
#include <iostream>
#include<time.h>
using namespace std;
 
int partition(int arr[], int start, int end,int *cnt)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    *cnt++;
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            *cnt++;
        }
    }
 
    return pivotIndex;
}
int randomized_partition(int *arr, int initial, int final, int *count)
{
    int i = rand() % (final - initial) + initial;
    swap(arr[final], arr[i]);
    return partition(arr, initial, final, count);
}
 
void quickSort(int arr[], int start, int end,int *cnt)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = randomized_partition(arr, start, end,cnt);
 
    // Sorting the left part
    quickSort(arr, start, p - 1,cnt);
 
    // Sorting the right part
    quickSort(arr, p + 1, end,cnt);
}
void getArray(int *arr, int n)
{

    FILE *fin = fopen("./NormalDst.txt", "r");

    double temp = 0.0;
    fscanf(fin, "%lf\n", &temp);
    for (int i = 0; i < n; i++)
    {
        int skip = rand() % 5;

        for (int j = 0; j < skip; j++)
            fscanf(fin, "%lf\n", &temp);

        fscanf(fin, "%lf\n", &temp);

        arr[i] = temp;
    }

    fclose(fin);
}

/* Driver code */
int main()
{
    int n = 2;
    int power = 15;
    int iterations = 20;

    FILE *fout = fopen("Normal_rqs_comparisons.txt", "w");

    for (int i = 0; i < power; i++)
    {

        long total_cnt = 0;
        float total_time = 0;

        for (int j = 0; j < iterations; j++)
        {
            int *arr = new int [n];
            int cnt = 0;
            getArray(arr, n);

            float start_time = clock();
            quickSort(arr, 0, n - 1, &cnt);
            float end_time = clock();

            total_cnt += cnt;

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            total_time += time_taken;

            
        }
        float avg_time = total_time / iterations;
        long avg_count = total_cnt / iterations;
        //printf("\nN: %d, Avg time: %0.4f, Avg count: %ld\n", n, avg_time, avg_count);
        fprintf(fout, "%d, %0.4f, %ld\n", n, avg_time, avg_count);
        n *= 2;
    }
    return 0;
}