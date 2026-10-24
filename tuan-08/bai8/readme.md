# Longest Bitonic Subarray Problem

Bài toán: Cho một mảng số nguyên `A[]` có kích thước $n$. Yêu cầu tìm và in ra mảng con liên tiếp Bitonic có độ dài lớn nhất. Một mảng con được gọi là Bitonic nếu các phần tử của nó ban đầu được sắp xếp theo thứ tự tăng ngặt, sau đó giảm ngặt (các mảng con chỉ tăng dần ngặt hoặc chỉ giảm dần ngặt hoàn toàn cũng được chấp nhận).

## 2. Ý tưởng giải thuật

Giải thuật gồm ba giai đoạn:

1. Xây dựng mảng phụ `I[]` lưu độ dài của mảng con tăng dần dài nhất kết thúc tại mỗi vị trí `i` (duyệt từ trái sang phải).
2. Xây dựng mảng phụ `D[]` lưu độ dài của mảng con giảm dần dài nhất bắt đầu tại mỗi vị trí `i` (duyệt từ phải sang trái).
3. Tìm vị trí `i` của mảng `A[]` sao cho mảng con liên tiếp Bitonic có tổng độ dài `I[i] + D[i] - 1` lớn nhất và in ra mảng con tương ứng.

### 2.1. Hàm `find_bitonic_subarray()`

Mục đích: Tìm và in ra các phần tử của mảng con Bitonic liên tiếp dài nhất trong mảng `A[]`.

Khởi tạo mảng `I[]` để lưu độ dài của các dãy con tăng dần trong mảng `A[]`:
- Gán `I[0] = 1`, đây là độ dài dãy con tăng dần đầu tiên (chính là phần tử đầu tiên `A[0]`)
- Vòng `for` duyệt chỉ số `i` từ `1` đến `n - 1`:
  1. Mặc định mỗi phần tử của mảng `A[]` là 1 dãy con tăng dần nên có độ dài bằng 1: `I[i] = 1`.
  2. Nếu phần tử trước nhỏ hơn phần tử hiện tại (`A[i - 1] < A[i]`), tăng độ dài của dãy con tăng dần lên 1: `I[i] = I[i - 1] + 1`.

Khởi tạo mảng `D[]` để lưu độ dài của các dãy con giảm dần trong mảng `A[]`::
- Gán `D[n - 1] = 1` , đây là độ dài dãy con giảm dần đầu tiên (chính là phần tử cuối cùng `A[n-1]`).
- Vòng `for` duyệt ngược chỉ số `i` từ `n - 2` về `0`:
  1. Mặc định gán `D[i] = 1`.
  2. Nếu phần tử hiện tại lớn hơn phần tử liền sau (`A[i] > A[i + 1]`), tăng độ dài dãy con giảm dần lên 1: `D[i] = D[i + 1] + 1`.

Tìm mảng con Bitonic dài nhất:
- Khởi tạo `longest_subarray = 1` (độ dài mảng con Bitonic lớn nhất tìm được) và `end = 0` (vị trí kết thúc của mảng con Bitonic dài nhất).
- Vòng `for` duyệt chỉ số `i` từ `0` đến `n - 1`:
  - Tại mỗi vị trí `i`, độ dài mảng con Bitonic là `I[i] + D[i] - 1`.
  - Nếu tìm được 1 dãy con dài hơn `longest_subarray < I[i] + D[i] - 1`, cập nhật kỷ lục mới `longest_subarray = I[i] + D[i] - 1` và vị trí kết thúc của mảng con `end = i + D[i] - 1`.

Khi vòng lặp kết thúc:
- In ra các phần tử của mảng con Bitonic dài nhất

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: Số nguyên `n` là kích thước mảng `A[]`.
2. Dòng 2: `n` số nguyên là phần tử của mảng `A[]`, cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

In ra các phần tử của mảng con Bitonic dài nhất tìm được, cách nhau bởi dấu cách.

### Test case 1 – Ví dụ cơ bản

**Input**
```text
11
3 5 8 4 5 9 10 8 5 3 4
```

**Output**
```text
4 5 9 10 8 5 3 
```

### Test case 2 – Mảng chỉ tăng dần ngặt

**Input**
```text
5
1 2 3 4 5
```

**Output**
```text
1 2 3 4 5 
```

### Test case 3 – Mảng chỉ giảm dần ngặt

**Input**
```text
5
9 7 5 3 1
```

**Output**
```text
9 7 5 3 1 
```

### Test case 4 – Toàn bộ mảng ban đầu là một dãy Bitonic

**Input**
```text
7
1 3 5 8 6 4 2
```

**Output**
```text
1 3 5 8 6 4 2 
```

### Test case 5 – Mảng gồm các phần tử bằng nhau

**Input**
```text
4
5 5 5 5
```

**Output**
```text
5 
```

### Test case 6 – Mảng chỉ có một phần tử

**Input**
```text
1
10
```

**Output**
```text
10 
```

### Test case 7 – Dãy giảm trước rồi tăng sau (dạng chữ V)

**Input**
```text
7
8 6 4 2 3 5 7
```

**Output**
```text
8 6 4 2 
```

### Test case 8 – Mảng con Bitonic dài nhất nằm ở đầu mảng

**Input**
```text
8
1 4 7 5 2 3 6 1
```

**Output**
```text
1 4 7 5 2 
```

### Test case 9 – Mảng con Bitonic dài nhất nằm ở cuối mảng

**Input**
```text
8
2 5 1 3 6 9 7 4
```

**Output**
```text
1 3 6 9 7 4 
```

### Test case 10 – Mảng chứa các số âm

**Input**
```text
7
-10 -5 -2 0 -3 -8 -1
```

**Output**
```text
-10 -5 -2 0 -3 -8 
```