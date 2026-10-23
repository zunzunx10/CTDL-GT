# Find the Largest Subarray Having an Equal Number of 0’s and 1’s

Bài toán: Cho một mảng nhị phân `A[]` chỉ chứa các giá trị `0` và `1` có kích thước $n$. Yêu cầu tìm và in ra các mảng con liên tiếp có độ dài lớn nhất sao cho số lượng phần tử `0` và phần tử `1` trong mảng con đó bằng nhau. Nếu không tồn tại mảng con nào thỏa mãn, in ra `-1`.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Sử dụng hai vòng lặp lồng nhau để duyệt qua tất cả các mảng con liên tiếp có thể tạo thành từ mảng `A[]`.
2. Trong quá trình duyệt, đếm số lượng số `0` và số `1`. Nếu số lượng số `0` và số `1` bằng nhau và tổng độ dài mảng con này lớn hơn độ dài mảng con đang lưu thì cập nhật lại độ dài lớn nhất cùng vị trí bắt đầu và kết thúc của mảng con đó.

### 2.1. Hàm `find_largest_subarray()`

Mục đích: Tìm và in ra các phần tử của mảng con dài nhất có số lượng `0` và `1` bằng nhau.

Khởi tạo các biến để lưu độ dài, vị trí kết thúc của mảng con dài nhất đang tìm thấy:
- `largest_subarray = 0`: lưu độ dài lớn nhất của mảng con thỏa mãn.
- `*ending_subarray = new int[n]`: mảng cấp phát động dùng để lưu các chỉ số kết thúc của những mảng con có cùng độ dài lớn nhất.
- `cnt = 0`: đếm số lượng mảng con cùng đạt độ dài lớn nhất.

Quá trình duyệt mảng:
- Vòng `for` ngoài duyệt chỉ số `i` từ `0` đến `n - 1` là vị trí bắt đầu của mảng con.
- Tại mỗi vị trí `i`, khởi tạo lại hai biến đếm `zeros = 0` và `ones = 0` để đếm số phần tử `0` và `1` của mảng con.
- Vòng `for` trong duyệt chỉ số `j` từ `i` đến `n - 1` là vị trí kết thúc của mảng con.
  1. Kiểm tra phần tử `A[j]`, nếu bằng `0` thì tăng `zeros` lên 1, ngược lại thì tăng `ones` lên 1.
  2. Khi `zeros == ones` (số lượng `0` và `1` bằng nhau):
     - Nếu `largest_subarray < zeros + ones` (tìm được mảng con mới dài hơn kỷ lục cũ): cập nhật kỷ lục mới `largest_subarray = zeros + ones`. Do số lượng mảng con dài nhất thay đổi, đặt lại biến `cnt = 0` và lưu vị trí kết thúc mới `ending_subarray[cnt++] = j`.
     - Ngược lại, nếu `largest_subarray == zeros + ones` (mảng con có độ dài bằng với kỷ lục hiện tại): lưu thêm vào `ending_subarray[]` vị trí kết thúc của mảng con này `ending_subarray[cnt++] = j`.

Khi vòng lặp kết thúc:

- Nếu `largest_subarray == 0` (không tìm thấy mảng con nào thỏa mãn), in ra `-1`.
- Ngược lại, vòng for duyệt các phần tử của `ending_subarray[]` là vị trí kết thúc của mảng con dài nhất qua biến  `j` từ `0` đến `cnt - 1`. Với mỗi vị trí kết thúc `ending_subarray[j]`, duyệt `i` từ vị trí bắt đầu `ending_subarray[j] - largest_subarray + 1` đến `ending_subarray[j]` để in mảng con dài nhất.

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: số nguyên `n` là kích thước mảng `A[]` .
2. Dòng 2: `n` phần tử của `A[]` (chỉ gồm `0` và `1`), cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

In ra các mảng con dài nhất có số lượng số `0` và `1` bằng nhau (mỗi mảng con in trên một dòng), hoặc `-1` nếu không tồn tại.

### Test case 1 – Ví dụ cơ bản

**Input**
```text
7
0 0 1 0 1 0 0
```

**Output**
```text
0 1 0 1 
1 0 1 0 
```

### Test case 2 – Cả mảng ban đầu đều thỏa mãn

**Input**
```text
6
0 1 0 1 1 0
```

**Output**
```text
0 1 0 1 1 0 
```

### Test case 3 – Mảng chỉ toàn số 0 (không có mảng con thỏa mãn)

**Input**
```text
4
0 0 0 0
```

**Output**
```text
-1
```

### Test case 4 – Mảng chỉ toàn số 1 (không có mảng con thỏa mãn)

**Input**
```text
5
1 1 1 1 1
```

**Output**
```text
-1
```

### Test case 5 – Mảng chỉ có một phần tử

**Input**
```text
1
0
```

**Output**
```text
-1
```

### Test case 6 – Mảng con dài nhất nằm ở đầu mảng

**Input**
```text
6
1 0 1 0 0 0
```

**Output**
```text
1 0 1 0 
```

### Test case 7 – Mảng con dài nhất nằm ở cuối mảng

**Input**
```text
6
0 0 0 1 0 1
```

**Output**
```text
0 1 0 1 
```

### Test case 8 – Mảng con tìm được có độ dài nhỏ nhất (bằng 2)

**Input**
```text
5
0 0 0 1 0
```

**Output**
```text
0 1 
1 0 
```

### Test case 9 – Nửa đầu toàn số 0, nửa sau toàn số 1

**Input**
```text
6
0 0 0 1 1 1
```

**Output**
```text
0 0 0 1 1 1 
```

### Test case 10 – Có nhiều mảng con đan xen cùng đạt độ dài lớn nhất

**Input**
```text
5
1 0 1 0 1
```

**Output**
```text
1 0 1 0 
0 1 0 1 
```