morse_rules = {}

import urllib.request # Importuje přímo soubor z webu

url = "https://math.hws.edu/eck/cs225/s03/code.txt"
with urllib.request.urlopen(url) as response:
    html = response.read().decode()
    

lines = html.split("\n")

for line in lines: # Načítá jednotlivé řádky a rozdělí je na Znak a Kód, který pak ukládá do seznamu 
    if line != "":
        morse_rules[line[0]] = line[2:]
    else:
        pass

def translate(vstup):
    # Vytvoříme prázdný výstupní řetězec a kontrolní proměnnou
    c = 0
    out = ""
    # Projdeme vstupní text znak po znaku
    for char in vstup:
        if char.upper() in morse_rules: # Nechceme přece vyřadit malá písmena
            out += morse_rules[char.upper()] + " "
        else:
            if c == 0: # Kontrolní proměnná "c" řídí: 0 Poprvé znak mimo abecedu. Po upozornění vždy: 1 Zahrnout 2. vynechat 
                check = str(input("Vstup obsahuje znaky mimo morseovu abecedu, chcete je zachovat nebo ignorovat? (Z/I) "))
                if (check == "Z" or check == "zachovat"):
                    c = 1
                    out += char + " "
                else:
                    c = 2
            elif c == 1:
                out += char + " "
            else:
                pass
    return out

            # Toto není vhodný zápis kódu, několik pod sebou vložených statementů je destrukce přehlednosti
            # Naštěstí teď ale nemám čas zabývat se elegantnější implementací

vstup = input("Zadejte text k přeložení do Morseovy abecedy: ")
print(translate(vstup))
