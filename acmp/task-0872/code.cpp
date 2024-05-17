#include <bits/stdc++.h>

// Time complexity: O(nV * len * log(ALPHABET_SIZE))
// Space complexity: O(nV * len)

struct Vertex {

    int id;

    std::map<char, int> toV;

    bool isTerm;

    Vertex()
        : isTerm(false)
    {}

    Vertex(int id)
        : id(id)
        , isTerm(false)
    {}
};

int dfs(int curV, std::vector<bool> &visited, std::vector<Vertex> &trie) {
    visited[curV] = true;
    int cnt = 0;
    for (auto [nextC, nextV] : trie[curV].toV) {
        if (!visited[nextV]) {
            cnt = std::max(cnt, dfs(nextV, visited, trie));
        }
    }
    if (trie[curV].isTerm) {
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    char buf[1 + 255];
    std::vector<Vertex> trie(1);
    for (int i = 0; i < n; i++) {
        scanf(" %s", &buf);
        std::string str(buf);
        int curV = 0;
        for (char next : str) {
            if (trie[curV].toV.find(next) == trie[curV].toV.end()) {
                trie.emplace_back((int) trie.size());
                trie[curV].toV[next] = trie.back().id;
            }
            curV = trie[curV].toV[next];
        }
        trie[curV].isTerm = true;
    }
    std::vector<bool> visited(trie.size(), false);
    printf("%d", dfs(0, visited, trie));
    return 0;
}