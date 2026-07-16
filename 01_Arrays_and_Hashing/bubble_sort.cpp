#include <iostream>
void bubble_sort(int arr[], int size);

int main()
{
    int arr[] = {1, 4, 5, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}