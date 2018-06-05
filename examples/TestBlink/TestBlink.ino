// Include header
#include "BlinkMillis.h"

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
