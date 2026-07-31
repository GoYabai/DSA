def solve():
    n, m = map(int, input().split())
    parent = list(range(n + 1))
    size = [1] * (n + 1)

    def find_set(u):
        if u == parent[u]:
            return u

        parent[u] = find_set(parent[u])
        return parent[u]

    def union_sets(u, v):
        a = find_set(u)
        b = find_set(v)
        if a != b:
            if size[a] < size[b]:
                a, b = b, a
            parent[b] = a
            size[a] += size[b]
    for _ in range(m):
        query = list(input().split())
        type_query = query[0]
        if type_query == "union":
            u = int(query[1])
            v = int(query[2])
            union_sets(u, v)
        elif type_query == "get":
            u = int(query[1])
            c = int(query[2])
            if find_set(u) == find_set(c):
                print("YES")
            else:
                print("NO")

if __name__ == '__main__':
    solve()