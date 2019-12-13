string = input()

width = 25
height = 6
#width = 3 
#height = 2

layer_index = 1
wh = width * height

resp_layer = ''
resp_layer_count = 100000000000000
while layer_index*wh <= len(string):
    layer = string[wh*(layer_index-1): wh*layer_index]
    #print("Layer: " + layer)
    count = layer.count('0')
    if(count < resp_layer_count): 
        resp_layer_count = count
        resp_layer = layer
    layer_index += 1

#print(resp_layer)
resp = resp_layer.count('1') * resp_layer.count('2')
print(resp)
