#include <iostream>
#include <vector>

class SortingAlgorithms {
private:
    // Utility function for merge sort
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        // TODO: Implement merge function
        // 1. Create temporary arrays L[] and R[]
        // 2. Copy data to temporary arrays
        // 3. Merge the temporary arrays back into arr[left..right]
        std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
        std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
        int i = 0;
        int j = 0;
        int curr = left;
        while (i < L.size() && j < R.size())
        {
            if (L[i] < R[j])
            {
                arr[curr] = L[i];
                curr++;
                i++;
            }
            else
            {
                arr[curr] = R[j];
                curr++;
                j++;
            }
        }
        while (i < L.size())
        {
            arr[curr] = L[i];
            curr++;
            i++;
        }
        while (j < R.size())
        {
            arr[curr] = R[j];
            curr++;
            j++;
        }
    }

    // Utility function for quick sort
    static int partition(std::vector<int>& arr, int low, int high) {
        // TODO: Implement partition function
        // 1. Select pivot (typically last element)
        // 2. Place pivot at its correct position
        // 3. Place smaller elements to left of pivot and greater to right
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1; // Placeholder return
    }

    // Recursive function for merge sort
    static void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
        // TODO: Implement recursive merge sort
        // 1. Check if left < right
        // 2. Find middle point
        // 3. Sort first and second halves
        // 4. Merge the sorted halves
        if (left < right)
        {
            int mid = (left + right) / 2;
            mergeSortRecursive(arr, left, mid);
            mergeSortRecursive(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    // Recursive function for quick sort
    static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
        // TODO: Implement recursive quick sort
        // 1. Check if low < high
        // 2. Get partition index
        // 3. Sort elements before and after partition
        if (low < high)
        {
            int ip = partition(arr, low, high);
            quickSortRecursive(arr, low, ip - 1);
            quickSortRecursive(arr, ip + 1, high);
        }
    }

public:
    // Bubble Sort
    static void bubbleSort(std::vector<int>& arr) {
        // TODO: Implement bubble sort
        // 1. Use nested loops
        // 2. Compare adjacent elements
        // 3. Swap if they are in wrong order
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = 0; j < arr.size() - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Selection Sort
    static void selectionSort(std::vector<int>& arr) {
        // TODO: Implement selection sort
        // 1. Find minimum element in unsorted array
        // 2. Swap it with first element of unsorted part
        // 3. Move boundary of unsorted array
        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            int index = i;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] < curr)
                {
                    curr = arr[j];
                    index = j;
                }
            }
            std::swap(arr[i], arr[index]);
        }
    }

    // Insertion Sort
    static void insertionSort(std::vector<int>& arr) {
        // TODO: Implement insertion sort
        // 1. Iterate through array
        // 2. For each element, insert it into its correct position in sorted part
        for (int i = 1; i < arr.size(); i++)
        {
            int curr = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > curr)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }
    }

    // Merge Sort (public interface)
    static void mergeSort(std::vector<int>& arr) {
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

    // Quick Sort (public interface)
    static void quickSort(std::vector<int>& arr) {
        quickSortRecursive(arr, 0, arr.size() - 1);
    }
};

// Utility function to print array
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Testing function - DO NOT MODIFY
void testSortingAlgorithms() {
    std::vector<std::vector<int>> testArrays = {
        {64, 34, 25, 12, 22, 11, 90},
        {38, 27, 43, 3, 9, 82, 10},
        {8, 4, 23, 42, 16, 15},
        {122, 45, 75, 90, 32, 11},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    std::cout << "Testing Bubble Sort:\n";
    std::vector<int> arr1 = testArrays[0];
    std::cout << "Original array: ";
    printArray(arr1);
    SortingAlgorithms::bubbleSort(arr1);
    std::cout << "Sorted array: ";
    printArray(arr1);
    std::cout << std::endl;

    std::cout << "Testing Selection Sort:\n";
    std::vector<int> arr2 = testArrays[1];
    std::cout << "Original array: ";
    printArray(arr2);
    SortingAlgorithms::selectionSort(arr2);
    std::cout << "Sorted array: ";
    printArray(arr2);
    std::cout << std::endl;

    std::cout << "Testing Insertion Sort:\n";
    std::vector<int> arr3 = testArrays[2];
    std::cout << "Original array: ";
    printArray(arr3);
    SortingAlgorithms::insertionSort(arr3);
    std::cout << "Sorted array: ";
    printArray(arr3);
    std::cout << std::endl;

    std::cout << "Testing Merge Sort:\n";
    std::vector<int> arr4 = testArrays[3];
    std::cout << "Original array: ";
    printArray(arr4);
    SortingAlgorithms::mergeSort(arr4);
    std::cout << "Sorted array: ";
    printArray(arr4);
    std::cout << std::endl;

    std::cout << "Testing Quick Sort:\n";
    std::vector<int> arr5 = testArrays[4];
    std::cout << "Original array: ";
    printArray(arr5);
    SortingAlgorithms::quickSort(arr5);
    std::cout << "Sorted array: ";
    printArray(arr5);
}

int main() {
    testSortingAlgorithms();
    return 0;
}
