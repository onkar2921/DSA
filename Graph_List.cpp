// #include<iostream>
// #include <vector>
// #include <stack>
// #include <queue>
// using namespace std;


// void addEdge(vector<int>adj[],int u,int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void display(vector<int>adj[],int n){
//     for(int i=0;i<n;i++){
//         cout<<i<<" ->";
//         for(auto x:adj[i]){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
// }


// void bfs(vector<int>adj[],int n,int start){
//     vector<bool>visited(n,false);
//     queue<int>q;


//     q.push(start);
//     visited[start]=true;

//     while(!q.empty()){
//         int front=q.front();
//         q.pop();
//         cout<<front<<" ";
//         for(auto x:adj[front]){
//             if(visited[x]==false){
//                 q.push(x);
//                 visited[x]=true;
//             }
//         }
//     }
// }



// void dfs(vector<int>adj[],int n,int start){
//     vector<bool>visited(n,false);
//     stack<int>s;

//     s.push(start);

//     while(!s.empty()){
//         int top=s.top();
//         s.pop();

//         if(visited[top]==false){
//             visited[top]=true;
//             cout<<top<<" ";
//         }

//         for(auto x:adj[top]){
//             if(visited[x]==false){
//                 s.push(x);
//             }
//         }
//     }
// }

                   
// int main(){
//                    int n;
//                    cout<<"enter the edges of the graph:"<<endl;
//                    cin>>n;
//      vector<int>adj[n];
// int u,v;
//      for(int i=0;i<n;i++){
//         cout<<"enter the u,v:"<<endl;
//         cin>>u>>v;
//         addEdge(adj,u,v);
//      }

// // bfs(adj,n,1);
// // cout<<endl;
// dfs(adj,n,1);
//     //  display(adj,n);
                   
                   
                   
// return 0;
// }




#include<iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data=d;
        next=NULL;
    }
};  


node* addNode(node* head,int d){
    node* newnode=new node(d);
    newnode->next=head;
    return newnode;
}


void addEdge(node* graph[],int u,int v){
    graph[u]=addNode(graph[u],v);
    graph[v]=addNode(graph[v],u);
}


void display(node* graph[],int n){
    for(int i=0;i<n;i++){
        cout<<i<<"=>";
        node* temp=graph[i];
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}



void bfs(node* graph[],int n,int start){
    vector<bool>visited(n,false);
    queue<int >q;

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";

        node* temp=graph[front];
        while(temp!=NULL){
            if(visited[temp->data]==false){
                q.push(temp->data);
                visited[temp->data]=true;
            }
            temp=temp->next;
        }

    }

    q.push(start);
}



void dfs(node* graph[],int n,int start){
    vector<bool>visited(n,false);
    stack<int>s;

    s.push(start);
    while(!s.empty()){
        int top=s.top();
        s.pop();

        if(visited[top]==false){
            cout<<top<<" ";
            visited[top]=true;
        }

        node* temp=graph[top];
        while(temp!=NULL){
            if(visited[temp->data]==false){
                s.push(temp->data);
            }
            temp=temp->next;
        }

    }

}
                   
int main(){


    node* graph[10]={NULL};

    int n=5;
    // cout<<"enter the number of edges of the graph:"<<endl;
    // cin>>n;
    int u,v,d;

   
        
        addEdge(graph,1,2);
        addEdge(graph,1,3);
        addEdge(graph,1,4);
        addEdge(graph,2,4);
        addEdge(graph,2,3);
                


display(graph,n);

cout<<endl;
bfs(graph,n,1);
cout<<endl;
dfs(graph,n,1);

     
                   
                   
                   
return 0;
}