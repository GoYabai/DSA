#include <iostream>

int binary_search(int arr[], int size, int target);
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    std::cin >> target;
    int n = binary_search(arr, size, target);
    std::cout << n;
    return 0;
}

int binary_search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}