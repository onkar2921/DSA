// #include<iostream>
// using namespace std;


// int sum(int fre[],int low,int high){
//     int sum=0;
//     for(int i=low;i<=high;i++){
//         sum=sum+fre[i];

//     }
//     return sum;
// }

// int minCostBST(int keys[],int fre[],int n){
//     int cost[n][n];
//     for(int i=0;i<n;i++){
//         cost[i][i]=fre[i];
//     }

//     for(int length=0;length<=n;length++){
//         for(int i=0;i<=n-length+1;i++){
//             int j=i+length-1;
//             cost[i][j]=9990;

//             for(int r=i;r<=j;r++){
//                 int c=((r>i)?cost[i][r-1]:0)+((r<j)?cost[r+1][j]:0)+sum(fre,i,j);
//                 if(c<cost[i][j]){
//                     cost[i][j]=c;
//                 }
//             }
//         }
//     }

//     return cost[0][n-1];


// }   

                   
// int main(){
                   

// int keys[]={10,12,20,12};
// int fre[]={34,8,50,9,7};
// int n=4;   

// cout<<"mincost for bst is: "<<minCostBST(keys,fre,n);
                   
                   
                   
// return 0;
// }



#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};


int sum(int fre[],int i,int j){
    int sum=0;
    for(int k=i;k<j;k++){
        sum+=fre[k];
    }
    return sum;
}


int minCostObst(int fre[],int keys[],int n){
   // making all element as zero
    int cost[n][n]={0};


    //making diagonal element as fre

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cost[i][j]=fre[i];
            }
        }
    }



    // calucalating min cost of nodes

    for(int length=2;length<=n;length++){
        for(int i=0;i<=n-length+1;i++){
            int j=i+length-1;
            cost[i][j]=9999;

            for(int r=i;r<=j;r++){
                int c=((r>i)?cost[i][r-1]:0)+((r<j)?cost[r+1][j]:0)+sum(fre,i,j);
                if(c<cost[i][j]){
                    cost[i][j]=c;
                }
            }
        }
    }
    return cost[0][n-1];

}


Node* buildObst(int keys[],int fre[],int i,int j){
    if(i>j){
        return NULL;
    }

    int minCostIndex=i;
    for(int k=i;k<=j;k++){
        if(fre[k]<fre[minCostIndex]){
            minCostIndex=k;
        }
    }

    Node* root=new Node(keys[minCostIndex]);
    root->left=buildObst(keys,fre,i,minCostIndex-1);
    root->right=buildObst(keys,fre,minCostIndex+1,j);

    return root;
}


void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);
}

                   
                   
int main(){
                   
     int keys[]={10,12,20,12};
     int fre[]={34,8,50,9};
     int n=4;

     cout<<minCostObst(fre,keys,n);
cout<<"obst inorder:-->"<<endl;
     Node* root=buildObst(keys,fre,0,n-1);
     inOrder(root);


                   
                   
                   
return 0;
}