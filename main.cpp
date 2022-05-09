#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <map>

#define standard_start 96
#define standard_set 27

#define extension_start 33
#define extension_set 94

using namespace std;

long long encode(long long e, long long n, long long m);
long long decode(long long d, long long n, long long c);
string encodetext(long long e, long long n, string m);
string decodetext(long long e, long long p, long long q, string c);
long long df(long long pq, long long e);
long long gcp(long long s, long long t);
long long txt2dec(string text);
string dec2txt(long long decimal);
vector<string> split(string text);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        long long p, q, e, m;
        cout << "p: ";
        cin >> p;
        cout << "q: ";
        cin >> q;
        cout << "e: ";
        cin >> e;
        cout << "m: ";
        cin >> m;
        long long d = df((p - 1) * (q - 1), e);
        long long c = encode(e, p * q, m);
        cout << "c: " << c << endl;
        cout << "d: " << d << endl;
        cout << "m: " << decode(d, p * q, c) << endl;
    }
    else
    {
        string type, arg = argv[1];
        map<string, long long> params;
        if (argc >= 3)
        {
            type = argv[2];
        }
        for (int i = 0; i < argc; i++)
        {
            string val = argv[i];
            if (val[2] == '=')
            {
                params[val.substr(1, 1)] = atoll(val.substr(3).c_str());
            }
        }
        if (arg == "keygen")
        {
            vector<long long> primes{1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919, 7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017, 8039, 8053, 8059, 8069, 8081, 8087, 8089, 8093, 8101, 8111, 8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219, 8221, 8231, 8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291, 8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 8387, 8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501, 8513, 8521, 8527, 8537, 8539, 8543, 8563, 8573, 8581, 8597, 8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677, 8681, 8689, 8693, 8699, 8707, 8713, 8719, 8731, 8737, 8741, 8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831, 8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929, 8933, 8941, 8951, 8963, 8969, 8971, 8999, 9001, 9007, 9011, 9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109, 9127, 9133, 9137, 9151, 9157, 9161, 9173, 9181, 9187, 9199, 9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283, 9293, 9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377, 9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 9437, 9439, 9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533, 9539, 9547, 9551, 9587, 9601, 9613, 9619, 9623, 9629, 9631, 9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733, 9739, 9743, 9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811, 9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 9887, 9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973};
            std::random_device seed_gen;
            std::mt19937_64 engine(seed_gen());
            long long p = primes[engine() % 1060];
            long long q = primes[engine() % 1060];
            while (p * q < 14348907)
            {
                p = primes[engine() % 1060];
                q = primes[engine() % 1060];
            }
            long long e = engine() % 1000;
            while (gcp((p - 1) * (q - 1), e) != 1)
            {
                e = engine() % 1000;
            }
            cout << "e=" << e << endl;
            cout << "p=" << p << endl;
            cout << "q=" << q << endl;
            cout << "n=" << p * q << endl;
        }
        else if (arg == "encode")
        {
            if (type == "-text")
            {
                vector<string> keys{"e", "n"};
                for (int i = 0; i < keys.size(); i++)
                {
                    if (params.find(keys[i]) == params.end())
                    {
                        cout << keys[i] << ": ";
                        cin >> params[keys[i]];
                    }
                }
                string m;
                cout << "mt: ";
                cin >> m;
                // cout << "m: " << txt2dec(m) << endl;
                cout << "ct: " << encodetext(params["e"], params["n"], m) << endl;
                // cout << "c: " << encode(e, n, txt2dec(m)) << endl;
            }
            else
            {
                vector<string> keys{"e", "n", "m"};
                for (int i = 0; i < keys.size(); i++)
                {
                    if (params.find(keys[i]) == params.end())
                    {
                        cout << keys[i] << ": ";
                        cin >> params[keys[i]];
                    }
                }
                cout << "c: " << encode(params["e"], params["n"], params["m"]) << endl;
            }
        }
        else if (arg == "decode")
        {
            if (type == "-text")
            {
                vector<string> keys{"e", "p", "q"};
                for (int i = 0; i < keys.size(); i++)
                {
                    if (params.find(keys[i]) == params.end())
                    {
                        cout << keys[i] << ": ";
                        cin >> params[keys[i]];
                    }
                }
                string c;
                cout << "ct: ";
                cin >> c;
                // cout << "c: " << h1ep2dec(c) << endl;
                cout << "mt: " << decodetext(params["e"], params["p"], params["q"], c) << endl;
                // cout << "m: " << decode(df((p - 1) * (q - 1), e), p * q, txt2dec(c)) << endl;
            }
            else
            {
                vector<string> keys{"p", "q", "e", "c"};
                for (int i = 0; i < keys.size(); i++)
                {
                    if (params.find(keys[i]) == params.end())
                    {
                        cout << keys[i] << ": ";
                        cin >> params[keys[i]];
                    }
                }
                cout << "m: " << decode(df((params["p"] - 1) * (params["q"] - 1), params["e"]), params["p"] * params["q"], params["c"]) << endl;
            }
        }
    }
    return 0;
}

vector<string> split(string text)
{
    vector<string> result;
    for (int i = 0; i <= text.size() - 1; i += 4)
    {
        string block = text.substr(i, min((unsigned long)4, text.size() - i));
        result.push_back(block);
        // if (block[0] == 'a')
        // {
        //     result = {};
        //     string fixed = "a" + text;
        //     for (int i = 0; i <= fixed.size() - 1; i += 4)
        //     {
        //         string block = fixed.substr(i, min((unsigned long)4, fixed.size() - i));
        //         result.push_back(block);
        //     }
        // }
    }
    return result;
}

string encodetext(long long e, long long n, string m)
{
    vector<string> messages = split(m);
    string result = "";
    for (int i = 0; i < messages.size(); i++)
    {
        string block = dec2txt(encode(e, n, txt2dec(messages[i])));
        result += dec2txt(block.size());
        result += block;
    }
    return result;
}

string decodetext(long long e, long long p, long long q, string c)
{
    string text = c;
    string m = "";
    while (text != "")
    {
        int size = text[0] - extension_start;
        string block = text.substr(1, size);
        m += dec2txt(decode(df((p - 1) * (q - 1), e), p * q, txt2dec(block)));
        text.erase(0, size + 1);
    }
    return m;
}

long long txt2dec(string text)
{
    long long result = 0;
    vector<int> decs;
    for (int i = 0; i < text.size(); i++)
    {
        char digit = text[i];
        int ascii = (int)digit - extension_start;
        decs.push_back(ascii);
    }
    for (int i = 0; i < decs.size(); i++)
    {
        result *= extension_set;
        result += decs[i];
    }
    return result;
}

string dec2txt(long long decimal)
{
    long long orig = decimal;
    vector<int> decs;
    while (orig != 0)
    {
        decs.push_back(orig % extension_set);
        orig /= extension_set;
    }
    char txts[decs.size()];
    for (int i = 1; i <= decs.size(); i++)
    {
        txts[decs.size() - i] = decs[i - 1] + extension_start;
    }
    string result(txts, decs.size());
    return result;
}

long long df(long long p1q1, long long e)
{
    long long a = e;
    long long b = p1q1;
    vector<long long> rs{1, b / a};
    long long r, c;
    r = b % a;
    b = a;
    a = r;
    for (int i = 2; b % a != 0; i++)
    {
        rs.push_back(rs[i - 2] + b / a * rs[i - 1]);
        r = b % a;
        b = a;
        a = r;
    }
    c = rs[rs.size() - 1];
    if ((c * e) % p1q1 != 1)
    {
        c = p1q1 - c;
    }
    return c;
}

long long gcp(long long s, long long t)
{
    long long a = s;
    long long b = t;
    while (true)
    {
        if (a == b)
        {
            return a;
        }
        a > b ? a -= b : b -= a;
    }
}

long long encode(long long e, long long n, long long m)
{
    vector<long long> e_binary;
    long long e_tmp = e;
    vector<long long> m_mods;
    long long me_mod = 0;
    while (e_tmp != 0)
    {
        e_binary.push_back((e_tmp % 2 == 0) ? false : true);
        e_tmp /= 2;
    }
    m_mods.push_back(m % n);
    for (long long i = 1; i < e_binary.size(); i++)
    {
        m_mods.push_back((m_mods[i - 1] * m_mods[i - 1]) % n);
    }
    for (long long i = 0; me_mod == 0; i++)
    {
        if (e_binary[i])
        {
            me_mod = m_mods[i];
        }
    }
    for (long long i = 1; i < e_binary.size(); i++)
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

long long decode(long long d, long long n, long long c)
{
    vector<long long> d_binary;
    long long d_tmp = d;
    vector<long long> c_mods;
    long long cd_mod = 0;
    while (d_tmp != 0)
    {
        d_binary.push_back((d_tmp % 2 == 0) ? false : true);
        d_tmp /= 2;
    }
    c_mods.push_back(c % n);
    for (long long i = 1; i < d_binary.size(); i++)
    {
        c_mods.push_back((c_mods[i - 1] * c_mods[i - 1]) % n);
    }
    for (long long i = 0; cd_mod == 0; i++)
    {
        if (d_binary[i])
        {
            cd_mod = c_mods[i];
        }
    }
    for (long long i = 1; i < d_binary.size(); i++)
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