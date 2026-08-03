class Solution {
public:
        bool tr;

    void cal(string &s1, string &s2, string &s3, int n, int m, int k) {

        if (tr) return;   

        if (n < 0 && m < 0 && k < 0) {
            tr = true;
            return;
        }

        if (n < 0) {
            while (m >= 0 && k >= 0) {
                if (s2[m] != s3[k]) {
                    tr = false;
                    return;
                }
                m--;
                k--;
            }
            tr = (m < 0 && k < 0);
            return;
        }

        if (m < 0) {
            while (n >= 0 && k >= 0) {
                if (s1[n] != s3[k]) {
                    tr = false;
                    return;
                }
                n--;
                k--;
            }
            tr = (n < 0 && k < 0);
            return;
        }

        if (s1[n] == s3[k])
            cal(s1, s2, s3, n - 1, m, k - 1);

        if (s2[m] == s3[k])
            cal(s1, s2, s3, n, m - 1, k - 1);
    }
    bool isInterleave(string s1, string s2, string s3) {
       if (s1.size() + s2.size() != s3.size())
            return false;

        tr = false;
        cal(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() - 1);

        return tr;
    }
};
