#include<iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define max 5


void addEdge(int adj[][max],int u,int v){

    adj[u][v]=1;
    adj[v][u]=1;

}   


void display(int adj[][max],int v){
    for(int i=0;i<v;i++){
        // cout<<"vertex: "<<i<<"->>>"<<" ";
            for(int j=0;j<v;j++){
                cout<<adj[i][j]<<" ";
                // cout<<j<<" ";
            }
            cout<<endl;
    }
    
}



void bfs(int adj[][max],int v,int start){
    vector<bool>visited(v,false);
    queue<int>q;

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int first=q.front();
        q.pop();
        cout<<first<<" ";

        for(int i=0;i<v;i++){
            if(adj[first][i] && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}



void dfs(int adj[][max],int v,int start){
    vector<bool>visited(v,false);
    stack<int>s;

    s.push(start);

    while(!s.empty()){
        int front=s.top();
        s.pop();
        if(!visited[front]){

            visited[front]=true;
            cout<<front<<" ";
        }


        for(int i=0;i<v;i++){
            if(adj[front][i] && visited[i]==false){
                s.push(i);
                // visited[i]=true;
            }
        }
    }


}
                   
int main(){

    // int n=5;
    // cout<<"enter the no of edges of graph:"<<endl;
    // cin>>n;
    int adj[max][max]={0};
    int u,v;
    for(int i=0;i<v;i++){
            cin>>u>>v;
            addEdge(adj,u,v);
    }


    display(adj,max);
    bfs(adj,max,1);
    cout<<endl;
    dfs(adj,max,1);
                   
     
                   
                   
                   
return 0;
}