#include <iostream>

using namespace std;

//Merge two arrays by satisfying given constraints

int m, n, *x, *y;
void rearrange () //sắp xếp lại phần tử của X sao cho cần phần tử 0 (chỗ trống) nằm về sau còn các phần tử khác 0 nằm ở m - n vị trí đầu
{
    int i = 0; //vị trí của các phần tử khác 0
    for (int j = 0; j < m; j++)
    {
        if (x[j] != 0) x[i++] = x[j]; //Nếu ở vị tri j, phần tử khác không thì gán vào vị trí i
    }

}
void merge()
{
    rearrange(); //sắp xếp lại X
    int i = m-n-1, j = n-1; //i chạy trong X, j chạy trong Y
    int k = m-1;
    while (i >= 0 && j >= 0) //lấp đầy các khoảng trống bắt đầu từ cuối của X
    {
        if (x[i] > y[j]) x[k--] = x[i--];
        else x[k--] = y[j--];  
    }
    //Sau khi xếp thì Y sẽ còn dư phần tử chưa được xếp vị trí
    while (j >= 0) x[k--] = y[j--]; //Xếp các phần tử còn dư của Y
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;
        x = new int[m]; y = new int[n];
        for (int i = 0; i < m; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> y[i];
        merge();
        for (int i = 0; i < m; i++) cout << x[i] << " ";
        cout << endl;
    }
    return 0;
}