class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map<int, vector<int>>m;
	vector<int>in(numCourses);
	for (auto a : prerequisites)
	{
		int b = a[0];
		int c = a[1];
		m[c].emplace_back(b);
		in[b]++;
	}
	queue<int>q;
	for (int i=0;i<in.size();i++)
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
		for (auto a : m[t])
		{
			in[a]--;
			if (in[a] == 0)
			{
				q.emplace(a);
			}
		}
	}
	for (auto a : in)
	{
		if (a != 0)
		{
			return false;
		}
	}
	return true;
}
};
