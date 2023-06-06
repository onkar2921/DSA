#include<iostream>
#include <string>
#include <fstream>
using namespace std;

class student{
    public:
    char name[50];
    int roll;
}; 
student obj;

void create(){
    cout<<"enter the name of student:"<<endl;
    cin>>obj.name;
    cout<<"enter the roll number:"<<endl;
    cin>>obj.roll;

    ofstream out;
    if(obj.roll>0 && obj.roll<20){
        out.open("0-20.txt",ios::binary|ios::app|ios::out);
        out.write((char*)&obj,sizeof(student));
    }
     else if(obj.roll>20 && obj.roll<40){
        out.open("21-40.txt",ios::binary|ios::app|ios::out);
        out.write((char*)&obj,sizeof(student));
    }
}


int search(){
    cout<<"enter the roll number to search:"<<endl;
    int r;
    cin>>r;
    ifstream in;
    int i=0;
    if(r>0 && r<20){
        in.open("0-20.txt",ios::binary|ios::in);
        while(in.read((char*)&obj,sizeof(student))){
            ++i;
            if(obj.roll==r){
                cout<<obj.roll<<" =="<<obj.name<<endl;
                return i;
            }
        }
        return 0;
    }
    else if(r>20 && r<40){
         in.open("21-40.txt",ios::binary|ios::in);
        while(in.read((char*)&obj,sizeof(student))){
            ++i;
            if(obj.roll==r){
                cout<<obj.roll<<" =="<<obj.name<<endl;
                return i;
            }
        }
        return 0;

    }
}


void Delete(){
    int r;
    cout<<"enter the number to be deletes"<<endl;
    cin>>r;
    ifstream in;
    ofstream out;
    bool found=false;
    if(r>0 &&r<20){
        in.open("0-20.txt",ios::binary|ios::in);
        in.seekg(0,ios::beg);
        out.open("d1.txt",ios::binary|ios::app|ios::out);
   
        
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
            remove("0-20.txt");
            rename("d1.txt","0-20.txt");
            cout<<"deleted sucessfully"<<endl;
        } else{
            cout<<"record  not found"<<endl;
        }
    }
    else if(r>20 && r<40){
          in.open("21-40.txt",ios::binary|ios::in);
          in.seekg(0,ios::beg);
        out.open("d2.txt",ios::binary|ios::app|ios::out);
    
        
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
            remove("21-40.txt");
            rename("d2.txt","21-40.txt");
            cout<<"deleted sucessfully"<<endl;
        }
        else{
            cout<<"record  not found"<<endl;
        }
    }
}
                   
int main(){


    // create();
    //  create();
    cout<<search()<<endl;;
    Delete();
                cout<<search()<<endl;;   
     
                   
                   
                   
return 0;
}




// // #include<bits/stdc++.h>

// // using namespace std;

// // class Emp_Cls
// // {
// //     typedef struct Employee
// //     {
// //         char name[20];
// //         int emp_id;
// //         int salary;
// //         char desig[50];
// //     }Record;
// //     typedef struct Index
// //     {
// //         int emp_id;
// //         int position;
// //     }Index_Record;

// //     Record rec;
// //     Index_Record ind_rec;

// //     public:
// //     Emp_Cls();
// //     void create();
// //     void display();
// //     void update();
// //     void deletion();
// //     void append();
// //     void search();
// // };

// // Emp_Cls::Emp_Cls()
// // {
// //     strcpy(rec.name, "");
// // }

// // void Emp_Cls::create()
// // {
// //     int i;
// //     char ch = 'Y';
// //     fstream seqfile;
// //     fstream indexfile;
// //     i = 0;
// //     indexfile.open("ind.txt", ios::in | ios::out);
// //     seqfile.open("emp.txt", ios::in | ios::out);
// //     do
// //     {
// //         cout << "\n Enter name: ";
// //         cin >> rec.name;
// //         cout << "\n Enter Employee ID: ";
// //         cin >> rec.emp_id;
// //         cout << "\n Enter salary: ";
// //         cin >> rec.salary;
// //         cout << "\n Enter designation: ";
// //         cin >> rec.desig;

// //         seqfile.write((char*)&rec, sizeof(rec)) << flush;
// //         ind_rec.emp_id = rec.emp_id;
// //         ind_rec.position = i;
// //         indexfile.write((char*)&ind_rec, sizeof(ind_rec)) << flush;
// //         i++;
// //         cout << "\nDo You want to add more records?: ";
// //         cin >> ch;

// //     }while(ch == 'Y' || ch == 'y');
// //     seqfile.close();
// //     indexfile.close();
// // }

// // void Emp_Cls::display()
// // {
// //     fstream seqfile;
// //     fstream indexfile;
// //     int i;
// //     indexfile.open("ind.txt", ios::in | ios::out);
// //     seqfile.open("emp.txt", ios::in | ios::out);
// //     indexfile.seekg(0, ios::beg);
// //     seqfile.seekg(0, ios::beg);
// //     cout << "\n The contents of file are. " << endl;
// //     i = 0;
// //     while(indexfile.read((char*)&ind_rec, sizeof(ind_rec)))
// //     {
// //         i = ind_rec.position * sizeof(rec);
// //         seqfile.seekg(i, ios::beg);
// //         seqfile.read((char*)&rec, sizeof(rec));
// //         if(rec.emp_id != -1)
// //         {
// //             cout << "\nName: " << rec.name;
// //             cout << "\nEmployee ID: " << rec.emp_id;
// //             cout << "\nSalary: " << rec.salary;
// //             cout << "\nDesignation: " << rec.desig;
// //             cout << "\n";

            
// //         }
// //     }
// //     seqfile.close();
// //     indexfile.close();

// // }


// // void Emp_Cls::update()
// // {
// //     int pos, id;
// //     char new_name[20];
// //     char new_desig[50];
// //     int new_salary;
// //     cout << "\n For Updation: ";
// //     cout << "\n Enter the Employee ID for for searching: ";
// //     cin >> id;
// //     fstream seqfile;
// //     fstream indexfile;

// //     seqfile.open("emp.txt", ios::in | ios::out);
// //     indexfile.open("ind.txt", ios::in | ios::out);
// //     indexfile.seekg(0, ios::beg);

// //     pos = -1;
// //     // reading index file for getting the index
// //     while (indexfile.read((char*)&ind_rec, sizeof(ind_rec)))
// //     {
// //         /* code */
// //         if (id == ind_rec.position)
// //         {
// //             pos = ind_rec.position;
// //             break;
// //         }
// //     }
// //     if(pos == -1)
// //     {
// //         cout << "\n The record is not present in the file";
// //         return;
// //     }
// //     else
// //     {
// //         cout << "\n Enter the values for updation.: ";
// //         cout << "\n Name: ";
// //         cin >> new_name;
// //         cout << "\n Salary: ";
// //         cin >> new_salary;
// //         cout << "\n Designation: ";
// //         cin >> new_desig;

// //         // calculate position of record in seq file using pos of ind file
// //         int offset = pos * sizeof(rec);
// //         seqfile.seekp(offset); //shift pointer to desired position where we want to change/update record 
// //         strcpy(rec.name, new_name); //update name
// //         rec.emp_id = id;
// //         rec.salary = new_salary;
// //         seqfile.write((char*)&rec, sizeof(rec)) << flush;
// //         cout << "\n The record is updated!!!";
// //     }
// //     seqfile.close();
// //     indexfile.close();
    
// // }

// // void Emp_Cls::deletion()
// // {
// //     int id, pos;
// //     cout << "\n For deletion.";
// //     cout << "\n Enter the employee id for searching: ";
// //     cin >> id;
// //     fstream seqfile;
// //     fstream indexfile;
// //     seqfile.open("emp.txt", ios::in | ios::out);
// //     indexfile.open("ind.txt", ios::in | ios::out);
// //     seqfile.seekg(0, ios::beg);
// //     indexfile.seekg(0, ios::beg);
// //     pos = -1;

// //     // reading ind file for geeting the index 
// //     while(indexfile.read((char*)&ind_rec, sizeof(ind_rec)))
// //     {
// //         if (id == ind_rec.emp_id)
// //         {
// //             pos = ind_rec.position;
// //             ind_rec.emp_id = -1;
// //             break;
// //         }
// //     }
// //     if (pos == -1)
// //     {
// //         cout << "\n The record is not present in the file";
// //         return;
// //     }

// //     // calculate postition of record in seq file using pos of index file 
// //     int offset = pos * sizeof(rec);
// //     seqfile.seekp(offset);
// //     strcpy(rec.name, "");
// //     rec.emp_id = -1;//logically making deletion using redefining as -1
// //     rec.salary = -1;
// //     strcpy(rec.desig, "");
// //     seqfile.write((char*)&rec, sizeof(rec)) << flush;
// //     // writing deleted status from index file also the dired record gerts deletd as follows
// //     offset = pos * sizeof(ind_rec);
// //     indexfile.seekp(offset);
// //     ind_rec.emp_id = -1;
// //     ind_rec.position = pos;
// //     indexfile.write((char*)&ind_rec, sizeof(ind_rec)) << flush;
// //     seqfile.seekg(0);
// //     indexfile.close();
// //     seqfile.close();
// //     cout<<"\n The record is Deleted!!!";

// // }

// // void Emp_Cls::append()
// // {
// //     fstream seqfile;
// //     fstream indexfile;
// //     int pos;
// //     indexfile.open("ind.txt", ios::in | ios::out);
// //     indexfile.seekg(0, ios::end);
// //     pos = indexfile.tellg() / sizeof(ind_rec);
// //     indexfile.close();

// //     indexfile.open("ind.txt", ios::in | ios::out);
// //     seqfile.open("emp.txt", ios::in | ios::out);

// //     cout << "\n Enter the record for appending. ";
// //     cout << "\n Name: ";
// //     cin >> rec.name;
// //     cout << "Employee ID: ";
// //     cin >> rec.emp_id;
// //     cout << "\n Salary: ";
// //     cin >> rec.salary;
// //     cout << "\nDesignation: ";
// //     cin >> rec.desig;

// //     seqfile.write((char*)&rec, sizeof(rec));
// //     ind_rec.emp_id = pos;
// //     indexfile.write((char*)&ind_rec, sizeof(ind_rec)) << flush;
// //     seqfile.close();
// //     indexfile.close();
// //     cout << "\n The record is appended!!!";

// // }

// // void Emp_Cls::search()
// // {
// //     fstream seqfile;
// //     fstream indexfile;
// //     int id, pos, offset;
// //     cout << "\n Enter the employee ID for searching the record: ";
// //     cin >> id;
// //     while(indexfile.read((char*)&ind_rec, sizeof(ind_rec)))
// //     {
// //         if (id == ind_rec.emp_id)
// //         {
// //             pos = ind_rec.position;
// //             break;
// //         }
// //     }
// //     if (pos == -1)
// //     {
// //         cout << "\n Record is not present in the file.";
// //         return;
// //     }
// //     offset = pos * sizeof(rec);
// //     seqfile.open("emp.txt", ios::in);
// //     seqfile.seekg(offset, ios::beg);
// //     seqfile.read((char*)&rec, sizeof(rec));
// //     if(rec.emp_id == -1)
// //     {
// //         cout << "\n Record is not present in the file.";
// //         return;
// //     }
// //     else{
// //         cout << "\n The record is present in the file and it is...";
// //         cout << "\n Name: " << rec.name;
// //         cout << "\n Employee ID: " << rec.emp_id;
// //         cout << "\n Salary: " << rec.salary;
// //         cout << "\n Designation: " << rec.desig;
// //     }
// //     seqfile.close();
// //     indexfile.close();
// // }


// // int main()
// // {
// //     Emp_Cls list;
// //     char ans = 'Y';
// //     int choice;

// //     do
// //     {
// //         /* code */
// //         cout << "\n***************************** Menu *********************************" << endl;
// //         cout << "\n 1.Create";
// //         cout << "\n 2.Diaplay";
// //         cout << "\n 3.Update";
// //         cout << "\n 4.Delete";
// //         cout <<"\n 5.Append";
// //         cout <<"\n 6.Search";
// //         cout <<"\n 7.Exit";
// //         cout << "\n Enter Your choice: ";
// //         cin >> choice;
// //         switch (choice)
// //         {
// //         case 1:
// //             /* code */
// //             list.create();
// //             break;
// //         case 2:
// //             /* code */
// //             list.display();
// //             break;
// //         case 3:
// //             /* code */
// //             list.update();
// //             break;
// //         case 4:
// //             /* code */
// //             list.deletion();
// //             break;
// //         case 5:
// //             /* code */
// //             list.append();
// //             break;
// //         case 6:
// //             /* code */
// //             list.search();
// //             break;
// //         case 7:
// //             /* code */
// //             exit(0);
// //             break;
       
// //         default:
// //             cout << "\n You have provided wrong information or option!";
// //             break;
// //         }

// //         cout << "\n\t Do you want to go back to main menu?";
// //         cin >> ans;

        
// //     } while (ans == 'Y' || ans == 'y');

// //     return 0;   
// // }





// #include <iostream>
// #include <fstream>
// using namespace std;

// class Employee
// {

// public:
//     struct Emply
//     {
//         int id;
//         char name[25];
//         char designation[15];
//         int salary;
//     } Records;

//     struct Index
//     {
//         int id;
//         int position;
//     } index;

//     void input()
//     {
//         cout << "\nEnter id number : ";
//         cin >> Records.id;
//         cout << "\nEnter name : ";
//         cin >> Records.name;
//         cout << "\nEnter designation(do not give spaces) : ";
//         cin >> Records.designation;
//         cout << "\nEnter salary : ";
//         cin >> Records.salary;
//     }

//     void output()
//     {

//         cout << "\n\t" << Records.id << "\t" << Records.name << "\t" << Records.designation << "\t" << Records.salary;
//     }
//     void outputIndex()
//     {

//         cout << "\n\t" << index.id << "\t" << index.position;
//     }

//     void insert()
//     {
//         fstream filedata;
//         fstream indexfile;
//         Employee e1;
//         filedata.open("DataFile.dat", ios::app | ios::binary);
//         indexfile.open("IndexFile.dat", ios::app | ios::binary);
//         int i = 0;
//         char ch;
//         do
//         {
//             e1.input();
//             filedata.write((char *)&e1, sizeof(e1));
//             index.id = e1.Records.id;
//             index.position = i;
//             i++;
//             indexfile.write((char *)&index, sizeof(index));
//             cout << "\nDo you want to enter one more record ?(y/n) :";
//             cin >> ch;
//         } while (ch == 'y');
//         filedata.close();
//         indexfile.close();
//     }

//     void display()
//     {

//         // display function is incomplete as it displays deleted records also
//         // we have just deleted record from index file and not from data file
//         fstream filedata;
//         Employee e2;
//         filedata.open("DataFile.dat", ios::in | ios::binary);
//         while (filedata.read((char *)&e2, sizeof(e2)))
//         {
//             e2.output();
//         }
//         filedata.close();
//     }

//     void displayIndex()
//     {
//         fstream indexdata;
//         Employee e2;
//         indexdata.open("IndexFile.dat", ios::in | ios::binary);
//         while (indexdata.read((char *)&e2.index, sizeof(e2.index)))
//         {
//             e2.outputIndex();
//         };
//         indexdata.close();
//     }

//     void search(int id)
//     {
//         fstream filedata;
//         fstream indexdata;
//         Employee e3;
//         indexdata.open("IndexFile.dat", ios::in | ios::binary);
//         int k;
//         bool found = false;
//         while (indexdata.read((char *)&e3.index, sizeof(e3.index)))
//         {
//             if (e3.index.id == id)
//             {
//                 k = e3.index.position;
//                 found = true;
//                 break;
//             }
//         }
//         indexdata.close();
//         if (found)
//         {
//             cout << "\nEmployee found !! " << endl;
//             filedata.open("DataFile.dat", ios::in | ios::binary);
//             int offset = k * sizeof(e3);
//             filedata.seekg(offset);
//             filedata.read((char *)&e3, sizeof(e3));
//             e3.output();
//             filedata.close();
//         }
//         else
//         {
//             cout << "\nEmployee Record not found";
//         }
//     }

//     void deleteEmployee(int id)
//     {

//         // deleteing from indexFile
//         fstream indexdata;
//         fstream indexdataNew;
//         Employee e4;
//         indexdata.open("IndexFile.dat", ios::in | ios::out | ios::binary);
//         indexdataNew.open("IndexFileNew.dat", ios::out | ios::binary);
//         bool found = false;
//         int i=0;
//         while (indexdata.read((char *)&e4.index, sizeof(e4.index)))
//         {
//             if (e4.index.id == id)
//             {
//                 found = true;
//             }
//             else
//             {
//                 e4.index.position=i;
//                 indexdataNew.write((char *)&e4.index, sizeof(e4.index));
//                 i++;
//             }
//         }
//         indexdata.close();
//         indexdataNew.close();
//         remove("IndexFile.dat");
//         rename("IndexFileNew.dat", "IndexFile.dat");

//         // deleting from DataFile
//         fstream filedata;
//         fstream filedataNew;
//         Employee e5;
//         filedata.open("DataFile.dat", ios::in | ios::binary);
//         filedataNew.open("DataFileNew.dat", ios::out | ios::binary);
//         while (filedata.read((char *)&e5, sizeof(e5)))
//         {

//             if (e5.Records.id == id)
//             {
//                 found = true;
//             }
//             if (e5.Records.id != id)
//             {
//                 filedataNew.write((char *)&e5, sizeof(e5));
//             }
//         }
//         if (!found)
//         {
//             cout << "\nEmployee not found, so can't delete";
//         }else{
//             cout<<"\nEmployee deleted ";
//         }
//         filedata.close();
//         filedataNew.close();
//         remove("DataFile.dat");
//         rename("DataFileNew.dat","DataFile.dat");
//     }
// };

// int main()
// {
//     Employee e;
//     int ch;
//     char c;
//     while (true)
//     {
//         cout << "\n\t---------------MENU-----------------------";
//         cout << "\n\tEnter 1 : To add employee record ";
//         cout << "\n\tEnter 2 : To delete employee record ";
//         cout << "\n\tEnter 3 : To search employee record ";
//         cout << "\n\tEnter 4 : To display all  employee record ";
//         cout << "\n\tEnter 5 : To display index file record ";
//         cout << "\n\tEnter 6 : To exit prgram ";
//         cout << "\nEnter choice: ";
//         cin >> ch;

//         switch (ch)
//         {
//         case 1:
//         {
//             e.insert();
//             break;
//         }
//         case 2:
//         {
//             int a;
//             cout << "\nEnter id which is to be deleted : ";
//             cin >> a;
//             e.deleteEmployee(a);
//             break;
//         }
//         case 3:
//         {
//             int a;
//             cout << "\nEnter id which is to be searched : ";
//             cin >> a;
//             e.search(a);
//             break;
//         }
//         case 4:
//         {
//             e.display();
//             break;
//         }
//         case 5:
//         {
//             e.displayIndex();
//             break;
//         }
//         case 6:
//         {
//             exit(0);
//         }
//         default:
//             cout << "Invalid choice";
//             break;
//         }
//     }

//     return 0;
// }