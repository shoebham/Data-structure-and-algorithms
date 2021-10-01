#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sol=0;
vector<pair<int,int>> ans;
void print_board(vector<vector<bool>> &board)
{
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[i].size();j++)
		{
			cout<<"| "<<board[i][j]<<" |";
		}
		cout<<endl;
	}
}

bool isSafe(vector<vector<bool>> &board, int row, int col,int total)
{

	//top left
	int i=row-1;
	int j=col-1;
	while(i>=0&&j>=0)
	{
		if(board[i][j])
			return false;
		i--;
		j--;	
	}

	//left
	i=row;
	j=col-1;
	while(j>=0)
	{
		if(board[i][j])
			return false;
		j--;
	}

	

	// bottom left
	i=row+1;
	j=col-1;
	while(i<total&&j>=0)
	{
		if(board[i][j])
			return false;
		i++;
		j--;
	}
	
	
	return true;
}

void board_positions(vector<vector<bool>> board){

	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[i].size();j++)
		{
			if(board[i][j])
				ans.push_back(make_pair(i,j));
		}
	}


}
void queen(vector<vector<bool>> &board,int col, int total)
{
	if(col==total)
	{
		sol++;
		board_positions(board);
		cout<<"Board Postions: ";
		for(auto y:ans)
		{
			cout<<"["<<y.first<<","<<y.second<<"] ";
		}			
		cout<<endl;
		ans.clear();
		cout<<"Board\n";
		print_board(board);
		cout<<"--------------------\n";
		return;
	}
	for(int i=0;i<total;i++)
	{
		if(isSafe(board,i,col,total))
		{
			board[i][col]=true;
			queen(board,col+1,total);
			board[i][col]=false;
		}
	}
}

int main()
{
	vector<vector<bool>> board(4,vector<bool>(4,false));
	queen(board,0,4);
	cout<<"Total Number of Solutions: "<<sol<<endl;

	

}