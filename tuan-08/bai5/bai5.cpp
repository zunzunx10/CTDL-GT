#include <iostream>
#include <algorithm>
using namespace std;

int m, n, *X, *Y;

void merge()
{
    int i = 0; //duyệt các vị trí phần tử của X
    for (int i = 0; i < m; i++)
    {
        if (X[i] > Y[0]) 
        {
            swap(X[i], Y[0]);
            for (int j = 0; j <= n - 2, Y[j] > Y[j+1]; j++) swap(Y[j], Y[j+1]);
        }
    }
}
int main()
{
    cin >> m >> n;
    X = new int[m], Y = new int[n];
    for (int i = 0; i < m; i++) cin >> X[i];
    for (int i = 0; i < n; i++) cin >> Y[i];
    merge();
    for (int i = 0; i < m; i++) cout << X[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << Y[i] << " ";
    cout << endl;
    return 0;
}