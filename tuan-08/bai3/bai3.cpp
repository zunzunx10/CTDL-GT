#include <iostream>

using namespace std;

int n, *A;

void find_largest_subarray()
{
    int largest_subarray = 0, *ending_subarray = new int[n], cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int zeros = 0, ones = 0;

        for (int j = i; j < n; j++)
        {
            if (A[j] == 0) ++zeros;
            else ++ones;
            if (zeros == ones)
            {
                if (largest_subarray < zeros + ones)
                {
                    largest_subarray = zeros + ones;
                    cnt = 0; 
                    ending_subarray[cnt++] = j;
                }
                else if (largest_subarray == zeros + ones) ending_subarray[cnt++] = j;
            }
        }
    }
    if (largest_subarray == 0) cout << -1;
    else 
    {
        for (int j = 0; j < cnt; j++)
        {
            for (int i = ending_subarray[j] - largest_subarray + 1; i <= ending_subarray[j]; i++) cout << A[i] << " ";
            cout << endl;
        }
    }
}

int main()
{
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    find_largest_subarray();
    return 0;
}