#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// ==========================================
// PHẦN 1: CẤU TRÚC DỮ LIỆU ĐÃ CÓ SẴN
// ==========================================
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// ==========================================
// PHẦN 2: KHU VỰC ĐỂ BẠN ĐIỀN CODE
// ==========================================

// --- NHÓM 1: DFS BẰNG ĐỆ QUY (RECURSION) ---

void preOrderRecursive(Node* root) {
    // TODO: Viết hàm duyệt Tiền thứ tự (Nút -> Trái -> Phải) bằng đệ quy
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);   
}

void inOrderRecursive(Node* root) {
    // TODO: Viết hàm duyệt Trung thứ tự (Trái -> Nút -> Phải) bằng đệ quy
    if (root == nullptr)
    {
        return;
    }
    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

void postOrderRecursive(Node* root) {
    // TODO: Viết hàm duyệt Hậu thứ tự (Trái -> Phải -> Nút) bằng đệ quy
    if (root == nullptr)
    {
        return;
    }
    inOrderRecursive(root->left);
    inOrderRecursive(root->right);
    cout << root->data << " ";
}

// --- NHÓM 2: DFS BẰNG VÒNG LẶP VÀ NGĂN XẾP (ITERATION + STACK) ---

void preOrderIterative(Node* root) {
    // TODO: Viết hàm duyệt Tiền thứ tự bằng Stack (Gợi ý: Nhớ đẩy con phải vào trước con trái)
    if (root == nullptr)
    {
        return;
    }
    stack<Node*> st;
    st.push(root);
    while (!st.empty())
    {
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right != nullptr)
        {
            st.push(curr->right);
        }
        if (curr->left != nullptr)
        {
            st.push(curr->left);
        }
    }
}

void inOrderIterative(Node* root) {
    // TODO: Viết hàm duyệt Trung thứ tự bằng Stack
    stack<Node*> st;
    Node* curr = root;
    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    
    
    
}

void postOrderIterative(Node* root) {
    // TODO: Viết hàm duyệt Hậu thứ tự bằng Stack (Gợi ý: Cách dễ nhất là dùng 2 Stacks)
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left != nullptr)
        {
            st1.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            st1.push(curr->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
    
    
}

// --- NHÓM 3: BFS DUYỆT THEO CHIỀU RỘNG BẰNG HÀNG ĐỢI (ITERATION + QUEUE) ---

void levelOrderBFS(Node* root) {
    // TODO: Viết hàm duyệt theo mức bằng Queue
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
    
}

// ==========================================
// PHẦN 3: CODE TEST (KHÔNG CẦN SỬA PHẦN NÀY)
// ==========================================
int main() {
    // Tạo sẵn một cây nhị phân để test:
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "======================================\n";
    cout << "      KIEM TRA KET QUA DUYET CAY      \n";
    cout << "======================================\n\n";

    // 1. Test DFS Đệ quy
    cout << "[1. DFS - DE QUY]\n";
    cout << "Pre-order Expected : 1 2 4 5 3 6 7 \n";
    cout << "Pre-order Your Code: "; preOrderRecursive(root); cout << "\n\n";

    cout << "In-order Expected  : 4 2 5 1 6 3 7 \n";
    cout << "In-order Your Code : "; inOrderRecursive(root); cout << "\n\n";

    cout << "Post-order Expected: 4 5 2 6 7 3 1 \n";
    cout << "Post-order Your Code: "; postOrderRecursive(root); cout << "\n\n";

    cout << "--------------------------------------\n";

    // 2. Test DFS Vòng lặp + Stack
    cout << "[2. DFS - VONG LAP (STACK)]\n";
    cout << "Pre-order Expected : 1 2 4 5 3 6 7 \n";
    cout << "Pre-order Your Code: "; preOrderIterative(root); cout << "\n\n";

    cout << "In-order Expected  : 4 2 5 1 6 3 7 \n";
    cout << "In-order Your Code : "; inOrderIterative(root); cout << "\n\n";

    cout << "Post-order Expected: 4 5 2 6 7 3 1 \n";
    cout << "Post-order Your Code: "; postOrderIterative(root); cout << "\n\n";

    cout << "--------------------------------------\n";

    // 3. Test BFS Vòng lặp + Queue
    cout << "[3. BFS - DUYET THEO MUC (QUEUE)]\n";
    cout << "Level-order Expected: 1 2 3 4 5 6 7 \n";
    cout << "Level-order Your Code: "; levelOrderBFS(root); cout << "\n\n";

    return 0;
}