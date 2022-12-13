from functools import cmp_to_key

def iscorrect(a, b):
    if isinstance(a, list) and isinstance(b, int):
        b = [b]

    if isinstance(a, int) and isinstance(b, list):
        a = [a]

    if isinstance(a, int) and isinstance(b, int):
        if a < b:
            return 1
        if a == b:
            return 0
        return -1

    if isinstance(a, list) and isinstance(b, list):
        i = 0
        while i < len(a) and i < len(b):
            if (iscorrect(a[i], b[i])!=0):
                return iscorrect(a[i], b[i])
            i += 1

        if i == len(a):
            if len(a) == len(b):
                return 0
            return 1 
        return -1

def solve1():
    with open("test1.txt") as f:
        parts = f.read()
        parts = parts.split("\n\n")
        ris=0
        i=1
        for row in parts:
            a,b=map(eval, row.split("\n"))
            if iscorrect(a, b) == 1:
                ris += i 
            i+=1
        print(ris)

def solve2():
    with open("test2.txt") as f:
        parts = f.read()
        parts = parts.split("\n\n")
        lista=[]
        for row in parts:
            a,b=map(eval, row.split("\n"))
            lista.append(a)
            lista.append(b)
        lista.append([[2]])
        lista.append([[6]])
        lista.sort(reverse=True, key=cmp_to_key(iscorrect))
        print((lista.index([[2]])+1)*(lista.index([[6]])+1))

solve1()
solve2()
        

