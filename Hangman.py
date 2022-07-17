import random


def intro_screen():
    print("----------------------------------------------------------------------------------------------------\n")
    print("----------------------------------------------------------------------------------------------------\n")
    print("             _   _                  ___  ___            ")
    print("            | | | |                 |  \\/  |            ")
    print("            | |_| | __ _ _ __   __ _| .  . | __ _ _ __  ")
    print("            |  _  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\ ")
    print("            | | | | (_| | | | | (_| | |  | | (_| | | | |")
    print("            \\_| |_/\\__,_|_| |_|\\__, \\_|  |_/\\__,_|_| |_|")
    print("                                __/ |                   ")
    print("                               |___/                    ")

    print("----------------------------------------------------------------------------------------------------")
    print("-------------------------------------------------Menu-----------------------------------------------")
    print("---------------------------------------Press 1 To Play The Game ------------------------------------")
    print("---------------------------------------Press 2 To View The Word List -------------------------------")
    print("---------------------------------------Press 3 to quit-----------------------------------------")
    print("---------------------------------------Enter your choice--------------------------------------------")


def random_word():
    rw_rn = random_number()
    counter = 0
    rw_word = ""
    rw_file = open("wordlist.txt", "r")
    while rw_file.readline():
        if rw_rn == counter:
            rw_word = rw_file.readline()
            break
        counter += 1
    return rw_word


def random_number():
    rn = random.randint(1, 6)
    return rn


def design(d_live):
    if d_live == 0:
        print(
            """
                               --------
                               |      |
                               |      O
                               |     \\|/
                               |      |
                               |     / \\
                               -
                               """
        )
    if d_live == 1:
        print(
            """
                               --------
                               |      |
                               |      O
                               |     \\|/
                               |      |
                               |     /
                               -
                               """
        )
    if d_live == 2:
        print(
            """
                               --------
                               |      |
                               |      O
                               |     \\|/
                               |      |
                               |
                               -
                               """
        )
    if d_live == 3:
        print(
            """
                               --------
                               |      |
                               |      O
                               |     \\|
                               |      |
                               |
                               -
                               """
        )
    if d_live == 4:
        print(
            """
                               --------
                               |      |
                               |      O
                               |      |
                               |      |
                               |
                               -
                               """
        )
    if d_live == 5:
        print(
            """
                               --------
                               |      |
                               |      O
                               |
                               |
                               |
                               -
                               """
        )
    if d_live == 6:
        print(
            """
                               --------
                               |      |
                               |      
                               |
                               |
                               |
                               -
                               """
        )


def print_word(pw_word, pw_letter):
    for x in range(len(pw_word) - 1):
        if pw_letter.find(pw_word[x]) != -1:
            print(pw_word[x], " ")
        else:
            print("_ ")
    return 0


# main function
if __name__ == '__main__':
    selection = 0
    while selection != 3:
        intro_screen()
        selection = int(input())
        if selection == 1:
            counter1 = 0
            live = 6
            letter = ""
            guessedLetters = ""

            word = random_word()

            while live > 0:
                design(live)
                print_word(word, guessedLetters)

                if counter1 == len(word) - 1:
                    break
                print("\n\nEnter one letter only once: ")
                print("\n\nLetters guesses: ", guessedLetters)
                letter = input("\n\nEnter a letter: ")

                guessedLetters += letter

                if word.find(letter) != -1:
                    counter1 += 1
                    continue
                else:
                    live -= 1

            if live == 0:
                design(0)
                print("\n\n\n\t\t\t >>>You Lose!<<<\n\n")
                print("The word was: ", word)
            if live > 0:
                print("\n\n\n\t\t\t >>>You WIN!<<<\n\n")
                print("The word was: ", word)
        if selection == 2:
            file = open("wordlist.txt", "r")
            word = file.read().replace("\n", " ")
            print(word)
            file.close()
