class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double ans[101][101]={0.0};
        ans[0][0]=poured;//first glass will always contain water
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(ans[i][j]>1)//excess water is present so it will overflow
                {
                    ans[i+1][j]+=(ans[i][j]-1)/2.0;
                    ans[i+1][j+1]+=(ans[i][j]-1)/2.0;
                    ans[i][j]=1;
                }
            }
        }
        return ans[query_row][query_glass];
    }
};
