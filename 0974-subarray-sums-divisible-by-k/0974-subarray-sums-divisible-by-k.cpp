class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();

unordered_map<int, int> f;

int sum = 0;
int res = 0;

f[0] = 1;

for (int i = 0; i < n; i++)
{
    sum += a[i];

    int rem = sum % k;

    if (rem < 0)
        rem = rem + k;

    res += f[rem];

    f[rem]++;
}

return res;
        
    }
};