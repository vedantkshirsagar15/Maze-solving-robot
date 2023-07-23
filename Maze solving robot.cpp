#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n){
        if((newx >=0 && newx < n) && (newy >=0 && newy<n)&&vis[newx][newy] !=1&&arr[newx][newy] !=0){
            return true;
        }
        else
        return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n,  vector<string> &ans, vector<vector<bool>> &vis, string path){
         if(x== n-1 && y ==n-1){
             ans.push_back(path);
             return ; 
         }
        // 4 moments
        // D, L, R, U 
        
        //Down
        if(isSafe(x+1, y, vis, arr, n)){
            vis[x][y]=1;
            solve(x+1, y, arr, n, ans, vis, path + 'D');
            vis[x][y] = 0;
        }
        
         //left
        if(isSafe(x, y-1, vis, arr, n)){
            vis[x][y]=1;
            solve(x, y-1, arr, n, ans, vis, path + 'L');
            vis[x][y] = 0;
        }
        
        //right
        if(isSafe(x, y+1, vis, arr, n)){
            vis[x][y]=1;
            solve(x, y+1, arr, n, ans, vis, path + 'R');
            vis[x][y] = 0;
        }
        
        //Up
        if(isSafe(x-1, y, vis, arr, n)){
            vis[x][y]=1;
            solve(x-1, y, arr, n, ans, vis, path + 'U');
            vis[x][y] = 0;
        }
}

void findPath(vector<vector<int>> &arr, int n) {
        vector<string> ans;     
        vector<vector<bool>> visited (n, vector<bool> (n, 0));
        string path = "";
        
        if(arr[0][0] == 0){
        cout<<-1<<endl;
        return;
        }
        
        solve(0,0,arr,n,ans,visited,path);
        
        for(auto i:ans){
            cout<<i<<" ";
        }
  }

  int main(){
    vector<vector<int>> arr = {{1, 0, 0, 0},
                               {1, 1, 0, 1}, 
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    int n = 4;
    findPath(arr, n);

    return 0;
  }