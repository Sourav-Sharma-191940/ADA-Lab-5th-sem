// Recursive Bubble sort for sorting random integers.
#include <iostream>
#include <chrono> //include clock
using namespace std;
using namespace std::chrono;

void BubbleSort(int arr[], int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    BubbleSort(arr, n - 1);
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
    BubbleSort(randArray, x);
    printArray(randArray, x);
    auto stop = high_resolution_clock::now();                  //stop clock
    auto duration = duration_cast<milliseconds>(stop - start); //calculate time duration
    cout << "Time taken by function: "
         << duration.count() << "milliseconds" << endl;
    return 0;
}
