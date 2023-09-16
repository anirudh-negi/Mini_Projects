import random

BankBalance=10000

suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Ace':1,'Two': 2, 'Three': 3, 'Four': 4, 'Five': 5, 'Six': 6, 'Seven': 7, 'Eight': 8, 
          'Nine': 9, 'Ten': 10, 'Jack': 11, 'Queen': 12, 'King': 13,}

class Deck:
    def __init__(self):
        self.all_cards = []
        for suit in suits:
            for rank in ranks:
                self.all_cards.append(Card(suit, rank))

    def shuffle(self):
        random.shuffle(self.all_cards)

    def deal_one(self):
        return self.all_cards.pop()

class Card:
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
        self.value = values[rank]

    def __str__(self):
        return self.rank + ' of ' + self.suit



class Player:
    def __init__(self, name):
        self.name = name
        self.all_cards = []
    
    def tos(self):
        sm=0
        for x in self.all_cards:
            sm+=x.value
        return sm

    def remove_one(self):
        return self.all_cards.pop(0)

    def add_cards(self, new_cards):
        if isinstance(new_cards, list):
            self.all_cards.extend(new_cards)
        else:
            self.all_cards.append(new_cards)

    def __str__(self):
        return f'Player {self.name} has {len(self.all_cards)} cards.'
    


playing =True
while playing:
    print("\n")
    #creating a deck
    new_deck=Deck()
    new_deck.shuffle()

    #initializing player and dealer
    dealer=Player("Dealer")
    name=input("ENTER YOUR NAME: ")
    player=Player(name)
    #taking the bet
    while True:
        try:
            bet=int(input("ENTER YOUR BET: "))
        except:
            print("INVALID BET ENTERED!")
        else:
            if bet<=BankBalance:
                break
            else:
                print("INSUFFICIENT FUNDS, YOU ONLY HAVE ${}".format(BankBalance))
    print("\n")
    print("WELCOME {} TO THE ROYAL CASINO!!\n".format(player.name))
    for x in range(2):
        player.add_cards(new_deck.deal_one())
        dealer.add_cards(new_deck.deal_one())

    pls=player.tos()
    dls=dealer.tos()
    print("DEALERS CARD:\n{}".format(dealer.remove_one()))
    print("\n")
    print("YOUR CARDS:\n{},{}".format(player.remove_one(),player.remove_one()))
    print("TOTAL: {}".format(pls))
    print("\n")
    while True:
        while True:
            try:
                ch=int(input("PRESS 1 TO HIT 0 TO STAND: "))
            except:
                print("ENTER VALID INPUT(0 OR 1)")
            else:
                break
        if ch==1:
            player.add_cards(new_deck.deal_one())
            pls+=player.tos()
            pc=player.remove_one()
            print("\n")
            print("YOUR CARD: {}\nTOTAL:{}".format(pc,pls))
            if pls>21:
                print("\nBUSTED")
                print("BETTER LUCK NEXT TIME {}\nYOU LOOSE ${}!".format(player.name,bet))
                BankBalance-=bet
                break
            else:
                continue
        else:
            print("\nDEALERS CARD: {}".format(dealer.remove_one()))
            while(dls<=17):
                print("DEALER HITS")
                dealer.add_cards(new_deck.deal_one())
                dls+=dealer.tos()
                print("DEALERS CARD: {}".format(dealer.remove_one()))
            print("\nYOUR TOTAL: {}".format(pls))
            print("DEALERS TOTAL: {}\n".format(dls))
            if(abs(21-dls)>abs(21-pls)):
                print("CONGRATS {} YOU WON ${}!!!".format(player.name,bet))
                BankBalance+=bet
                break
            else:
                print("DEALER WON!\n,BETTER LUCK NEXT TIME {}. YOU LOST ${}!".format(player.name,bet))
                BankBalance-=bet
                break
    while True:
        try:
            pg=int(input("\nYOUR BALANCE IS ${}\nPRESS 0 TO EXIT 1 TO PLAY AGAIN! ".format(BankBalance)))
        except:
            print("ENTER VALID CHOICE(0 OR 1)!")
        else:
            if pg==0:
                print("CLOSING GAME...")
                playing=False
                break
            else:
                break

