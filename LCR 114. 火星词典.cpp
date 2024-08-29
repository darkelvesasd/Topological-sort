class Solution {
public:
    string alienOrder(vector<string>& words) {
	unordered_map<char,unordered_set<char>>v;
	int len = words.size();
	unordered_map<char, int>in;
	queue<char>q;
	string ret;
	for (int i = 0; i < len; i++)
	{
		for (auto a : words[i])
		{
			in[a] = 0;
		}
	}
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			string pre = words[i];
			string cur = words[j];
			int prelen = pre.length();
			for (int k = 0; k < prelen; k++)
			{
				if (cur[k] == NULL)
				{
					return"";
				}
				if (pre[k] != cur[k])
				{
					if (v[pre[k]].count(cur[k])==0)
					{
						in[cur[k]]++;
					}
					v[pre[k]].emplace(cur[k]);
					break;
				}
			}
		}
	}
	for (auto a : in)
	{
		if (a.second == 0)
		{
			q.emplace(a.first);
		}
	}
	while (!q.empty())
	{
		char t = q.front();
		ret += t;
		q.pop();
		for (auto a:v[t])
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
		if (a.second != 0)
		{
			return {};
		}
	}
	return ret;
}
};
