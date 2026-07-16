#include <iostream>

void insertion_sort(int arr[], int size);
int main()
{
    int arr[] = {3, 2, 5, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
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