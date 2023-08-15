#include <cstdio>

const int MaxN=10000000;
char s[MaxN+4];

int main()
{
	int N;
	scanf("%d",&N);
	N+=2;
	s[1]='b';
	int i,j;
	for (i=1;i<=N;i++)
	{
		if (i&1)
		{
			char si=s[i],sj=si;
			for (j=i;j*=2,j<=N;)
			{
				sj=si+'c'-sj;
				s[j]=sj;
				s[j+1]='a'+'b'-si;
			}
		}
	}
	char max='a'-1;
	for (i=3;i<=N;i++)
		if (s[i]>max)
			if (max=s[i],max=='c')
				break;
	printf("%d\n",max-'a'+1);
	s[N+1]=0;
	puts(s+3);
}