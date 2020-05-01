n = int(input())


def solve(num):
    up_star = ""
    down_star = ""

    for j in range(num):
        if (j + 1) % 2 == 1:
            up_star += "* "
        else:
            down_star += " *"

    print(up_star)
    print(down_star)


for i in range(n):
    solve(n)
