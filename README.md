# Documentație: Knight's Tour

## Descriere


Problema "Knight's Tour" constă în găsirea unui traseu închis pe o tablă de șah astfel încât un cal să treacă prin fiecare celulă a tablei o singură dată, respectând regulile de mișcare ale calului în șah.

Mișcarea unui cal în șah este specificată prin deplasarea sa în formă de "L". Adică, calul se deplasează doi pași într-o direcție (orizontală sau verticală) și apoi un pas perpendicular la direcția inițială. Aceasta poate fi descrisă prin diferite combinații de deplasări pe axele x și y..


## Intrare și Ieșire

- Utilizatorul este solicitat să introducă dimensiunea tablei de șah (n) și poziția de start a calului (x, y).
- Soluția sau mesajul de eșec este afișat la ieșire.

## Exemplu de Utilizare

```plaintext
## Exemplu de Utilizare

```plaintext
(Tasteaza 0 pentru a iesi din program:
Dimensiunea table de sah N*N:8
Pozitia de start (x y): 0 0
|   0 |  59 |  38 |  33 |  30 |  17 |   8 |  63 |
|  37 |  34 |  31 |  60 |   9 |  62 |  29 |  16 |
|  58 |   1 |  36 |  39 |  32 |  27 |  18 |   7 |
|  35 |  48 |  41 |  26 |  61 |  10 |  15 |  28 |
|  42 |  57 |   2 |  49 |  40 |  23 |   6 |  19 |
|  47 |  50 |  45 |  54 |  25 |  20 |  11 |  14 |
|  56 |  43 |  52 |   3 |  22 |  13 |  24 |   5 |
|  51 |  46 |  55 |  44 |  53 |   4 |  21 |  12 |

## Structura Codului

### Funcții

- **`afis(int n, int **sol)`**: Afișează soluția găsită pe tablă.
- **`valid(int x, int y, int n, int **sol)`**: Verifică dacă o anumită poziție pe tablă este validă pentru a muta calul.
- **`solve(int x, int y, int n, int movei, int **sol)`**: Funcția principală de rezolvare a problemei prin backtracking.
- **`cifra(char x)`**: Verifică dacă caracterul dat este o cifră.
- **`citeste_n()`**: Citeste un număr de la intrarea standard, asigurându-se că este valid.

### Funcția `main()`

- Inițializează dimensiunea tablei de șah și primește poziția de start de la utilizator.
- Alocă dinamic memorie pentru tablă.
- Inițializează tablă cu -1.
- Verifică dacă poziția de start este validă, altfel cere reintroducerea acesteia.
- Aplică algoritmul de rezolvare a problemei și afișează soluția sau un mesaj de eșec.

## Flux de Execuție

1. **Inițializare**
   - Alocare dinamică de memorie pentru tablă.
   - Inițializare a tablei cu -1.

2. **Citirea Inputului**
   - Citirea dimensiunii tablei și poziției de start de la utilizator.

3. **Validare**
   - Verificare dacă poziția de start este validă.

4. **Rezolvare**
   - Apelul funcției `solve()` pentru a găsi soluția.

5. **Afișare**
   - Afișarea soluției sau a mesajului de eșec.

6. **Eliberare Memorie**
   - Eliberarea memoriei alocate dinamic.


