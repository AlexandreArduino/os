def square(x): return x**2

def SquareRoot(n):
    if n <= 0: return 0
    else:
        p = 0
        while(square(p) < n): p += 0.001
        return p