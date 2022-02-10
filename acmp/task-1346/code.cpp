#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len^3 * log(len))
// Space complexity: O(len^3)

struct Compress {

	int cnt;

	std::string s;

	Compress()
		: cnt(0)
		, s({}) 
	{}
};

std::string getPowStr(int exp, std::string str) {
	if (exp == 0) {
		return {};
	}
	std::string half = getPowStr(exp / 2, str);
	if (exp % 2 == 0) {
		return half + half;
	} else {
		return half + half + str;
	}
}

int main() {
	char buf[1 + 100];
	scanf("%s", &buf);
	std::string str(buf);
	int len = (int) str.length();
	std::vector<std::vector<Compress>> minPress(len, std::vector<Compress>(len));
	for (int iLen = 1; iLen <= len; iLen++) {
		for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
			int iRight = iLeft + iLen - 1;
			if (iLen == 1) {
				minPress[iLeft][iRight].s = str[iLeft];
				minPress[iLeft][iRight].cnt = 1;
			} else {
				std::string lastStr = str.substr(iLeft, iLen);
				std::string curStr;
				for (int lenPeriod = 1; lenPeriod < iLen; lenPeriod++) {
					curStr += str[iLeft + lenPeriod - 1];
					int curCnt = iLen / lenPeriod;
					if (iLen % lenPeriod == 0 && getPowStr(curCnt, curStr) == lastStr) {
						minPress[iLeft][iRight].cnt = curCnt;
						std::string temp = std::to_string(curCnt) + '(' + minPress[iLeft][iLeft + lenPeriod - 1].s + ')';
						if (temp.length() < lastStr.length()) {
							minPress[iLeft][iRight].s = temp;
						} else {
							minPress[iLeft][iRight].s = minPress[iLeft][iLeft + lenPeriod - 1].s + 
														minPress[iLeft + lenPeriod][iRight].s;
						}
						break;
					}
				}
				for (int iMid = iLeft + 1; iMid <= iRight; iMid++) {
					curStr = minPress[iLeft][iMid - 1].s + minPress[iMid][iRight].s;
					if (minPress[iLeft][iRight].s.length() == 0 ||
						curStr.length() < minPress[iLeft][iRight].s.length()
					) {
						minPress[iLeft][iRight].s = curStr;
						minPress[iLeft][iRight].cnt = 1;
					}
				}
			}
		}
	}
	printf("%s", minPress[0][len - 1].s.c_str());
	return 0;
}