// Straseen's matrix multiplication


#include <bits/stdc++.h>

using namespace std;

int ** create2darray(int N)
{

	int **a = (int **)malloc(N*N*(sizeof(int)));
	int i, j;
	for(i = 0; i < N; i++)
    {
		a[i] =(int *)malloc(N*sizeof(int));
	}
	return a;
}

int ** create2darrays(int r,int c)
{
	int **a = (int **)malloc(r*c*(sizeof(int)));
	int i, j;
	for(i = 0; i < r; i++)
    {
		a[i] =(int *)malloc(c*sizeof(int));
	}
	return a;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}



void display(int **A, int r,int c)
{
	int i,j;

	cout << endl << endl;
	for(i = 0; i < r; i++)
    {
		for(j = 0; j < c; j++)
            cout << A[i][j] << " ";
        cout << endl;
	}

}

void input2D(int **A, int r, int c)
{
	int i,j;
	for(i = 0; i < r; i++)
    {
		for(j = 0; j < c; j++)
        {
            int k;
            cin >> k;
            A[i][j] = k;
        }
	}

}

int ** copy_a(int **src, int N, int quad)
{
	int src_i,src_j, res_i, res_j;
	int **res=create2darray(N);
	if(quad==1)
		for(src_i=0, res_i=0; src_i<N/2; res_i++,src_i++)
        {
			for(src_j=0,res_j=0; src_j<N/2; src_j++,res_j++)
			{
				res[res_i][res_j]=src[src_i][src_j];
			}
		}
	if(quad==2)
		for(src_i=0,res_i=0; src_i<N/2; res_i++,src_i++)
        {
			for(src_j=N/2,res_j=0; src_j<N ;src_j++,res_j++)
			{
				res[res_i][res_j]=src[src_i][src_j];
			}
		}
	if(quad==3)
		for(src_i=N/2,res_i=0; src_i<N; res_i++,src_i++)
        {
			for(src_j=0,res_j=0; src_j<N/2; src_j++,res_j++)
            {
				res[res_i][res_j]=src[src_i][src_j];
			}
		}
	if(quad==4)
		for(src_i=N/2,res_i=0; src_i<N; res_i++,src_i++)
        {
			for(src_j=N/2,res_j=0; src_j<N; src_j++,res_j++)
			{
				res[res_i][res_j]=src[src_i][src_j];
			}
		}

	return res;
}


int **plus_a(int **A, int **B, int N)
{
	int i,j;

	int **C = create2darray(N);
	for(i = 0; i < N; i++)
    {
		for(j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];
	}

	return C;
}

int ** minus_a(int **A, int **B, int N)
{
	int i,j;

	int **C=create2darray(N);
	for(i = 0; i < N; i++)
    {
		for(j = 0; j < N; j++)
			C[i][j]=A[i][j]-B[i][j];
	}

	return C;
}

int **mul(int **A, int **B, int N)
{
	int **C = create2darray(N);
	if(N<=2)
    {
			int **CZ = create2darray(N);
			int a, b, c, d, e, f, g, h;
			a A[0][0]; b=A[0][1]; c=A[1][0]; d=A[1][1];

			e=B[0][0]; f=B[0][1]; g=B[1][0]; h=B[1][1];

			int p1,p2,p3,p4,p5,p6,p7;
	        p1=(a+d)*(e+h); p2=(c+d)*e; p3=a*(f-h); p4=d*(g-e);
	        p5=(a+b)*h; p6=(c-a)*(e+f);p7=(b-d)*(g+h);

	        CZ[0][0]=p1+p4-p5+p7;
			CZ[0][1]=p3+p5;
			CZ[1][0]=p2+p4;
		    CZ[1][1]=p1+p3-p2+p6;

		    return CZ;
	}


	int **A1 = copy_a(A,N,1);
	int **A2 = copy_a(A,N,2);
	int **A3 = copy_a(A,N,3);
	int **A4 = copy_a(A,N,4);

    int **B1 = copy_a(B,N,1);
	int **B2 = copy_a(B,N,2);
	int **B3 = copy_a(B,N,3);
	int **B4 = copy_a(B,N,4);

	int **P1,**P2,**P3,**P4,**P5,**P6,**P7;

	P1 = mul(plus_a(A1,A4,N/2),plus_a(B1,B4,N/2),N/2);
	P2 = mul(plus_a(A3,A4,N/2),B1,N/2);
	P3 = mul(A1,minus_a(B2,B4,N/2),N/2);
	P4 = mul(A4,minus_a(B3,B1,N/2),N/2);
	P5 = mul(plus_a(A1,A2,N/2),B4,N/2);
	P6 = mul(minus_a(A3,A1,N/2),plus_a(B1,B2,N/2),N/2);
	P7 = mul(minus_a(A2,A4,N/2),plus_a(B3,B4,N/2),N/2);

	int **C1 = plus_a(plus_a(P1,P4,N/2),minus_a(P7,P5,N/2),N/2);
	int **C2 = plus_a(P3,P5,N/2);
	int **C3 = plus_a(P2,P4,N/2);
	int **C4 = plus_a(plus_a(P1,P3,N/2),minus_a(P6,P2,N/2),N/2);

	int res_i,res_j,i,j;

	for(res_i=0,i=0;i<N/2;i++,res_i++)
		for(res_j=0,j=0;j<N/2;res_j++,j++)
			C[res_i][res_j]=C1[i][j];

	for(res_i=0,i=0;i<N/2;res_i++,i++)
		for(res_j=N/2,j=0;j<N/2;res_j++,j++)
			C[res_i][res_j]=C2[i][j];

	for(res_i=N/2,i=0;i<N/2;res_i++,i++)
		for(res_j=0,j=0;j<N/2;res_j++,j++)
			C[res_i][res_j]=C3[i][j];

	for(res_i=N/2,i=0;i<N/2;res_i++,i++)
		for(res_j=N/2,j=0;j<N/2;res_j++,j++)
			C[res_i][res_j]=C4[i][j];

	return C;
}


int ** multiply(int **A, int **B, int r1, int c2, int N)
{
	int **C = create2darray(N);

   	C = mul(A,B,N);

   	int **res = create2darrays(r1,c2);

   	int i,j;

   	for(i = 0; i < r1; i++)
   		for(j = 0; j < c2; j++)
   			res[i][j]=C[i][j];
   	return res;

}


int main(int argc, char const *argv[])
{
	int r1,c1,r2,c2;

	cout << "Enter number of rows matrix1: ";
	cin >> r1;
	cout << "Enter number of columns matrix1: ";
	cin >> c1;
	cout << "Enter number of rows matrix2: ";
	cin >> r2;
	cout << "Enter number of columns matrix2: ";
	cin >> c2;

	int N1 = max(max(r1,c1),max(r2,c2));
	int N = ceil(log2(N1));

	N = pow(2,N);
	int **a = create2darray(N);
	cout << "Enter First Array: " << endl;
	input2D(a,r1,c1);

	int **b = create2darray(N);

	cout << "Enter Second Array: " << endl;
	input2D(b,r2,c2);

	cout << "Matrix Product: ";
   	int **C = multiply(a,b,r1,c2,N);

   	display(C,r1,c2);
	return 0;

}
