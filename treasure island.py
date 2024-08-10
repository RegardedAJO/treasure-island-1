print("Welcome to treasure island. You will choose your path, only one path will take you to the treasure")
direction = input("left or right? ")
if direction == "right":
    print("you chose wisely")
    water = input("you now find yourself at a large river. do you 'wait' for a boat or 'swim' across the river ")
    if water == "wait":
        print("a boat has come to take you across the river")
        door = input("now you come to three doors: 'red' 'yellow' or blue', which one do you choose? ")
        if door == "yellow":
            print("eureka, you have chosen wisely and found the treasure")
        elif door == "blue":
            print("you were mauled by a beast, game over")
        elif door == "red":
            print("you were consumed by fire, game over")
    else:
        print("you were eaten by crocodiles, game over")
else:
    print("you fell in to a trap and died, game over")