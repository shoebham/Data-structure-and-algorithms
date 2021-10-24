#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void init_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

// substring array
vector<char> sub;
set<string> subs;
 // dp matrix
vector<vector<int> > arr;



set<string> printall(string a,string b, int row,int col)
{
    set<string> s;

    if(row==0||col==0)
    {
        s.insert("");
        return s;
    }

    if(a[row-1]==b[col-1])
    {
        set<string> temp = printall(a,b,row-1,col-1);

        for(auto x:temp)
            s.insert(x+a[row-1]);
    }
    else
    {
        if(arr[row-1][col]>=arr[row][col-1])
            s = printall(a,b,row-1,col);
        if(arr[row][col-1]>=arr[row-1][col])
        {
            set<string> temp = printall(a,b,row,col-1);
            s.insert(temp.begin(), temp.end());
        }
    }
return s;

}
void printDPMatrix(string a,string b, int row,int col)
{
    cout<<"     |";
    for(int i=0;i<b.length();i++){
        cout<<b[i]<<"|";
    }
    cout<<"\n   |";
    for(int i=0;i<=col;i++)
    {
        cout<<i<<"|";
    }
    cout<<endl;
    for(int i=0;i<=row;i++)
    {
        if(i>0)
            cout<<a[i-1];
        if(i==0)
            cout<<" |"<<i<<"|";
        else
            cout<<"|"<<i<<"|"; 

        for(int j=0;j<=col;j++)
        {
            cout<<arr[i][j]<<"|";
        }
        cout<<endl;
    }
}

void printOneLCS(string a, string b, int row, int col)
{
    int i=row,j=col;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            sub.push_back(a[i-1]);
            i--;j--;
        }
        else
        {
            if(arr[i][j-1]>arr[i-1][j])
                j--;
            else
                i--;
        }
    }
}
// Top-down DP
int longest(string a,string b, int row,int col)
{

    arr.resize(row+1);
    if(row==b.length())
        swap(a,b);
    
    for(int i=0;i<=row;i++)
        arr[i].resize(col+1);

    int count=0;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(a[i-1]==b[j-1])
            {

                arr[i][j] = 1+arr[i-1][j-1];
            }
            else
            {
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    printDPMatrix(a,b,row,col);
    printOneLCS(a,b,row,col);
    subs = printall(a,b,row,col);

    int ans=arr[row][col];

    

    return ans;
}
// Recursive 
int lcs(string a,string b,int i,int j)
{
    // if(i==0|| j==0)
    //     return 0;

    // if(a[i]==b[j])
    //     return 1+lcs(a,b,i-1,j-1);
    // else
    //     return max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));

    
    if(a[i]=='\0'|| b[j]=='\0')
        return 0;
    else if(a[i]==b[j])
        return 1+lcs(a,b,i+1,j+1);
    else
        return max(lcs(a,b,i+1,j),lcs(a,b,i,j+1));
}

// static vector<vector<int>> rec_arr;
// memoized recursive 
int lcs_memo(string a, string b, int i, int j, vector<vector<int>> &rec_arr)
{
    // cout<<i<<" "<<j<<" "<<a[i]<<" "<<b[j]<<" ";
    if(a[i]=='\0'||b[j]=='\0')
        return 0;
    if(rec_arr[i][j]!=-1)
        return rec_arr[i][j];
    else if(a[i]==b[j])
    {
        return rec_arr[i][j]=1+lcs_memo(a,b,i+1,j+1,rec_arr);
    }
    else
        return rec_arr[i][j]=max(lcs_memo(a,b,i+1,j,rec_arr),lcs_memo(a,b,i,j+1,rec_arr));       
}
int main()
{   
    string a = "AGTGATG";
    string b = "GTTAG";
    if(b.length()>a.length())
        swap(a,b);
    int i=min(a.length(),b.length());
    int j=max(a.length(),b.length()); 
    vector<vector<int>> rec_arr(j+1);
    for(int x=0;x<=j;x++)
    {
        rec_arr[x].resize(i+1,-1);
    }

    cout<<"--------longest common subsequence with recursion------\n";
    cout<<lcs(a,b,0,0);
    cout<<endl;    
    cout<<"--------longest common subsequence with memoization------\n";
    cout<<lcs_memo(a,b,0,0,rec_arr);
    cout<<endl;
    cout<<"--------Memory table for recursion-------";
    cout<<endl;
    for(auto x:rec_arr)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    cout<<"--------longest common subsequence with top-down DP table------\n";
    cout<<"Length of lcs "<<longest(a,b,i,j)<<endl;
    cout<<"Lonest common subsequences\n";
    cout<<subs.size();
    for(auto x:subs)
        cout<<x<<endl;
}