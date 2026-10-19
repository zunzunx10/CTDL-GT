#include <iostream>

using namespace std;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[k]) k = j; 
        } 
        cout << "Min: " << a[k] << endl;
        swap(a[k], a[i]);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    selection_sort(a, n);
}