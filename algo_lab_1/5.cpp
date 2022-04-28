//bucket sort algorithm implementation and check for correctness
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{
     
    // 1) Create n empty buckets
    vector<float> b[n];
 
    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
//function to check for correctness
bool iscorrect(float arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        return false;
    }
    return true;
}
int main()
{
    float arr[]
        = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
    if(iscorrect(arr,n))
    cout<<"The array is sorted correctly"<<endl;
   return 0;
}