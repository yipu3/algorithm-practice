#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;			
char temp[100];
char s[10000];
char a[10000][10000];
int find()
{
	for(int i=0;i<strlen(temp);i++)
		if(temp[i]==';')
			return i;
	return -1;
}
void merge(int n)
{
	int i;
	for(i=0;i<=n;i++)
		s[strlen(s)+i]=temp[i];
	s[i]='\0';
}
void small(int f,int a)
{
	int i;
	for(i=0;i<a-1-f;i++)
		temp[i]==temp[f+i+1];
	temp[i]='\0';
}
void add(int num)
{	
	int i;
	for(i=0;i<strlen(s);i++)
		a[num][i]=s[i];
	a[num][i]='\0';
}
int main()
{
	int n;
	char end[]="END OF CASE";
	int time[10000];
	int t;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		memset(s,0,sizeof(s));
		t=1;
		int num=0;
		int amo[10000];
		while(1)
		{
			string temp2;
			getline(cin,temp2);
			int i;
			//for(i=0;i<temp2.size();i++)
				//temp[i]=temp2[i];
			temp[i]='\0';
			//puts(temp);
			if(temp2=="END OF CASE")
				break;
			while(1)
			{
				if(find()!=-1)
				{
					merge(find());
					add(num);
					time[num]=t;
					//cout<<time[num];
					amo[num]=strlen(s);
					for(int i=0;i<amo[num];i++)
						cout<<a[num][i];
					cout<<'\n';
					num++;
					memset(s,0,sizeof(s));
					small(find(),strlen(temp));
				}
				else
				{
					merge(strlen(temp));
					break;
				}
			}
			t++;
		}
		for(int i=0;i<num;i++)
		{
			printf("%d: ",time[i]);
			for(int j=0;j<amo[i];j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
