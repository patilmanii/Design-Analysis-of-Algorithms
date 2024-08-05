#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i; 
    int left_child = 2 * i + 1; 
    int right_child = 2 * i + 2;

    // If the left child is smaller than the root
    if (left_child < n && arr[left_child] < arr[smallest])
        smallest = left_child;

    // If the right child is smaller than the smallest so far
    if (right_child < n && arr[right_child] < arr[smallest])
        smallest = right_child;

    // If the smallest is not the root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        // Recursively heapify the affected subtree
        heapify(arr, n, smallest);
    }
}
// Function to build a Min Heap from an array
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node in reverse order
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
// Function to print the elements of the heap
void printHeap(int arr[], int n) {
    cout << "Min Heap: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);
    printHeap(arr, n);

    return 0;
}
