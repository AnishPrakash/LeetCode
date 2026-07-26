class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int total = series1.size() + series2.size();
        vector<vector<int>> res;
        res.reserve(total);
        
        int i = 0, j = 0;
        int n1 = series1.size();
        int n2 = series2.size();
        
        while (i < n1 && j < n2) {
            int t1 = series1[i][0];
            int t2 = series2[j][0];
            
            if (t1 < t2) {
                res.push_back({t1, series1[i][1] + series2[j][1]});
                i++;
            } else if (t1 > t2) {
                res.push_back({t2, series1[i][1] + series2[j][1]});
                j++;
            } else {
                res.push_back({t1, series1[i][1] + series2[j][1]});
                i++;
                j++;
            }
        }
        
        while (i < n1) {
            res.push_back(series1[i]);
            i++;
        }
        
        while (j < n2) {
            res.push_back(series2[j]);
            j++;
        }
        
        return res;
    }
};