
#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right) {
    int leftArraySize  = mid - left + 1;
    int rightArraySize = right - mid;

    auto *leftArray  = new int[leftArraySize],
         *rightArray = new int[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[left + i];

    for (int j = 0; j < rightArraySize; j++)
        rightArray[j] = array[mid + 1 + j];

    int leftArrayIndex = 0, rightArrayIndex = 0;
    int mergedArrayIndex = left;

    while (leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize) {

        if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex]) {
            array[mergedArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        }
        else {
            array[mergedArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }

        mergedArrayIndex++;
    }

    while (leftArrayIndex < leftArraySize) {
        array[mergedArrayIndex] = leftArray[leftArrayIndex];

        leftArrayIndex++;
        mergedArrayIndex++;
    }

    while (rightArrayIndex < rightArraySize) {
        array[mergedArrayIndex] = rightArray[rightArrayIndex];

        rightArrayIndex++;
        mergedArrayIndex++;
    }
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main() {
    int ara[] = {2, 6, 4, 1, 3, 8, 9, 7, 5, 10};
    auto n    = sizeof(ara) / sizeof(ara[0]);

    mergeSort(ara, 0, n - 1);

    for (auto i = 0; i < n; i++)
        cout << ara[i] << " ";
    cout << endl;

    return 0;
}
