int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

class Solution {
int mat[400][400], vis[400][400];
int m, n;
    
public:
    int mov[6][3] = {{1, 3, 5}, {2, 5, 6}, {1, 4, 6}, {1, 3, 5}, {2, 3, 4}, {2, 3, 4}};
    
    bool bfs(int sx, int sy)
    {
        queue<pair<int, int> > q;
        q.push(make_pair(sx, sy));
        vis[sx][sy] = 1;
        
        while(!q.empty()){
            pair<int, int> u = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int tx = fx[i] + u.first;
                int ty = fy[i] + u.second;
                
                if(tx >= 0 && tx < m && ty >= 0 && ty < n && !vis[tx][ty]){
                    if(mat[u.first][u.second] == 1){
                        if(tx == u.first && ty == u.second + 1){
                            if(mat[tx][ty] == 1 || mat[tx][ty] == 3 || mat[tx][ty] == 5){
                                vis[tx][ty] = 1;
                                q.push(make_pair(tx, ty));
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
                        }
                        else if(tx == u.first && ty == u.second - 1){
                            if(mat[tx][ty] == 1 || mat[tx][ty] == 4 || mat[tx][ty] == 6){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
                        }
                    }
                    else if(mat[u.first][u.second] == 2){
                        if(tx == u.first - 1 && ty == u.second){
                            if(mat[tx][ty] == 2 || mat[tx][ty] == 3 || mat[tx][ty] == 4){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
                        }
                        else if(tx == u.first + 1 && ty == u.second){
                            if(mat[tx][ty] == 2 || mat[tx][ty] == 5 || mat[tx][ty] == 6){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
                        }
                    }
                    else if(mat[u.first][u.second] == 3){
                        if(tx == u.first && ty == u.second - 1){
                            if(mat[tx][ty] == 1 || mat[tx][ty] == 4 || mat[tx][ty] == 6){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
      
                        }
                        if(tx == u.first + 1 && ty == u.second){
                            if(mat[tx][ty] == 2 || mat[tx][ty] == 5 || mat[tx][ty] == 6){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }

                        }
                    }
                    else if(mat[u.first][u.second] == 4){
                        if(tx == u.first && ty == u.second + 1){
                            if(mat[tx][ty] == 1 || mat[tx][ty] == 3 || mat[tx][ty] == 5){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }

                        }
                        if(tx == u.first + 1 && ty == u.second){
                            if(mat[tx][ty] == 2 || mat[tx][ty] == 5 || mat[tx][ty] == 6){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }

                        }
                    }
                    else if(mat[u.first][u.second] == 5){
                        if(tx == u.first && ty == u.second - 1){
                            if(mat[tx][ty] == 1 || mat[tx][ty] == 4 || mat[tx][ty] == 6){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
                        }
                        if(tx == u.first - 1 && ty == u.second){
                            if(mat[tx][ty] == 2 || mat[tx][ty] == 3 || mat[tx][ty] == 4){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }

                        }
                    }
                    else if(mat[u.first][u.second] == 6){
                        if(tx == u.first && ty == u.second + 1){
                            if(mat[tx][ty] == 1 || mat[tx][ty] == 3 || mat[tx][ty] == 5){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }

                        }
                        if(tx == u.first - 1 && ty == u.second){
                            if(mat[tx][ty] == 2 || mat[tx][ty] == 3 || mat[tx][ty] == 4){
                                q.push(make_pair(tx, ty));
                                vis[tx][ty] = 1;
                                if(tx == m - 1 && ty == n - 1)
                                    return true;
                            }
                        }
                    }
                }
            }
            
        }
        
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        if(m == 1 && n == 1)
            return true;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = grid[i][j];
            }
        }
        
        return bfs(0, 0);
    }
};