
r1=[" "," "," "]
r2=[" "," "," "]
r3=[" "," "," "]

p1c=[]
p2c=[]

def board():
    for index in range(0,len(r1)):
        print(r1[index],end=" ")
        if index<2:
            print("|",end=" ")
    print("\n---------")
    for index in range(0,len(r2)):
        print(r2[index],end=" ")
        if index<2:
            print("|",end=" ")
    print("\n---------")
    for index in range(0,len(r3)):
        print(r3[index],end=" ")
        if index<2:
            print("|",end=" ")

def emp_board():    
    for index in range(0,len(r1)):
        r1[index]=" "
        r2[index]=" "
        r3[index]=" "

def chcwin(ls):
    if (1 in ls and 2 in ls and 3 in ls) or (4 in ls and 5 in ls and 6 in ls) or (7 in ls and 8 in ls and 9 in ls) or (1 in ls and 5 in ls and 9 in ls) or (3 in ls and 5 in ls and 7 in ls) or (1 in ls and 4 in ls and 7 in ls) or (2 in ls and 5 in ls and 8 in ls) or (3 in ls and 6 in ls and 9 in ls):
        return True
    return False

def play_game():
    play=1
    while(play==1):
        won=False
        draw=False
        p1c=[]
        p2c=[]
        print("PLAYER 1-X")
        print("PLAYER 2-0\n")
        ch=1
        while won==False or draw==False:
            ia="0"
            if ch==1:
                board()
                while int(ia) not in range(1,10):
                    while True:
                        ia=input("\nPLAYER 1 ENTER YOUR MOVE(1-9) ")
                        if (int(ia) not in p1c) and (int(ia) not in p2c):
                            break
                        else:
                            print("POSITION ALREADY CHOSEN!")
                ip=int(ia)-1
                if ip>=0 and ip<=2:
                    r1[ip]="X"
                elif ip>=3 and ip<=5:
                    r2[ip-3]="X"
                elif ip>=6 and ip<=8:
                    r3[ip-6]="X"
                else:
                    print("Invalid Choice")
                p1c.append(ip+1)
                if chcwin(p1c):
                    board()
                    print("\nPLAYER ONE WON")
                    won=True
                    break

                if len(p1c)==5:
                    board()
                    print("\nDRAW")
                    draw=True
                    break
                ch=2
            
            else:
                ia="0"
                board()
                while int(ia) not in range(1,10) :
                    while True:
                        ia=input("\nPLAYER 2 ENTER YOUR MOVE(1-9) ")
                        if (int(ia) not in p1c) and (int(ia) not in p2c):
                            break
                        else:
                            print("POSITION ALREADY CHOSEN!")
                ip=int(ia)-1
                if ip>=0 and ip<=2:
                    r1[ip]="O"
                elif ip>=3 and ip<=5:
                    r2[ip-3]="O"
                elif ip>=6 and ip<=8:
                    r3[ip-6]="O"
                else:
                    print("Invalid Choice")
                p2c.append(ip+1)
                if chcwin(p2c):
                    board()
                    print("\nPLAYER 2 WON")
                    won=True
                    break
                ch=1

                if len(p2c)==5:
                    board()
                    print("\nDRAW")
                    draw=True
                    break
        emp_board()
        while True:
            try:
                play=int(input("\nPRESS 1 TO PLAY AGAIN\nPRESS 0 TO EXIT "))
                if play==1 or play==0:
                    break

            except ValueError:
                print("Invalid input. Please enter 0 or 1")

play_game()
