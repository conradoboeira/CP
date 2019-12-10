line1 = input().split(',')
line2 = input().split(',')
pts_marked = []
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
        for i in range (pt[0], end_point[0]+1):
            pts_marked.append((i, pt[1]))
    elif(direction == 'L'):
        for i in range (pt[0], end_point[0]-1, -1):
            pts_marked.append((i, pt[1]))
    elif(direction == 'U'):
        for i in range (pt[1], end_point[1]+1):
            pts_marked.append((pt[0], i))
    else:
        for i in range (pt[1], end_point[1]-1, -1):
            pts_marked.append((pt[0], i))
    pt = end_point

print(pts_marked)

closer_pt = -1
pt = (0,0)
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
        for i in range (pt[0], end_point[0]+1):
            point = (i, pt[1])
            if point in pts_marked:
                #print(point)
                dist = abs(point[0]) + abs(point[1])
                if(closer_pt == -1 or dist < closer_pt):
                    if(pt == (0,0)): continue
                    closer_pt = dist 
    elif(direction == 'L'):
        for i in range (pt[0], end_point[0]-1, -1):
            point = (i, pt[1])
            if point in pts_marked:
                #print(point)
                dist = abs(point[0]) + abs(point[1])
                if(closer_pt == -1 or dist < closer_pt):
                    if(pt == (0,0)): continue
                    closer_pt = dist 
    elif(direction == 'U'):
        for i in range (pt[1], end_point[1]+1):
            point = (pt[0], 1)
            if point in pts_marked:
                #print(point)
                dist = abs(point[0]) + abs(point[1])
                if(closer_pt == -1 or dist < closer_pt):
                    if(pt == (0,0)): continue
                    closer_pt = dist
    else:
        for i in range (pt[1], end_point[1]-1, -1):
            point = (pt[0], 1)
            if point in pts_marked:
                #print(point)
                dist = abs(point[0]) + abs(point[1])
                if(closer_pt == -1 or dist < closer_pt):
                    if(pt == (0,0)): continue
                    closer_pt = dist
    print(end_point)   
    pt = end_point

print(closer_pt)
