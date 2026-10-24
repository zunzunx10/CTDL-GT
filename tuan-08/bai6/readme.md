# Rearrange an Array with Alternate High and Low Elements

Bài toán: Cho một mảng số nguyên `A[]` có kích thước $n$, chứa các phần tử đôi một khác nhau (không có phần tử trùng lặp). Yêu cầu sắp xếp lại mảng sao cho mọi phần tử ở vị trí lẻ, ví dụ như $1, 3, 5, \dots$, đều lớn hơn phần tử đứng liền trước (bên trái) và phần tử đứng liền sau (bên phải) của nó.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Duyệt qua mảng `A[]` tại các vị trí có chỉ số lẻ.
2. Tại mỗi vị trí đang xét, lần lượt so sánh phần tử đó với phần tử liền kề bên trái và phần tử liền kề bên phải. Nếu phần tử liền kề lớn hơn thì thực hiện đổi chỗ hai phần tử để đảm bảo phần tử ở vị trí chỉ số lẻ luôn lớn hơn hai phần tử hai bên.

### 2.1. Hàm `rearrange()`

Mục đích: Sắp xếp lại các phần tử trong mảng `A[]` sao cho các phần tử ở vị trí chỉ số lẻ luôn lớn hơn hai phần tử liền kề bên trái và bên phải.

Quá trình duyệt mảng:

- Vòng `for` duyệt chỉ số `i` từ `1` đến `n - 1` với bước nhảy `i = i + 2` (chỉ duyệt qua các vị trí có chỉ số lẻ trong mảng).
- Tại mỗi vị trí `i`:
  1. So sánh với phần tử liền kề bên trái `A[i - 1]`: Nếu `A[i - 1] > A[i]` (phần tử bên trái lớn hơn phần tử hiện tại), gọi hàm `swap(A[i - 1], A[i])` để đổi chỗ hai phần tử.
  2. So sánh với phần tử liền kề bên phải `A[i + 1]`: Nếu `i + 1 < n` (đảm bảo vị trí `i + 1` nằm trong phạm vi mảng) và `A[i] < A[i + 1]` (phần tử hiện tại nhỏ hơn phần tử bên phải), gọi hàm `swap(A[i], A[i + 1])` để đổi chỗ hai phần tử.

Khi vòng lặp kết thúc:

- Mảng `A[]` đã được sắp xếp lại thỏa mãn điều kiện xen kẽ thấp - cao ($A[0] < A[1] > A[2] < A[3] > A[4] \dots$).

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: Số nguyên `n` là kích thước mảng `A[]`.
2. Dòng 2: `n` phần tử là số nguyên đôi một khác nhau của mảng `A[]`, cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

Các phần tử trong mảng `A[]` sau khi đã được sắp xếp  xen kẽ.

### Test case 1 – Ví dụ cơ bản (mảng tăng dần)

**Input**
```text
7
1 2 3 4 5 6 7
```

**Output**
```text
1 3 2 5 4 7 6 
```

### Test case 2 – Mảng ban đầu có thứ tự giảm dần

**Input**
```text
6
6 5 4 3 2 1
```

**Output**
```text
5 6 3 4 1 2 
```

### Test case 3 – Mảng có các phần tử ngẫu nhiên

**Input**
```text
6
9 6 8 3 7 4
```

**Output**
```text
6 9 3 8 4 7 
```

### Test case 4 – Mảng đã thỏa mãn điều kiện từ đầu

**Input**
```text
5
1 5 2 8 3
```

**Output**
```text
1 5 2 8 3 
```

### Test case 5 – Mảng chỉ có một phần tử

**Input**
```text
1
5
```

**Output**
```text
5 
```

### Test case 6 – Mảng có hai phần tử theo thứ tự tăng dần

**Input**
```text
2
3 8
```

**Output**
```text
3 8 
```

### Test case 7 – Mảng có hai phần tử theo thứ tự giảm dần

**Input**
```text
2
8 3
```

**Output**
```text
3 8 
```

### Test case 8 – Mảng chỉ có ba phần tử

**Input**
```text
3
4 2 9
```

**Output**
```text
2 9 4 
```

### Test case 9 – Dãy có số âm

**Input**
```text
6
-5 -10 -2 -8 0 -3
```

**Output**
```text
-10 -2 -8 0 -5 -3 
```

### Test case 10 – Cả hai phép đổi chỗ trái và phải đều xảy ra tại mỗi bước

**Input**
```text
7
5 1 6 2 7 3 8
```

**Output**
```text
1 6 2 7 3 8 5 
```