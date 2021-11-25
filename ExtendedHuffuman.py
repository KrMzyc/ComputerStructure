#!usr/bin/env python
# -*- coding: utf-8 -*-


def fun():
    Q = x  # 通过队列进行处理
    while len(Q) > 1:
        Q.sort(key=lambda xx: xx.prob)  # 根据使用频度排序
        # for i in Q:
        #     print i.prob
        l = Q.pop(0)
        r = Q.pop(0)
        if l.name is not None:
            newQ.append(l)
        if r.name is not None:
            newQ.append(r)
        # 左1右0左小右大
        l.codeword = '0'
        r.codeword = '1'

        fa = hafnode(prob=l.prob + r.prob)
        fa.l = l
        fa.r = r
        l.fa = fa
        r.fa = fa
        Q.append(fa)

    Q[0].fa = None
    return Q[0]


def hufdeal():
    root = fun()
    pro = []
    codes = [''] * len(newQ)
    symbol = []

    for i in range(len(newQ)):
        tmp = newQ[i]
        while tmp.fa != None:
            codes[i] = tmp.codeword + codes[i]
            tmp = tmp.fa
        newQ[i].codeword = codes[i]


class hafnode():
    def __init__(self, name=None, prob=None, codeword='', procode=None):
        self.name = name
        self.prob = prob
        self.codeword = codeword
        self.procode = procode
        self.fa = None
        self.l = None
        self.codeword = None


# ----------------------------------哈夫曼编码-----------------------------------------------------
class dengchang():
    def __init__(self, name=None, prob=None, codeword=''):
        self.name = name
        self.prob = prob
        self.codewode = codeword


def dcdeal():
    n = 0
    for i in range(1, 10):
        if 2 ** i >= len(y):
            n = i
            break
    for i in range(len(y)):
        y[i].codeword = str(bin(i))[2:].zfill(n)
        print (y[i].codeword)


# ------------------------------------等长编码-----------------------------------


def extend(n):
    # x = input("请输入需要几种编码长度？")
    # len = []
    # for i in range(0,10):
    #    len[i] = (2**i)-1
    m = int(input("输入编码的最短长度："))
    M = int(input("输入编码的最长长度："))
    print('扩展编码的结果是：\n')
    z.sort(key=lambda xx: xx.prob, reverse=True)
    cnt = 0

    for i in range(len(z)):
        if cnt == 7:
            break
        if i <= len(z) - 2:
            tmp = float(z[i].prob) / float(z[i + 1].prob)
            if int(tmp * 1000000 + M) >= int(m * 1000000):
                break
        cnt += 1
    cnt += 1
    for i in range(cnt):
        z[i].codeword = str(bin(i))[2:].zfill(m)
        print (z[i].codeword)
    for i in range(cnt, len(z)):
        z[i].codeword = str(bin(i - cnt))[2:].rjust(m, '0').rjust(M, '1')
        print (z[i].codeword)


x = []
y = []
z = []
newQ = []  # 保存使用过的节点


def main():
    n = int(input("请输入个数："))
    for i in range(n):
        rate = input("请输入第%d的频率:" % i)
        x.append(hafnode(i, rate, ''))
        y.append(dengchang(i, rate))
        z.append(dengchang(i, rate))

    hufdeal()

    print ('哈夫曼编码：\n')
    for i in newQ:
        print (i.name, i.codeword)
    print ('等长编码：\n')
    dcdeal()
    print('扩展编码：\n')
    extend(n)

    len1 = 0
    len2 = 0
    len3 = 0

    for i in range(len(z)):
        len1 += len(newQ[i].codeword)
        len2 += len(y[i].codeword)
        len3 += len(z[i].codeword)

    len1 = float(1.0 * len1 / n)
    len2 = float(1.0 * len2 / n)
    len3 = float(1.0 * len3 / n)
    print ("哈夫曼编码平均码长为%.2f,等长编码平均码长为%.2f,扩展编码平均码长为%.2f" % (len1, len2, len3))


if __name__ == '__main__':
    main();


# 10个值：0.30  0.20 0.16  0.09  0.08 0.07  0.04  0.03  0.02  0.01