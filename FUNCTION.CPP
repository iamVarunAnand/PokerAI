long int fact(int n)
{
	long int 	f=1;
			for(int i=1;i<=n;i++)
				f=f*i;

	return	f;
}
long int permute(int n,int r)
{
	long int	p=1;
			for(int i=1;i<=r;i++,n--)
				p=p*n;

	return	p;
}
long int combine(int n,int r)
{
	long int	c;
	long int	nr=1,dr=1;
			for(int i=1;i<=r;i++,n--)
			{
				nr=nr*n;
				dr=dr*i;
			}
			c=nr/dr;
	return c;
}
/*long float isrflush(int a[],int N,int r,int size)
{
	long float  	prflush;
	int             n=0;//Stores number of cards >=10
			for(int i=0;i<size;i++)
				if(a[i]>=10)n++;

			if(5-n==r)prflush=float(fact(5-n))/combine(N,r);
				else prflush=float((permute(5,5-n)*permute(n,n+r-5)))/combine(N,r);

			return prflush;
} */