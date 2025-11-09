#include<iostream>
#include<vector> 
#include<queue> 

using namespace std; 

class Solution{
public: 
   int orangesRotting(vector<vector<int>>& grid) {
     int m = grid.size(); 
     int n = grid[0].size(); 
     int minute=0; 
     int freshOranges =0; 
     queue<pair<int,int>> q; 
     for(int i=0; i<m; ++i){
       for(int j=0; j<n; ++j){
         if(grid[i][j]==2) q.push({i,j}); 
         if(grid[i][j]==1) ++freshOranges; 
       }
     }
     vector<int> direction={-1,0,1,0}; 
     while(!q.empty()&& freshOranges>0){
        ++minute;
        int sz = q.size(); 
       for(int i=0; i<sz; ++i){
           
         auto [x,y] = q.front(); 
         q.pop(); 
         for(int k=0; k<4; ++k){
           int dx = x+direction[k]; 
           int dy = y+direction[k+1]; 
           if(dx>=0 && dy>=0 && dx<m && dy<n && grid[dx][dy]==1){
             grid[dx][dy]=2; 
             q.push({dx,dy}); 
             --freshOranges; 
           }
         }
       }
     }
     return (freshOranges==0)? minute:-1; 
   }
};
int main(){
  vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
  Solution sol; 
  cout <<sol.orangesRotting(grid)<<endl; 
  return 0; 
}
