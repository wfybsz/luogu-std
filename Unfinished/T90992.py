import math

lm = 2
ms = 0
ss = 0
nlm = 0
nms = 0
nss = 0
mod = 19260817
n = int(input())
if n == 0:
    print(0)
else:
    for i in range(1,n):
        nlm = lm
        nms = lm + ms
        nss = ms + ss + ss
        lm = nlm
        ms = nms
        ss = nss
    print(ss % mod)
