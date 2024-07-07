#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define endl '\n'

const ll mod = 1000000007;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector < vector<int> > graph(n+1,vector<int>());
    for (int i = 0; i < m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> prev(n+1,0);
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        if (cur==n){
            break;
        }
        for (int child : graph[cur]){
            if (prev[child]==0){
                prev[child]=cur;
                q.push(child);
            }
        }
    }
    if (prev[n]==0){
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int>path;
        path.push_back(n);
        int end = prev[n];
        while(end!=1){
            path.push_back(end);
            end=prev[end];
        }
        path.push_back(end);
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(int c:path) cout<<c<<" ";
    }
    return 0;
}

