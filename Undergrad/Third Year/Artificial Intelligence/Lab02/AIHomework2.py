
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

    def initializare(self, capacitate_barca, n1_misionari, n1_canibali):
        stareInitiala = State(capacitate_barca, n1_misionari, n1_canibali, 
                              1, 0, 0)
        return stareInitiala

def esteFinala(stare):
    if stare.n1_misionari == 0 and stare.m1_canibali == 0 and stare.pozitie_barca == 2:
         return True
    else:
         return False

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

def esteValida(stare, v1_misionari, v2_canibali):
    # stareValida = State(stare.capacitate_barca, stare.n1_misionari + v1_misionari, 
    #                   stare.m1_canibali + v2_canibali, 3 - stare.pozitie_barca,
    #                   stare.n2_misionari - v1_misionari, stare.m2_canibali - v2_canibali)

    if stare.n1_misionari > 0 and stare.n1_misionari < stare.m1_canibali:
        return False
    elif stare.n2_misionari > 0 and stare.n2_misionari < stare.m2_canibali:
        return False
    elif v1_misionari + v2_canibali > stare.capacitate_barca: 
        return False
    elif v1_misionari + v2_canibali > 0 and v1_misionari >= 0 and v2_canibali >= 0 and stare.pozitie_barca == 2:
        return False
    elif v1_misionari + v2_canibali < 0 and v1_misionari <= 0 and v2_canibali <= 0 and stare.pozitie_barca == 1:
        return False

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