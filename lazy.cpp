#include<iostream>
#include<vector>
using namespace std;

struct lzMat{
	lzMat* a;
	lzMat* b;
	vector<vector<int> > vis;
	vector<vector<int> > c;
	int n, m;
	lzMat(int n, int m): n(n), m(m), c(n, vector<int> (m, 0)){ vis = c;}
	lzMat operator*(lzMat& b)
	{
		lzMat newMat(n, b.m);
		newMat.a = this;
		newMat.b = &b;
		return newMat;
	}
	int val(int x, int y)
	{
		if(!vis[x][y])
			for(int k = 0; k < a->m; k++)
				c[x][y] += a->val(x, k) * b->val(k, y);
		return c[x][y];
	}
	void input()
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				cin >> c[i][j];
				vis[i][j] = 1;
			}
	}
	void output()
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
				cout << val(i, j) << " ";
			cout << endl;
		}
	}
};



int main()
{
	lzMat a(3, 3);
	lzMat b(3, 3);
	a.input();
	b.input();
	lzMat c = a * b;
	c.output();	
	cout << endl;
}
