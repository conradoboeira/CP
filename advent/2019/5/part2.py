val = input()
commands = [int(x) for x in val.split(',')]
pc = 0
inp = 5
while(True):
    command = commands[pc]
    opcode = command%100
    mode1 = command//100 %10
    mode2 = command//1000 %10
    mode3 = command//10000 %10
    print(opcode)
    if(opcode == 1):
        val1 = commands[pc+1]
        val2 = commands[pc+2]
        pos = commands[pc+3]
        
        rval1 = commands[val1] if mode1==0 else val1
        rval2 = commands[val2] if mode2==0 else val2
        commands[pos] = rval1 + rval2
        pc += 4
    elif(opcode == 2):
        val1 = commands[pc+1]
        val2 = commands[pc+2]
        pos = commands[pc+3]
        rval1 = commands[val1] if mode1==0 else val1
        rval2 = commands[val2] if mode2==0 else val2
        commands[pos] = rval1 * rval2
        pc += 4
    elif(opcode == 3):
        pos = commands[pc+1]
        commands[pos] = inp
        pc+=2
    elif(opcode == 4):
        pos = commands[pc+1]
        print("output: {}".format(commands[pos]))
        pc+=2
    elif(opcode == 5):
        val1 = commands[pc+1]
        val2 = commands[pc+2]
        
        rval1 = commands[val1] if mode1==0 else val1
        rval2 = commands[val2] if mode2==0 else val2
       
        pc = rval2 if rval1!=0 else pc+3
    elif(opcode == 6):
        val1 = commands[pc+1]
        val2 = commands[pc+2]
        
        rval1 = commands[val1] if mode1==0 else val1
        rval2 = commands[val2] if mode2==0 else val2
       
        pc = rval2 if rval1==0 else pc+3
    elif(opcode == 7):
        val1 = commands[pc+1]
        val2 = commands[pc+2]
        pos = commands[pc+3]

        rval1 = commands[val1] if mode1==0 else val1
        rval2 = commands[val2] if mode2==0 else val2
        commands[pos] = 1 if rval1 < rval2 else 0

        pc += 4 
    elif(opcode == 8):
        val1 = commands[pc+1]
        val2 = commands[pc+2]
        pos = commands[pc+3]

        rval1 = commands[val1] if mode1==0 else val1
        rval2 = commands[val2] if mode2==0 else val2
        commands[pos] = 1 if rval1 == rval2 else 0

        pc += 4 
    elif(opcode == 99):
        break
    else: 
        print("fuck")
        break
print(commands)
