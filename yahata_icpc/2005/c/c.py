dic = {"m":1000, "c":100, "x":10, "i":1}
dic_rev = {1000:"m", 100:"c", 10:"x", 1:"i"}
N = int(input())

for i in range(N):
    slist = list(map(str, input().split()))
    numlist = []
    for word in slist:
        before = 1
        word_sum = 0
        for c in word:
            if c in dic:
                word_sum += (int(before) * dic[c])
                before = 1
            else:
                before = c
        numlist.append(word_sum)

    wordsum = sum(numlist)

    ans = ""
    cnt = 1
    for w in reversed(str(wordsum)):
        if w == "0":
            tmp = ""
        elif w == "1":
            tmp = dic_rev[cnt]
        else:
            tmp = w + dic_rev[cnt]
        ans = tmp + ans
        cnt = cnt * 10

    print(ans)
