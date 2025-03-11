# STM746 - PWM

## Konfiguracja PWM
PWM zostało ustawione pod timer 3, który znajduje się pod zegarem magistrali APB1.

### Szczegóły konfiguracji:
- **Deklaracja:** W pliku `functions.h`
- **Implementacja:** W pliku `functions.c`
- **Zegar APB1:** 72 MHz

### Parametry timera:
- **Prescaler:** 71  
  Prescaler dzieli zegar APB1. Wartość 71 oznacza podział zegara na 72 (ponieważ liczymy od 0).

- **Counter:** 999  
  Counter liczy od 0 do 999, co daje łącznie 1000 cykli na okres.

- **Auto-reload enable:**  
  Zapobiega wydłużeniu lub skróceniu okresu w trakcie zmiany parametrów podczas trwania bieżącego okresu, poprzez zresetowaniu licznika.

### Obliczenia:
Zegar wyjściowy PWM można obliczyć ze wzoru:
Częstotliwość PWM =Zegar APB1 / ((Prescaler + 1) X (Counter + 1))

Podstawiając:
Częstotliwość PWM =72Mhz / ((71 + 1) X (999 + 1))=1KHz


## Ważne informacje
Timer 3 został skonfigurowany tak, aby generować sygnał PWM o częstotliwości 1 kHz. Implementacja szczegółów znajduje się w odpowiednich plikach kodu, co pozwala na łatwą modyfikację parametrów w razie potrzeby.

