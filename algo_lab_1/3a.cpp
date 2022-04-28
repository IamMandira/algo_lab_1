//Count the operations performed for MS with both UD and ND as input data.
#include <iostream>
#include <time.h>
using namespace std;
void merge(int array[], int const left, int const mid, int const right,int *count)
{
    int op_count=(*count);
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            op_count++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            op_count++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of left[]
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        op_count++;
    }
    // Copy the remaining elements of right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        op_count++;
    }
    *count=op_count;
}
void mergeSort(int array[], int const begin, int const end,int *count)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid,count);
    mergeSort(array, mid + 1, end,count);
    merge(array, begin, mid, end,count);
}
//utility function
void getArray(int *arr, int n) {
    FILE *fin = fopen("./UniformDst.txt", "r");

    int temp = 0;
    fscanf(fin, "%d\n", &temp);
    for (int i = 0; i < n; i++) {
        int skip = rand() % 5;

        for (int j = 0; j < skip; j++) fscanf(fin, "%d\n", &temp);

        fscanf(fin, "%d\n", &temp);

        arr[i] = temp;
    }

    fclose(fin);
}

/* Driver code */
int main() {
    int n = 2;
    int power = 16;
    int iterations = 20;

    FILE *fout = fopen("Uniform_comparisons.txt", "w");

    for (int i = 0; i < power; i++) {
        long total_cnt = 0;
        float total_time = 0;

        for (int j = 0; j < iterations; j++) {
            int *arr = (int *)malloc(n * sizeof(int));
            int cnt = 0;
            getArray(arr, n);

            float start_time = clock();
            mergeSort(arr, 0, n - 1, &cnt);
            float end_time = clock();

            total_cnt += cnt;

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            total_time += time_taken;
        }
        float avg_time = total_time / iterations;
        long avg_count = total_cnt / iterations;
        // printf("\nN: %d, Avg time: %0.4f, Avg count: %ld\n", n, avg_time,
        // avg_count);
        fprintf(fout, "%d, %0.4f, %ld\n", n, avg_time, avg_count);
        n *= 2;
    }
    return 0;
}