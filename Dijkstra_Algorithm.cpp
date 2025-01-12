#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

const int maxn = 100001; // Số đỉnh tối đa là 100000
const int INF = 1e9;     // Giá trị vô cùng lớn

int n, m, s; // Số đỉnh, số cạnh, và đỉnh bắt đầu

vector<pair<int, int>> adj[maxn]; // Danh sách kề {đỉnh kề, trọng số}

// Khai báo hàm printResult
void printResult(int s, const vector<ll>& d, const vector<int>& pre);


// Hàm nhập
void enter() {
    cin >> n >> m >> s; // Nhập số đỉnh, số cạnh, đỉnh bắt đầu
    for (int i = 0; i < m; i++) {
        int x, y, w; 
        cin >> x >> y >> w; // Nhập hai đỉnh và trọng số của cạnh
        // chuyển đổi danh sách cạnh thành danh sách kề
        adj[x].push_back({y, w}); 
        adj[y].push_back({x, w}); 
    }
}

// Dijkstra
void dijkstra(int s) {
    vector<ll> d(n + 1, INF);     // Khoảng cách từ s đến các đỉnh, khởi tạo là vô cùng
    vector<bool> visited(n + 1, false); // Mảng đánh dấu đã thăm
    vector<int> pre(n + 1, -1);  // Mảng lưu đỉnh trước đó (khởi tạo là -1)
    // khởi tạo hàng đợi ưu tiên
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    d[s] = 0;    // Khoảng cách từ s đến chính nó là 0
    pre[s] = s;  // Đỉnh trước của s là chính nó
    Q.push({0, s}); // Đưa đỉnh bắt đầu vào hàng đợi

    while (!Q.empty()) {
        pair<int, int> top = Q.top(); 
        Q.pop();
        int u = top.second; // Đỉnh hiện tại
        int kc = top.first; // Khoảng cách từ s đến u

        if (visited[u]) continue; // Nếu đỉnh u đã được thăm thì bỏ qua
        visited[u] = true;        // Đánh dấu đỉnh u đã được thăm

        for (auto it : adj[u]) {
            int v = it.first;  // Đỉnh kề
            int w = it.second; // Trọng số cạnh (u, v)

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w; // Cập nhật khoảng cách ngắn nhất đến v
                pre[v] = u;      // Lưu đỉnh trước đó trên đường đi đến v
                Q.push({d[v], v}); // Đưa v vào hàng đợi với khoảng cách mới
            }
        }
    }

    printResult(s, d, pre); // Gọi hàm in kết quả
}

// In khoảng cách từ đỉnh s đến các đỉnh khác
void printResult(int s, const vector<ll>& d, const vector<int>& pre) {
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            cout << "Khoang cach tu dinh " << s << " den dinh " << i << " la: Khong co duong di.\n";
        } else {
            cout << "Khoang cach tu dinh " << s << " den dinh " << i << " la: " << d[i] << ". ";
            cout << "Duong di: ";
            vector<int> path;
            int current = i;
            while (current != s) {
                path.push_back(current);
                current = pre[current];
            }
            path.push_back(s);
            reverse(path.begin(), path.end()); // Đảo ngược để hiển thị từ s đến i
            for (size_t j = 0; j < path.size(); j++) {
                if (j > 0) cout << " -> ";
                cout << path[j];
            }
            cout << '\n';
        }
    }
}


int main() {
    enter();       
    dijkstra(s);   
    return 0;
}
