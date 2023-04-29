/*Problem Description:
Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).*/

#include <iostream>
using namespace std;
void inplaceHeapSort(int *arr, int n)
{
    // built heap
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[parentIndex] > arr[childIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    // remove elements
    int size = n;
    while (size > 1)
    {
        int ans = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = ans;

        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < size)
        {

            int minIndex = parentIndex;
            if (arr[leftChildIndex] < arr[minIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && arr[minIndex] > arr[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        
    }
}


int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    inplaceHeapSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}