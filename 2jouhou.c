#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 6
int main(void){
	int i, n;
	double x[N],y[N];
	char yname[]="ydata111.txt";
	char res[]="result111.txt";
	FILE *fp;

	while(strcmp(yname, "ydata411.txt") == 0){

	fp = fopen("xdata.txt", "r");

    for(i=0; i<N; i++){
    	fscanf(fp, "%lf", &(x[i]) );
    }
    fclose(fp);
    for(i=0; i<N; i++) {
    	printf("%f\n", x[i]);
	}

	fp = fopen(yname, "r");

    for(i=0; i<N; i++){
    	fscanf(fp, "%lf", &(y[i]) );
    }
    fclose(fp);
    for(i=0; i<N; i++) {
    	printf("%f\n", y[i]);
	}

	double a=0, b=0;
	double sum_xy=0, sum_x=0, sum_y=0, sum_x2=0;

	for(i=0; i<N;i++){
		sum_xy+=x[i]*y[i];
		sum_x+=x[i];
		sum_y+=y[i];
		sum_x2+=pow(x[i], 2);
	}
	a=(N*sum_xy-sum_x*sum_y)/(N*sum_x2-pow(sum_x, 2));
	b=(sum_x2*sum_y-sum_xy*sum_x)/(N*sum_x2-pow(sum_x, 2));
	fp=fopen(res, "w");
	fprintf(fp,"a=%f\n",a);
	fprintf(fp,"b=%f\n",b);
	fclose(fp);
	if((yname[7]=='1')||(yname[7]=='2')){
		yname[7]++;
		res[8]++;
	}
	else if(yname[6]<'5'){
		yname[6]++;
		res[7]++;
		yname[7]='1';
		res[8]='1';
	}
	else {
		yname[5]++;
		res[6]++;
		yname[6]='1';
		yname[7]='1';
		res[7]='1';
		res[8]='1';
	}
	}
	return 0;
}
