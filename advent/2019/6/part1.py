from sys import stdin

orbits = {}
planet_list = []
orbits_num = {}

def rec(planet):
    if(planet in orbits_num): return orbits_num[planet]
    if(not planet in orbits): return 0
    else: return 1 + rec(orbits[planet])

for line in stdin:
    planet1, planet2 = line.strip().split(')')
    orbits[planet2] = planet1
    if(not planet1 in planet_list): planet_list.append(planet1)
    if(not planet2 in planet_list): planet_list.append(planet2)

count = 0
for planet in planet_list:
    count += rec(planet)

print(count)
