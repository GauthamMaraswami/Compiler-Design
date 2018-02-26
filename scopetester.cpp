#include<bits/stdc++.h>
#include <string> 
#include <boost/lexical_cast.hpp>
using namespace std;
int main()
{
string s;
stack <int> scopecount;
scopecount.push(-1);
cin>>s;
string id="";
for(int i=0;i<s.length();++i)
{
	if(s[i]=='{')
	{
		if(scopecount.top()==-1)
		{
		 	id.append("0");		
		}
		else if(scopecount.top()!=-1)
		{
		 	 int temp=scopecount.top();
			temp++;
			scopecount.pop();
			ostringstream str1;
    			str1 << temp;
    			string temp1 = str1.str();
			//std::string temp1=(temp);
			id.append(temp1);		
		}
	}
	else if(s[i]=='}')
	{
		
		 int temp = boost::lexical_cast<int>(id);
		scopecount.push(temp%10);
		temp=temp/10;
		ostringstream str1;
    			str1 << temp;
    			id = str1.str();
	}
	else{

		cout<<id<<endl;
	}

}

return 0;
}
