#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>

using namespace std;
float a[20][20];
float b[20];
float temp;
int n,i,j;
void TampilMatriks();
int o,p;

int main(){
	while(true){
 	//untuk baris dan kolom
		cout<<"Masukkan jumlah variabel : ";
		cin>>o;
		cout<<"Masukkan jumlah persamaan : ";
		cin>>p;
		if(p>o){
			cout<<"\nJumlah persamaan tidak boleh lebih besar dari jumlah variabel, silakan input kembali\n";
		}
		else
		 break;
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<o;j++){
		cout<<" Input A["<<i+1<<"]"<<"["<<j+1<<"] : ";
		cin>>a[i][j];
		}
	}
	for(int i=0;i<p;i++){
		cout<<" 	Input Hasil["<<i+1<<"] : ";
		cin>>b[i];
	}
	
	cout<<"\nMatriks Awal : \n";
	cout<<"--------------------------------------------------------\n";
	TampilMatriks();

//tahap2 penyelesaian menggunakan metode Gauss-Jordan
	cout<<"\nPENYELESAIAN : \n";
	cout<<"--------------------------------------------------------\n";
	for (n=0;n<p;n++) {
		cout<<"\nTahap "<<(n+1)<<endl;
		temp=a[n][n];
			for (j=0;j<o;j++){
				a[n][j]=a[n][j]/temp;
			}
			b[n]=b[n]/temp;
			for (i=0;i<o;i++){
				if (i!=n){
					temp=a[i][n];
					for (j=n;j<o;j++){
						a[i][j]=a[i][j]-(temp*a[n][j]);
					}
					b[i]=b[i]-(temp*b[n]);
				}
			}
		//menampilkan matriks
		TampilMatriks();
	}

//tahap pembuktian
//cout<<"\nDari penyelesaian diatas diperoleh solusi nilai x dari sistem persamaan linier yaitu : \n";
	for (i=0;i<p;i++){
		if(isinf(b[i])||isnan(b[i])){
			cout<<"\nMatriks tidak konsisten, tidak dapat menghasilkan solusi persamaan linier, silakan input matriks kembali";
			break;
		}
		else
		cout<<endl;
		printf("X%d = %3.4f \n",(i+1),b[i]);
	}
	getch();
}

void TampilMatriks(){
	for (i=0;i<p;i++){
		cout<<" |  ";
		for (j=0;j<o;j++){
			if (a[i][j]>=0)
				printf(" %3.4f ",a[i][j]);
			else
				printf("%3.4f ",a[i][j]);
		}
		cout<<"|  |x"<<(i+1)<<"|";
			if (i==3)
				cout<<" = ";
			else
				cout<<"   ";
				printf("| %3.4f |",b[i]);
		cout<<endl;
	}
}
