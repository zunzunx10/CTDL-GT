#include <iostream>

using namespace std;

int n, *A; 

void find_equilibrium()
{
    int* sum_left = new int[n + 1](), sum_right = 0;
    int* equilibrium_index = new int[n], cnt = 0;
    for (int i = 0; i < n; i++) sum_left[i + 1] += A[i]; 
    for (int i = n - 1; i >= 0; i--)
    {
        if (sum_left[i - 1] == sum_right)
        {
            equilibrium_index[cnt++] = i;
        } 
        sum_right += A[i];
    }   
    if (cnt)
    {
        cout << "equilibrium index is: ";
        for (int i = 0; i < cnt; i++) cout << equilibrium_index[i] << " ";
    }
    else cout << "No equilibrium index!";
    cout << endl;
}
int main()
{
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    find_equilibrium();
    return 0;
}