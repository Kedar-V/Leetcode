struct initialise
{
    int prev = -1;
};

class Solution {
    public:
        vector<int> partitionLabels(string S)
        {

            vector<int> ans;

            int len = int(S.length());
            vector<bool> first(len, false);
            vector<bool> last(len, false);

            unordered_map<char, initialise> visited;

            for(int i = 0; i < len; i++)
            {
                char curr = S[i];
                if (visited[curr].prev != -1)
                {
                    last[visited[curr].prev] = false;
                    visited[curr].prev = i;
                    last[i] = true;
                }
                else
                {
                    visited[curr].prev = i;
                    last[i] = true;
                    first[i] = true;
                }
            }

            for (int i = 0; i < len; i++)
            {
                int curr_len = 0;
                int start = i;
                int max_len = visited[S[i]].prev - start ;
                while (i < start + max_len)
                {
                    int next_max_len = visited[S[i]].prev - start;
                    if (i == len-1)
                    {
                        break;
                    }

                    if (next_max_len > max_len)
                    {
                        max_len = next_max_len;
                    }
                    i++;
                }
                curr_len = max_len + 1;
                ans.push_back(curr_len);
            }

            return ans;
        }
};
