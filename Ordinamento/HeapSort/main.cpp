// Heap Sort O(nlog(n))
#include <iostream>


// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap

template<typename T>
void swap(T* arr, int i, int j){
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}

template <typename T>
void heapify(T* arr, int n, int i){
	
    // Initialize largest as root
        int largest = i;
        
    // left = 2*i + 1
        int l = 2 * i + 1;
        
    // right = 2*i + 2
        int r = 2 * i + 2;

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest
        // so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr, i, largest);

            // Recursively heapify the affected
            // sub-tree
            heapify(arr, n, largest);
        }
}

// Main function to do heap sort
template <typename T>
void heapSort(T arr[], int n)
{
    
    // Build heap (rearrange array)
    for (int i = n/2; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element
    // from heap

    for (int i = n-1; i > 0; i--) {
        // Move current root to end
       // std::cout << "Debug i: " << i << "\n";
        //std::cout << "Debug i: " << v[i] << "\n";
        swap(arr, 0, i);
        //std::cout << "Debug arr[ultimo]: " << arr[i] << "\n";
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
       // std::cout << "Debug arr[ultimo] dopo heapify: " << arr[i] << "\n";
    }
}

// A utility function to print array of size n
template <typename T>
void printArray(T arr[], int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}




// Driver code
int main()
{
	int arr[] = {78, 26 , 39 , 47 , 1 , 25, 36, 7, 34};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	std::cout << "Sorted array is \n";
	printArray(arr, n);
}
