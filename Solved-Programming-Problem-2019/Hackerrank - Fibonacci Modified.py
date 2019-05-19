#Problem ID: HackerRank - Fibonacci Modified
#Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
#Date: 17/05/19
#Problem Link: https://www.hackerrank.com/challenges/fibonacci-modified/problem
arr = list(map(int, input().split()))
F = []
F.append(arr[0])
F.append(arr[1])
n = arr[2]

k = 2
while k < n:
    temp = F[k-1] * F[k-1] + F[k-2]
    F.append(temp)
    k = k + 1

print(F[n-1])
