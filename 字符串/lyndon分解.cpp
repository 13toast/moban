/*
若字符串s的字典序严格小于s的所有后缀的字典序，称s是简单串
a,b,aab,abb,ababb
串s的Lyndon分解记为s=w1w2...wk,其中所有wi为简单串，
并且他们的字典序按照非严格单减排序，即w1>=w2>=wk。
可以发现，这样的分解存在且唯一。
*/
vector<string> duval(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}