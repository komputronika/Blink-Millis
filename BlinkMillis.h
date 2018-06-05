//------------------------------------------------
//
//  Library Arduino: Blink Millis
//  Blink menggunakan millis()
//  - Tidak memblok eksekusi
//  - Dapat membuat banyak blink secara bersamaan
//  - Jumlah perulangan dapat diatur
//  - Dapat membuat blink infinity
//
//  Author: Komputronika.com
//
//------------------------------------------------

#include "Arduino.h"

#ifndef BLINKMILLIS_H
#define BLINKMILLIS_H

class Blinker {

    protected:
        int pinLED;                 // Pin untuk LED
        long waktuOn;               // Waktu menyala
        long waktuOff;              // Waktu mati
        int jumlahUlang;            // Jumlah blink diulang
        int statusLED;              // Status LED terakhir
        unsigned long millisLalu;   // Mencatat waktu terakhi LED diupdate

    public:

        //---------------------------------
        // Constructor: Blinker
        //---------------------------------
        Blinker(int pin, long on, long off, int ulang = -1)  {
            pinLED = pin;
            pinMode(pinLED, OUTPUT);

            waktuOn = on;
            waktuOff = off;

            jumlahUlang = ulang;
            statusLED = LOW;
            millisLalu = 0;
        }

        //---------------------------------
        // Run: Jalankan LED kedap-kedip
        //---------------------------------
        void Run() {
            // Catat nilai millis saat ini
            unsigned long millisKini = millis();

            // if (jumlahUlang>0 or jumlahUlang==-1) {

            // Ulangi selama jumlah jumlahUlang tidak sama dengan 0 atau jumlahUlang == -1 (infinity)
            if (jumlahUlang != 0) {
                if((statusLED == HIGH) && (millisKini - millisLalu >= waktuOn)) {
                    statusLED = LOW;                    // Jadikan off
                    millisLalu = millisKini;            // Catat lagi waktunya
                    digitalWrite(pinLED, statusLED);    // Update kondisi LED
                    if (jumlahUlang>0) jumlahUlang--;   // Kurangi jumlah perulangan
                } else if ((statusLED == LOW) && (millisKini - millisLalu >= waktuOff)) {
                    statusLED = HIGH;                   // Jadikan on
                    millisLalu = millisKini;            // Catat waktunya
                    digitalWrite(pinLED, statusLED);    // Update kondisi LED
                }
            }
        }

        //---------------------------------
        // Selesai: Mendeteksi apakah perulangan sudah selesai
        //---------------------------------
        bool Selesai() {
            // Kalau jumlahUlang sudah 0, berarti sudah selesai
            // Kalau jumlahUlang -1, maka fungsi ini selalu false
            // kecuali ada pemanggilan .Stop()
            return (jumlahUlang==0)
        }

        //---------------------------------
        // Stop: Stop LED blink
        //---------------------------------
        void Stop() {
            jumlahUlang = 0;                    // Habiskan jumlahUlang nya
            statusLED = LOW;                    // Status LED jadi LOW
            digitalWrite(pinLED, statusLED);    // Update kondisi LED
        }

}; // Akhir Class Blinker

#endif
