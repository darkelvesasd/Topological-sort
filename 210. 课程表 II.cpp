class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map<int, vector<int>>m;
	vector<int>in(numCourses);
	queue<int> q;
	vector<int>ret;
	for (auto a : prerequisites)
	{
		int v1 = a[0];
		int v2 = a[1];
		m[v2].emplace_back(v1);
		in[v1]++;
	}
	for (int i = 0; i < numCourses; i++)
	{
		if (in[i] == 0)
		{
			q.emplace(i);
		}
	}
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		ret.emplace_back(t);
		for (auto a : m[t])
		{
			in[a]--;
			if (in[a] == 0)
			{
				q.emplace(a);
			}
		}
	}
	for (int i = 0; i < numCourses; i++)
	{
		if (in[i] != 0)
		{
			return {};
		}
	}
	return ret;
}
};
