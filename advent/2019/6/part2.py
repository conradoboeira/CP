from sys import stdin

orbits = {}
visited = []
orbits_num = {}

def rec(planet):
    if(planet in visited): return -1
    visited.append(planet)
    if('SAN' in orbits[planet]): return 0
    for plan in orbits[planet]:
        val = rec(plan)
        if(val == -1): continue
        else: return 1 + val
    return -1

for line in stdin:
    planet1, planet2 = line.strip().split(')')
    if(planet1 in orbits): orbits[planet1].append(planet2)
    else: orbits[planet1] = [planet2]
    if(planet2 in orbits): orbits[planet2].append(planet1)
    else: orbits[planet2] = [planet1]


count = rec('YOU') -1

print(count)
