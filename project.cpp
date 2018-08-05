#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
using namespace std;
class year1
{private:
	char regno[11];
	char name[20];
	char sec[2];
	char cgpa[5];
	char attend[5];
	char branch[4];char buf[100];
	int prev,curr,prev1,curr1,prev2,curr2,prev3,curr3,prev4,curr4;
	public:
        year1()
        {
        	 prev= 0;curr =0;
        	 prev1= 0;curr1=0;
        	 prev2= 0;curr2=0;
        	 prev3= 0;curr3=0;
        	 prev4= 0;curr4=0;
        	 
		}
		void pack();
		void unpack();
		void add();
		void del(char*key);
		void search();
		void modify();
		void add2();
		void sort();
};
void year1::del(char*key)
{
	
	char buf2[15];
	/*cout<<"enter the key u want to delete"<<endl;
	cin>>key;*/
    ifstream fin2;
    fin2.open("i2.txt");
    while(!fin2.eof())
    {
    	fin2.getline(buf2,40,'#');
    	
        if(!(strcmp(key,strtok(buf2,"|"))))
        {cout<<"found !";
        	char*add = new char[3];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            fstream fin;
            fin.open("s2.txt");
            fin.seekg(a);
            fin.getline(buf,40,'#');
            unpack();
            buf[0] = '*';
            
            buf[strlen(buf)] = '\0';
            fin.seekp(a);
            
            fin<<buf;
            fin.close();
            fin2.close();
            return ;
        }
    }
    
            
}
                        


void year1::add2()
{
	ofstream fout1;ofstream fout2;
	
	if(atoi(attend)<75)
	{
	cout<<"detained becoz of attendance"<<endl;
	return;
}
if(atoi(cgpa)<4)
{
	cout<<"detained becoz of less no of credits"<<endl;
	return;
}

		
	strcpy(attend,"0");
	strcpy(cgpa,"NILL");
	pack();
	fout1.open(branch,ios::app);
	char index[11];
	strcpy(index,branch);
	strcat(index,"i");
	cout<<"index file "<<index<<endl;
	cout<<"dat file "<<branch<<endl;
	fout2.open(index,ios::app);
	switch(branch[0])
	{
		
		/*cse*/case 'c' : fout2<<regno<<"|"<<prev1+curr1<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();break;
	    /*ece || *eee)*/case 'e' : if(branch[1] == 'c')
	                {
		
		            fout2<<regno<<"|"<<prev2+curr2<<"#";
	                 prev2 = curr2;
	                 curr2 = strlen(buf);
	                 fout1<<buf;
	                 fout1.close();
	                 fout2.close();break;}
	                 else
	                 
                      {
					    fout2<<regno<<"|"<<prev3+curr3<<"#";
	                 prev4 = curr4;
	                 curr4 = strlen(buf);
	                 fout1<<buf;
	                 fout1.close();
	                 fout2.close();break;
	                   }
	   /* bio */ case 'b'	: fout2<<regno<<"|"<<prev4+curr4<<"#";
	                 prev4 = curr4;
	                 curr4 = strlen(buf);
	                 fout1<<buf;
	                 fout1.close();
	                 fout2.close();break;
	
	}
	del(regno);
}

void year1::sort()
{
	
	
	
	
	
	
	
	
	
	
	
	
	
}
void year1::pack()
{
	strcpy(buf,regno);
	strcat(buf,"|");
	strcat(buf,name);
	strcat(buf,"|");
	strcat(buf,sec);
	strcat(buf,"|");
	strcat(buf,cgpa);
	strcat(buf,"|");
	strcat(buf,attend);
	strcat(buf,"|");
	strcat(buf,branch);
	strcat(buf,"#");
}
void year1::unpack()
{
	strcpy(regno,strtok(buf,"|"));
	strcpy(name,strtok(NULL,"|"));
	strcpy(sec,strtok(NULL,"|"));
	strcpy(cgpa,strtok(NULL,"|"));
	strcpy(attend,strtok(NULL,"|"));
	strcpy(branch,strtok(NULL,"#"));
	
}
void year1::add()
{
	cout<<"enter rego "<<endl;
	cin>>regno;
	cout<<"enter name "<<endl;
	cin>>name;
	cout<<"enter sec "<<endl;cin>>sec;
	cout<<"enter cgpa "<<endl;cin>>cgpa;
	cout<<"enter attend "<<endl;cin>>attend;
	cout<<"enter branch "<<endl;cin>>branch;
	pack();
	ofstream fout;
	fout.open("s2.txt",ios::app);
	ofstream fout2;
	fout2.open("i2.txt",ios::app);
	
    
	fout2<<regno<<"|"<<prev+curr<<"#";
	prev = curr;
	curr = strlen(buf);
	fout<<buf;
	fout.close();
	fout2.close();
	
	
	
	
	
}
void year1::search()
{
	
	
	char key[11];
	char buf2[100];
	cout<<"enter the registration number of the student"<<endl;
	cin>>key;
    ifstream fin2;
    fin2.open("i2.txt");
    while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        if(!(strcmp(key,strtok(buf2,"|"))))
        {
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            ifstream fin;
            fin.open("s2.txt");
            fin.seekg(a);
            fin.getline(buf,100,'#');
            unpack();
            if(regno[0]!='*')
            {
            	 cout<<"record found !"<<endl;
			
            cout<<"the record is "<<regno<<" "<<"name :"<<name<<" "<<"sec :"<<sec<<"cgpa :"<<cgpa<<"attend :"<<attend<<"branch :"<<branch<<endl;
			add2();
			}
            else
            {
            	 cout<<"delted previously"<<endl;
			}
            fin.close();
            fin2.close();
            return;
}
}
	cout<<"not found"<<endl;
	
	fin2.close();
}
void year1::modify()
{
	char key[11],buf2[100];
	cout<<"enter the pri key of the record u want to modify"<<endl;
	cin>>key;
	ifstream fin2;
	fin2.open("i2.txt");
	while(!fin2.eof())
    {fin2.getline(buf2,100,'#');
      if(!(strcmp(key,strtok(buf2,"|"))))
      {
      	cout<<"found !";
      	char*add = new char[5];
      	add = strtok(NULL,"#");
      	int a = atoi(add);
      	fstream fin;
      	fin.open("s2.txt");
      	fin.seekg(a);
      	fin.getline(buf,100,'#');
      	unpack();
      	int next = (strlen(name)+strlen(regno)+strlen(sec)+strlen(cgpa)+strlen(attend)+strlen(branch)+2);
    
      	cout<<"enter the new name and new age "<<endl;
      	cin>>regno>>name>>sec>>cgpa>>attend>>branch;
      	int nc  = (strlen(name)+strlen(regno)+strlen(sec)+strlen(cgpa)+strlen(attend)+strlen(branch)+2);
	cout<<"nc "<<nc;

      	if(nc>next)
      	{
      		cout<<"record size exceeds the limit"<<endl;
      		fin.close();
      		fin2.close();
      		return ;
		  }
		  else
		  {
		  	pack();
		  	fin.seekg(a);
		  	for(int i = 0;i<=next-a-nc;i++)
		  	{
		  		strcat(buf,"#");
		  		
			  }
			  fin<<buf;
			  fin.close();
			  fin2.close();
			  return ;
		  	
		  	
		  	
		  }
      	
      	
      	
      	
      	
	  }
    	
    	
    	
		}}
		
		
	
		

int main()
{
	year1 a;
	char ch;
	do
	{
		cout<<"enter to continue y/n"<<endl;cin>>ch;
		if(ch=='y')
         a.add();		
	}while(ch!='n');
   
   cout<<"first yr records completed"<<endl;
   cout<<"second yr registration starts"<<endl;
   do
   {
   	
   	cout<<"enter to continue y/n"<<endl;
   	cin>>ch;
   	if(ch == 'y')
   	{
	   a.search();
	   
          	
   	
   }
   
   	
	
	
	
	}while(ch!='n');
	
	
	
	
	
}
