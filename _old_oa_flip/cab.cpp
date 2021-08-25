// 0 -> city ride
// 1 -> inter-city ride
// 2 -> no ride

map<pair<int, int>, int>dp;
int go(int idx, vector<vector<int>>& cost, int prev) {
	//base
	if (idx >= cost.size()) {
		return 0;
	}
	if (dp.count({idx, prev})) return dp[{idx, prev}];

	//hypo
	int op1 = 0, op2 = 0, op3 = 0;
	if (prev == 2) { // when no previous ride
		op1 = go(idx + 1, cost, 1) + cost[idx][1]; // take inter-city ride
		op2 = go(idx + 1, cost, 0) + cost[idx][0]; // take city ride
		op3 = go(idx + 1, cost, 2); // take no ride
	} else {
		op1 = go(idx + 1, cost, 0) + cost[idx][0]; // take city ride
		op2 = go(idx + 1, cost, 2); // take no ride
	}
	return dp[{idx, prev}] = max({op1, op2, op3});
}


int main() {
	int n; cin >> n;
	dp.clear();
	vector<vector<int>>cost(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		int city_ride, inter_city_ride;
		cin >> city_ride >> inter_city_ride;
		cost[i][0] = city_ride;
		cost[i][1] = inter_city_ride;
	}
	cout << go(0, cost, 2);
}