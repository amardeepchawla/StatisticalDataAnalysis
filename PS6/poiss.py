import math 
from scipy.stats import norm

def poiss(n, b):
    x = 0
    for i in range(n+1):
        x += ((b**i)/math.factorial(i))*math.exp(-b)
    return (1-x)


def sig(p):
    print(norm.ppf(1-p))

p = 1-poiss(15,3.9)
print(p)

sig(p)
