#include<iostream>
#include <vector>
using namespace std;


void addEdge(vector<pair<int,int>>adj[],int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}  



void prims(vector<pair<int,int>>adj[],int n){
    vector<bool>visited(n,false);
    vector<int>key(n,9999);
    vector<int>parent(n,-1);

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n;count++){
        int min=9999,minindex;

        for(int i=0;i<n;i++){
            if(visited[i]==false && key[i]<min){
                min=key[i];
                minindex=i;
            }
        }
        visited[minindex]=true;

        for(auto x:adj[minindex]){
            int vertex=x.first;
            int wt=x.second;
            if(visited[vertex]==false && wt<key[vertex]){
                parent[vertex]=minindex;
                key[vertex]=wt;
            }
        }

    }

    //printing parent;
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" ";

    }


    cout<<endl;
    cout<<"minimum weight is:"<<endl;
    int minwt=0;
    for(int i=0;i<n;i++){
        minwt+=key[i];
    }

    cout<<minwt<<endl;
}


                   
int main(){
                   
int n;
cout<<"enter the no of edges:"<<endl;
cin>>n;
vector<pair<int,int>>adj[n];
     

    int u,v,w;
    for(int i=0;i<n;i++){
        cout<<"enter the u,v,w :"<<endl;
        cin>>u>>v>>w;

        addEdge(adj,u,v,w);
    }


    for(int i=0;i<n;i++){
        cout<<i<<" ->";
        for(auto x:adj[i]){
            cout<<x.first<<"-----"<<x.second<< " ";

        }
        cout<<endl;
    }      


    prims(adj,n); 
                   
                   
return 0;
}