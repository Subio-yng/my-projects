#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len^4)
// Space complexity: O(len^3)

std::string getPowStr(int exp, std::string str) {
	if (exp == 0) {
		return "";
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
	std::vector<std::vector<std::string>> minPress(len, std::vector<std::string>(len, ""));
	for (int iLen = 1; iLen <= len; iLen++) {
		for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
			int iRight = iLeft + iLen - 1;
			if (iLen == 1) {
				minPress[iLeft][iRight] = str[iLeft];
			} else {
				std::string lastStr = str.substr(iLeft, iLen);
				std::string curStr;
				for (int lenPeriod = 1; lenPeriod < iLen; lenPeriod++) {
					curStr += str[iLeft + lenPeriod - 1];
					int curCnt = iLen / lenPeriod;
					if (iLen % lenPeriod == 0 && getPowStr(curCnt, curStr) == lastStr) {
						std::string temp = std::to_string(curCnt) + '(' + minPress[iLeft][iLeft + lenPeriod - 1] + ')';
						if (temp.length() < lastStr.length()) {
							minPress[iLeft][iRight] = temp;
						} else {
							minPress[iLeft][iRight] = minPress[iLeft][iLeft + lenPeriod - 1] + 
													  minPress[iLeft + lenPeriod][iRight];
						}
						break;
					}
				}
				for (int iMid = iLeft + 1; iMid <= iRight; iMid++) {
					curStr = minPress[iLeft][iMid - 1] + minPress[iMid][iRight];
					if (minPress[iLeft][iRight].length() == 0 ||
						curStr.length() < minPress[iLeft][iRight].length()
					) {
						minPress[iLeft][iRight] = curStr;
					}
				}
			}
		}
	}
	printf("%s", minPress[0][len - 1].c_str());
	return 0;
}