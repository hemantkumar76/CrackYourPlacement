class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		stations.push_back({target,0});
		int min_stops = 0;
		int cur_fuel = startFuel;
		int cur_pos = 0;
		priority_queue<int> optional;
		for(int i = 0; i < stations.size();i++){
			int required_fuel = stations[i][0] - cur_pos;
			// iagar chaiye to lelo khi aur se 
			while(cur_fuel < required_fuel && !optional.empty()){
				int top_fuel = optional.top();
				optional.pop();
				cur_fuel += top_fuel;
				min_stops++;
			}
			if(required_fuel <= cur_fuel){
				cur_fuel -= required_fuel;
				cur_pos += required_fuel;
			}
			else return -1;
			// gar pahuch gaye to add kardo 
			optional.push(stations[i][1]);
		}
		return min_stops;
	}
};
