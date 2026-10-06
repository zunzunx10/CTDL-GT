# Sắp xếp các phần tử trong tập số nguyên A[n]
## Input
* Dòng 1: số phần tử của tập A `n`
* Dòng 2: `n` phần tử của tập A cách nhau bởi dấu cách
## Output
Từng bước sắp xếp
---
## Test Case
```cpp
5
4 8 6 5 1
```

## Selection sort
### Output
```cpp
Min: 1
1 8 6 5 4 
Min: 4
1 4 6 5 8 
Min: 5
1 4 5 6 8 
Min: 6
1 4 5 6 8 
Min: 8
1 4 5 6 8
```
## Insertion sort
### Output
```cpp
So so sanh: 8
4 8  | 6 5 1 
So so sanh: 6
4 6 8  | 5 1 
So so sanh: 5
4 5 6 8  | 1 
So so sanh: 1
1 4 5 6 8  | 
```

