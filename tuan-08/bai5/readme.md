# In-place Merge Two Sorted Arrays

Bài toán: Cho hai mảng đã sắp xếp tăng dần `X[]` (kích thước $m$) và `Y[]` (kích thước $n$). Yêu cầu trộn các phần tử của `X[]` và `Y[]` trực tiếp trên hai mảng sao cho sau khi trộn, mảng `X[]` chứa $m$ phần tử nhỏ nhất theo thứ tự tăng dần và mảng `Y[]` chứa $n$ phần tử lớn hơn còn lại theo thứ tự tăng dần.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Duyệt qua từng phần tử của mảng `X[]` và so sánh với phần tử đầu tiên `Y[0]` (cũng là phần tử nhỏ nhất hiện tại của mảng `Y[]`).
2. Nếu phần tử đang xét của `X[]` lớn hơn `Y[0]`, tiến hành đổi chỗ hai phần tử này cho nhau. Sau khi đổi chỗ, sắp xếp lại `Y[0]` về đúng vị trí trong mảng `Y[]` để đảm bảo `Y[]` luôn duy trì thứ tự sắp xếp tăng dần.

### 2.1. Hàm `merge()`

Mục đích: Trộn trực tiếp hai mảng `X[]` và `Y[]` sao cho các phần tử nhỏ hơn nằm ở `X[]` và các phần tử lớn hơn nằm ở `Y[]` theo thứ tự tăng dần.

Quá trình duyệt mảng:

- Vòng `for` ngoài duyệt từng phần tử của mảng `X[]` qua biến `i`.
- Tại mỗi vị trí `i`, kiểm tra xem phần tử `X[i]` có lớn hơn phần tử `Y[0] `X[i] > Y[0]`:
  1. Nếu đúng (phần tử hiện tại của `X[]` lớn hơn phần tử nhỏ nhất của `Y[]`), thực hiện đổi chỗ hai giá trị bằng hàm `swap(X[i], Y[0])`.
  2. Sau khi đổi chỗ, sử dụng vòng `for` trong duyệt mảng `Y[]` để xếp `Y[0]` về đúng vị trí theo thứ tự tăng dần.
     - Chừng nào phần tử đứng trước còn lớn hơn phần tử đứng liền sau (`Y[j] > Y[j+1]`), thực hiện đổi chỗ hai phần tử liền kề bằng hàm `swap(Y[j], Y[j+1])` để đưa phần tử vừa tráo về đúng vị trí sắp xếp trong `Y[]`.

Khi vòng lặp kết thúc:

- Mảng `X[]` sẽ chứa $m$ phần tử nhỏ nhất đã được sắp xếp tăng dần, và mảng `Y[]` sẽ chứa $n$ phần tử còn lại cũng theo thứ tự tăng dần.

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: Kích thước mảng `X[]` và `Y[]` là hai số nguyên `m n`.
2. Dòng 2: `m` phần tử của `X[]` theo thứ tự tăng, cách nhau bởi dấu cách.
3. Dòng 3: `n` phần tử của `Y[]` theo thứ tự tăng, cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

1. Dòng 1: Các phần tử trong mảng `X[]` sau khi đã trộn và sắp xếp.
2. Dòng 2: Các phần tử trong mảng `Y[]` sau khi đã trộn và sắp xếp.

### Test case 1 – Ví dụ cơ bản

**Input**
```text
5 3
1 4 7 8 10
2 3 9
```

**Output**
```text
1 2 3 4 7 
8 9 10 
```

### Test case 2 – Tất cả phần tử của `X[]` đều nhỏ hơn `Y[]`

**Input**
```text
4 3
1 2 3 4
5 6 7
```

**Output**
```text
1 2 3 4 
5 6 7 
```

### Test case 3 – Tất cả phần tử của `X[]` đều lớn hơn `Y[]`

**Input**
```text
3 4
6 7 8
1 2 3 4
```

**Output**
```text
1 2 3 
4 6 7 8 
```

### Test case 4 – Hai dãy có phần tử trùng nhau

**Input**
```text
5 4
1 3 5 7 9
2 3 5 8
```

**Output**
```text
1 2 3 3 5 
5 7 8 9 
```

### Test case 5 – Cả hai mảng đều chỉ có một phần tử

**Input**
```text
1 1
5
2
```

**Output**
```text
2 
5 
```

### Test case 6 – `Y[]` chỉ có một phần tử

**Input**
```text
5 1
1 3 5 7 9
4
```

**Output**
```text
1 3 4 5 7 
9 
```

### Test case 7 – `X[]` chỉ có một phần tử

**Input**
```text
1 4
6
1 2 5 8
```

**Output**
```text
1 
2 5 6 8 
```

### Test case 8 – Các phần tử của hai mảng đan xen nhau

**Input**
```text
4 4
1 3 5 7
2 4 6 8
```

**Output**
```text
1 2 3 4 
5 6 7 8 
```

### Test case 9 – Dãy có số âm

**Input**
```text
5 3
-8 -3 0 4 6
-5 -1 2
```

**Output**
```text
-8 -5 -3 -1 0 
2 4 6 
```

### Test case 10 – Hai mảng chứa các phần tử hoàn toàn giống nhau

**Input**
```text
3 3
2 2 2
2 2 2
```

**Output**
```text
2 2 2 
2 2 2 
```