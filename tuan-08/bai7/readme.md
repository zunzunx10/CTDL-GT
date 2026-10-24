# Find Equilibrium Index of an Array

Bài toán: Cho một mảng số nguyên `A[]` có kích thước $n$. Yêu cầu tìm và in ra các vị trí cân bằng (equilibrium index) của mảng. Vị trí $i$ ($0 \le i < n$) được gọi là vị trí cân bằng nếu tổng các phần tử nằm bên trái nó ($A[0] + A[1] + \dots + A[i-1]$) bằng với tổng các phần tử nằm bên phải nó ($A[i+1] + A[i+2] + \dots + A[n-1]$). Nếu không tồn tại vị trí nào thỏa mãn, in ra thông báo `No equilibrium index!`.

## 2. Ý tưởng giải thuật

Giải thuật gồm hai giai đoạn:

1. Tính trước tổng cộng dồn các phần tử từ trái sang phải và lưu vào mảng `sum_left[]`, trong đó `sum_left[0] = 0` còn `sum_left[i]` ($i \neq 0$)  lưu tổng các phần tử từ vị trí `0` đến vị trí `i-1` của mảng `A`.
2. Duyệt mảng từ phải sang trái (từ cuối về đầu), vừa duyệt vừa cộng dồn tổng các phần tử bên phải vào biến `sum_right`. Tại mỗi vị trí `i`, nếu tổng bên trái `sum_left[i]` bằng tổng bên phải `sum_right` thì đây chính là vị trí cân bằng.

### 2.1. Hàm `find_equilibrium()`

Mục đích: Tìm và in ra tất cả các chỉ số cân bằng có trong mảng `A[]`.

Khởi tạo các mảng và biến hỗ trợ:
- `*sum_left = new int[n + 1]()`: khởi tạo mảng cấp phát động kích thước `n + 1` với các phần tử có giá trị mặc định bằng `0`, dùng để lưu tổng cộng dồng các phần tử bên trái.
- `sum_right = 0`: biến lưu tổng cộng dồn các phần tử phía bên phải.
- `*equilibrium_index = new int[n]`: khởi tạo mảng cấp phát động dùng để lưu lại các vị trí cân bằng tìm được.
- `cnt = 0`: biến đếm số lượng phần tử của mảng `equilibrium_index[]`.

Quá trình duyệt mảng:
- Vòng `for` thứ nhất duyệt các phần tử của mảng `A` qua biến `i` từ `0` đến `n - 1` để tính tổng cộng dồn các phần tử bên trái của mảng `A` và lưu giá trị tương ứng vào mảng `sum_left[]`: `sum_left[i + 1] = sum_left[i] + A[i]`. Sau vòng lặp này, `sum_left[i]` ($i \neq 0$) chính là tổng các phần tử từ `A[0]` đến `A[i - 1]`.
- Vòng `for` thứ hai duyệt ngược chỉ số `i` từ `n - 1` về `0`:
  1. Kiểm tra điều kiện cân bằng: Nếu `sum_left[i] == sum_right` (tổng các phần tử bên trái bằng tổng các phần tử bên phải vị trí `i`), lưu chỉ số `i` vào mảng kết quả `equilibrium_index[cnt++] = i`.
  2. Cập nhật lại tổng bên phải cho bước lặp tiếp theo: `sum_right += A[i]`.

Khi vòng lặp kết thúc:
- Nếu `cnt` khác `0` (có ít nhất một chỉ số cân bằng), in ra kết quả.
- Ngược lại, nếu không tìm thấy vị trí nào thỏa mãn (`cnt == 0`), in ra `"No equilibrium index!"`.

## 3. Dữ liệu kiểm thử

### Mô tả dữ liệu đầu vào

1. Dòng 1: Số nguyên `n` là kích thước mảng `A[]`.
2. Dòng 2: `n` phần tử số nguyên của mảng `A[]`, cách nhau bởi dấu cách.

### Mô tả dữ liệu đầu ra

In ra các vị trí cân bằng tìm được (theo thứ tự từ cuối mảng về đầu mảng), hoặc in ra `"No equilibrium index!"` nếu không tồn tại.

### Test case 1 – Ví dụ cơ bản (có nhiều chỉ số cân bằng)

**Input**
```text
8
0 -3 5 -4 -2 3 1 0
```

**Output**
```text
equilibrium index is: 7 3 0 
```

### Test case 2 – Chỉ có một chỉ số cân bằng ở giữa mảng

**Input**
```text
5
1 3 5 2 2
```

**Output**
```text
equilibrium index is: 2 
```

### Test case 3 – Không có chỉ số cân bằng

**Input**
```text
5
1 2 3 4 5
```

**Output**
```text
No equilibrium index!
```

### Test case 4 – Chỉ số cân bằng nằm ở đầu mảng (`i = 0`)

**Input**
```text
4
5 2 -3 1
```

**Output**
```text
equilibrium index is: 0 
```

### Test case 5 – Chỉ số cân bằng nằm ở cuối mảng (`i = n - 1`)

**Input**
```text
4
3 -1 -2 8
```

**Output**
```text
equilibrium index is: 3 
```

### Test case 6 – Mảng chỉ có một phần tử

**Input**
```text
1
10
```

**Output**
```text
equilibrium index is: 0 
```

### Test case 7 – Mảng toàn số 0 (mọi vị trí đều là chỉ số cân bằng)

**Input**
```text
4
0 0 0 0
```

**Output**
```text
equilibrium index is: 3 2 1 0 
```

### Test case 8 – Mảng đối xứng

**Input**
```text
5
2 4 1 4 2
```

**Output**
```text
equilibrium index is: 2 
```

### Test case 9 – Mảng có hai phần tử khác 0 bằng nhau

**Input**
```text
2
5 5
```

**Output**
```text
No equilibrium index!
```

### Test case 10 – Dãy toàn số âm

**Input**
```text
5
-2 -3 -1 -4 -1
```

**Output**
```text
equilibrium index is: 2 
```