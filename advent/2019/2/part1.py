val = input()
commands = [int(x) for x in val.split(',')]
i = 0
commands[1] = 12
commands[2] = 2
while(True):
    if(commands[i] == 1):
        val1 = commands[i+1]
        val2 = commands[i+2]
        pos = commands[i+3]
        commands[pos] = commands[val1] + commands[val2]
    if(commands[i] == 2):
        val1 = commands[i+1]
        val2 = commands[i+2]
        pos = commands[i+3]
        commands[pos] = commands[val1] * commands[val2]
    if(commands[i] == 99):
        break
    i += 4
print(commands)
