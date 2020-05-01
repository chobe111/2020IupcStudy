n = int(input())


def make_star(n):
    star_list = ""
    for star in range(n):
        star_list += "*"

    return star_list


for i in range(n):
    if i + 1 == n:
        break
    print(make_star(i + 1))

print(make_star(n))

for i in range(n):
    if i + 1 == n:
        break
    print(make_star(n - i + 1))

