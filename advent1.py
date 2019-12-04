def collision(val1, val2):
    b_point1, e_point1 = val1
    b_point2, e_point2 = val2
    
    b1_horizontal = (b_point1[0] == e_point1[0])
    b2_horizontal = (b_point2[0] == e_point2[0])

    if(b1_horizontal and b2_horizontal or
            (not b1_horizontal and not b2_horizontal)):
        return (False, (0,0))

    if(b1_horizontal):
        if not(b_point1[0] <= b_point2[0] and e_point1[0]>= b_point2[0] ):
            return (False, (0,0))
        if not(b_point2[1] <= b_point1[1] and e_point2[1]>= b_point1[1] ):
            return (False, (0,0))

    if(b2_horizontal):
        if not(b_point2[0] <= b_point1[0] and e_point2[0]>= b_point1[0] ):
            return (False, (0,0))


    else:
        if(b1_horizontal):
            return(True, (b_point1[0], b_point2[1]))
        else:
            return(True, (b_point2[0], b_point1[1]))
    



line1 = input().split(',')
line2 = input().split(',')

pts1 = []
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
        end_point = (pt[0]+ dist, pt[1]- dist)
    pts1.append((pt,end_point))
    pt = end_point

pts2 = []
pt = (0,0)
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
        end_point = (pt[0]+ dist, pt[1]- dist)
    pts2.append((pt,end_point))
    pt = end_point

for val1 in pts1:
    for val2 in pts2:
        check, pos = collision(val1,val2)
        if(check):
            print(pos)
            print(pos[0]+pos[1])

