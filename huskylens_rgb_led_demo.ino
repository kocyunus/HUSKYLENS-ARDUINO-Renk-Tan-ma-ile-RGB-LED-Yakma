/*  Yunus Koç – HuskyLens Color → RGB LED (ortak ANOT) demo
 *  Kart: Arduino UNO
 *  HuskyLens: AUTO / I2C, Color Recognition, Learn Multiple = ON
 *  LED: Ortak anot (+5 V), R=D10, G=D11, B=D9 – DİRENÇSİZ kullanım!
 * --------------------------------------------------------------- */

#include <Wire.h>
#include <HUSKYLENS.h>

HUSKYLENS husky;

// --- LED pinleri (ortak anot) ---
constexpr byte R_PIN = 10;   // kırmızı
constexpr byte G_PIN = 11;   // yeşil
constexpr byte B_PIN =  9;   // mavi

/* Ortak anot LED’de:
   LOW  → akım akar → LED YANAR
   HIGH → iki uç da +5 V → LED SÖNER
*/
inline void setRGB(bool rOn, bool gOn, bool bOn)
{
  digitalWrite(R_PIN, rOn ? LOW : HIGH);
  digitalWrite(G_PIN, gOn ? LOW : HIGH);
  digitalWrite(B_PIN, bOn ? LOW : HIGH);
}

void setup()
{
  // Seri monitör – video çekerken çıktıları okuyabilmen için
  Serial.begin(115200);
  Serial.println(F("=== HuskyLens + RGB LED (common anode) ==="));

  // LED pinleri çıkış, başlangıçta kapalı
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  setRGB(false, false, false);

  // HuskyLens’e I²C üzerinden bağlan
  Wire.begin();                       // A4=SDA, A5=SCL
  if (husky.begin(Wire)) {
    Serial.println(F(">> HuskyLens BAGLANDI (I2C)"));
    husky.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
  } else {
    Serial.println(F("!! HuskyLens bulunamadi – kablo/protokol kontrol"));
  }
}

void loop()
{
  // HuskyLens’ten en son kareyi iste; bağlantı koparsa döngünün başına dön
  if (!husky.request()) {
    Serial.println(F("-- I2C hatasi / cevap yok"));
    setRGB(false, false, false);
    delay(200);
    return;
  }

  // Karede blok yoksa LED kapalı
  if (!husky.available()) {
    setRGB(false, false, false);
    delay(100);
    return;
  }

  // En büyük renk bloğu verisi
  HUSKYLENSResult r = husky.read();
  Serial.print(F("ID=")); Serial.print(r.ID);
  Serial.print(F("  x=")); Serial.print(r.xCenter);
  Serial.print(F("  y=")); Serial.print(r.yCenter);
  Serial.print(F("  w=")); Serial.print(r.width);
  Serial.print(F("  h=")); Serial.println(r.height);

  // ID’ye göre LED
  switch (r.ID) {
    case 1: setRGB(true,  false, false); break; // kırmızı
    case 2: setRGB(false, true,  false); break; // yeşil
    case 3: setRGB(false, false, true ); break; // mavi
    default:setRGB(false, false, false);        // tanımsız
  }

  delay(150);                                   // ≈6 fps
}
