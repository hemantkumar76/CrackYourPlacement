class Solution {
 public:
  string addBinary(string a, string b) {
    string ans_hoga = "";
    int carry_karega = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry_karega) {
      if (i >= 0)
        carry_karega += a[i--] - '0';
      if (j >= 0)
        carry_karega += b[j--] - '0';
      ans_hoga += carry_karega % 2 + '0';
      carry_karega /= 2;
    }

    reverse(begin(ans_hoga), end(ans_hoga));
    return ans_hoga;
  }
};
