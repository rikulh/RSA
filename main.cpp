#include <string>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

long decode(long e, long n, long m);
long encode(long d, long n, long c);
long df(long p, long q, long e);
long gcp(long s, long t);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        long p, q, e, m;
        cout << "p: ";
        cin >> p;
        cout << "q: ";
        cin >> q;
        cout << "e: ";
        cin >> e;
        cout << "m: ";
        cin >> m;
        long d = df(p, q, e);
        long c = decode(e, p * q, m);
        cout << "c: " << c << endl;
        cout << "d: " << d << endl;
        cout << "m: " << encode(d, p * q, c) << endl;
    }
    else
    {
        string arg = argv[1];
        if (arg == "--keygen")
        {
            vector<long> primes{101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
            std::random_device seed_gen;
            std::mt19937_64 engine(seed_gen());
            long p = primes[engine() % primes.size()];
            long q = primes[engine() % primes.size()];
            long e = engine() % 1000;
            while (gcp((p - 1) * (q - 1), e) != 1)
            {
                e = engine() % 1000;
            }
            cout << "p: " << p << endl;
            cout << "q: " << q << endl;
            cout << "e: " << e << endl;
            cout << "n: " << p * q << endl;
        }
        else if (arg == "--decode")
        {
            long n, e;
            char* m;
            cout << "e: ";
            cin >> e;
            cout << "n: ";
            cin >> n;
            cout << "m: ";
            cin >> m;
            long c = decode(e, n, (int)m);
            cout << "c: " << c << endl;
        }
        else if (arg == "--encode")
        {
            long p, q, e, c;
            cout << "p: ";
            cin >> p;
            cout << "q: ";
            cin >> q;
            cout << "e: ";
            cin >> e;
            cout << "c: ";
            cin >> c;
            long m = encode(df(p, q, e), p * q, c);
            cout << "m: " << m << endl;
        }
    }
    return 0;
}

long df(long p, long q, long e)
{
    long a = e;
    long b = (p - 1) * (q - 1);
    vector<long> rs{1,b/a};
	long r,c;
	r = b % a;
	b = a;
	a = r;
	for (int i = 2;b % a != 0;i++) {
		rs.push_back(rs[i-2] + b / a * rs[i-1]);
		r = b % a;
		b = a;
		a = r;
	}
	c = rs[rs.size() - 1];
	if (c % (p - 1) * (q - 1) != 1) {
		c = (p - 1) * (q - 1) - c;
	}
	return c;
}

long gcp(long s, long t)
{
    long a = s;
    long b = t;
    while (true)
    {
        if (a == b)
        {
            return a;
        }
        a > b ? a -= b : b -= a;
    }
}

long decode(long e, long n, long m)
{
    vector<long> e_binary;
    long e_tmp = e;
    vector<long> m_mods;
    long me_mod = 0;
    while (e_tmp != 0)
    {
        e_binary.push_back((e_tmp % 2 == 0) ? false : true);
        e_tmp /= 2;
    }
    m_mods.push_back(m % n);
    for (long i = 1; i < e_binary.size(); i++)
    {
        m_mods.push_back((m_mods[i - 1] * m_mods[i - 1]) % n);
    }
    for (long i = 0; me_mod == 0; i++)
    {
        if (e_binary[i])
        {
            me_mod = m_mods[i];
        }
    }
    for (long i = 1; i < e_binary.size(); i++)
    {
        if (e_binary[i])
        {
            me_mod = (me_mod * m_mods[i]) % n;
        }
    }
    if (me_mod < 0)
    {
        me_mod += n;
    }
    return me_mod;
}

long encode(long d, long n, long c)
{
    vector<long> d_binary;
    long d_tmp = d;
    vector<long> c_mods;
    long cd_mod = 0;
    while (d_tmp != 0)
    {
        d_binary.push_back((d_tmp % 2 == 0) ? false : true);
        d_tmp /= 2;
    }
    c_mods.push_back(c % n);
    for (long i = 1; i < d_binary.size(); i++)
    {
        c_mods.push_back((c_mods[i - 1] * c_mods[i - 1]) % n);
    }
    for (long i = 0; cd_mod == 0; i++)
    {
        if (d_binary[i])
        {
            cd_mod = c_mods[i];
        }
    }
    for (long i = 1; i < d_binary.size(); i++)
    {
        if (d_binary[i])
        {
            cd_mod = (cd_mod * c_mods[i]) % n;
        }
    }
    if (cd_mod < 0)
    {
        cd_mod += n;
    }
    return cd_mod;
}