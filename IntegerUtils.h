

namespace IntegerUtils {

	auto gcd(auto a, auto b) {
		if (a < 0 or b < 0) {
			cerr << "GCDError" << endl;
			exit(0);
		}
		auto c = a;
		while (b > 0) {
			c = a;
			a = b;
			b = c % b;
		}
		return a;
	}

	auto reverse(auto n) {
		auto r = n;
		r = 0;
		while (n > 0) {
			r = (r * 10) + (n % 10);
			n /= 10;
		}
		return r;
	}

	int length(auto n) {
		if (n == 0) {
			return 1;
		}
		int r = 0;
		while (n > 0) {
			++r;
			n /= 10;
		}
		return r;
	}

	auto concatenate(int x, int y) {
		return x * ten[length(y)] + y;
	}

	int sumOfDigits(int n) {
		int s = 0;
		while (n > 0) {
			s += (n % 10);
			n /= 10;
		}
		return s;
	}

}

