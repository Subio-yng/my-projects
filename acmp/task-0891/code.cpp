#include <stdio.h>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <map>

const short EDGES = 6;
const std::vector<char> ORDER = {'F', 'L', 'B', 'R', 'U', 'D'};
std::vector<short> NEXT_E = {0, 1, 2, 3, 4, 5};

struct Cube {
	// front
	char f1L, f1R, f2L, f2R;
	// left
	char l1L, l1R, l2L, l2R;
	// back
	char b1L, b1R, b2L, b2R;
	// right
	char r1L, r1R, r2L, r2R;
	// up
	char u1L, u1R, u2L, u2R;
	// down
	char d1L, d1R, d2L, d2R;

	static Cube read() {
		char f1L, f1R, f2L, f2R;
		char l1L, l1R, l2L, l2R;
		char b1L, b1R, b2L, b2R;
		char r1L, r1R, r2L, r2R;
		char u1L, u1R, u2L, u2R;
		char d1L, d1R, d2L, d2R;
		scanf(" %c%c", &f1L, &f1R);
		scanf(" %c%c", &l1L, &l1R);
		scanf(" %c%c", &b1L, &b1R);
		scanf(" %c%c", &r1L, &r1R);
		scanf(" %c%c", &u1L, &u1R);
		scanf(" %c%c", &d1L, &d1R);
		scanf(" %c%c", &f2L, &f2R);
		scanf(" %c%c", &l2L, &l2R);
		scanf(" %c%c", &b2L, &b2R);
		scanf(" %c%c", &r2L, &r2R);
		scanf(" %c%c", &u2L, &u2R);
		scanf(" %c%c", &d2L, &d2R);
		return {f1L, f1R, f2L, f2R,
				l1L, l1R, l2L, l2R,
				b1L, b1R, b2L, b2R,
				r1L, r1R, r2L, r2R,
				u1L, u1R, u2L, u2R,
				d1L, d1R, d2L, d2R};
	}

	bool operator ==(const Cube &a) const {
		return f1L == a.f1L && f2L == a.f2L &&
			l1L == a.l1L && l2L == a.l2L &&
			b1L == a.b1L && b2L == a.b2L &&
			r1L == a.r1L && r2L == a.r2L &&
			u1L == a.u1L && u2L == a.u2L &&
			d1L == a.d1L && d2L == a.d2L;
	}

	bool operator <(const Cube &a) const {
		if (f1L != a.f1L) {
			return f1L < a.f1L;
		}
		if (f1R != a.f1R) {
			return f1R < a.f1R;
		}
		if (f2L != a.f2L) {
			return f2L < a.f2L;
		}
		if (f2R != a.f2R) {
			return f2R < a.f2R;
		}
		if (l1L != a.l1L) {
			return l1L < a.l1L;
		}
		if (l1R != a.l1R) {
			return l1R < a.l1R;
		}
		if (l2L != a.l2L) {
			return l2L < a.l2L;
		}
		if (l2R != a.l2R) {
			return l2R < a.l2R;
		}
		if (b1L != a.b1L) {
			return b1L < a.b1L;
		}
		if (b1R != a.b1R) {
			return b1R < a.b1R;
		}
		if (b2L != a.b2L) {
			return b2L < a.b2L;
		}
		if (b2R != a.b2R) {
			return b2R < a.b2R;
		}
		if (r1L != a.r1L) {
			return r1L < a.r1L;
		}
		if (r1R != a.r1R) {
			return r1R < a.r1R;
		}
		if (r2L != a.r2L) {
			return r2L < a.r2L;
		}
		if (r2R != a.r2R) {
			return r2R < a.r2R;
		}
		if (u1L != a.u1L) {
			return u1L < a.u1L;
		}
		if (u1R != a.u1R) {
			return u1R < a.u1R;
		}
		if (u2L != a.u2L) {
			return u2L < a.u2L;
		}
		if (u2R != a.u2R) {
			return u2R < a.u2R;
		}
		if (d1L != a.d1L) {
			return d1L < a.d1L;
		}
		if (d1R != a.d1R) {
			return d1R < a.d1R;
		}
		if (d2L != a.d2L) {
			return d2L < a.d2L;
		}
		return d2R < a.d2R;
	}

	bool isSolved() const {
		return f1L == f1R && f1L == f2L && f1L == f2R &&
			l1L == l1R && l1L == l2L && l1L == l2R &&
			b1L == b1R && b1L == b2L && b1L == b2R &&
			r1L == r1R && r1L == r2L && r1L == r2R &&
			u1L == u1R && u1L == u2L && u1L == u2R &&
			d1L == d1R && d1L == d2L && d1L == d2R;
	}

	void turn(short e) {
		if (e == 0) {
			char curF1L = f1L;
			f1L = f2L;
			f2L = f2R;
			f2R = f1R;
			f1R = curF1L;
			char curL1R = l1R, curL2R = l2R;
			l1R = d1L, l2R = d1R;
			d1L = r2L, d1R = r1L;
			r1L = u2L, r2L = u2R;
			u2L = curL2R, u2R = curL1R;
		} else if (e == 1) {
			char curL1L = l1L;
			l1L = l2L;
			l2L = l2R;
			l2R = l1R;
			l1R = curL1L;
			char curB1R = b1R, curB2R = b2R;
			b1R = d2L, b2R = d1L;
			d2L = f2L, d1L = f1L;
			f2L = u2L, f1L = u1L;
			u2L = curB1R, u1L = curB2R;
		} else if (e == 2) {
			char curB1L = b1L;
			b1L = b2L;
			b2L = b2R;
			b2R = b1R;
			b1R = curB1L;
			char curR1R = r1R, curR2R = r2R;
			r1R = d2R, r2R = d2L;
			d2R = l2L, d2L = l1L;
			l2L = u1L, l1L = u1R;
			u1L = curR1R, u1R = curR2R;
		} else if (e == 3) {
			char curR1L = r1L;
			r1L = r2L;
			r2L = r2R;
			r2R = r1R;
			r1R = curR1L;
			char curF1R = f1R, curF2R = f2R;
			f2R = d2R, f1R = d1R;
			d1R = b2L, d2R = b1L;
			b1L = u2R, b2L = u1R;
			u2R = curF2R, u1R = curF1R;
		} else if (e == 4) {
			char curU1L = u1L;
			u1L = u2L;
			u2L = u2R;
			u2R = u1R;
			u1R = curU1L;
			char curL1L = l1L, curL1R = l1R;
			l1L = f1L, l1R = f1R;
			f1L = r1L, f1R = r1R;
			r1L = b1L, r1R = b1R;
			b1R = curL1R, b1L = curL1L;
		} else {
			char curD1L = d1L;
			d1L = d2L;
			d2L = d2R;
			d2R = d1R;
			d1R = curD1L;
			char curL2R = l2R, curL2L = l2L;
			l2R = b2R, l2L = b2L;
			b2R = r2R, b2L = r2L;
			r2R = f2R, r2L = f2L;
			f2L = curL2L, f2R = curL2R;
		}
	}
};

struct Prev {

	short ops;

	bool reverse;
};

void printWay(Cube &start, const Cube &end, std::map<Cube, Prev> &from) {
	if (start == end) {
		return;
	}
	Prev &cur = from[start];
	if (cur.reverse) {
		start.turn(cur.ops);
	} else {
		start.turn(cur.ops);
		start.turn(cur.ops);
		start.turn(cur.ops);
	}
	printWay(start, end, from);
	printf("%c", ORDER[cur.ops]);
	if (cur.reverse) {
		printf("'");
	}
}

void bfs(const Cube &start) {
	if (start.isSolved()) {
		printf("Solved");
		return;
	}
	std::map<Cube, Prev> from;
	std::queue<Cube> inProcess;
	inProcess.push(start);
	Cube cur = inProcess.front();
	std::random_device rd;
	std::mt19937 gen(rd());
	while (!inProcess.empty()) {
		std::swap(cur, inProcess.front());
		inProcess.pop();
		if (cur.isSolved()) {
			printWay(cur, start, from);
			return;
		}
		std::shuffle(NEXT_E.begin(), NEXT_E.end(), gen);
		Cube next = cur;
		for (short e : NEXT_E) {
			for (short i = 0; i < 2; i++) {
				next.turn(e);
				if (from.find(next) == from.end()) {
					from[next] = {e, i == 1};
					inProcess.push(next);
				}
				next.turn(e);
			}
		}
	}
	throw 1;
}

int main() {
	Cube start = Cube::read();
	bfs(start);
	return 0;
}