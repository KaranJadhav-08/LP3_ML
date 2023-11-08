#include<iostream>
#include<vector>
// using namespace std;

//#include <bits/stdc++.h> 
using namespace std; 

void solve(int col,int n,vector<string> &board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(leftrow[row]==0 && upperdiagonal[(n-1)+col-row]==0 && lowerdiagonal[row+col]==0 )
        {
            board[row][col]='Q';
            leftrow[row]=1;
            upperdiagonal[(n-1)+col-row]=1;
            lowerdiagonal[row+col]=1;
            solve(col+1,n,board,ans,leftrow,upperdiagonal,lowerdiagonal);
            board[row][col]='.';
            leftrow[row]=0;
            upperdiagonal[(n-1)+col-row]=0;
            lowerdiagonal[row+col]=0;

        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }

    vector<int>leftrow(n,0),upperdiagonal(2*n -1,0),lowerdiagonal(2*n-1,0);
    solve(0,n,board,ans,leftrow,upperdiagonal,lowerdiagonal);

    for (int i = 0; i < ans.size(); i++) { 
        for (int j = 0; j < ans[i].size(); j++) 
            cout << " "<<ans[i][j] <<endl;
        cout << endl; 
    } 

    return 0;
}
