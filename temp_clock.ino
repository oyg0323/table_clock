#include <DS1302.h>
#include <LiquidCrystal_I2C.h>

#include<DHT11.h>


const int kCePin   = 8;   // Chip Enable
const int kIoPin   = 7;   // Input/Output
const int kSclkPin = 6;   // Serial Clock
DHT11 dht11(5); 

DS1302 rtc(kCePin, kIoPin, kSclkPin);

LiquidCrystal_I2C lcd(0x27, 16, 2);

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "SUN";
    case Time::kMonday: return "MON";
    case Time::kTuesday: return "TUE";
    case Time::kWednesday: return "WED";
    case Time::kThursday: return "THU";
    case Time::kFriday: return "FRI";
    case Time::kSaturday: return "SAT";
  }
  return "";
}

void setup() {
  Serial.begin(9600);

  //rtc.writeProtect(false);
  //rtc.halt(false);
  //Time t(2017, 11, 11, 8, 43, 00, Time::kSaturday);
  //rtc.time(t);

  lcd.begin();
  lcd.print("test");
}


void loop()
{
  float humi, temp;
 dht11.read(humi, temp);

  Time t = rtc.time();
  const String day = dayAsString(t.day);
  char buf[50];
  snprintf(buf, sizeof(buf), "%02d-%02d %02d:%02d %s", t.mon, t.date, t.hr, t.min, day.c_str());
  lcd.setCursor(0, 0);
  lcd.print(buf);
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d", day.c_str(), t.yr, t.mon, t.date, t.hr, t.min, t.sec);
  Serial.println(buf);

  lcd.setCursor(0, 1);
  lcd.print("TE:");

  lcd.print((int)temp);
  lcd.print("'C");

  lcd.print(" HU:");
  lcd.print((int)humi);
  delay(1000);
  lcd.print("%");
}
