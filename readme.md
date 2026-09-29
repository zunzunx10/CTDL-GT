# Bài Toán Tháp Hà Nội

## 1. Mô tả bài toán
Cho ba cọc: cọc nguồn `nguon`, cọc trung gian `temp` và cọc đích `dich`, cùng với $n$ đĩa có kích thước khác nhau xếp chồng lên cọc nguồn theo thứ tự đĩa nhỏ nằm trên đĩa to nằm dưới. 

**Mục tiêu:** Di chuyển toàn bộ $n$ đĩa từ cọc nguồn sang cọc đích với cáctheo quy tắc sau:
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

Giải thuật theo phương pháp đệ quy thông qua hàm:
`void xep(int n, char nguon, char temp, char dich)`

### Các bước thực hiện giải thuật
* **Bước 1 (Điều kiện dừng):**
  * Nếu $n = 1$: Chỉ có duy nhất 1 đĩa, ta chuyển trực tiếp đĩa đó từ cọc `nguon` sang cọc `dich`:
    $$\text{cout} \ll \text{nguon} \ll \text{" -> "} \ll \text{dich}$$
  * Sau đó kết thúc hàm bằng lệnh `return`.

* **Bước 2 (Chuyển $n - 1$ đĩa trên sang cọc trung gian):**
  * Để chuyển được đĩa lớn nhất (đĩa thứ $n$) sang cọc `dich`, ta chuyển toàn bộ $n - 1$ đĩa nằm phía trên sang cọc trung gian `temp`.
  * Gọi đệ quy: `xep(n - 1, nguon, dich, temp);` (với n - 1 đĩa này thì cọc `temp` sẽ là cọc đích còn cọc `dich` sẽ trở thành cọc trung gian).

* **Bước 3 (Chuyển đĩa lớn nhất sang cọc đích):**
  * Di chuyển đĩa lớn nhất còn lại ở cọc `nguon` sang cọc `dich`:
    $$\text{cout} \ll \text{nguon} \ll \text{" -> "} \ll \text{dich}$$

* **Bước 4 (Chuyển $n - 1$ đĩa từ cọc trung gian sang cọc đích):**
  * Chuyển $n - 1$ đĩa đang tạm ở cọc `temp` về lại cọc `dich`.
  * Gọi đệ quy: `xep(n - 1, temp, nguon, dich);` (n - 1 đĩa này sẽ được xếp đến cọc đích `đích` bằng cách coi cọc nguồn `nguon` mà n - 1 đĩa này ở lúc đầu là cọc trung gian).

## 4. Bộ Test Cases kiểm thử

| STT | Loại Test Case | Input | Output mong muốn | Giải thích |
| :--- | :--- | :--- | :--- | :--- |
| **1** | Trường hợp cơ sở ($n = 1$) | `1 A C B` | `A -> C` | Chỉ có 1 đĩa, chuyển thẳng từ cọc nguồn `A` sang cọc đích `C`.|
| **2** | Trường hợp nhỏ ($n = 2$) | `2 A C B` | `A -> B`<br>`A -> C`<br>`B -> C` | 1. Chuyển đĩa 1 sang `B`.<br>2. Chuyển đĩa 2 sang `C`.<br>3. Chuyển đĩa 1 từ `B` sang `C`.|
| **3** | Trường hợp tiêu chuẩn ($n = 3$) | `3 A C B` | `A -> C`<br>`A -> B`<br>`C -> B`<br>`A -> C`<br>`B -> A`<br>`B -> C`<br>`A -> C`|
