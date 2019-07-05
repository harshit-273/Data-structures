//code for regular language
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vari,states,current_state=0;
	cout<<"Enter the number of variables:";
	cin>>vari;
	cout<<"Enter the number of states:";
	cin>>states;
	int input_table[states][vari],acc_state;
	cout<<"Enter the input table:"<<endl;
	for(int i=0;i<states;i++)
	{
		for(int j=0;j<vari;j++)
		{
			cin>>input_table[i][j];
		}
	}
	cout<<"Enter the accepting state:";
	cin>>acc_state;
	char in_str[10];
	int i=0;
	while(1)
	{
		cout<<"Enter the string:";
		cin>>in_str;
		while(in_str[i]!='z')
		{
			current_state=input_table[current_state][in_str[i]-'0'];
			i++;
		}
		if(current_state==acc_state)
		{
			cout<<"string accepted"<<endl;
		}
		else
		{
			cout<<"string not accepted"<<endl;
		}
	}
}
