# Blink Millis

Membuat banyak LED berkedip menggunakan fungsi ```millis()```, tanpa fungsi ```delay()```. LED dapat berkedip tanpa menunda atau menghentikan  jalannya program utama (*non blocking*).

- Tidak memblok eksekusi
- Dapat membuat banyak blink secara bersamaan
- Jumlah perulangan blink dapat diatur
- Dapat membuat blink berulang terus-menerus (*infinity*)
- Tidak perlu memangil ```pinMode(x, OUTPUT)```

## Cara Penggunaan

**Langkah-1**: Include

```cpp
#include "BlinkMillis.h";
```

**Langkah-2**: Buat object

```cpp
// Parameter: pin, waktu_on, waktu_off, jumlah_ulang)
// Bila ingin berulang terus, jumlah_ulang diisi dengan -1
Blinker led1(D13, 100,  400, 10);
```

**Langkah-3**: Run dalam loop

```cpp
void loop() {
    led1.Run();
}

```

**Stop**: Menghentikan blink

```cpp
void loop() {
    led1.Stop();
}

```

### Contoh Lengkap

```cpp
// Include header
#include "BlinkMillis.h";

// Buat 2 buah LED blink pada pin 12 dan 13
Blinker led1(12, 100,  400, 10); // (pin, on, off, ulang)
Blinker led2(13, 3000, 350, 15);  // (pin, on, off, ulang)

void setup() {

}

void loop() {
    // Jalankan LED
    led1.Run();
    led2.Run();
}
```
