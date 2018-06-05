# Blink Millis

Membuat banyak LED blinking menggunakan fungsi millis(), tanpa fungsi delay. LED dapat berkedip tanpa mengganggu jalannya program utama (non blocking).

- Tidak memblok eksekusi
- Dapat membuat banyak blink secara bersamaan
- Jumlah perulangan dapat diatur
- Dapat membuat blink infinity

```cpp
// Include header
#include "BlinkMillis.h";

// Buat 2 buah LED blink pada pin 12 dan 13
Blinker led1(12, 100,  400, 10); // (pin, on, off, ulang)
Blinker led2(13, 3000, 350, 3);  // (pin, on, off, ulang)

void setup() {

}

void loop() {
    // Jalankan LED
    led1.Run();
    led2.Run();
}
```
