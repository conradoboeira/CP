line1 = input()
line2 = input()
line3 = input()

character = line3.split()

st = ''
count = 0
for c in line2:
    if(not c in character):
        count += (len(st)*(len(st)+1)) /2
        st = ''
    else:
        st += c
count += (len(st)*(len(st)+1)) /2
print(int(count))
