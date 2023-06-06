#include<iostream>
#include <string>
#include <fstream>
using namespace std;

class student{
    public:
    // string name;
    char name[50];
    int roll;


}; 

student obj;
void create(){
    ofstream out;
    cout<<"enter the name of student:"<<endl;
    // cin.ignore(); // Clear input buffer
    cin.getline(obj.name, sizeof(obj.name));
    out.open("file.txt",ios::binary|ios::app|ios::out);
    // cin>>obj.name;
    cout<<"enter the roll number of student:"<<endl;
    cin>>obj.roll;

    out.write((char*)&obj,sizeof(student));
    out.close();

}


void display(){
    ifstream in;
    in.open("file.txt",ios::binary|ios::in);
    in.seekg(0,ios::beg);
    while(in.read((char*)&obj,sizeof(student))){
        cout<<obj.name<<"->"<<obj.roll<<endl;
    }
    in.close();
}


int search(){
    ifstream in;
    in.open("file.txt",ios::binary|ios::in);
    in.seekg(0,ios::beg);
    int r;
    cout<<"enter the roll to search"<<endl;
    cin>>r;
int i=0;
    while(in.read((char*)&obj,sizeof(student))){
        ++i;
        if(obj.roll==r){
            cout<<obj.name<<"   is present in the record  ->"<<obj.roll<<endl;
        return i;
        }

    }

    return 0;
}



void Delete(){
    // int index=search();
    cout<<"enter roll no to delete:"<<endl;
    int r;
    cin>>r;
    ifstream in;
    ofstream out;
    bool found=false;
    in.open("file.txt",ios::binary|ios::in);
    in.seekg(0,ios::beg);

    out.open("temp.txt",ios::binary|ios::app|ios::out);
   

   while(in.read((char*)&obj,sizeof(student))){
    if(obj.roll!=r){
        out.write((char*)&obj,sizeof(student));
    
    }else{
        found=true;
    }
   }

   in.close();
   out.close();

if(found){
   remove("file.txt");
   rename("temp.txt","file.txt");
    cout<<"deletd sucessfully"<<endl;
}
else{
    cout<<"record not found"<<endl;
}


    
}
                   
int main(){


                // create();   
                display();
                cout<<endl;
                // cout<<search()<<endl;
                Delete();
                display();
                   
                   
                   
return 0;
}