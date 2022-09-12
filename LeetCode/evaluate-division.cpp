class Solution {
private:
	double find(unordered_map<string, vector<pair<string, double>>> &grf, unordered_set<string> visited, string start, string end){
		if(grf.find(start) == grf.end() || grf.find(end) == grf.end()) return -1.0; 
		if(start == end) return 1.0; 

		visited.insert(start); 

		for(auto next : grf[start]){
			if(visited.count(next.first)==0){
				double res = find(grf, visited, next.first, end);

				if(res != -1.0){
					return res*next.second;
				}
			}
		}
		return -1.0;
	} 


public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, vector<pair<string, double>>> grf;

		for(int i = 0; i < equations.size(); i++){
			grf[equations[i][0]].push_back({equations[i][1], values[i]});
			grf[equations[i][1]].push_back({equations[i][0], 1/values[i]});
		}

		vector<double> ans;

		for(auto q: queries){
			unordered_set<string> visited;
			double res = find(grf, visited, q[0], q[1]); 
			ans.push_back(res);
		}
		return ans;
	}
};