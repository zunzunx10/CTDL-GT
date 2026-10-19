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

void merge(int* a, int l, int m, int r)
{
    int x_size = m + 1 - l, y_size = r - (m + 1) + 1;
    int *x = new int[x_size]; 
    int *y = new int[y_size]; //tạo dãy con trái và dãy con phải
    for (int i = 0; i < x_size; i++) x[i] = a[i + l];
    for (int i = 0; i < y_size; i++) y[i] = a[i + m + 1];
    int i = 0, j = 0;
    while (i < x_size && j < y_size) //merge 2 dãy con đã được sắp xếp
    {
        if (x[i] <= y[j]) 
        {
            a[l] = x[i];
            ++l;
            ++i;
        }
        else
        {
            a[l] = y[j];
            ++l;
            ++j;
        }
       print(a);
    }
    while (i < x_size)
    {
        a[l] = x[i];
        print(a);
        ++l;
        ++i;
    }
    while (j < y_size)
    {
        a[l] = y[j];
        print(a);
        ++l;
        ++j;
    }
}
void merge_sort(int* a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r)/2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    merge_sort(A, 0, n-1);

}