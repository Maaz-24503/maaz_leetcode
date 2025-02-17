class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<int> ans;
        int lim = (min(height, width) + 1)/2;
        for(int i = 0; i<=lim; i++){
            if(2*i >= width || 2*i >= height) break;
            cout<<width<<" "<<height<<" "<<i<<endl;
            for(int k = i; k<width-i; k++) ans.push_back(matrix[i][k]);
            if(height - (2*i) > 1) for(int k = i+1; k<height-i; k++) ans.push_back(matrix[k][width - i - 1]);
            if(height - (2*i) > 1 && width - (2*i)>1) for(int k = width - i - 2; k>=i; k--) ans.push_back(matrix[height - i - 1][k]);
            if(width - (2*i) > 1 && height - (2*i) > 2) for(int k = height - i - 2; k>i; k--) ans.push_back(matrix[k][i]);
        }
        return ans;
    }
};