line1 = input().split(',')
line2 = input().split(',')
pts_marked = [(0,0)]
pt= (0,0)
for com in line1:
    direction = com[0]
    dist = int(com[1:])
    if(direction == 'R'):
        end_point = (pt[0]+ dist, pt[1])
    if(direction == 'L'):
        end_point = (pt[0]- dist, pt[1])
    if(direction == 'U'):
        end_point = (pt[0], pt[1] + dist)
    if(direction == 'D'):
        end_point = (pt[0], pt[1]- dist)

    if(direction == 'R'):
        for i in range (pt[0]+1, end_point[0]+1):
            pts_marked.append((i, pt[1]))
    elif(direction == 'L'):
        for i in range (pt[0]-1, end_point[0]-1, -1):
            pts_marked.append((i, pt[1]))
    elif(direction == 'U'):
        for i in range (pt[1]+1, end_point[1]+1):
            pts_marked.append((pt[0], i))
    else:
        for i in range (pt[1]-1, end_point[1]-1, -1):
            pts_marked.append((pt[0], i))
    pt = end_point

pts_marked2 = [(0,0)]
pt= (0,0)
for com in line2:
    direction = com[0]
    dist = int(com[1:])
    if(direction == 'R'):
        end_point = (pt[0]+ dist, pt[1])
    if(direction == 'L'):
        end_point = (pt[0]- dist, pt[1])
    if(direction == 'U'):
        end_point = (pt[0], pt[1] + dist)
    if(direction == 'D'):
        end_point = (pt[0], pt[1]- dist)

    if(direction == 'R'):
        for i in range (pt[0]+1, end_point[0]+1):
            pts_marked2.append((i, pt[1]))
    elif(direction == 'L'):
        for i in range (pt[0]-1, end_point[0]-1, -1):
            pts_marked2.append((i, pt[1]))
    elif(direction == 'U'):
        for i in range (pt[1]+1, end_point[1]+1):
            pts_marked2.append((pt[0], i))
    else:
        for i in range (pt[1]-1, end_point[1]-1, -1):
            pts_marked2.append((pt[0], i))
    pt = end_point

lowest_steps = -1
for pt in pts_marked2:
    if(pt in pts_marked and pt != (0,0)):
        steps = pts_marked.index(pt) + pts_marked2.index(pt)
        if(lowest_steps == -1 or steps < lowest_steps):
            lowest_steps = steps
print(lowest_steps)

