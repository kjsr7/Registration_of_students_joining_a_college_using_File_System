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
	int prev,curr,prev1,curr1,prev2,curr2,prev3,curr3,prev4,curr4,prev5,curr5,prev6,curr6,prev7,curr7,prev8,curr8,n1,n2,n3,n4,n5,n6,n7,n8;
	public:
        year1()
        {
        	 prev= 0;curr =0;n1 = 0;n2 = 0;n3 = 0;n4 = 0;n5 = 0;n6 = 0;n7 = 0;n8 = 0;
        	 
        	 prev1= 0;curr1=0;
        	 prev2= 0;curr2=0;
        	 prev3= 0;curr3=0;
        	 prev4= 0;curr4=0;
             prev5= 0;curr5=0;
			 prev6= 0;curr6=0;
			 prev7= 0;curr7=0;
			 prev8= 0;curr8=0;        	 
		}
		void pack();
		void unpack();
		void add();
		void del(char*key);
		void search();
		void modify();
		void add2();
		void sort();
		void updaterollno(string s[],char*filename);
		void sortbyname();
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
	if(!(strcmp(branch,"cse")))
	{
		fout2<<regno<<"|"<<prev1+curr1<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();
					++n1;return;
	}
    if(!(strcmp(branch,"ece")))
    {
    	fout2<<regno<<"|"<<prev2+curr2<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n2;return;
	}
	if(!(strcmp(branch,"eee")))
    {
    	fout2<<regno<<"|"<<prev3+curr3<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n3;return;
	}
	if(!(strcmp(branch,"civ")))
    {
    	fout2<<regno<<"|"<<prev4+curr4<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n4;return;
	}
	if(!(strcmp(branch,"mec")))
    {
    	fout2<<regno<<"|"<<prev5+curr5<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n5;return;
	}
	if(!(strcmp(branch,"che")))
    {
    	fout2<<regno<<"|"<<prev6+curr6<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n6;return;
	}
	if(!(strcmp(branch,"bio")))
    {
    	fout2<<regno<<"|"<<prev7+curr7<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n7;return;
	}
	if(!(strcmp(branch,"mme")))
    {
    	fout2<<regno<<"|"<<prev8+curr8<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();++n8;return;
	}
	/*switch(branch[0])
	{
		
		cse case 'c' : fout2<<regno<<"|"<<prev1+curr1<<"#";
	                prev1= curr1;
	                 curr1 = strlen(buf);
	                  fout1<<buf;
	                   fout1.close();
	                fout2.close();break;
	    /*ece || *eee)case 'e' : if(branch[1] == 'c')
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
	   /* bio case 'b'	: fout2<<regno<<"|"<<prev4+curr4<<"#";
	                 prev4 = curr4;
	                 curr4 = strlen(buf);
	                 fout1<<buf;
	                 fout1.close();
	                 fout2.close();break;
	
	}*/
	del(regno);
}
void year1::updaterollno(string s[],char*filename)
{
     char index[5];
     strcpy(index,filename);
     int n;
     char reg[11];
     if(!(strcmp(filename,"cse")))
    {n = n1;strcat(reg,"4115");}
      if(!(strcmp(filename,"ece")))
         {n = n1;strcat(reg,"4115");}

      if(!(strcmp(filename,"eee")))
       {n = n1;strcat(reg,"4115");}

      if(!(strcmp(filename,"civ")))
        {n = n1;strcat(reg,"4115");}

      if(!(strcmp(filename,"mec")))
         {n = n1;strcat(reg,"4115");}

      if(!(strcmp(filename,"che")))
         {n = n1;strcat(reg,"4115");}

      if(!(strcmp(filename,"bio")))
         {n = n1;strcat(reg,"4115");}

      if(!(strcmp(filename,"mme")))
      {n = n1;strcat(reg,"4115");}

	 strcat(index,"i");
     ifstream fin2;
     fin2.open(index);
     fstream fin1;
     fin1.open(filename);
     char buf2[100];
     while(!fin2.eof())

   {
	fin2.getline(buf2,100,'#');
      	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
			for(int i = 0;i<n;i++)
			{
				if(s[i] == name)
				{
					  int r = i+1;
					  char t[10];
					  itoa(r,t,10);
					  
					  strcpy(regno,reg);
					  if(r<10)
					  strcat(regno,"0");
					  strcat(regno,t);
					  pack();
					  fin1.seekp(a);
					  fin1<<buf;
			}
		}
	
					  
					  
					  
					 
					
				}
				}	
	
void year1::sortbyname()
{
	ifstream fin2;ifstream fin1;
	fin2.open("csei");
	
            fin1.open("cse");
	string s[100];int i = -1;
	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
            int n;
            n = i+1;
            string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"cse");
        
        fin2.open("ecei");
	
            fin1.open("ece");
//	string s[100];int i = -1;
	//char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
           // int n;
            n = i+1;
           // string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"ece");
	
	
	fin2.open("eeei");
	
            fin1.open("eee");
//	string s[100];int i = -1;
//	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
          //  int n;
            n = i+1;
            //string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"eee");
        
        
        
        fin2.open("civi");
	
            fin1.open("civ");
	string s[100];int i = -1;
	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
            int n;
            n = i+1;
            string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"civ");
	
	
	
	fin2.open("meci");
	
            fin1.open("mec");
	string s[100];int i = -1;
	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
            int n;
            n = i+1;
            string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"mec");
	
	
	fin2.open("chei");
	
            fin1.open("che");
	string s[100];int i = -1;
	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
            int n;
            n = i+1;
            string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"che");
	
	
	fin2.open("bioi");
	
            fin1.open("bio");
	string s[100];int i = -1;
	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
            int n;
            n = i+1;
            string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"bio");
	
	fin2.open("mmei");
	
            fin1.open("mme");
	string s[100];int i = -1;
	char buf2[100];
	while(!fin2.eof())
    {
    	fin2.getline(buf2,100,'#');
    	
        
        	char*add = new char[5];
        	add = strtok(NULL,"#");
            int a = atoi(add);
            
            fin1.seekg(a);
            fin1.getline(buf,100,'#');
            unpack();
            s[++i] = name;
            }
            int n;
            n = i+1;
            string t;
        for(int l = 0;l<n;l++)
        {
        	for(int m = l+1;m<n;m++)
        	{
        		if(s[l]<s[m])
        		{
        			t = s[l];
        			s[l] = s[m];
        			s[m] = t;
				}
			}
        }
        updaterollno(s,"mme");
	
	
	
	
        
        
        
		
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

a.sortbyname();	
	
	
	
	
}
