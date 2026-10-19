#include <iostream>

using namespace std;

void insertion_sort(int* a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int tro = a[i];
        int j = i;
        while (a[j-1] > tro && j > 0)
        {
            a[j] = a[j-1];
            --j;
        }
        a[j] = tro;
        cout << "So so sanh: " << tro << endl;
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
            if (k == i) cout << " | ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    insertion_sort(a, n);
}