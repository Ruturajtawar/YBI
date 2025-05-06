#include <iostream> 
#include <omp.h> 
using namespace std; 
 
void merge(int arr[], int left, int mid, int right) { 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
 
    // Create temporary arrays 
    int leftArr[n1], rightArr[n2]; 
 
    // Copy data to temporary arrays 
    for (int i = 0; i < n1; i++) { 
        leftArr[i] = arr[left + i]; 
    } 
    for (int i = 0; i < n2; i++) { 
        rightArr[i] = arr[mid + 1 + i]; 
    } 
 
    // Merge the temporary arrays back into arr[left..right] 
    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) { 
        if (leftArr[i] <= rightArr[j]) { 
            arr[k] = leftArr[i]; 
            i++; 
        } else { 
            arr[k] = rightArr[j]; 
            j++; 
        } 
        k++; 
    } 
 
    // Copy remaining elements of leftArr[], if any 
    while (i < n1) { 
        arr[k] = leftArr[i]; 
        i++; 
        k++; 
    } 
 
    // Copy remaining elements of rightArr[], if any 
    while (j < n2) { 
        arr[k] = rightArr[j]; 
        j++; 
        k++; 
    } 
} 
 
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        int mid = left + (right - left) / 2; 
 
        // Parallelize the mergeSort recursively 
        #pragma omp parallel sections 
        { 
            #pragma omp section 
            mergeSort(arr, left, mid); 
 
            #pragma omp section 
            mergeSort(arr, mid + 1, right); 
        } 
 
        // Merge the sorted halves 
        merge(arr, left, mid, right); 
    } 
} 
 
int main() { 
    int n; 
    cout << "Enter the number of elements: "; 
    cin >> n; 
 
    int arr[n];  // Declare an array of size n 
 
    cout << "Enter the elements of the array: "; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
 
    cout << "Unsorted array: "; 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
 
    // Call mergeSort 
    mergeSort(arr, 0, n - 1); 
 
    cout << "Sorted array: "; 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
 
    return 0; 
} 
