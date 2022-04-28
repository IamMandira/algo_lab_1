//Implement Quick Sort (QS) and check for correctness
#include <iostream>
using namespace std;
 
int partition(int arr[], int start, int end)
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
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
//Function to check for correctness
bool iscorrect(int A[],int size)
{
    for(int i=1;i<size;i++)
    {
        if(A[i]<A[i-1])
        return false;
    }
    return true;
}
 
int main()
{
 
    int arr[] = { 9, 3, 4, 2, 1, 8 };
    int n = 6;
    cout << "Given array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    quickSort(arr, 0, n - 1);
    cout << "\nSorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    if(iscorrect(arr,n))
    cout<<"\nThe array is sorted correctly"<<endl;
    else
    cout<<"\nThere is some problem in sorting the array"<<endl;
 
    return 0;
}