import os
import shutil

# Thư mục hiện tại (nơi chứa các file .cpp)
base_dir = "."

# Cấu trúc thư mục chuẩn theo roadmap NeetCode
# Key: Tên thư mục | Value: Danh sách từ khóa nhận diện
categories = {
    "01_Arrays_and_Hashing": ["array", "hash", "stock", "chocolates", "sort", "pairs"],
    "02_Two_Pointers": ["two_pointer"],
    "03_Stack": ["stack", "polish_notation", "baseball"],
    "04_Binary_Search": ["binary_search"],
    "05_Sliding_Window": ["sliding", "window"],
    "06_Linked_List": ["linked_list", "list_node"],
    "07_Trees": ["tree", "bst", "bt", "leaves"],
    "08_Tries": ["trie", "prefix_tree"],
    "09_Backtracking": ["backtrack", "combination", "subset"],
    "10_Heap_Priority_Queue": ["heap", "priority_queue", "kth"],
    "11_Graphs": ["graph", "bfs", "dfs", "course", "all_paths"],
    "12_1-D_DP": ["climbing_stairs", "decode_ways"],
    "13_Intervals": ["interval", "merge"],
    "14_Greedy": ["greedy"],
    "15_Advanced_Graphs": ["flight", "flow", "cut", "karp", "fulkerson", "dijkstra"],
    "16_2-D_DP": ["common_subsequence"],
    "17_Bit_Manipulation": ["bit", "xor"],
    "18_Math_and_Geometry": ["math", "geometry"]
}

for filename in os.listdir(base_dir):
    # Chỉ dọn dẹp các file code C++
    if not filename.endswith(".cpp"):
        continue

    name_lower = filename.lower()
    placed = False

    for folder, keywords in categories.items():
        if any(keyword in name_lower for keyword in keywords):
            folder_path = os.path.join(base_dir, folder)
            if not os.path.exists(folder_path):
                os.makedirs(folder_path)

            src = os.path.join(base_dir, filename)
            dst = os.path.join(folder_path, filename)
            shutil.move(src, dst)
            print(f"Đã phân loại: {filename} -> {folder}/")
            placed = True
            break

    # Những bài chưa nhận diện được sẽ gom vào đây để anh phân loại tay sau
    if not placed:
        other_path = os.path.join(base_dir, "Uncategorized")
        if not os.path.exists(other_path):
            os.makedirs(other_path)
        shutil.move(os.path.join(base_dir, filename), os.path.join(other_path, filename))
        print(f"Chưa phân loại: {filename} -> Uncategorized/")

print("\nĐã dọn dẹp xong theo chuẩn NeetCode!")