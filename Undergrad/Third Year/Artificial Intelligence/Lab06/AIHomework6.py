import math

# Plata unei sume de bani folosind numar minim de bancnote
# Input: suma, nr_bancnote, b1... bnr_bancnote
# Output: nr_minim bancnote

def greedy(C, n):
    N = [0]*(len(C))

    if n == 0: 
        return N

    N[1] = math.inf

    for i in range(0, len(C)):
        if n >= C[i]:

            # 90
            subprob = greedyman(C, n - C[i])

            # 87 + 3
            if sum(subprob) + 1 < sum(N):
                N = subprob
                N[i] = N[i] + 1

    return N
#print(greedy([10, 5, 1], 26))
#N = [2, 1, 1]

def DPCoinchange(C, n):
    N = [[0 for x in range(len(C))] for x in range(n + 1)]

    for m in range(1, n + 1):
        N[m][0] = math.inf
        for i in range(0, len(C)):
            if m >= C[i]:
                if sum(N[m - C[i]]) + 1 < sum(N[m]):
                    print(N[m])
                    N[m] = N[m - C[i]]
                    N[m][i] = N[m][i] + 1
    return N[n]
#print(DPCoinchange([1, 5, 10], 26))
#N = [2, 1, 1]

def coinChangeBKT(C, n):

    minCoins = [0] * (n + 1)
    bestChoice = [0] * (n + 1)
    bestChoice[0] = -1
     
    for m in range(1, n + 1):

        minCoins[0] = math.inf;

        for i in range(0, len(C)):
            if m >= C[i]:
                if minCoins[m - C[i]] + 1 < minCoins[m]:
                    minCoins[m] = minCoins[m - C[i]] + 1
                    bestChoice[m] = i

    C.sort(reverse = True)

    N = [0] * (len(C))
    while n > 0:
        N[bestChoice[n]] = N[bestChoice[n]] + 1

        for index, element in enumerate(C):
            if element <= n:
                n = n - C[index]
                break

    return N[0]

print(coinChangeBKT([10, 5, 1], 27))
N = [2, 1, 2]


import sys
def coinChangeBKT2(C,n):
    minCoins = [0]*(n+1) # vector de lungime n+1 (cazul cel mai nefavorabil)
    bestChoice = [0]*(n+1) # vector de lung n+1 ( retine cele mai bune alegeri ale bacnotelor)

    minCoins[0] = 0
    bestChoice[0] = -1

    print(minCoins)
    print(bestChoice)

    N = [0]*(len(C)) # vector de aceeasi lungime ca C, imi retine de cate ori am folosit acea bacnota
    print(N)

    C.sort(reverse=True)

    while n > 0:
        N[bestChoice[n]] = N[bestChoice[n]] + 1

        for index, element in enumerate(C):
            if element <= n:
                n = n - C[index]
                break

    return N[0]

print(coinChangeBKT2([10, 5, 1, 2], 27)) 
