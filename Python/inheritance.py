import math

# Základní třída pro geometrické tvary
class Tvar:
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
class Ctvrc(Tvar):
    def __init__(self, side_length):
        self.side_length = side_length
    
    def calc_obvod(self):
        return 4 * self.side_length
    
    def calc_obsah(self):
        return self.side_length ** 2

# Odvozená třída pro obdélník
class Obdelnik(Tvar):
    def __init__(self, sirka, vyska):
        self.sirka = sirka
        self.vyska = vyska
    
    def calc_obvod(self):
        return 2 * (self.sirka + self.vyska)
    
    def calc_obsah(self):
        return self.sirka * self.vyska
    
# Odvozená třída pro kvádr
class Kvadr(Obdelnik):
    def __init__(self, a, b, c):
        super().__init__(a, b)
        self.c = c
    
    def calc_obsah(self):
        return 2 * (self.sirka * self.vyska + self.sirka * self.c + self.vyska * self.c)
    
    def calc_objem(self):
        return self.sirka * self.vyska * self.c

# Odvozená třída pro krychli
class Krychle(Tvar):
    def __init__(self, a):
        super().__init__()
        self.a = a
    
    def calc_obsah(self):
        return 6 * (self.a ** 2)
    
    def calc_objem(self):
        return self.a ** 3

# Odvozená třída pro kouli
class Koule(Tvar):
    def __init__(self, prumer):
        self.prumer = prumer
    
    def calc_obsah(self):
        return 4 * math.pi * self.prumer ** 2
    
    def calc_objem(self):
        return (4 / 3) * math.pi * self.prumer ** 3

# Odvozená třída pro kružnici
class Kruznice(Tvar):
    def __init__(self, polomer):
        self.polomer = polomer
    
    def calc_obvod(self):
        return 2 * math.pi * self.polomer
    
    def calc_obsah(self):
        return math.pi * self.polomer ** 2

# Ukázka použití tříd
ctvrc = Ctvrc(5)
print("Čtverec - Obvod:", ctvrc.calc_obvod(), "Obsah:", ctvrc.calc_obsah())

obdelnik = Obdelnik(4, 6)
print("Obdélník - Obvod:", obdelnik.calc_obvod(), "Obsah:", obdelnik.calc_obsah())

kvadr = Kvadr(3, 4, 5)
print("Kvádr - Povrchová plocha:", kvadr.calc_obsah(), "Objem:", kvadr.calc_objem())

krychle = Krychle(3)
print("Krychle - Povrchová plocha:", krychle.calc_obsah(), "Objem:", krychle.calc_objem())

koule = Koule(4)
print("Koule - Povrchová plocha:", koule.calc_obsah(), "Objem:", koule.calc_objem())

kruznice = Kruznice(3)
print("Kružnice - Obvod:", kruznice.calc_obvod(), "Obsah:", kruznice.calc_obsah())
