#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h> 

Servo myservo1;

int IR1 = 3; // Первый ИК датчик
int IR2 = 4; // Второй ИК датчик

const int MaxSlots = 5; // Максимальное количество парковочных мест
int Slot = MaxSlots; // Текущее количество свободных парковочных мест

int flag1 = 0; // Флаг для въезда
int flag2 = 0; // Флаг для выезда

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  myservo1.attach(2);
  myservo1.write(90); // Закрытое положение шлагбаума

  // Начальное сообщение на экране
  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYSTEM ");
  delay(2000);
  lcd.clear();  
}

void loop() {
  // Проверка на въезд (первый ИК датчик)
  if (digitalRead(IR1) == LOW && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      myservo1.write(0); // Открыть шлагбаум
      Serial.println("Въезд: Шлагбаум открыт");
      delay(1000); // Дать время на открытие
      Slot--; // Уменьшить количество свободных мест
      Serial.print("Осталось мест: ");
      Serial.println(Slot);

      // Закрытие шлагбаума после въезда
      delay(1000);
      myservo1.write(90); // Закрыть шлагбаум
      flag1 = 0; // Сброс флага после операции
    } else {
      lcd.setCursor(0, 0);
      lcd.print("    SORRY :(    ");  
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  "); 
      delay(3000);
      lcd.clear(); 
    }
  }

  // Проверка на выезд (второй ИК датчик)
  if (digitalRead(IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    myservo1.write(0); // Открыть шлагбаум
    Serial.println("Выезд: Шлагбаум открыт");
    delay(1000); // Дать время на открытие

    if (Slot < MaxSlots) {
      Slot++; // Увеличить количество свободных мест, если оно меньше максимального
      Serial.print("Осталось мест: ");
      Serial.println(Slot);
    }

    // Закрытие шлагбаума после выезда
    delay(1000);
    myservo1.write(90); // Закрыть шлагбаум
    flag2 = 0; // Сброс флага после операции
  }

  // Отображение количества свободных мест на экране
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1);
  lcd.print("Slot Left: ");
  lcd.print(Slot);
  lcd.print("   "); // Дополнительные пробелы для очистки строки
}
