#include<iostream>
#include <algorithm>
using namespace std;
                   
class node{
public:
int data;
node* left;
node* right;

node(int d){
data=d;
left=NULL;
right=NULL;

}
};


node *insertBst(node *&root ,int &val){
    if(root==NULL){
        root=new node(val);
        return  root;
    }
    else if (val>root->data){
        root->right=insertBst(root->right,val);
    }
    else if(val<root->data){
        root->left=insertBst(root->left,val);
    }

    return root;
}


int heightOfTree(node* &root){
    
    if(root==NULL){
        return 0;    
    }
    return  max(heightOfTree(root->right),heightOfTree(root->left))+1;
}

int minValue(node* &root){
    if(root==NULL){
        return 0;
    }
    while (root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int maxValue(node* &root){
    if(root==NULL){
        return 0;
    }
    while (root->right!=NULL)
    {
        root=root->right;
    }

    return root->data;
    
}

bool searchFromBst(node* &root,int &val){
    if(root->data==val){
        return true;
    }
    else if(val>root->data){
        return searchFromBst(root->right,val);
    }
    else if(val<root->data){
        return searchFromBst(root->left,val);
    }
    else{
        return false;
    }
}


node *mirror(node * &root){
    if(root==NULL){
        return NULL ;
    }

    mirror(root->left);
    mirror(root->right);
    node * temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;

}

void inOrder(node * &root){
    if(root==NULL){
        return  ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node * &root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node * &root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

node * inOrderPredessor(node * root){
    // if(root==NULL){
    //     return NULL;
    // }
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
    
    
}


node* findMin(node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

node * deleteBst(node * &root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        delete(root);
        return NULL;
    }
    if(val<root->data){
        root->left=deleteBst(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteBst(root->right,val);
    }
    else{   
            // if root->data==val;
            // tree is left skewd
         
    
            if(root->left!=NULL && root->right==NULL){
                        node * temp=root->left;
                        delete root;
                        return temp;
                }
            //if tree is right skewd

            else if(root->left==NULL && root->right!=NULL){
                node * temp=root->right;
                delete(root);
                return temp;
            }
        //if tree is not skewed
       else{

        node * inPre=inOrderPredessor(root);
        root->data=inPre->data;
        root->left=deleteBst(root->left,inPre->data);
       }

  
  
  
  
  
  
  
    // if(root->left==NULL){
    //     node* temp=root->right;
    //     delete root;
    //     return temp;
    // }
    // else if(root->right==NULL){
    //     node* temp=root->left;
    //     delete root;
    //     return temp;
    // }
    
    //     node* temp=findMin(root->right);
    //     root->data=temp->data;
    //     root->right=deleteBst(root->right,temp->data);

    
        
    }

    // return root;

}


void createBst(node *&root){
    int data;
    cin>>data;
    while(data!=-1){
        insertBst(root,data);
        cin>>data;
    }
}




int main(){

    node * root=NULL;
    
    createBst(root);
      inOrder(root);
    mirror(root);
    cout<<"after mirror"<<endl;
    inOrder(root);
    cout<<"height:"<<heightOfTree(root)<<endl;
    //   preOrder(root);
    cout<<"deletion"<<endl;
  deleteBst(root,10);
  inOrder(root);
                   
     
                   
                   
                   
return 0;
}