# lcm.py - Project Euler problem 5, find LCM of factors 2-20
# Blake Mitchell, 2011


def isprime(n):
        if n < 2:
                return False
        i = 2 
        while i <= n // i:
                if n / i == float(n // i):
                        return False
                i += 1
        return True


def pdict_hit(pd, n):
        try:
                pd[n] += 1
        except KeyError:
                pd[n] = 1


def pdict_hit_greatest(pd, n, c):
        try:
                if (c > pd[n]):
                        pd[n] = c
        except KeyError:
                pd[n] = c


def pdict_product(pd):
        prod = 1
        for prime, count in pd.items():
                prod = prod * prime**count
        return prod


def primefac(n):
        pdict = {}
        if (isprime(n)):
                pdict_hit(pdict, n)
        else:
                i = 2
                while i <= n:
                        if isprime(i) and n / i == float(n // i):
                                pdict_hit(pdict, i)
                                n = n // i
                                i = 2
                        else:
                                i += 1
        return pdict


def make_lcm_primefac(pdlist):
        lcmpdict = {}
        for pdict in pdlist:
                for prime, count in pdict.items():
                        pdict_hit_greatest(lcmpdict, prime, count)
        return lcmpdict


def lcmrange(i):
        pdlist = [primefac(x) for x in range(2, i+1)]
        pdict = make_lcm_primefac(pdlist)
        return pdict_product(pdict)


if __name__ == '__main__':
        print('LCM of all factors between 2 and 20: ' + str(lcmrange(20)))
