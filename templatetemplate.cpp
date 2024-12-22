//! 1. GRID ITERATION

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string ds = "RLDU";

int n, m;
bool possible(int x, int y) {
  // cout<<n<<" "<<m<<" "<<x<<" "<<y<<" possible"<<endl;

  return (x < n && x >= 0 && y < m && y >= 0);
}

//! 2. Rolling Hash
class HashedString {
private:
  // change M and B if you want
  static const long long M = 1e9 + 9;
  static const long long B = 9973;

  // pow[i] contains B^i % M
  static vector<long long> pow;

  // p_hash[i] is the hash of the first i characters of the given string
  vector<long long> p_hash;

public:
  HashedString(const string &s) : p_hash(s.size() + 1) {
    while (pow.size() <= s.size()) {
      pow.push_back((pow.back() * B) % M);
    }

    p_hash[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
    }
  }

  long long get_hash(int start, int end) {
    long long raw_val =
        (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
    return (raw_val % M + M) % M;
  }
};
vector<long long> HashedString::pow = {1};
//* usage : HashedString hs(h);

//! 3. Modulus
int mod_inv(int n, int m) { return power(n, m - 2, m); }
int mod_add(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mod_inv(b, m), m));
}

//! 4. Rolling hash (CodenCode)

int getHash(string s) {
  int val = 0;
  int mod = 1e9 + 7;
  int p = 9973;
  int power = 1;
  // hash( "coding") = c •p^0 + 0• p^l+ d • p^2 +
  for (auto i : s) {
    val = (val + (i - 'a' + 1) * power) % mod;
    power = (power * p) % mod;
  }
  return val;
}

//! 5. Custom Hash
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
// Usage:
// unordered_map<int, int, custom_hash> safe_map;