#include <iostream>
using namespace std;

int n, *A;
 
bool isConsecutive(int i, int j, int min, int max) 
{
    //mảng con chứa các số  liên tiếp thì phải có độ dài - 1  của mảng phải bằng phần tử max - min 
    if (max - min != j - i) return false;
    bool *visited = new bool[j - i + 1](); //Dùng để kiểm tra các phần tử trong mảng con phải là các số nguyên liền nhau
    // Duyệt các phần tử trong mảng con từ vị trí đầu là i đến vị trí kết thúc là j
    for (int k = i; k <= j; k++)
    {
        if (visited[A[k] - min]) //Nếu 2 phần tử trùng nhau nhau là sai
        {
            delete[] visited;
            return false;
        }
        visited[A[k] - min] = true; //ngược lại đánh dấu số A[k] đã xuất hiện trong mảng con
    }
    delete[] visited;
    return true;
}
 
void findMaxSubarray()
{
    int len = 1, start = 0;
    //Duyệt qua từng mảng con
    for (int i = 0; i < n - 1; i++)
    {
        int min_val = A[i], max_val = A[i];
        for (int j = i + 1; j < n; j++)
        {
            min_val = min_val < A[j] ? min_val : A[j];
            max_val = max_val > A[j] ? max_val : A[j];
            if (isConsecutive(i, j, min_val, max_val))
            {
                if (len < max_val - min_val + 1)
                {
                    len = max_val - min_val + 1;
                    start = i;
                }
            }
        }
    }
    for (int i = start, end = start + len; i < end; i++) cout << A[i] << " ";
    cout << endl;
}
 
int main()
{
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    findMaxSubarray();
    return 0;
}