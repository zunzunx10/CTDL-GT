#include <iostream>

using namespace std;

int n, *A;

int main()
{
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    sort_binary_array(); 
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    return 0;
}