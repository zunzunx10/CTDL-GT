#include <iostream>

using namespace std;

int n;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(int* A)
{
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

int Partition(int* A, int l, int r){
	int pivot = A[l];
    --l; ++r;
    while (true)
    {
        do {
            ++l;
        } while (A[l] < pivot);
        do {
            --r;
        } while (A[r] > pivot);
        if (l < r) 
        {
            swap(A[l], A[r]);
            print(A);
        }
        else return r;
    }
}

void Quick_sort(int* A, int l, int r) {
    if (l < r) {
        int pivot_index = Partition(A, l, r);
        Quick_sort(A, l, pivot_index);
        Quick_sort(A, pivot_index + 1, r);
    }
}

int main()
{
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    Quick_sort(A, 0, n-1);
}