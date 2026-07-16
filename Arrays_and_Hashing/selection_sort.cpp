#include <iostream>

void selection_sort(int arr[], int size);

int main()
{
    int arr[] = {4, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}