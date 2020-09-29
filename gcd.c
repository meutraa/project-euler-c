int gcd(int a, int b)
{
    return (0 == (a %= b)) ? b : gcd(b, a);
}
