https://www.hackerearth.com/problem/algorithm/teachers-dilemma-3-00955296/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

const int MOD = 1e9+7;
vector<int>parent(1e5+1);
vector<int>siz(1e5+1);

int find(int node){
    if(parent[node] == node) return node;
    else return parent[node] = find(parent[node]);
}

void union_(int a, int b){
    a = find(a);
    b = find(b);

    if(siz[a] < siz[b]) swap(a, b);

    if(a != b){
        parent[b] = a;
        siz[a] += siz[b];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        siz[i] = 1;
        parent[i] = i;
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        union_(a, b);
    }

    unordered_set<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(find(i));
    }

    ll ans = 1;
    for(auto root : s){
        ans = (ans * siz[root]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
