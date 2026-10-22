# Merge Two Arrays by Satisfying Given Constraints

Bài toán: Cho hai mảng đã sắp xếp `X[]` (kích thước $m$) và `Y[]` (kích thước $n$), trong đó $m \ge n$. Mảng `X[]` chứa đúng $n$ ô trống (được biểu diễn bằng giá trị `0`). Yêu cầu gộp mảng `Y[]` vào mảng `X[]` sao cho mảng `X[]` sau khi gộp vẫn giữ nguyên thứ tự sắp xếp tăng dần.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Dồn các phần tử khác `0` của `X[]` về đầu mảng, để các ô trống nằm ở cuối.
2. Trộn hai dãy đã sắp xếp bằng cách đi từ cuối về đầu, ghi phần tử lớn hơn vào vị trí cuối còn trống.

### 2.1. Hàm `rearrange()`

Mục đích: đưa tất cả phần tử khác `0` về các vị trí đầu của `X[]`.

- Khởi tạo `i = 0`, có giá tri chạy từ vị trí đầu tiên `X[0]` đến vị trí cuối cùng của `X[n-1]`, nhiệm vụ lưu lại các.
- Vòng for duyệt từng phần tử của `X[]` từ `0` đến `m - 1` qua biến `j`.
- Nếu vị trí `j` trống, gán `x[i] = x[j]` rồi tăng `i`.
- Sau vòng lặp, các phần tử khác `0` nằm ở `m - n` vị trí đầu `X[]`.


### 2.2. Hàm `merge()`

Mục đích: Trộn 2 dãy, bắt đầu từ vị trị cuối cùng của `X[]`.


Sau khi gọi `rearrange()`, khởi tạo ba chỉ số:

- `i = m - n - 1`: trỏ đến phần tử cuối cùng khác 0 của `X[]`.
- `j = n - 1`: trỏ đến phần tử cuối cùng của `Y[]`.
- `k = m - 1`: trỏ đến vị trí cuối cùng của `X[]` để ghi lại giá trị cần điền.

Khi `i >= 0` và `j >= 0`:

1. So sánh `x[i]` với `y[j]` tìm phẩn tử lớn hơn.
2. Nếu `x[i] > y[j]`, ghi `x[i]` vào vị trí `k` của `X[]`, sau đó giảm `i` và `k`.
3. Ngược lại, ghi `y[j]` vào vị trí `k` của `X[]`, sau đó giảm `j` và `k`.

Khi vòng lặp kết thúc:

- Nếu `Y[]` còn phần tử (`j >= 0`), sao chép các phần tử còn lại của `Y[]` vào `X[]` từ phải sang trái.

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: Kích thức mảng `X[]` và `Y[]` là hai số nguyên `m n`.
2. Dòng 2: `m` phần tử của `X[]` theo thứ tự tăng, cách nhau bởi dấu cách.
3. `n` phần tử của `Y[]` theo thứ tự tăng,  cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

Các phần tử trong mảng `X[]` đã được sắp xêp và trộn

### Test case 1 – Ví dụ cơ bản

**Input**
```text
6 3
2 0 7 0 0 9
1 5 8
```

**Output**
```text
1 2 5 7 8 9
```

### Test case 2 – `Y[]` có các phần tử nhỏ hơn `X[]`

**Input**
```text
7 3
4 0 6 0 8 0 10
1 2 3
```

**Output**
```text
1 2 3 4 6 8 10
```

### Test case 3 – `Y[]` có các phần tử lớn hơn `X[]`

**Input**
```text
6 2
1 0 3 0 5 7
8 9
```

**Output**
```text
1 3 5 7 8 9
```

### Test case 4 – Hai dãy có phần tử trùng nhau

**Input**
```text
8 3
1 0 3 0 5 0 7 9
3 5 7
```

**Output**
```text
1 3 3 5 5 7 7 9
```

### Test case 5 – Chỉ có một ô trống

**Input**
```text
5 1
1 3 0 7 9
5
```

**Output**
```text
1 3 5 7 9
```

### Test case 6 – `X[]` toàn ô trống

**Input**
```text
4 4
0 0 0 0
1 2 3 4
```

**Output**
```text
1 2 3 4
```

### Test case 7 – `Y[]` chỉ có một phần tử

**Input**
```text
6 1
2 0 4 6 8 10
5
```

**Output**
```text
2 4 5 6 8 10
```

### Test case 8 – `Y[]` được chèn vào giữa các phần tử của `X[]`

**Input**
```text
8 3
2 0 6 0 10 0 14 18
4 8 12
```

**Output**
```text
2 4 6 8 10 12 14 18
```

### Test case 9 – `X[]` ban đầu có các ô trống ở đầu

**Input**
```text
6 2
0 0 3 5 7 9
1 2
```

**Output**
```text
1 2 3 5 7 9
```

### Test case 10 – Dãy có số âm

**Input**
```text
7 2
-8 0 -2 0 4 6 9
-5 3
```

**Output**
```text
-8 -5 -2 3 4 6 9
```