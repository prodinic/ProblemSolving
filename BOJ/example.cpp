s = 'AAAAaaaaBBBBbbbbCCCCccccDDSDDddddFFffKKKKkk'

int i, j;
string ans;
for (i = 0, i < s.size(); i++) {
    char from = s[i];
    char to = s[i + 1];
    int cnt = 0;
    while(from == to) {
        cnt++;
    }
    ans.push_back(from);
    ans.push_back(cnt);
}


A4a4B4b4C4c4D2S1D2d4F2f2K4k2