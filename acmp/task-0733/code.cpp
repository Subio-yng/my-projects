#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    const int INF = 1000001;
    int n;
    scanf("%d", &n);
    std::vector<int> sequence(n + 2, INF);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sequence[i]);
    }
    std::vector<int> st(1, 0);
    std::vector<int> listIdRightMax(n, -1);
    for (int i = 1; i <= n; i++) {
        while (sequence[st.back()] < sequence[i]) {
            listIdRightMax[st.back() - 1] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    std::vector<int> ans = {sequence[1]};
    int leftMax = sequence[1];
    for (int i = 2; i <= n; i++) {
        if (listIdRightMax[i - 1] == -1 || leftMax <= sequence[i]) {
            ans.push_back(sequence[i]);
            if (leftMax < sequence[i]) {
                leftMax = sequence[i];
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}