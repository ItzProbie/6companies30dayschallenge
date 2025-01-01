class Solution {

    bool isValidIdx(int i , int j , int row , int col){
        return i>=0 && i<row && j>=0 && j<col;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int row = img.size() , col = img[0].size();
        vector<vector<int>>ans(row , vector<int>(col));

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){

                int tot = 0 , cnt = 0;
                for(int i1 = i-1 ; i1 <= i+1 ; i1++){
                    for(int j1 = j-1 ; j1 <= j+1 ; j1++){

                        if(isValidIdx(i1,j1,row,col)){
                            cnt++;
                            tot += img[i1][j1];
                        }

                    }
                }

                ans[i][j] = tot/cnt;

            }
        }

        return ans;
    }
};