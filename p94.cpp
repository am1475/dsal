#include<iostream>
#include<string.h>
#define N 20
#define serious 10
#define nonserious 5
#define checkup 1

using namespace std;

string Q[N];
int P[N];
int f=-1;
int r=-1;
int i,j;

void enqueue(string data, int p)
{
    if(f==0 && r==N-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        if(f==-1)
        {
            f=0;
            r=0;
            Q[r]=data;
            P[r]=p;
        }
        else if(r==N-1)
        {
            for(i=f;i<=r;i++)
            {
                Q[i-f]=Q[i];
                P[i-f]=P[i];
                r=r-f;
                f=0;
            }
            for(i=r;i>f;i--)
            {
                if(p>P[i])
                {
                    Q[i+1]=Q[i];
                    P[i+1]=P[i];
                }
                else
                {
                    break;
                }
                Q[i+1]=data;
                P[i+1]=p;
                r++;
            }
        }
        else
        {
            for(i=r;i>=f;i--)
            {
                if(p>P[i])
                {
                    Q[i+1]=Q[i];
                    P[i+1]=P[i];
                }
                else
                {
                    break;
                }
                Q[i+1]=data;
                P[i+1]=p;
                r++;
            }
        }
    }
}

void print()
{
    int i;
    for(i=f;i<=r;i++)
    {
        cout<<"Patient name:"<<Q[i]<<endl;
    
    switch (P[i])
    {
    case 1:
        cout<<"General checkup"<<endl;
        break;

    case 5:
        cout<<"Non serious:"<<endl;
        break;
    
    case 10:
        cout<<"Serious :"<<endl;
        break;
    
    default:
        cout<<"Priority not found:"<<endl;
        break;
    }
    }
}

int main() {
	string data;
	int opt,n,i,p;
	cout<<"Enter Your Choice:-"<<endl;
	do {
	    cout << "1 for Insert the Data in Queue" << endl 
             << "2 for show the Data in Queue " << endl 
             << "3 for Delete the data from the Queue" 
		     << endl << "0 for Exit"<< endl;
	    cin >> opt;
		switch(opt) {
			case 1:
				cout << "Enter the number of patients" << endl;
				cin >> n;
				i = 0;
				while(i < n) {
					cout << "Enter the name of the patient : ";
					cin >> data;
					ifnotdoagain: 
						cout << "Enter your Priorities (0: serious, 1: non-serious, 2: general checkup) : ";
						cin >> p;
						switch(p) {
							case 0: 
								enqueue(data, serious);
								break;
							case 1: 
								enqueue(data, nonserious);
								break;
							case 2: 
								enqueue(data, checkup);
								break;
							default:
								goto ifnotdoagain;
						}
					i++;
				}
				break;
			case 2:
				print();
				break;
		}
    } while(opt!=0);
    return 0;
}
