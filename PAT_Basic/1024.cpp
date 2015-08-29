#include<iostream>
#include<string>
#include<sstream>  

using namespace std;
int main()
{
    string s;
    stringstream stream;
    int n;
    cin>>s;
    string::size_type pos=s.find('E');
    string s2=s.substr(pos+2);
    stream<<s2;
    stream>>n;
    if(s[pos+1]=='-')
	{
        if(s[0]=='-')
        cout<<s[0];
       for(int i=0;i<n;i++)
       {        
               if(i==1)cout<<".0";
               else 
               cout<<"0";
	   }
       cout<<s[1];
       for(int i=3;i<pos;i++)
       cout<<s[i];
       cout<<endl;
                          
	}
    else
	{
        if(n>=pos-3)
		{
          if(s[0]=='-')
          cout<<s[0]<<s[1];
          else
          cout<<s[1];
          for(int i=3;i<pos;i++)
            cout<<s[i];
          for(int i=0;i<n-(pos-3);i++)
             cout<<"0";
          cout<<endl;
          }
         else
		 {
          if(s[0]=='-')
          cout<<s[0]<<s[1];
          else
          cout<<s[1];
           for(int i=3;i<3+n;i++)
              cout<<s[i];
              cout<<".";
              for(int i=3+n;i<pos;i++)
               cout<<s[i];
              cout<<endl;
           }
    }
    system("pause");
    return 0;
}
