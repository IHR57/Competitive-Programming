import sys

fact = []
fact.append(1)
for i in range(1, 101, 1):
    fact.append(i * fact[i-1])

for _input in sys.stdin:
    line = str(_input.split()[0])
    freq = {}
    for i in line:
        if ord(i) in freq:
            freq[ord(i)] += 1
        else:
            freq[ord(i)] = 1
    ans = fact[len(line)]
    for i in freq:
        ans = ans // fact[freq[i]]
    print(ans)
            