import math

# Základní třída pro geometrické tvary
class tvar:
    def __init__(self):
        pass
    
    # Metoda pro výpočet obvodu 
    def calc_obvod(self):
        pass
    
    # Metoda pro výpočet obsahu 
    def calc_obsah(self):
        pass
    
    # Metoda pro výpočet objemu 
    def calc_objem(self):
        pass

# Odvozená třída pro čtverec
class ctvrc(tvar):
    def __init__(self, side_length):
        self.side_length = side_length
    
    def calc_obvod(self):
        return 4 * self.side_length
    
    def calc_obsah(self):
        return self.side_length ** 2
    
    def calc_objem(self):
        return None  # Čtverec nemá objem

# Odvozená třída pro obdélník
class obdelnik(tvar):
    def __init__(self, sirka, vyska):
        self.sirka = sirka
        self.vyska = vyska
    
    def calc_obvod(self):
        return 2 * (self.sirka + self.vyska)
    
    def calc_obsah(self):
        return self.sirka * self.vyska
    
    def calc_objem(self):
        return None  # Obdélník nemá objem

# Odvozená třída pro kruh
class kruh(tvar):
    def __init__(self, prumer):
        self.prumer = prumer
    
    def calc_obvod(self):
        return 2 * math.pi * self.prumer
    
    def calc_obsah(self):
        return math.pi * self.prumer ** 2
    
    def calc_objem(self):
        return None  # Kruh nemá objem

# Odvozená třída pro válec
class valec(tvar):
    def __init__(self, prumer, vyska):
        self.prumer = prumer
        self.vyska = vyska
    
    def calc_obvod(self):
        return 2 * math.pi * self.prumer
    
    def calc_obsah(self):
        return 2 * math.pi * self.prumer * (self.prumer + self.vyska)
    
    def calc_objem(self):
        return math.pi * self.prumer ** 2 * self.vyska

# Odvozená třída pro kouli
class koule(tvar):
    def __init__(self, prumer):
        self.prumer = prumer
    
    def calc_obvod(self):
        return None  # Koule nemá obvod
    
    def calc_obsah(self):
        return 4 * math.pi * self.prumer ** 2
    
    def calc_objem(self):
        return (4 / 3) * math.pi * self.prumer ** 3

# Odvozená třída pro kvádr
class kvadr(tvar):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    
    def calc_obvod(self):
        return 4 * (self.a + self.b + self.c)
    
    def calc_obsah(self):
        return 2 * (self.a * self.b + self.a * self.c + self.b * self.c)
    
    def calc_objem(self):
        return self.a * self.b * self.c

# Odvozená třída pro krychli
class krychle(tvar):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    
    def calc_obvod(self):
        return None  # kvadr nemá obvod
    
    def calc_obsah(self):
        return 2 * (self.a * self.b + self.a * self.c + self.b * self.c)
    
    def calc_objem(self):
        return self.a * self.b * self.c

# Ukázka použití tříd
class krychle(tvar):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    
    def calc_obvod(self):
        return None  # kvadr nemá obvod
    
    def calc_obsah(self):
        return 2 * (self.a * self.b + self.a * self.c + self.b * self.c)
    
    def calc_objem(self):
        return self.a * self.b * self.c

# Náhodná zkouška
ctvrc = ctvrc(5)
print("Čtverec - Obvod:", ctvrc.calc_obvod(), "Obsah:", ctvrc.calc_obsah())

obdelnik = obdelnik(4, 6)
print("Obdélník - Obvod:", obdelnik.calc_obvod(), "Obsah:", obdelnik.calc_obsah())

kruh = kruh(3)
print("Kruh - Obvod:", kruh.calc_obvod(), "Obsah:", kruh.calc_obsah())

valec = valec(2, 5)
print("Válec - Obvod:", valec.calc_obvod(), "Povrchová plocha:", valec.calc_obsah(), "Objem:", valec.calc_objem())

koule = koule(4)
print("Koule - Povrchová plocha:", koule.calc_obsah(), "Objem:", koule.calc_objem())

kvadr = kvadr(3, 3, 3)
print("Kvádr - Obvod:", kvadr.calc_obvod(), "Povrchová plocha:", kvadr.calc_obsah(), "Objem:", kvadr.calc_objem())

krychle = krychle(2, 4, 6)
print("kvadr - Povrchová plocha:", krychle.calc_obsah(), "Objem:", krychle.calc_objem())

# Ještě by šlo implementovat funkci round() aby výsledky nebyly tak šílené
# Toto je krásný kód. Možná by z toho šla udělat kalkulačka... 
