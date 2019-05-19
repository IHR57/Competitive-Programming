#Problem ID: HackerRank - Stock Maximize
#Programmer: IQBAL HOSSAIN      Description: Dynamic Programming
#Date: 18/05/19
#Problem Link: https://www.hackerrank.com/challenges/stockmax/problem
import math
import os
import random
import re
import sys

def stockmax(prices):
    n = len(prices)
    last = prices[n-1]
    cnt = 0
    Sum = 0
    res = 0
    for i in range(n - 2, -1, -1):
        if prices[i] <= last:
            cnt += 1
            Sum += prices[i]
        else:
            res += (last * cnt) - Sum;
            last = prices[i]
            Sum = 0
            cnt = 0
    if prices[0] <= last:
        res += (last * cnt) - Sum;

    return res


t = int(input())

for t_itr in range(t):
    n = int(input())

    prices = list(map(int, input().rstrip().split()))

    result = stockmax(prices)
    print(result)


