while True:
    entry = input().split()
    n = int(entry[0])
    m = int(entry[1])
    c = int(entry[2])

    if n == 0: break

    r = (n-7)*(m-7)
    if (r % 2 == 1 and c ==1): r+=1
    print(int(r/2))

