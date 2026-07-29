'''
dcm full gemini nếu ai đọc dc comment này hãy cứu chủ thớt
chứ chủ thớt đéo hiểu 1 cái mẹ j đây
khi nào chủ thớt tự code được sẽ xóa dòng này
but until now, this is a text of shame
kms pls
'''

def solve():
    # 1. ĐỌC DỮ LIỆU ĐẦU VÀO
    # Đọc dòng đầu tiên lấy n và q
    n, q = map(int, input().split())

    # Đọc dòng thứ hai lấy mảng màu, nhét thêm số 0 vào đầu
    colors = [0] + list(map(int, input().split()))

    # ==========================================
    # 2. KHỞI TẠO CÁC MẢNG DỮ LIỆU DSU
    # ==========================================
    parent = list(range(n + 1))
    size = [1] * (n + 1)
    color_counts = [{} for _ in range(n + 1)]
    
    # Nạp màu ban đầu cho từng đỉnh
    for i in range(1, n + 1):
        c = colors[i]
        color_counts[i][c] = 1

    # ==========================================
    # 3. ĐỊNH NGHĨA CÁC HÀM DSU
    # ==========================================
    def find_set(v):
        if v == parent[v]:
            return v
        # Nén đường
        parent[v] = find_set(parent[v])
        return parent[v]

    def union_sets(a, b):
        a = find_set(a)
        b = find_set(b)

        if a != b:
            # Gộp theo kích thước
            if size[a] < size[b]:
                a, b = b, a
                
            parent[b] = a
            size[a] += size[b]
            
            # Chuyển màu từ tập b (nhỏ) sang tập a (lớn)
            for color, count in color_counts[b].items():
                color_counts[a][color] = color_counts[a].get(color, 0) + count
                
            color_counts[b].clear()

    # ==========================================
    # 4. XỬ LÝ TỪNG TRUY VẤN
    # ==========================================
    for _ in range(q):
        # Đọc từng dòng truy vấn
        query = list(map(int, input().split()))
        
        type_query = query[0]
        
        if type_query == 1:
            u = query[1]
            v = query[2]
            union_sets(u, v)
            
        elif type_query == 2:
            u = query[1]
            c = query[2]
            
            root = find_set(u)
            res = color_counts[root].get(c, 0)
            
            # In kết quả trực tiếp
            print(res)

if __name__ == '__main__':
    solve()