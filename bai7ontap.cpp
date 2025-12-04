#include<stdio.h>
#include<string.h>
typedef struct{
	char ma[50];
	char ten[30];
	int sl;
	int dg;
	int slt;
	int bh;
}MatHang;
int main(){
	MatHang kho[100];
	int n;
	 printf("nhap so luong hang:");
	 scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("nhap mon thu %d:\n",i+1);
		printf("ma:");
		scanf("%s",kho[i].ma);
		printf("ten:");
		getchar();
		gets(kho[i].ten);
		printf("so luong:");
		scanf("%d",&kho[i].sl);
		printf("gia:");
		scanf("%d",&kho[i].dg);
		printf("slt:");
		scanf("%d",&kho[i].slt);
		printf("bh:");
		scanf("%d",&kho[i].bh);
	}
	int vitrivua=0;
	for(int i=1;i<n;i++){
		if (kho[i].slt>kho[vitrivua].slt){
		vitrivua=i;
	    }
	}
	printf("hang ton nhieu nhat la:%s\n ",kho[vitrivua].slt);
	int vitrigiaunhat=0;
	for(int i=1;i<n;i++){
		if (kho[i].dg>kho[vitrigiaunhat].dg){
			vitrigiaunhat=i;
		}
	}
	printf("hang tang gia nhieu nhat la:%d\n",kho[vitrigiaunhat].dg);
	printf("cac bao hanh lon hon 12 thang la:\n");
	for(int i=0;i<n;i++){
		if (kho[i].bh>12){
		printf("---%s(bao hanh:%d thang)\n",kho[i].ten,kho[i].bh);
		}
	}
	return 0;
}
