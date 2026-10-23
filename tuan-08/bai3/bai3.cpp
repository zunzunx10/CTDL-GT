#include <iostream>

using namespace std;

int n, *A;

void find_largest_subarray()
{
    int largest_subarray = 0, ending_subarray = 0, starting_subarray = 0;

    for (int i = 0; i < n; i++)
    {
        int zeros = 0, ones = 0;

        for (int j = i; j < n; j++)
        {
            if (A[j] == 0) ++zeros;
            else ++ones;
            if (zeros == ones && largest_subarray < zeros + ones)
            {
                largest_subarray = zeros + ones;
                ending_subarray = j;
                starting_subarray = i;
            }
        }
    }
    if (largest_subarray == 0) cout << -1;
    else 
    {
        for (int i = starting_subarray; i <= ending_subarray; i++) cout << A[i] << " ";
        cout << endl;
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