#include <iostream>

using namespace std;

int n, *A;

void find_bitonic_subarray()
{
    int* I = new int[n];
    I[0] = 1;
    for (int i = 1; i < n; i++)
    {
        I[i] = 1;
        if (A[i - 1] < A[i]) {
            I[i] = I[i - 1] + 1;
        }
    }
    int* D = new int[n];
    D[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        D[i] = 1;
        if (A[i] > A[i + 1]) {
            D[i] = D[i + 1] + 1;
        }
    } 
    int longest_subarray = 1, end = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (longest_subarray < I[i] + D[i] - 1)
        {
            longest_subarray = I[i] + D[i] - 1;
            end = i + D[i] - 1;
        }
    }
    for (int i = end - longest_subarray + 1; i <= end; i++) cout << A[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    find_bitonic_subarray();
    return 0;
}