def random(j, k, m):
    first_ten = [4, 5, 3, 3, 3, 4, 6, 2, 6, 5]

    def fib_mod_m(n):
        if n < 10:
            return first_ten[n] % m
        else:
            return (fib_mod_m(n-j) + fib_mod_m(n-k)) % m

    return fib_mod_m


if __name__ == '__main__':
    fib_mod = random(j=7, k=10, m=4)

    for i in range(30):
        print(str(i) + " - " + str(fib_mod(i)))