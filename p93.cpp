#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student
{
    struct stud
    {
        int roll;
        char name[100];
        char div;
        char add [100];
    };
    stud rec;
    
    public:
    void create();
    void display();
    int search();
    void Delete();
};
void Student::create()
{
    char ans;
    ofstream fout;
    fout.open("ash.dat", ios::out|ios::binary);
    do
    {
      cout<<"Enter the roll number:"<<endl;
      cin>>rec.roll;
      cout<<"Enter the name:"<<endl;
      cin>>rec.name;
      cout<<"Enter the division:"<<endl;
      cin>>rec.div;
      cout<<"Enter the address:"<<endl;
      cin>>rec.add;
      fout.write((char*)&rec,sizeof(stud));
      cout<<"Do you want to add more records:"<<endl;
      cin>>ans;
    } while (ans=='y'||ans=='Y');
    fout.close();
}
void Student::display()
{
    ifstream fin;
    fin.open("ash.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"The contents of the file are:"<<endl;
    while(fin.read((char*)&rec,sizeof(stud)))
    {
        if(rec.roll!=-1)
        {
        cout<<"Roll No:"<<rec.roll<<endl;
        cout<<"Name:"<<rec.name<<endl;
        cout<<"Division:"<<rec.div<<endl;
        cout<<"Address:"<<rec.add<<endl;
        }
    }
    fin.close();
}
int Student::search()
{
    int r,i=0;
    ifstream fin;
    fin.open("ash.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"Enter the roll no:"<<endl;
    cin>>r;
    while(fin.read((char*)&rec,sizeof(stud)))
    {
        if(rec.roll==r)
        {
            cout<<"Record is present"<<endl;
            cout<<"======================Record details============================="<<endl;
            cout<<"Name:"<<rec.name<<endl;
            cout<<"Division:"<<rec.div<<endl;
            cout<<"Roll No:"<<rec.roll<<endl;
            cout<<"Address:"<<rec.add<<endl;
            return i;
        }
    }
    i++;
    fin.close();
    return 0;
}

void Student::Delete()
{
    int pos,offset;
    pos=search();
    if(pos==0)
    {
        cout<<"Record not found:"<<endl;
    }
    fstream f;
    f.open("ash.dat",ios::in|ios::binary);
    f.seekg(0,ios::beg);
    offset=pos*sizeof(stud);
    f.seekp(offset);
    rec.roll=-1;
    strcpy(rec.name,"NULL");
    rec.div='N';
    strcpy(rec.add,NULL);
    f.write((char*)&rec,sizeof(stud));
    f.seekg(0);
    f.close();
    cout<<"Record deleted:"<<endl;
}


int main()
{
    Student obj;
    int key;
    obj.create();
    obj.display();
    if(key==0)
    {
        cout<<"Record Found:"<<endl;
    }
    obj.Delete();
    return 0;
}