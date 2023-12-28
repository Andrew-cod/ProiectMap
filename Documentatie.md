# Documentație: Knight's Tour

## Descriere

Problema "Knight's Tour" constă în găsirea unui traseu închis pe o tablă de șah, astfel încât calul să treacă printr-o singură dată prin fiecare celulă a tablei, respectând regulile de mișcare ale calului în șah.

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

## Intrare și Ieșire

- Utilizatorul este solicitat să introducă dimensiunea tablei de șah (n) și poziția de start a calului (x, y).
- Soluția sau mesajul de eșec este afișat la ieșire.

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

## Exemplu de Utilizare

```plaintext
(Tasteaza 0 pentru a iesi din program:
Dimensiunea table de sah N*N: 8
Pozitia de start (x y): 0 0
|   0 |  59 |   2 |  49 |   4 |  41 |   6 |  51 |
|  33 |   8 |  57 |  22 |  63 |  36 |  11 |  40 |
|   1 |  58 |  23 |  50 |   3 |  42 |   5 |  52 |
|  32 |  35 |  10 |  37 |  56 |  21 |  62 |  39 |
|   9 |  24 |  55 |  18 |  61 |  48 |  13 |  26 |
|  34 |  31 |  38 |  53 |  20 |  19 |  12 |  43 |
|  25 |  54 |  17 |  60 |  47 |  14 |  27 |  44 |
|  30 |  15 |  46 |  29 |  16 |  45 |  28 |  7  |
