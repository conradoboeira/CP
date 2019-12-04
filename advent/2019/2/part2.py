val = input()
inp = [int(x) for x in val.split(',')]
for x in range(100):
    for j in range(100):
        commands = inp.copy()
        commands[1] = x
        commands[2] = j
        #print("{} {}".format(x,j))
        i = 0
        while(True):
            if(i > len(commands) or commands[i] == 99):
                break
            elif(commands[i] == 1):
                val1 = commands[i+1]
                val2 = commands[i+2]
                pos = commands[i+3]
                if not (val1 >= len(commands) or val2 >= len(commands) or
                        pos>=len(commands)): 
                    commands[pos] = commands[val1] + commands[val2]
            elif(commands[i] == 2):
                val1 = commands[i+1]
                val2 = commands[i+2]
                pos = commands[i+3]
                if not (val1 >= len(commands) or val2 >= len(commands) or
                        pos>=len(commands)): 
                    commands[pos] = commands[val1] * commands[val2]
            i += 4
        #print(commands[0])
        if(commands[0] == 19690720):
            print(x)
            print(j)
            print(100 * x + j)
            exit() 


