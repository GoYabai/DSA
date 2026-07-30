def solve():
    n, q = map(int, input().split())
    friend_group = list(range(n + 1))
    size = [1] * (n + 1)

    def find_set(a):
        if a == friend_group[a]:
            return a
        friend_group[a] = find_set(friend_group[a])
        return friend_group[a]
    def union_sets(a, b):
        a = find_set(a)
        b = find_set(b)
        if a != b:
            if size[a] < size[b]:
                a, b = b, a
            friend_group[b] = a
            size[a] += size[b]
    for _ in range(q):
        query = list(map(int, input().split()))
        type_query = query[0]
        if type_query == 1:
                u = query[1]
                v = query[2]
                union_sets(u, v)    
        elif type_query == 2:
            u = query[1]
            c = query[2]
            if find_set(u) == find_set(c):
                print("YES")
            else:
                print("NO") 

if __name__ == '__main__':
    solve()