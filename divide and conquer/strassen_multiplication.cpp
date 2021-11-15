#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> add(vector<vector<int>> a,vector<vector<int>> b,int size)
{

	vector<vector<int>> res(size,vector<int>(size));

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			res[i][j] =a[i][j]+b[i][j];
		}		
	}
	return res;
}


vector<vector<int>> sub(vector<vector<int>> a,vector<vector<int>> b,int size)
{

	vector<vector<int>> res(size,vector<int>(size));
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			res[i][j] =a[i][j]-b[i][j];
		}		
	}
	return res;
}

void printm(vector<vector<int> > matrix)
{
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[i].size();j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}

// function to print diagonal of matrix
// void print_diag (vector< std::vector<int> > m, int d)
// {
// 	for (int i = 0; i < d; i++)
// 	{
// 		cout << m[i][i] << "\n";
// 	}
// }

bool isPowerOfTwo (int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
// vector<vector<int> > res;
vector<vector<int>> multi(vector<vector<int>> a,vector<vector<int>> b,int n)
{
	// int size=n;
	if(n==2)
	{
		int p1,p2,p3,p4,p5,p6,p7;
		int c11,c12,c21,c22;

		p1 = (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
		p2 = (a[1][0]+a[1][1])*b[0][0];
		p3 = (a[0][0])*(b[0][1]-b[1][1]);
		p4 = (a[1][1])*(b[1][0]-b[0][0]);
		p5 = (a[0][0]+a[0][1])*(b[1][1]);
		p6 = (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
		p7 = (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);


		c11 = p1+p4-p5+p7;
		c12 = p3+p5;
		c21 = p2+p4;
		c22 = p1-p2+p3+p6;

		vector<vector<int> > temp_res(n);
		temp_res.resize(n);
		temp_res[0].push_back(c11);
		temp_res[0].push_back(c12);
		temp_res[1].push_back(c21);
		temp_res[1].push_back(c22);
		return  temp_res;

	}
	else
	{
		vector<vector<int> > res(n,vector<int>(n,0));
		res.resize(n,vector<int>(n,0));
		int mid = n/2;
		vector<vector<int>> a11(mid,vector<int>(mid,0));
		vector<vector<int>> a12(mid,vector<int>(mid,0));
		vector<vector<int>> a21(mid,vector<int>(mid,0));
		vector<vector<int>> a22(mid,vector<int>(mid,0));
		vector<vector<int>> b11(mid,vector<int>(mid,0));
		vector<vector<int>> b12(mid,vector<int>(mid,0));
		vector<vector<int>> b21(mid,vector<int>(mid,0));
		vector<vector<int>> b22(mid,vector<int>(mid,0));
		int i=0,j=0;
		while(i<mid)
		{
			while(j<mid)
			{
				a11[i][j]=a[i][j];
                b11[i][j]=b[i][j];

                a21[i][j]=a[i+(n/2)][j];
                b21[i][j]=b[i+(n/2)][j];

                a12[i][j]=a[i][j+(n/2)];
                b12[i][j]=b[i][j+(n/2)];

                a22[i][j]=a[i+(n/2)][j+(n/2)];
                b22[i][j]=b[i+(n/2)][j+(n/2)];

                j++;	
            }
            i++;j=0;
		}
		vector<vector<int> > m1(mid,vector<int>(mid,0));
		vector<vector<int> > m2(mid,vector<int>(mid,0));
		vector<vector<int> > m3(mid,vector<int>(mid,0));
		vector<vector<int> > m4(mid,vector<int>(mid,0));
		vector<vector<int> > m5(mid,vector<int>(mid,0));
		vector<vector<int> > m6(mid,vector<int>(mid,0));
		vector<vector<int> > m7(mid,vector<int>(mid,0));
		vector<vector<int> > temp1(mid,vector<int>(mid,0));
		vector<vector<int> > temp2(mid,vector<int>(mid,0));

		
		temp2=add(b11,b22,mid);
		temp1=add(a11,a22,mid);
		m1 = multi(temp1,temp2,mid);

		temp1=add(a21,a22,mid);
		m2=multi(temp1,b11,mid);

		temp1=sub(b12,b22,mid);


		m3=multi(a11,temp1,mid);

		temp1=sub(b21,b11,mid);
		m4=multi(a22,temp1,mid);

		temp1=add(a11,a12,mid);
		m5=multi(temp1,b22,mid);

		temp2=add(b11,b12,mid);
		temp1=sub(a21,a11,mid);
		m6=multi(temp1,temp2,mid);

		temp2=add(b21,b22,mid);
		temp1=sub(a12,a22,mid);
		m7=multi(temp1,temp2,mid);
        
		for(int i=0;i<n/2;i++)
		{
			for(int j=0;j<n/2;j++)
			{

				res[i][j]= m1[i][j]+m4[i][j]-m5[i][j]+m7[i][j];
                res[i][j+(n/2)]=m3[i][j]+m5[i][j];
                res[i+(n/2)][j]=m2[i][j]+m4[i][j];
                res[i+(n/2)][j+(n/2)]= m1[i][j]-m2[i][j]+m6[i][j]+m3[i][j];
			}
		}
		return res;
	}
}
int main()
{
	vector<vector<int>> first = {
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}};
	vector<vector<int>> second = {
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8},
		{1,2,3,4,5,6,7,8}};
	vector<vector<int>> res = multi(first,second,8);
	printm(res);
}