#include<iostream>
#include <string>
#include <vector>
using namespace std;


class patient{
    public:
    int prio;
    string name;

};  


//global vector
vector<patient*>heap;



void swap(vector<patient*>&heap,int curr,int parent){
    patient *temp=heap[curr];
    heap[curr]=heap[parent];
    heap[parent]=temp;
}


patient* getInput(){
    patient  *temp=new patient();
    cout<<"enter the name of patient:"<<endl;
    cin>>temp->name;
    cout<<"enter the priority:"<<endl;
    cin>>temp->prio;
    return temp;
}


void maxHeap(vector<patient*>&heap){
    patient *temp=getInput();
    heap.push_back(temp);

   
   int curr=heap.size()-1;

   while(curr>0){
    int parent=(curr-1)/2;
    if(heap[curr]->prio > heap[parent]->prio){
        swap(heap,curr,parent);
        curr=parent;
    }
    else{
        return;
    }
   }
}


int  popHeap(vector<patient*>&heap){
    int maxElement=heap[0]->prio;

    int last=heap.size()-1;
    
    heap[0]=heap[last];
    heap.pop_back();
   int curr=0;
    
    while(true){
    int maxchild=-1;
    int leftChild=2*curr+1;
    int rightChild=2*curr+2;
   

    if(leftChild<heap.size()){
        maxchild=leftChild;
        if(rightChild<heap.size() && heap[rightChild]->prio>heap[leftChild]->prio){
            maxchild=rightChild;
        }
    }


    if(maxchild==-1 || heap[curr]->prio >=heap[maxchild]->prio){
        break;
    }
    swap(heap,curr,maxchild);
    curr=maxchild;
    }

    
    return maxElement;
    
}


 

                   
int main(){

    
    int n;
    cout<<"enter how many data you want to store:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
       
        maxHeap(heap);
    }


    cout<<endl;
    for(auto x:heap){
        cout<<x->name<<" "<<x->prio<<endl;
    }


    
    cout<<popHeap(heap)<<endl;
    cout<<popHeap(heap)<<endl;
    cout<<popHeap(heap)<<endl;
    cout<<popHeap(heap)<<endl;
    cout<<popHeap(heap)<<endl;
                   
     
                   
                   
                   
return 0;
}