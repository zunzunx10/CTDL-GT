#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int n, *A; 

void rearrange()
{
    for (int i = 1; i < n; i = i + 2)
    {
        if (A[i - 1] > A[i]) swap(A[i-1], A[i]);
        if (i + 1 < n && A[i] < A[i + 1]) swap(A[i], A[i + 1]);
    }
}

int main()
{
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    rearrange();
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    return 0;
}