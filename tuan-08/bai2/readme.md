# Sort Binary Array in Linear Time

Bài toán: Cho một mảng nhị phân `A[]` (chỉ chứa các giá trị `0` và `1`) có kích thước $n$. Yêu cầu sắp xếp lại mảng sao cho tất cả các số `0` nằm ở đầu mảng, theo sau là tất cả các số `1`. Giải thuật cần đạt độ phức tạp thời gian tuyến tính $O(n)$ và không gian bộ nhớ $O(1)$.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Duyệt mảng để đếm số lượng phần tử `0`.
2. Đưa các phần tử `0` ở lên, các vị trí còn lại được điền bằng `1`.

### 2.1. Hàm `sort_binary_array()`

Mục đích: sắp xếp mảng `A[]` sao cho tất cả số `0` nằm trước tất cả số `1`.

- Khởi tạo biến `zeros = 0` để đếm số lượng số `0` trong mảng.
- Vòng lặp `for` duyệt các phần tử của `A[]` từ chỉ số `0` đến `n - 1`.
- Nếu `A[i] == 0`, tăng biến đếm `zeros` lên `1`.
- Khởi tạo `k = 0`, là biến duyệt qua mảng `A[]` để ghi lại vị trí của mảng .
- Vòng lặp `while (zeros--)` ghi số `0` vào `A[k]`, sau đó tăng `k`. Vòng lặp kết thúc khi các số `0` đã đếm được đều nằm hết ở đầu.
- Vòng lặp `while (k < n)` ghi số `1` vào các vị trí còn lại cho đến hết mảng.

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: Số nguyên `n`, là kích thước của mảng `A[]`.
2. Dòng 2: `n` phần tử của mảng `A[]`, cách nhau bởi dấu cách. Mỗi phần tử phải là `0` hoặc `1`.

### Mô tả dữ liệu đầu ra

In ra `n` phần tử của mảng `A[]` sau khi sắp xếp, cách nhau bởi dấu cách. Tất cả số `0` phải nằm trước tất cả số `1`.

### Test case 1 – Ví dụ cơ bản

**Input**

```text
7
1 0 1 0 1 0 1
```

**Output**

```text
0 0 0 1 1 1 1
```

### Test case 2 – Mảng đã được sắp xếp

**Input**

```text
6
0 0 0 1 1 1
```

**Output**

```text
0 0 0 1 1 1
```

### Test case 3 – Tất cả phần tử đều bằng `0`

**Input**

```text
5
0 0 0 0 0
```

**Output**

```text
0 0 0 0 0
```

### Test case 4 – Tất cả phần tử đều bằng `1`

**Input**

```text
4
1 1 1 1
```

**Output**

```text
1 1 1 1
```

### Test case 5 – Mảng chỉ có một phần tử bằng `0`

**Input**

```text
5
1 1 0 1 1
```

**Output**

```text
0 1 1 1 1
```

### Test case 6 – Mảng chỉ có một phần tử bằng `1`

**Input**

```text
5
0 0 1 0 0
```

**Output**

```text
0 0 0 0 1
```

### Test case 7 – Mảng có một phần tử

**Input**

```text
1
1
```

**Output**

```text
1
```

### Test case 8 – Các số `0` nằm ở cuối mảng

**Input**

```text
8
1 1 1 1 0 0 0 0
```

**Output**

```text
0 0 0 0 1 1 1 1
```

### Test case 9 – Các số `0` và `1` xen kẽ

**Input**

```text
10
1 0 1 0 1 0 1 0 1 0
```

**Output**

```text
0 0 0 0 0 1 1 1 1 1
```

### Test case 10 – Mảng có độ dài lớn hơn

**Input**

```text
12
1 1 0 1 0 0 1 0 1 1 0 0
```

**Output**

```text
0 0 0 0 0 0 1 1 1 1 1 1
```
