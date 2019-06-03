/**
*
Spiral Order Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order
*
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    
    /**
     *  the cursor can move in one of the possible directions during the spiral
     * 
     * 
     * right  {0, 1}
     * bottom {1, 0}
     * left   {0,-1}
     * top    {-1,0}
     * 
     * in cyclic order
     * 
     */
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    

    
    // boolean to check if the cell is already done
    bool done[A+2][A+2];
    for(int i =0 ; i < A+2; i++)
        for(int j =0; j < A+2; j++)
            done[i][j] = false;
    
    // making the boundaries of the cell for the matrix
    /**
     * XXXXXXXX
     * X------X
     * X------X
     * X------X
     * X------X
     * XXXXXXXX
     * 
     * 
     * values are filled from top left '-' to spiral
     *  
     */ 
    for(int i = 0; i < A+2; i++)
        done[i][A+1] = true;
        
    for(int i = 0; i < A+2; i++)
        done[A+1][i] = true;
        
    for(int i = 0; i < A+2; i++)
        done[0][i] = true;
        
    for(int i = 0; i < A+2; i++)
        done[i][0] = true;
    

    // making the result mat to be filled   
    vector<vector<int>> result;
    for(int i =0; i< A; i++)
    {
        vector<int> v(A);
        result.push_back(v);
    }
    

    // fill is the value to be filled
    int fill =1;
    // iterator for direction in order initially set to right
    int dirItr = 0;

    // first cell coordinated on done matrix => (0,0) on result matrix
    // adjusted due to boundary
    int i =1;
    int j =1;

    while(!done[i][j])
    // while not trapped
    {
        result[i-1][j-1] = fill;
        fill++;

        done[i][j] = true;

         
        if(done[ i + dir[dirItr][0] ][ j + dir[dirItr][1] ])
        {
            dirItr = (dirItr + 1)%4;
        }

        // moving to the next spot
        i = i + dir[dirItr][0];
        j = j + dir[dirItr][1];
    }


    /**
         * 
         * Iteration Exaplained: 
         * Changing direction if hit boundary or already done cell
         * sample case
         * current direction is right
         * X X X X X X X X
         * X 1 2 - - - - X
         * X - - - - - - X   
         * X - - - - - - X
         * X - - - - - - X
         * X X X X X X X X 
         * 
         * 
         * after some more iterations
         * X X X X X X X X
         * X 1 2 3 4 5 6 X  blocked by boundary
         * X - - - - - - X
         * X - - - - - - X
         * X - - - - - - X
         * X X X X X X X X
         * 
         * direction itr++ in cycle
         * next direction is bottom as in the array above
         * 
         * X X X X X X X X
         * X 1 2 3 4 5 6 X
         * X - - - - - 7 X 
         * X - - - - - - X 
         * X - - - - - - X 
         * X X X X X X X X 
         * 
         * Similar case occurs when hit the next boundaries
         * 
         * after first complete circle the new circle acts as boundary
         * as boundary is identified by done value = true
         * which is true for every filled spot
         * 
         * 
         * 
         * 
         * END case:
         * 
         * recently filled the second last block with '8'
         * X X X X X
         * X 1 2 3 X
         * X 8 - 4 X
         * X 7 6 5 X
         * X X X X X
         * 
         * moving right as moving top is blocked by 1
         * 
         * filling the last centre block
         * X X X X X
         * X 1 2 3 X
         * X 8 9 4 X
         * X 7 6 5 X
         * X X X X X
         * 
         * 
         * now next direction is bottom as right is blocked by 4
         * 
         * when 'done matrix' of bottom is checked by while condition
         * it is already done
         * then terminated
         * 
         * and returned the result
         * 
         */


    
    return result;
}
