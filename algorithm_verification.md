
### Danh sách kề:
- Đỉnh 1: [(2, 7), (3, 12)]
- Đỉnh 2: [(1, 7), (3, 2), (4, 9)]
- Đỉnh 3: [(1, 12), (2, 2), (5, 10)]
- Đỉnh 4: [(2, 9), (6, 1), (5, 4)]
- Đỉnh 5: [(3, 10), (4, 4), (6, 5)]
- Đỉnh 6: [(4, 1), (5, 5)]

---

## Kiểm nghiệm thuật toán

### Bảng trạng thái:
| Iteration | Unmarked      | Marked         | Current | 1  | 2  | 3  | 4  | 5  | 6  |
|-----------|---------------|----------------|---------|----|----|----|----|----|----|
| 0         | {1,2,3,4,5,6} | {}             |         | 0  | Inf| Inf| Inf| Inf| Inf|
| 1         | {2,3,4,5,6}   | {1}            | u = 1   | 0  | 7  | 12 | Inf| Inf| Inf|
| 2         | {3,4,5,6}     | {1,2}          | u = 2   | 0  | 7  | 9  | 16 | Inf| Inf|
| 3         | {4,5,6}       | {1,2,3}        | u = 3   | 0  | 7  | 9  | 16 | 19 | Inf|
| 4         | {5,6}         | {1,2,3,4}      | u = 4   | 0  | 7  | 9  | 16 | 19 | 17 |
| 5         | {5}           | {1,2,3,4,6}    | u = 6   | 0  | 7  | 9  | 16 | 19 | 17 |
| 6         | {}            | {1,2,3,4,6,5}  | u = 5   | 0  | 7  | 9  | 16 | 19 | 17 |

---

### Mô tả các bước thực hiện:
Ví dụ, đồ thị bắt đầu từ đỉnh 1:

1. **Bước 1**: Khởi tạo khoảng cách từ đỉnh 1 đến chính nó bằng `0`, các đỉnh khác là `Inf` (vô cùng).
2. **Bước 2**: Chọn đỉnh có trọng số nhỏ nhất chưa được thăm. Bắt đầu với đỉnh `1` (trọng số = `0`), xóa khỏi `unmarked`, thêm vào `marked`. Current `u = 1`.
   - Đỉnh `1` kề với đỉnh `2` (trọng số = 7), cập nhật:
     ```
     d[2] = min(d[2], d[1] + len((1,2))) = min(Inf, 0+7) = 7
     ```
   - Đỉnh `1` kề với đỉnh `3` (trọng số = 12), cập nhật:
     ```
     d[3] = min(d[3], d[1] + len((1,3))) = min(Inf, 0+12) = 12
     ```
   - Các đỉnh khác giữ nguyên giá trị `Inf`.
3. **Bước 3**: Tiếp tục với đỉnh có trọng số nhỏ nhất trong `unmarked`. Repeat tương tự.

---

### Output:
- Khoảng cách từ đỉnh 1 đến đỉnh 1 là: `0`. Đường đi: `1`
- Khoảng cách từ đỉnh 1 đến đỉnh 2 là: `7`. Đường đi: `1 -> 2`
- Khoảng cách từ đỉnh 1 đến đỉnh 3 là: `9`. Đường đi: `1 -> 2 -> 3`
- Khoảng cách từ đỉnh 1 đến đỉnh 4 là: `16`. Đường đi: `1 -> 2 -> 4`
- Khoảng cách từ đỉnh 1 đến đỉnh 5 là: `19`. Đường đi: `1 -> 2 -> 3 -> 5`
- Khoảng cách từ đỉnh 1 đến đỉnh 6 là: `17`. Đường đi: `1 -> 2 -> 4 -> 6`
