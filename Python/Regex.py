import re

text = "Toto je první věta. A toto je druhá věta! A ještě třetí věta? No a čtvrtá věta."
vety = re.findall(r'[^.!?]+[.!?]', text)
print(vety)

# Neřešitelná situace: Řadová číslovka Následovná vlastním jménem.
# Například: Český císař Karel IV. Prahu velmi miloval.
# Má na větu tu být input(vstup)? 