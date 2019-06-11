#include <stdio.h>
#include <string.h>

char empty;

void apaga()
{
	system("clear");
}

void timer(float t)
{
	char cmd[255];
	sprintf(cmd,"sleep %f",t);
	system(cmd);
}

void sclean(char *str)
{
	int i=0;
	
	while(*(str+i)!='\0')
 	{
	*(str+i)=empty;
	i++;
	}
	i++;
	*(str+i)=empty;
}

void lstr(int in, int fin,char str[],char fstr[])
{
	int i=0;
	int tmh;
		
	in--;
	fin--;
	sclean(fstr);
	tmh=strlen(str);
	
	if (fin>tmh)
		fin=tmh;
	if (fin==0)
		fin=tmh;
	if (in<0)
		in=0;
	
	for(i=in;i<=fin;i++)
	{
	fstr[i-in]=str[i];
	}
	if(in==fin)
	{
		sclean(fstr);
		fstr[0]=str[in];
	}
	
	i++;
	fstr[i-in]='\0';	
}

int mdc(int x,int y)
{
    int c=1;
    if (y>x)
	{
		c=x;
		x=y;
		y=c;
		c=1;
	}
	
	while(c!=0)
	{
		c=x%y;
		x=y;
		y=c;
    }
    return x;
}

int mmc(int x,int y)
{
    return (x*y)/mdc(x,y);
}

int primo(int num)
{
	int i;
	
	if(num==2)
		return 1;
	
	for(i=2;i<num;i++)
	{
		if(num%i==0)
			break;
		if(i==(num-1))
			return 1;
	}
	return 0;
}

