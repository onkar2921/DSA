#include<iostream>
#include <string>
using namespace std;

struct node{
    char name[20];
    string label;
    int childCount;
    node *child[10];
};                

node * root;


class GeneralTree{
    public:
    GeneralTree(){
        root=NULL;
    }

    void create(){
        // int chap_cnt;
        root=new node;
        cout<<"enter the title of book:"<<endl;
        cin>>root->label;
        cout<<"enter the no of chapters:"<<endl;
        // cin>>chap_cnt;
        cin>>root->childCount;
        // root->childCount=chap_cnt;
        for(int i=0;i<root->childCount;i++){
            root->child[i]=new node;
            cout<<"enter the name of chapter:"<<endl;
            cin>>root->child[i]->name;
            cout<<"enter the number of sections:"<<endl;
            cin>>root->child[i]->childCount;

            for(int j=0;j<root->child[i]->childCount;j++){
                root->child[i]->child[j]=new node;
                cout<<"enter the name of section :"<<endl;
                cin>>root->child[i]->child[j]->name;
            }
        }
    }



   




    void display(node *root){
        if(root!=NULL){
            // int chap_cnt;
            cout<<"Book title :"<<root->label<<endl;;
            // chap_cnt=root->childCount;

            //childs
            for(int i=0;i<root->childCount;i++){
                cout<<"chapter: "<<i+1<<endl;
                cout<<root->child[i]->name<<endl;
                cout<<"sections: "<<endl;

                //for grandchilds
                for(int j=0;j<root->child[i]->childCount;j++){
                    cout<<root->child[i]->child[j]->name<<" ";
                }
            }
        }
    }
};
                   
int main(){


 GeneralTree obj;
 obj.create();    
 obj.display(root);              
     
                   
                   
                   
return 0;
}