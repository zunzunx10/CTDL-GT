#include <iostream>

using namespace std;

void xep(int n, char nguon, char temp, char dich)
{
    if (n == 1)
    {
        cout << nguon << " -> " << dich << endl;
        return;
    }
    xep(n-1, nguon, dich, temp);
    cout << nguon << " -> " << dich << endl;
    xep(n-1, temp, nguon, dich);
}
int main()
{
    int n;
    cin >> n;
    char nguon, dich, temp;
    cin >> nguon >> dich >> temp;
    xep(n, nguon, temp, dich);
}