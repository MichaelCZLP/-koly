import requests
import os

def ukradni(url, soubor):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            # Přístup k Ploše
            cela_cesta = os.path.join(os.path.join(os.path.expanduser("~"), "Desktop"), soubor)
            with open(cela_cesta, 'wb') as file:
                file.write(response.content)
            print("Kniha byla úspěšně stažena a uložena do souboru:", cela_cesta)
        else:
            print("Chyba při stažení knihy. Číslo chyby:", response.status_code)
    except Exception as e:
        print("Došlo k chybě při stahování knihy:", str(e))

kniha_url = str(input("Zadejte přesnou webovou adresu k souboru, který si chcete \"vypůjčit\": ")) 
soubor = str(input("Zadejte jak se má váš soubor jmenovat ve formátu \"nazev.txt\": "))
ukradni(kniha_url, soubor)

# Exemplární URL knihy: https://www.gutenberg.org/files/1342/1342-0.txt
# Soubory se ukládají na Plochu, pokud by tam náhodou nebyly, budou v uživatelské složce
# V názvu musí být uvedeno.txt, zkoušel jsem funkci, co by ji tam přidala, kdyby na to uživatel zapomněl - nemělo se to rádo
# Vstupy lze pochopitelně nahradit přímo deklarovanou proměnnou