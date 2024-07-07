#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const ll mod = 1000000007;

void dfs(vector<bool>&visited,vector<vector<int>>&graph,int i){
    stack<int>s;
    s.push(i);
    while(!s.empty()){
        int u = s.top();s.pop();
        if (visited[u]==false){
            visited[u]=true;
            for(int child:graph[u]){
                s.push(child);
            }
            cout<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector < vector<int> > graph(n+1);
    vector<bool> visited(n+1);

    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count=0;
    vector<int>l;
    for(int i=1;i<n+1;i++){
        if(visited[i]==false){
            dfs(visited,graph,i);
            l.push_back(i);
            count++;
        }
    }
    cout<<count-1<<endl;
    for(int i=1;i<count;i++){
        cout<<l[0]<<" "<<l[i]<<endl;
    }


    return 0;
}
