#include <stdio.h>
#include <math.h>

double f(double x,double y){
	return(x*x+y*y-1);
}

double g(double x,double y){
	return(pow(x,3)-y);
}

int solve(double (*fun1)(double,double),
		  double (*fun2)(double,double),
			double x,double y){
	static int i=0;
	double _x,_y;
	_x=x-((*fun1)(x,y)+2*y*(*fun2)(x,y))/(2*x*(1+3*x*y));
	_y=y-(3*x*x*(*fun1)(x,y)-2*x*(*fun2)(x,y))/(2*x*(1+3*x*y));
	if((_x-x)*(_x-x)+(_y-y)*(_y-y)<1e-6)
	{
		printf("the result:(%lf,%lf)\n",_x,_y);
		return (0);
	}
	else
	{
		i++;
		printf("(x[%d],y[%d])=(%lf,%lf)\n",i,i,_x,_y);
		solve(fun1,fun2,_x,_y);
		return (0);
	}
}

int main()
{
	solve(f,g,0.6,0.8);
}