#include <iostream>

using namespace std;

int n, *A;
void sort_binary_array() //Sắp xếp lại mảng sao cho tất cả các số 0 nằm ở đầu, số 1 nằm ở cuối
{
    int zeros = 0; 
    //Đếm xem có bao nhiêu số 0 trong mảng
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0) 
        {
            zeros++;
        }
    }
    int k = 0; // Con trỏ vị trí mảng
    // Đưa tất cả số 0 lên phần đầu của mảng
    while (zeros--) 
    {
        A[k++] = 0;
    }
    // Điền các vị trí còn lại ở cuối mảng bằng số 1
    while (k < n) 
    {
        A[k++] = 1;
    }
}

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