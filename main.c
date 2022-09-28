
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Operasi Matriks
float determinant(float[][25],float);
void cofactor(float[][25],float);
void transpose(float[][25],float[][25],float);
void inverse();
void matrixmultiply();
void multireadmatrix(int[][10],int[][10],int,int,int,int);
void multishowmatrix(int[][10],int,int);
void multiprocessmatrix(int[][10],int[][10],int[][10],int,int,int,int);
void matrixadd(float[][25],float[][25],int,int);
void matrixsub(float[][25],float[][25],int,int);
void matrix_output(float[][25],int,int);
void matrixaddsub();
void determinant_input();
void transpose_input();

//SPL
void SPL();
void TampilMatriks();

void main(){
	int a;
	char str;
	int valid = 1;

	while(valid = 1){
		system("cls");
		printf("--------------PROGRAM PERHITUNGAN MATRIKS--------------\n");
		printf("::::1.Menghitung Penjumlahan atau Pengurangan dari matriks::::::::\n");
		printf("::::2.Menghitung Determinan dari matriks::::\n");
		printf("::::3.Menghitung Invers dari matriks::::::\n");
		printf("::::4.Menghitung Perkalian dari matriks::::\n");
		printf("::::5.Menghitung Transpose dari matriks::::::\n");
		printf("::::6.SPL Gauss Jordan::::::\n");
		printf("::::7.Exit::::::\n");
		printf("\nMasukan Pilihan 1 - 7 : ");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
				matrixaddsub();
				break;
			case 2:
				determinant_input();
				break;
			case 3:
				inverse();
				break;
			case 4:
				matrixmultiply();
				break;
			case 5:
				transpose_input();
				break;
			case 6:
				SPL();
				break;
			case 7:
				exit(0);
			default:
				printf("Silahkan Masukan Pilihan Yang Sesuai !\n");
				break;
		}
		getch();
	}

}

void transpose_input(){
	int i,j,n;float a[25][25],b[25][25];
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("\tTranspose Matriks\n\n");
	
	printf("Masukan dimensi dari matriks yang akan di transpose : ");
	scanf("%d",&n);
	printf("\nMasukan elemen dari matriks %dX%d\n",n,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f",&a[i][j]);	
		}
	}
	for (i=0;i<n;i++){
     	for (j=0;j<n;j++){
        	b[i][j]=a[j][i];
        }
    }
    printf("Hasil transpose dari matriks adalah :\n");
    matrix_output(b,n,n);

}

void determinant_input(){
	float a[25][25],k,d;
	int i,j;
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("\tPenghitungan Determinan Matriks\n\n");
	
	printf("Masukan ordo dari matriks : ");
	scanf("%f",&k);
	
	printf("Masukan elemen dari matriks %.0fX%.0f : \n",k,k);
	for (i=0;i<k;i++){
	 for (j=0;j<k;j++)
	   {
	    scanf("%f",&a[i][j]);
	    }
	}
	
	d=determinant(a,k);
	printf("Determinan dari matriks adalah %f",d);
}

void matrixadd(float a[][25],float b[][25],int m, int n){
	int i,j;float integral[25][25];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		integral[i][j]=a[i][j] +b[i][j];
	}
	printf("\nHasil penjumlahan dari kedua matriks adalah \n");

	matrix_output(integral,m,n);
}

void matrixsub(float a[][25],float b[][25],int m, int n){
	int i,j;float integral[25][25];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		integral[i][j]=a[i][j] - b[i][j];
	}
	printf("Hasil pengurangan dari kedua matriks adalah \n");

	matrix_output(integral,m,n);
}

void matrix_output(float dis[][25],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%10f",dis[i][j]);
		}
		printf("\n");
	}
}

void matrixaddsub(){
	int i,j,m,n,cho; float a[25][25],b[25][25];
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("\tPenjumlahan/Pengurangan Matriks\n\n");
	
	printf("Masukan dimensi dari matriks sebagai MxN : ");
	scanf("%d %d",&m,&n);
	printf("Masukan elemen dari matriks pertama\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("Masukan elemen dari matriks kedua\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%f",&b[i][j]);
		}
	}
	printf("\n1.Hitung Penjumlahan Matriks.\n");
	printf("2.Hitung Pengurangan Matriks.\n");
	printf("Masukan Pilihan : ");
	scanf("%d",&cho);

	switch(cho){
		case 1:
			
			matrixadd(a,b,m,n);
			break;
		case 2:

			matrixsub(a,b,m,n);
			break;
	}

}

void inverse(){
	float a[25][25],k,d;
	int i,j;
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("\tMencari Invers Matriks\n\n");
	
	printf("Masukan ordo dari matriks : ");
	scanf("%f",&k);
	
	printf("Masukan elemen dari matriks %.0fX%.0f : \n",k,k);
	for (i=0;i<k;i++){
	 for (j=0;j<k;j++){
	    scanf("%f",&a[i][j]);
	    }
	}
	
	d=determinant(a,k);
	printf("Determinan dari matriks adalah = %f",d);
	if (d==0){
		printf("\nMatriks tidak memiliki invers\n");
	}
	else{
		cofactor(a,k);
	}

}

//For calculating Determinant of the Matrix
float determinant(float a[25][25],float k){
	float s=1,det=0,b[25][25];
	int i,j,m,n,c;
	
	if (k==1){
		return (a[0][0]);
	}
	else{
		det=0;
		for (c=0;c<k;c++){
			m=0;
			n=0;
			for (i=0;i<k;i++){
				for (j=0;j<k;j++){
					b[i][j]=0;
					if (i != 0 && j != c){
						b[m][n]=a[i][j];
						
						if (n<(k-2)){
							n++;	
						}
						else{
							n=0;
							m++;
						}
					}
				}
			}
			det=det + s * (a[0][c] * determinant(b,k-1));
			s=-1 * s;
		}
	}
	return (det);
}

void cofactor(float num[25][25],float f){
	float b[25][25],fac[25][25];
	int p,q,m,n,i,j;
	for (q=0;q<f;q++){
		for (p=0;p<f;p++){
			m=0;
			n=0;
			for (i=0;i<f;i++){
				for (j=0;j<f;j++){
			  		if (i != q && j != p){
			    		b[m][n]=num[i][j];
			    		if (n<(f-2)){
			    			n++;
						}
			    		else{
			       			n=0;
			       			m++;
			       		}
			    	}
				}
			}	
			fac[q][p]=pow(-1,q + p) * determinant(b,f-1);
		}
	}
  	transpose(num,fac,f);
}

//Finding transpose of matrix
void transpose(float num[25][25],float fac[25][25],float r){
	int i,j;
	float b[25][25],inverse[25][25],d;
	
	for (i=0;i<r;i++){
	 	for (j=0;j<r;j++){
	     	b[i][j]=fac[j][i];
	    }
	}
	
	d=determinant(num,r);
	
	for (i=0;i<r;i++){
		for (j=0;j<r;j++){
			inverse[i][j]=b[i][j] / d;
		}
	}
	printf("\n\n\nInverse dari matrix adalah : \n");
	
	for (i=0;i<r;i++){
		for (j=0;j<r;j++){
			printf("\t%f",inverse[i][j]);
		}
		printf("\n");
	}
}

void matrixmultiply(){
	int matrix1[10][10],matrix2[10][10],m,n,p,q,multi[10][10];
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("\tPenghitungan Perkalian Matriks\n\n");
	
	printf("Masukan dimensi matriks pertama sebagai MxN : ");
	scanf("%d %d",&m,&n);
	printf("Masukan dimensi matriks kedua sebagai MxN : ");
	scanf("%d %d",&p,&q);
	
	if (n==p){
		printf("\n======Masukan Elemen Matriks======\n");
		multireadmatrix(matrix1,matrix2,m,n,p,q);
		multiprocessmatrix(matrix1,matrix2,multi,m,n,p,q);
		printf("\nHasil perkalian dari kedua matriks adalah ::::\n");
		multishowmatrix(multi,m,q);
	}
	else{
		printf("Perkalian matriks tidak memungkinkan");
	}
}

void multishowmatrix(int multi[][10],int n,int p)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%10d ",multi[i][j]);
		}
		printf("\n");
	}
}

void multireadmatrix(int matrix1[][10],int matrix2[][10],int m,int n,int p,int q){
	int i,j;
	printf("\nMasukan elemen matriks pertama\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix1[i][j]);	
		}
	}
	printf("\nMasukan elemen matriks kedua\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&matrix2[i][j]);	
		}
	}
}

void multiprocessmatrix(int matrix1[][10],int matrix2[][10],int multi[][10],int m, int n, int p, int q){
	int i,j,k;
	for (i=0;i<m;i++){
		for(j=0;j<q;j++){
			multi[i][j]=0;
			for(k=0;k<n;k++){
				multi[i][j]=multi[i][j]+(matrix1[i][k]*matrix2[k][j]);	
			}
		}
	}

}

///////////////////////////////////////////////////SPL///////////////////////////////////////////////////

float a[20][20];
float b[20];
float temp;
int n,i,j;
void TampilMatriks();
int o,p;

void SPL(){
	int bool = 1;
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("-------------------------------------------------------------\n");
	printf("\tPenghitungan SPL Matriks dengan Gauss Jordan\n\n");
	
	while(bool=1){
 	//untuk baris dan kolom
		printf("Masukkan jumlah variabel : ");
		scanf("%d",&o);
		printf("Masukkan jumlah persamaan : ");
		scanf("%d",&p);
		if(p>o){
			printf("\nJumlah persamaan tidak boleh lebih besar dari jumlah variabel, silakan input kembali\n");
		}
		else{
			break;	
		}
		 
	}
	printf("\nMasukkan elemen matriks %dx%d : \n",o,p);
	for(int i=0;i<p;i++){
		for(int j=0;j<o;j++){
			//printf(" Input A[%d][%d] : ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	for(int i=0;i<p;i++){
		printf("Input Hasil[%d] : ",i+1);
		scanf("%f",&b[i]);
	}
	
	printf("\nMatriks Awal : \n");
	printf("--------------------------------------------------------\n");
	TampilMatriks();

//tahap2 penyelesaian menggunakan metode Gauss-Jordan
	printf("\nPENYELESAIAN : \n");
	printf("--------------------------------------------------------\n");
	for (n=0;n<p;n++) {
		printf("\nTahap %d \n",n+1);
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
			printf("\nMatriks tidak konsisten, tidak dapat menghasilkan solusi persamaan linier, silakan input matriks kembali");
			break;
		}
		else{
			printf("\n");
			printf("X%d = %3.4f \n",(i+1),b[i]);
		}
	}
	getch();
}

void TampilMatriks(){
	for (i=0;i<p;i++){
		printf(" |  ");
		for (j=0;j<o;j++){
			if (a[i][j]>=0)
				printf(" %3.4f ",a[i][j]);
			else
				printf("%3.4f ",a[i][j]);
		}
		printf("|  |x%d|",i+1);
			if (i==3)
				printf(" = ");
			else
				printf("   ");
				printf("| %3.4f |",b[i]);
		printf("\n");
	}
}



