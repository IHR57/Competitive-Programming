#Problem ID: HackerRank - Red John is Back
#Programmer: IQBAL HOSSAIN      Description: Dynamic Programming
#Date: 18/05/19
#Problem Link: https://www.hackerrank.com/challenges/red-john-is-back/problem
import math
import os
import random
import re
import sys

def genSieve(n):
    lim = math.sqrt(300005)
    mark = [0] * 300005
    mark[1] = 1
    for i in range(4, 300005, 2):
        mark[i] = 1
    cnt = 0
    if 2 <= n:
        cnt += 1;

    for i in range(3, 300005, 2):
        if mark[i] == 0:
            if i <= n:
                cnt += 1
            if i <= lim:
                for j in range(i * i, 300005, i * 2):
                    mark[j] = 1
    return cnt;

def redJohn(n):
    dp = []
    for i in range(4):
        dp.append(1)
    dp.append(2)
    i = 5
    while i <= n:
        dp.append(dp[i-1] + dp[i-4])
        i += 1

    return genSieve(dp[n])


t = int(input())

for t_itr in range(t):
    n = int(input())

    result = redJohn(n)
    print(result)


