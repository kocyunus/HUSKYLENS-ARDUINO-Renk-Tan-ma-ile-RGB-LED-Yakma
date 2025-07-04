# HUSKYLENS-ARDUINO-Renk-Tan-ma-ile-RGB-LED-Yakma
• Renkli kartları kameraya gösterip aynı renkte LED’i yakma demo
# HuskyLens 🎥 + Arduino 🎛️ | Renk Tanıma ile RGB LED Yakma

Bu projede **HuskyLens AI Vision Sensor**’ün  
> **Color Recognition ➜ Learn Multiple**  
modu kullanılarak üç farklı renk (ID 1 – 2 – 3) öğreniliyor ve kamera ekranda bu renkleri gördüğünde **ortak anot** RGB LED’i aynı renkte yakıyor.

---

## 🛠️ Donanım Listesi

| Adet | Parça | Not |
| ---- | ----- | --- |
| 1 | HuskyLens (SEN0305/SEN0336) | AUTO / I²C mod |
| 1 | Arduino UNO R3 | Diğer AVR kartlarla da çalışır |
| 1 | Ortak anot RGB LED | Dirençsiz **LOW = yanar** mantığı |
| 4 | Jumper kablo (F-F) | HuskyLens bağlantısı |
| 3 | Jumper kablo (M-M) | LED pinleri |
| 1 | Breadboard | Hızlı prototip |

---

## 🔌 Bağlantı Şeması

| HuskyLens | Arduino UNO |  
|-----------|-------------|  
| VCC (kırmızı) | **5 V** |
| GND (siyah)  | **GND** |
| SDA (yeşil)  | **A4**  |
| SCL (mavi)   | **A5**  |

| RGB LED bacağı | Arduino pini |
|----------------|--------------|
| Ortak ANOT (+) | 5 V |
| R | D10 |
| G | D11 |
| B | D9  |

---

## 📑 Kurulum

1. Arduino IDE ≥ 2.0 kurulu olmalı.  
2. **Kütüphane:** `HUSKYLENS`  
   * **IDE › Tools › Library Manager** → **DFRobot HuskyLens** → *Install*  
3. HuskyLens menüsü  
   * *General Settings → Protocol Type → I²C*  
   * *Parameter Settings → Learn Multiple = ON* → *Save & Return*

---

## 💾 Kullanım

```bash
git clone https://github.com/<kullanici>/huskylens-rgb-led.git
cd huskylens-rgb-led
open huskylens_rgb_led_demo/huskylens_rgb_led_demo.ino
