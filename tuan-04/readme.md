# Bài Toán Tháp Hà Nội

## 1. Mô tả bài toán
Cho ba cọc: cọc nguồn `nguon`, cọc trung gian `temp` và cọc đích `dich`, cùng với $n$ đĩa có kích thước khác nhau xếp chồng lên cọc nguồn theo thứ tự đĩa nhỏ nằm trên đĩa to nằm dưới. 

**Mục tiêu:** Di chuyển toàn bộ $n$ đĩa từ cọc nguồn sang cọc đích theo quy tắc sau:
- Mỗi lần chỉ được di chuyển đúng 1 đĩa trên cùng từ cọc này sang cọc khác.
- Không được đặt đĩa lớn hơn lên trên đĩa nhỏ hơn dù chỉ là tạm thời.

---

## 2. Mô tả đầu vào (Input) và đầu ra (Output)

* **Input:**
  * Dòng 1: Số nguyên dương $n$ — số lượng đĩa cần chuyển.
  * Dòng 2: Ba ký tự `char` cách nhau bởi dấu cách theo thứ tự là tên của 3 chiếc cọc nguồn, đích và trung gian.
* **Output:**
  * In ra màn hình từng bước di chuyển đĩa: `<Tên cọc nguồn> -> <Tên cọc đích>` trên từng dòng.

---

## 3. Diễn giải các bước thực hiện giải thuật

### Giải thuật theo phương pháp đệ quy 
Hàm đệ quy nhận đầu vào lần lượt là số đĩa chuyển `n`, cọc nguồn `nguon`, cọc trung gian `temp`, và cọc đích `dich`: <br>
`void xep(int n, char nguon, char temp, char dich)`

#### Các bước thực hiện giải thuật
* **Bước 1 (Điều kiện dừng):**
  * Nếu $n = 1$: Chỉ có duy nhất 1 đĩa, ta chuyển trực tiếp đĩa đó từ cọc `nguon` sang cọc `dich` và in ra `<Tên cọc nguồn> -> <Tên cọc đích>`.
  * Sau đó kết thúc hàm bằng lệnh `return`.

* **Bước 2 (Chuyển $n - 1$ đĩa trên sang cọc trung gian):**
  * Chuyển toàn bộ $n - 1$ đĩa nằm phía trên cùng của cọc nguồn `nguon` sang cọc trung gian `temp`.
  * Gọi đệ quy: `xep(n - 1, nguon, dich, temp);` (với $n-1$ đĩa này thì cọc `temp` sẽ trở thành cọc đích mà đĩa sắp được chuyển đến còn cọc `dich` sẽ trở thành cọc trung gian).

* **Bước 3 (Chuyển đĩa lớn nhất sang cọc đích):**
  * Di chuyển đĩa lớn nhất còn lại ở cọc `nguon` sang cọc `dich` và in ra `<Tên cọc nguồn> -> <Tên cọc đích>`.

* **Bước 4 (Chuyển $n - 1$ đĩa từ cọc trung gian sang cọc đích):**
  * Chuyển $n - 1$ đĩa đang tạm ở cọc trung gian `temp` về lại cọc `dich`.
  * Gọi đệ quy: `xep(n - 1, temp, nguon, dich);` (Lúc này, với $n-1$ đĩa này đang ở cọc trung gian `temp` nên cọc `temp` này sẽ là cọc nguồn và cọc mà $n-1$ đĩa sắp chuyển tới là cọc `dich`. Còn lại cọc `nguon` sẽ được coi là cọc trung gian).

### Giải thuật theo phương pháp khử đệ quy
Ta sẽ viết chương trình mô phỏng lại cơ chế call stack giống như gọi đệ quy bằng cấu trúc dữ liệu `stack`. Ta khởi tạo `Stack`. Mỗi phần tử trong `Stack` giống như 1 `stack frame` chứa các dữ liệu : 
```cpp
struct Frame {
    int n; // Số lượng đĩa của bài toán con hiện tại
    char nguon, dich, temp; // Tên cọc nguồn, cọc đích, cọc trung gian
    int state; // Trạng thái thực thi hiện tại (0, 1, 2)
};
```
member `state` có ý nghĩa là đánh dấu các lệnh đã thực thi trước khi push 1 frame khác vào stack để đảm bảo khi quay lại frame này, không thực hiện lại các nhiệm vụ trước.

| Giá trị | Ý nghĩa| Hành động tiếp theo |
| :---: | :--- | :--- |
| `0` | frame vừa được tạo | Đánh dấu `state = 1`, thêm 1 frame thực hiện nhiệm vụ chuyển $n - 1$ đĩa trên cùng từ cọc `nguon` $\rightarrow$ cọc `temp` vào `stack`|
| `1` | Đánh dấu đã thực hiện xong nhiệm vụ ở `state = 0` | Di chuyển đĩa thứ $n$ sang cọc `dich`. Đánh dấu `state = 2`, thêm 1 frame thực hiện chuyển $n - 1$ đĩa đang ở cọc `temp` $\rightarrow$  cọc `nguon` vào `stack` |
| `2` | Đánh dấu đã thực hiện xong nhiệm vụ ở `state = 1` | xóa frame này `frame.pop()`|

Giả sử chuyển 2 đĩa từ A sang C (mượn B):
| Số vòng lặp | Phần tử top của stack (`top_frame`) | Hành động thực hiện | Trạng thái stack sau khi thực thi hành động (Đáy $\rightarrow$ Đỉnh) | Kết quả in ra |
| :---: | :--- | :--- | :--- | :--- |
| **0** | *(Khởi tạo)* | Push cấu hình gốc ($n = 2$) | `[(2, A, C, B, state = 0)]` | *(Chưa có)* |
| **1** | `(2, A, C, B, state = 0)` | Kiểm tra thấy `state = 0`. Đi gán `state = 1`, Push cấu hình chuyển $n-1$ đĩa trên cùng sang cọc trung gian (lúc này $n = 1$) | `[(2, A, C, B, state = 1), (1, A, B, C, state = 0)]` | *(Chưa có)* |
| **2** | `(1, A, B, C, state = 0)` | Kiểm tra thấy $n = 1$ tức cọc có 1 đĩa, in ra cách chuyển đĩa này sang cọc đích. Sau đó xóa frame này| `[(2, A, C, B, s=1)]` | `A -> B` |
| **3** | `(2, A, C, B, state = 1)` |Kiểm tra thấy `state = 1`. In ra cách chuyển đĩa thứ $n$ sang cọc đích. Gán `state = 2`. Push cấu hình chuyển $n - 1$ đĩa từ cọc trung gian sang cọc đích| `[(2, A, C, B, s=2), (1, B, C, A, state = 0)]` | `A -> C` |
| **4** | `(1, B, C, A, state = 0)` | Kiểm tra thấy $n = 1$ tức cọc có 1 đĩa, in ra cách chuyển đĩa này sang cọc đích. Sau đó xóa frame này | `[(2, A, C, B, state = 2)]` | `B -> C` |
| **5** | `(2, A, C, B, s=2)` | Thấy `state = 2`, tức frame đã chuyển xong $n$ đĩa về cọc đích. Xóa frame này | `[]` *(Ngăn xếp rỗng)* | *(Chưa có)* |

---

## 4. Bộ Test Cases kiểm thử

| STT | Test Case | Input | Output | Giải thích |
| :--- | :--- | :--- | :--- | :--- |
| **1** | Trường hợp cơ sở $n = 1$ | `1 A C B` | `A -> C` | Chỉ có 1 đĩa, chuyển thẳng từ cọc nguồn `A` sang cọc đích `C`.|
| **2** | Trường hợp nhỏ $n = 2$ | `2 A C B` | `A -> B`<br>`A -> C`<br>`B -> C` | 1. Chuyển đĩa 1 sang `B`.<br>2. Chuyển đĩa 2 sang `C`.<br>3. Chuyển đĩa 1 từ `B` sang `C`.|
| **3** | Trường hợp tiêu chuẩn $n = 3$ | `3 A C B` | `A -> C`<br>`A -> B`<br>`C -> B`<br>`A -> C`<br>`B -> A`<br>`B -> C`<br>`A -> C`|
| **4** | Trường hợp lớn hơn $n = 4$ | `4 A C B` | `A -> B`<br>`A -> C`<br>`B -> C`<br>`A -> B`<br>`C -> A`<br>`C -> B`<br>`A -> B`<br>`A -> C`<br>`B -> C`<br>`B -> A`<br>`C -> A`<br>`B -> C`<br>`A -> B`<br>`A -> C`<br>`B -> C` |
