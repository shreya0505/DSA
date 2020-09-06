#include<bits/stdc++.h>
using namespace std;



#define N 20000
const int MAXLOG = log2(N)+1;

std::vector<pair<int,int>> adj[N];
int d[N];
int p[N];

// Idea by: https://www.youtube.com/watch?v=CLnpzCnSDSY

void dijikstra(int s, int e){
    //pair: distance , node
    // Log N insertion, O(1) pop and O(1) access
    priority_queue<pair<int,int>> q;
    q.push({d[s],s});

    while(!q.empty()){

        pair<int,int> curr = q.top();
        int dist = curr.first;
        int node = curr.second;
        q.pop();
        // p stores the ancestor with least distance
        // push into queue only if distance gets upated
        for(pair<int,int> edge: adj[node]){
            int v= edge.first;
            int cost = edge.second;
            if(d[node]+cost<d[v]){
                d[v]=d[node]+cost;
                p[v]= node;
                q.push({d[v],v});
            }
        }    
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n+10;i++){
        adj[i].clear();
        d[i]= INT_MAX;
    }

    while(k--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    memset(p, -1, sizeof(p));
    int s,e;
    cin>>s>>e;
    d[s]=0;
    dijikstra(s,e);

    if(d[e]!=INT_MAX){
        cout<<"Distance:\t" <<d[e]<<'\n';
        cout<<"Path:\t"<<e<<' ';
        while(p[e]!=-1){
            cout<<p[e]<<' ';
            e=p[e];
        }
        cout<<'\n';
    }
    else cout<<"No path\n";
}   


int main()
{
    return 0;
}