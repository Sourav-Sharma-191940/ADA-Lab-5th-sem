// Recursive Merge sort for sorting random integers.
#include <iostream>
#include <chrono> //include clock
using namespace std;
using namespace std::chrono;

void merge(int *Arr, int start, int mid, int end)
{
    int temp[end - start + 1];

    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (Arr[i] <= Arr[j])
        {
            temp[k] = Arr[i];
            k += 1;
            i += 1;
        }
        else
        {
            temp[k] = Arr[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid)
    {
        temp[k] = Arr[i];
        k += 1;
        i += 1;
    }

    while (j <= end)
    {
        temp[k] = Arr[j];
        k += 1;
        j += 1;
    }

    for (i = start; i <= end; i += 1)
    {
        Arr[i] = temp[i - start];
    }
}

void MergeSort(int *Arr, int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(Arr, start, mid);
        MergeSort(Arr, mid + 1, end);
        merge(Arr, start, mid, end);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int x; //creating random array value.
    cout << "Enter the size of array::";
    cin >> x;
    int randArray[x];
    for (int i = 0; i < x; i++)
        randArray[i] = rand() % 3000;
    cout << "\nElements of the array::" << endl;
    for (int i = 0; i < x; i++)
        cout << randArray[i] << " ";

    auto start = high_resolution_clock::now(); //start clock
    cout << "\nThe sorted numbers are:: ";
    MergeSort(randArray, 0, x - 1);
    printArray(randArray, x);
    auto stop = high_resolution_clock::now();                  //stop clock
    auto duration = duration_cast<milliseconds>(stop - start); //calculate time duration
    cout << "Time taken by function: "
         << duration.count() << "milliseconds" << endl;
    return 0;
}
