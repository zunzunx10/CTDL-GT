# Find Largest Subarray Formed by Consecutive Integers

Bài toán: Cho một mảng số nguyên `A[]` có kích thước $n$. Yêu cầu tìm và in ra mảng con liên tiếp có độ dài lớn nhất sao cho tất cả các phần tử trong mảng con đó tạo thành một dãy các số nguyên liên tiếp.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Sử dụng hai vòng lặp lồng nhau để duyệt qua tất cả các mảng con từ mảng `A[]`, đồng thời tìm giá trị nhỏ nhất (`min_val`) và giá trị lớn nhất (`max_val`) của từng mảng con.
2. Trong quá trình duyệt, kiểm tra xem mảng con hiện tại có chứa các số nguyên liên tiếp hay không. Nếu thỏa mãn và độ dài mảng con này lớn hơn độ dài mảng con đang lưu thì cập nhật lại độ dài lớn nhất cùng vị trí bắt đầu của mảng con đó.

### 2.1. Hàm `isConsecutive(int i, int j, int min, int max)`

Mục đích: Kiểm tra mảng con từ vị trí đầu `i` đến vị trí kết thúc `j` có chứa các số nguyên liên tiếp hay không.

- Kiểm tra điều kiện độ dài: Một mảng con chứa các số nguyên liên tiếp thì hiệu giữa phần tử lớn nhất và nhỏ nhất (`max - min`) phải bằng độ dài của mảng con trừ đi 1 (`j - i`). Nếu `max - min != j - i` thì trả về `false`.
- Khởi tạo mảng cấp phát động `*visited = new bool[j - i + 1]()` (các phần tử được khởi tạo mặc định bằng `false`) dùng để kiểm tra các phần tử trong mảng con không bị trùng lặp.
- Vòng `for` duyệt các phần tử trong mảng con từ vị trí đầu là `i` đến vị trí kết thúc là `j` qua biến `k`:
  1. Kiểm tra `visited[A[k] - min]`, nếu nhận giá trị `true` (tức là có 2 phần tử trùng nhau trong mảng con) thì giải phóng mảng `visited` và trả về `false`.
  2. Ngược lại, đánh dấu số `A[k]` đã xuất hiện trong mảng con bằng cách gán `visited[A[k] - min] = true`.
- Sau vòng lặp, giải phóng bộ nhớ của mảng `visited` và trả về `true`.

### 2.2. Hàm `findMaxSubarray()`

Mục đích: Tìm và in ra các phần tử của mảng con dài nhất chứa các số nguyên liên tiếp.

Khởi tạo các biến để lưu độ dài và vị trí bắt đầu của mảng con dài nhất đang tìm thấy:
- `len = 1`: lưu độ dài lớn nhất của mảng con thỏa mãn (mặc định ban đầu là mảng con gồm 1 phần tử).
- `start = 0`: lưu vị trí bắt đầu của mảng con dài nhất.

Quá trình duyệt mảng:
- Vòng `for` ngoài duyệt chỉ số `i` từ `0` đến `n - 2` là vị trí bắt đầu của mảng con.
- Tại mỗi vị trí `i`, khởi tạo hai biến `min_val = A[i]` và `max_val = A[i]` để theo dõi giá trị nhỏ nhất và lớn nhất trong mảng con.
- Vòng `for` trong duyệt chỉ số `j` từ `i + 1` đến `n - 1` là vị trí kết thúc của mảng con:
  1. Cập nhật lại giá trị nhỏ nhất `min_val` và lớn nhất `max_val` khi xét đến phần tử `A[j]`.
  2. Khi `isConsecutive(i, j, min_val, max_val)` trả về `true` (mảng con từ `i` đến `j` chứa các số nguyên liên tiếp):
     - Nếu `len < max_val - min_val + 1` (tìm được mảng con mới dài hơn kỷ lục cũ): cập nhật kỷ lục mới `len = max_val - min_val + 1` và lưu lại vị trí bắt đầu mới `start = i`.

Khi vòng lặp kết thúc:

- Vòng `for` duyệt chỉ số `i` từ vị trí bắt đầu `start` đến trước vị trí `end = start + len` để in ra các phần tử của mảng con dài nhất.

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: số nguyên `n` là kích thước mảng `A[]`.
2. Dòng 2: `n` phần tử số nguyên của `A[]`, cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

In ra mảng con dài nhất chứa các số nguyên liên tiếp.

### Test case 1 – Ví dụ

**Input**
```text
8
2 0 2 1 4 3 1 0
```

**Output**
```text
0 2 1 4 3 
```

### Test case 2 – Cả mảng ban đầu đều thỏa mãn

**Input**
```text
6
4 2 1 5 3 6
```

**Output**
```text
4 2 1 5 3 6 
```

### Test case 3 – Mảng chứa các phần tử hoàn toàn giống nhau

**Input**
```text
4
5 5 5 5
```

**Output**
```text
5 
```

### Test case 4 – Không có 2 phần tử nào tạo thành dãy số liên tiếp

**Input**
```text
5
10 20 30 40 50
```

**Output**
```text
10 
```

### Test case 5 – Mảng chỉ có một phần tử

**Input**
```text
1
7
```

**Output**
```text
7 
```

### Test case 6 – Mảng con dài nhất nằm ở đầu mảng

**Input**
```text
6
3 1 2 4 2 2
```

**Output**
```text
3 1 2 4 
```

### Test case 7 – Mảng con dài nhất nằm ở cuối mảng

**Input**
```text
6
1 1 5 3 4 2
```

**Output**
```text
5 3 4 2 
```

### Test case 8 – Mảng có chứa số âm

**Input**
```text
7
5 -1 -3 -2 0 1 5
```

**Output**
```text
-1 -3 -2 0 1 
```

### Test case 9 – Mảng bị ngắt quãng bởi phần tử trùng lặp

**Input**
```text
7
1 2 3 2 4 5 6
```

**Output**
```text
3 2 4 5 6 
```

### Test case 10 – Có nhiều mảng con cùng đạt độ dài lớn nhất (ưu tiên mảng đầu tiên)

**Input**
```text
6
1 2 3 7 8 9
```

**Output**
```text
1 2 3 
```