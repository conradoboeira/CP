string = input()

width = 25
height = 6
#width = 2 
#height = 2
debug = False 

layer_index = 1
wh = width * height

image = ''
while layer_index*wh <= len(string):
    layer = string[wh*(layer_index-1): wh*layer_index]
    if(layer_index == 1): image = layer
    else:
        for i in range(len(layer)):
            if(image[i] == '2' and layer[i] != '2'):
                l = list(image)
                l[i] = layer[i]
                image = ''.join(l)
    layer_index += 1

for i in range (height):
    line = ''
    for j in range(width):
        index = i*width + j
        value = image[index]
        if(debug):
            line += value
        if(not debug):
            if(value == '2'): line += " "
            if(value == '1'): line += "x"
            if(value == '0'): line += " "
    print(line)
