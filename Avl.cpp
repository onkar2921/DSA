#include<iostream>
using namespace std;


class node{
    public:
    int data;
    int height;
    node*  left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
        height=1;
    }
};

//geting height
int getHeight(node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}


//balance factor

int getBalanceFactor(node * root){
    if(root==NULL){
        return 0;
    }

return getHeight(root->left)-getHeight(root->right);

}

//RightRotate

node * RightRotate(node* y){
    node *x=y->left;
    node* t2=x->right;

    x->right=y;
    y->left=t2;


    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;

    return x;
}

//LeftRotate

node *LeftRotate(node* x){
    node* y=x->right;
    node* t2=y->left;

    y->left=x;
    x->right=t2;

   
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;

    return y;
}


//insertion in avl

node* InsertAvl(node* root,int val){

// normal insertion as we do in bst
    if(root==NULL){
        node* newnode=new node(val);
        return newnode;
    }
    if(val<root->data){
        root->left=InsertAvl(root->left,val);
    }
    else if(val>root->data){
        root->right=InsertAvl(root->right,val);
    }

    //updating heights
    root->height=1+max(getHeight(root->right),getHeight(root->left));


//checking balance factor
int bf=getBalanceFactor(root);


//LL
if(bf>1 && val<root->left->data){
return RightRotate(root);
}



//RR
if(bf<- 1 && val>root->right->data){
return LeftRotate(root);
}



//LR
if(bf>1 && val> root->left->data){
    root->left=LeftRotate(root->left);
   return RightRotate(root);
}



//RL
if(bf<-1 && val < root->right->data){
    root->right=RightRotate(root->right);
   return LeftRotate(root);

}
    return root;
}




void InOrder(node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}



//for deletion
//find minimum value node from left subtree

node* minValue(node* root){
    if(root==NULL){
        return NULL;
    }

    node * temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


//deleting of node

node* deleteFromAvl(node* root,int val){
    
    //searching the node
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left=deleteFromAvl(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteFromAvl(root->right,val);

    }
        //get the key to be deleted
    else {

       
    if(root->left==NULL){  //only right child is exist or no childs
        node* temp=root->right;
        delete(root);
        return temp;
    }
    else if(root->right==NULL){ //left child exist
        node* temp=root->left;
        delete(root);
        return temp;
    }
    else{  //have both childs

        node* temp=minValue(root->right); // getting inorder sucessor
        root->data=temp->data;
        root->right=deleteFromAvl(root->right,root->data);//delete the desire node which is at min of rightsubtree


    }
}

//again upadate root -> height (current node)
root->height=max(getHeight(root->left),getHeight(root->right))+1;

//upto node is get deleted 

// now check balance factor and perform rotations

    int bf=getBalanceFactor(root);

    //ll
    //eg :- left skewd
    if(bf>1 && getBalanceFactor(root->left)>=0){
        return RightRotate(root);
    }

    //RR
    // eg  :-  right skewd 

    if(bf<-1 && getBalanceFactor(root->right)<=0){
        return LeftRotate(root);
    }

    //lR
    if(bf >1 && getBalanceFactor(root->left)<0){
        root->left=LeftRotate(root->left);
        return RightRotate(root);
    }




    //Rl
    if(bf <-1 && getBalanceFactor(root->right)>0 ){
        root->right=RightRotate(root->right);
        return LeftRotate(root);
    }

    
    
    
    return root;
}


node* search(node* root,int val){
    if(root==NULL){
        return NULL;
    }
    else if(val<root->data){
        return root->left=search(root->left,val);
    }
    else if(val>root->data){
        return root->right=search(root->right,val);
    }
    else{
        return root;
    }
}


//ascending-> left----root-----right
//descending->  right----root -----left

void PostOrder(node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->right);
    cout<<root->data<<" ";
    PostOrder(root->left);

}


//updation

void UpdateInAvl(node* root,int oldValue,int newValue){
    node* temp=search(root,oldValue);
    temp->data=newValue;
}

                   
int main(){
                   
 node* root=NULL;
 root= InsertAvl(root,10);
 root=InsertAvl(root,20);
 root= InsertAvl(root,30);
 deleteFromAvl(root,10);
// UpdateInAvl(root,20,40);
 InOrder(root);
 cout<<"search for node :->"<<search(root,30)->data; 

                   
                   
                   
return 0;
}