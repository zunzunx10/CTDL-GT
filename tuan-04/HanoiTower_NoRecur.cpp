#include <iostream>
#include <stack>

using namespace std;
struct frame
{
    int n; //số đĩa
    char nguon, dich, temp;
    int state; //kiểm tra frame đã hoàn thành chương trình chưa, đồng thời để gọi frame khác (giống gọi đệ quy)
};

void xep(int n, char nguon, char temp, char dich)
{
    stack<frame> Stack;
    Stack.push({n, nguon, dich, temp, 0});
    while (!Stack.empty())
    {
        frame &top_frame = Stack.top();
        if (top_frame.n == 1) //Base
        {
            cout << top_frame.nguon << " -> " << top_frame.dich << endl;
            Stack.pop();
            continue;
        }
        if (top_frame.state == 0) //frame_0 chưa thực hiện nhiệm vụ gì. Call stack thêm frame_1 thực hiện nhiệm vụ xếp n - 1 đĩa trên cùng sang cọc trung gian
        {
            top_frame.state = 1;
            Stack.push({top_frame.n - 1, top_frame.nguon, top_frame.temp, top_frame.dich, 0});
        }
        else if (top_frame.state == 1) //frame_1 đã thực hiện xong nhiệm vụ và quay lại frame_0. Frame_0 tiếp tục thực hiện nhiệm vụ chuyển đĩa lớn nhất nằm cuối cùng ở cọc nguồn sang cọc đích
        {
            top_frame.state = 2;
            cout << top_frame.nguon << " -> " << top_frame.dich << endl;
            Stack.push({top_frame.n - 1, top_frame.temp, top_frame.dich, top_frame.nguon, 0}); //Call stack thêm frame_2 để thực hiện nhiệm vụ chuyển n-1 đĩa ở cọc trung gian về lại cọc đích
        }
        else Stack.pop(); //Hoàn thành frame_2, quay trở lại frame_0 và frame_0 cũng hoàn thành xong việc nên được xóa khỏi stack
    }
}

int main()
{
    int n;
    cin >> n;
    char nguon, dich, temp;
    cin >> nguon >> dich >> temp;
    xep(n, nguon, temp, dich);
}
