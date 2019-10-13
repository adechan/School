
class State(object):
    # python nu suporta mai mult constructori 
    def __init__(self, capacitate_barca, n1_misionari, m1_canibali, 
                 pozitie_barca, n2_misionari, m2_canibali):

        self.capacitate_barca = capacitate_barca
        self.n1_misionari = n1_misionari
        self.m1_canibali = m1_canibali
        self.pozitie_barca = pozitie_barca
        self.n2_misionari = n2_misionari
        self.m2_canibali = m2_canibali

    # functie de initializare
    def initializare(self, capacitate_barca, n1_misionari, n1_canibali):
        stareInitiala = State(capacitate_barca, n1_misionari, n1_canibali, 
                              1, 0, 0)
        return stareInitiala

# functie care verifiica daca o stare este finala
def esteFinala(stare):
    if stare.n1_misionari == 0 and stare.m1_canibali == 0 and stare.pozitie_barca == 2:
         return True
    else:
         return False

# functie de tranzitie
def functieTranzitie(stare, v1_misionari, v2_canibali):
    # sunt pe malul 1: trazintie 1 -> 2
    if stare.pozitie_barca == 1: 
        stangaDreapta = State(stare.capacitate_barca, stare.n1_misionari - v1_misionari, 
                              stare.m1_canibali - v2_canibali, 3 - stare.pozitie_barca, 
                              stare.n2_misionari + v1_misionari, stare.m2_canibali + v2_canibali)
        return stangaDreapta

    # sunt pe malul 2: tranzitie 2 -> 1
    else:
        dreaptaStanga = State(stare.capacitate_barca, stare.n1_misionari + v1_misionari, 
                              stare.m1_canibali + v2_canibali, 3 - stare.pozitie_barca, 
                              stare.n2_misionari - v1_misionari, stare.m2_canibali - v2_canibali)
        return dreaptaStanga

# functie care verifica daca tranzitia este valida
def esteValida(stare,v1_misionari,v2_canibali):

    stareValida = State(stare.capacitate_barca,stare.n1_misionari+v1_misionari,
                        stare.m1_canibali+v2_canibali,3-stare.pozitie_barca,
                        stare.n2_misionari-v1_misionari,stare.m2_canibali-v2_canibali)

    if stare.n1_misionari > 0 and stare.n1_misionari < stare.m1_canibali:
        print("Nevalida: prea multi canibali pe malul 1 !!")
        return False

    elif stare.n2_misionari > 0 and stare.n2_misionari < stare.m2_canibali:
        print("Nevalida: prea multi canibali pe malul 2 !!")
        return False

    elif v1_misionari + v2_canibali > stare.capacitate_barca:
        print("Nevalida: prea multi canibali si misionari in barca !!")
        return False

    elif v1_misionari + v2_canibali > 0 and v1_misionari >= 0 and v2_canibali >= 0 and stare.pozitie_barca == 2:
        print("Nevalida: pe malul 2")
        return False

    elif v1_misionari + v2_canibali < 0 and v1_misionari <= 0 and v2_canibali <= 0 and stare.pozitie_barca == 1:
        print("Nevalida: pe malul 1")
        #de pe 1 pe 2 schimbam semnul lui v1 si v2, - cu - = +
        return False

    print("Stare valida!")
    return True


state = State(0, 0, 0, 0, 0, 0)
# am initializat capacitatea barcii, numarul misionarilor si numarul canibalilor
state1 = state.initializare(1, 3, 3)
print(state1.m2_canibali)

state2 = State(1, 0, 0, 2, 3, 3)

# conteaza ceea ce este dat ca parametru pentru functia esteFinala
stareNefinala = esteFinala(state1)
print(stareNefinala)

stareFinala = esteFinala(state2)
print(stareFinala)

state3 = state.initializare(1, 3, 3)
tranzitie = functieTranzitie(state3, 1, 0)
print("n1_misionari", tranzitie.n1_misionari)
print("n2_misionari", tranzitie.n2_misionari)
print("m1_canibali", tranzitie.m1_canibali)
print("m2_canibali", tranzitie.m2_canibali)
print("pozitie_barca", tranzitie.pozitie_barca)
print("\n")

state4 = State(1, 2, 1, 2, 1, 2)
tranzitie2 = functieTranzitie(state4, 1, 1)
print("n1_misionari", tranzitie2.n1_misionari)
print("n2_misionari", tranzitie2.n2_misionari)
print("m1_canibali", tranzitie2.m1_canibali)
print("m2_canibali", tranzitie2.m2_canibali)
print("pozitie_barca", tranzitie2.pozitie_barca)

state5 = State(2, 3, 3, 1, 0, 0)
print("Stare valida? ", esteValida(state5, 1, 0))

print("starea 6")
# cazul cu prea multi canibali >  misionari pe malul 1
stare6 = State(2, 3, 4, 1, 0, 0) 
stareValida = esteValida(stare6, 1, 1)
print(stareValida)

print("starea 7")
# cazul cu prea multi canibali >  misionari pe malul 2
stare7 = State(2, 3, 3, 1, 1, 2) 
stareValida = esteValida(stare7, 1, 1)
print(stareValida)

print("starea 8")
 # cazul cand se intrece capacitatea din barca
stare8 = State(2, 3, 3, 1, 2, 2)
stareValida = esteValida(stare8, 2, 1)
print(stareValida)

print("starea 9")
# pe malul 1
stare9 = State(2, 3, 3, 1, 2, 2)
stareValida = esteValida(stare9, -1, -2) 
print(stareValida)

print("starea 10")
# pe malul 2
stare10 = State(2, 3, 3, 2, 2, 2)
stareValida = esteValida(stare10, 1, 0) 
print(stareValida)

print("starea 11")
 # o stare true, adica valida
stare11 = State(2, 3, 3, 1, 2, 2)
stareValida = esteValida(stare11, 1, 1)
print(stareValida)