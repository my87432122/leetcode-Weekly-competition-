// name: 制造字母异位词的最小步骤数
// 思路：统计两个字符串字母的不一样的个数，例如 'bab' 和 'aba' s1中出现的字母c对 cnt[c] ++ s2中出现的字母c对 cnt[c]--
// 这样两者如果有相同的字母就会++ -- 抵消掉，这样就只留下不同的，cnt[]中为整数的即s1中有的s2中没有，cnt[]中为负数的即s2中有而s1中没有
// s2 --> s1 两者除去一样的剩下的就是不一样的 就只需要统计 负数的总和 或者 正数的总和 或者 绝对值之和 / 2 即可
// tips：再也不要用map<char, int>这种愚蠢至极的数据结构了，如果要统计字母出现的次数
// tips: 统计字母出现的次数 直接一个int cnt[26]  每遇到一个字母 cur 就让 cnt[cur - 'a']++

// tips: 统计两个字符串字母的不一样的个数 一个++ 一个--

// ?方法一: int a[3][2]={0};//所有数组元素均为0
// ?方法二: int a[3][2]={1,2,3,4,5,6};//常规的赋值方法
// ?方法三: int a[3][2]={{1,2},{3,4},{5,6}};//分行的赋...
// ?方法四: int a[3][2]={{1,2},{0},{3}};//部分赋值方法.
class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0}; //一维数组初始化
        for(auto p1 : s) cnt[p1 - 'a']++; //这种两个对象对称一个 + 一个 - 的思想真的很重要
        for(auto p2 : t) cnt[p2 - 'a']--;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(cnt[i] < 0) ans -= cnt[i]; else ans += cnt[i];
        }
        return ans / 2;
    }
};