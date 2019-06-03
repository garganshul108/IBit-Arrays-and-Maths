/**
*
Spiral Order Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order
*
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool done[A+2][A+2];
    for(int i =0 ; i < A+2; i++)
        for(int j =0; j < A+2; j++)
            done[i][j] = false;
            
    for(int i = 0; i < A+2; i++)
        done[i][A+1] = true;
        
    for(int i = 0; i < A+2; i++)
        done[A+1][i] = true;
        
    for(int i = 0; i < A+2; i++)
        done[0][i] = true;
        
    for(int i = 0; i < A+2; i++)
        done[i][0] = true;
    
        
    vector<vector<int>> result;
    for(int i =0; i< A; i++)
    {
        vector<int> v(A);
        result.push_back(v);
    }
    
    int fill =1;
    int dirItr = 0;
    int i =1;
    int j =1;
    while(!done[i][j])
    {
        result[i-1][j-1] = fill;
        fill++;
        done[i][j] = true;
        if(done[ i + dir[dirItr][0] ][ j + dir[dirItr][1] ])
        {
            dirItr = (dirItr + 1)%4;
        }
        i = i + dir[dirItr][0];
        j = j + dir[dirItr][1];
    }
    
    return result;
}
