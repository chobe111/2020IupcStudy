h,m = input().split()
h = int(h)
m = int(m)
if h>0 :
    H= (h*60+m-45)//60
    M= (h*60+m-45)%60
    print(H, M)
if h==0:
    if m<45:
        print(((h+24)*60+m-45)//60,((h+24)*60+m-45)%60)
    else:
        print((((0+24)*60)+50-45)//60, 60-m)