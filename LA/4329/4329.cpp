#include<iostream>
#include<algorithm>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define Debug
//************For Debug********
#ifdef Debug
ifstream fin("4329.txt");
#define in fin

#else
#define in cin
#endif
//******************************
#define MAX_N 20005
#define MAX_A 100010
int a[MAX_A];
int c[MAX_A];
int d[MAX_A];
int w[MAX_A];
int n;

int T;
int lowbit(int x)
{
	return x&(-x);
}
int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=a[x];x-=lowbit(x);
	}
	return ret;
}
void add(int x,int d)
{
	while(x<=n)
	{
		a[x]+=d;x+=lowbit(x);
	}
}

int main()
{
    in>>T;
	for(int k=0;k<T;++k)
	{
		in>>n;
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;++i)
			in>>w[i];
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)
		{
			add(w[i],1);
			c[i]=sum(w[i]-1);
		}
		memset(a,0,sizeof(a));
		for(int i=n;i>=1;--i)
		{
			add(w[i],1);
			d[i]=sum(w[i]-1);
		}
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			ans+=c[i]*(n-i-d[i])+d[i]*(i-1-c[i]);
		}
		cout<<ans<<endl;
	}
    return 0;
}


