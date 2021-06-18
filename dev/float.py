def GetNumbersBeforeComa(n):
    p = n*10
    c = 1
    while p != n:
        p *= 10
        c += 1 
        input(p)
    return p
print(GetNumbersBeforeComa(25.56))