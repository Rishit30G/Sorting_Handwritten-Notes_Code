#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(a[k], a[i]);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low, j = high;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);
    swap(a[low], a[j]);
    return j;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi);
        QuickSort(a, pi + 1, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    for (; i <= mid; i++)
    {
        b[k++] = a[i];
    }
    for (; j <= high; j++)
    {
        b[k++] = a[j];
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
}
void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void CountSort(int a[], int n)
{
    int maxi = *max_element(a, a + n);
    int b[maxi + 1];
    for (int i = 0; i < maxi + 1; i++)
    {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int j = 0, i = 0;
    while (j < maxi + 1)
    {
        if (b[j] > 0)
        {
            a[i++] = j;
            b[j]--;
        }
        else
            j++;
    }
}

void ShellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter size of the array: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;

    cout << "Menu for Sorting: " << endl;
    cout << "-------------------" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Count Sort" << endl;
    cout << "7. Shell Sort" << endl;

    cout << endl;

    cout << "Enter your choice: ";
    int t;
    cin >> t;

    // Bubble Sort
    if (t == 1)
    {
        BubbleSort(a, n);
        printArray(a, n);
    }

    // Insertion Sort
    else if (t == 2)
    {
        InsertionSort(a, n);
        printArray(a, n);
    }

    // Selection Sort
    else if (t == 3)
    {
        SelectionSort(a, n);
        printArray(a, n);
    }

    // Quick Sort
    else if (t == 4)
    {
        QuickSort(a, 0, n);
        printArray(a, n);
    }

    // Merge Sort
    else if (t == 5)
    {
        MergeSort(a, 0, n - 1);
        printArray(a, n);
    }

    // Count Sort
    else if (t == 6)
    {
        CountSort(a, n);
        printArray(a, n);
    }

    // Shell Sort
    else if (t == 7)
    {
        ShellSort(a, n);
        printArray(a, n);
    }
}