https://codeforces.com/blog/entry/55782?#comment-395139

const int maxx=100005;
int trie[maxx][26], finish[maxx];
int nxt = 1;
void Add (string s){
    int node = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if(trie[node][s[i] - 'a'] == 0) {
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        } else {
            node = trie[node][s[i] - 'a'];
        }
    }
    finish[node - 1] = 1;
}

int Find (string s) {
    int idx = 0;
    int sz=s.size();
    for (int i = 0; i < sz; i++)
        if (trie[idx][s[i] - 'a'] == 0)
            return 0;
        else
            idx = trie[idx][s[i] - 'a'];
    return finish[idx];
}
