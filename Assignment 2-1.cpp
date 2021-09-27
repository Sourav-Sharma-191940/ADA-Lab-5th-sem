// Recursive Insertion sort for sorting random integers.
#include <iostream>
#include <chrono>//include clock
using namespace std;
using namespace std::chrono;

void InsertionRecur(int arr[], int n)
{
    if (n <= 1)
        return;
    InsertionRecur(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 and arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
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
    InsertionRecur(randArray, x);
    printArray(randArray, x);
    auto stop = high_resolution_clock::now();                  //stop clock
    auto duration = duration_cast<milliseconds>(stop - start); //calculate time duration
    cout << "Time taken by function: "
         << duration.count() << "milliseconds" << endl;
    return 0;
}
