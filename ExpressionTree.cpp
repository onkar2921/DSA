#include<iostream>
#include <stack>
#include <string>
using namespace std;

class node{
    public:
    char data;
    node* left;
    node* right;
    node(char d){
        data=d;
        left=NULL;
        right=NULL;
    }

};  


bool isOperator(char c){
    return (c=='+' || c=='-' || c=='*' ||c=='/');
}




node * Conversion(string expression){
    stack<node*>s;
    for(int i=expression.size()-1;i>=0;i--){
        char c=expression[i];
            if(isOperator(c)){
                node* newnode=new node(c);
                 newnode->left=s.top();
                s.pop();
                newnode->right=s.top();
                s.pop();
                s.push(newnode);
               
            }else{
                node* newnode=new node(c);
               
                s.push(newnode);
            }
    }

    return s.top();
}


void PostOrder(node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data;
}





void NonRecurssivePostOreder(node *root){
    stack<node*>s1,s2;
    node * temp=root;
    s1.push(temp);
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
        
            }

        while(!s2.empty()){
            cout<<s2.top()->data;
            s2.pop();
        }

}
                   
int main(){

    string exp="+--a*bc/def";
    cout<<exp<<endl;
    node* root=Conversion(exp);
            //    PostOrder(root); 
            NonRecurssivePostOreder(root);   
     
                   
                   
                   
return 0;
}