# 🍷 Alcohol Concentration Detection with MQ Sensor (Arduino)

This project measures the **alcohol concentration in the air** using an **MQ-type alcohol gas sensor** (e.g. MQ-3).  
It reads the analog voltage from the sensor, estimates alcohol concentration in **PPM**, and converts it (approximately) to **promiles (‰)** — although this conversion is not scientifically accurate.

---

## ⚠️ Disclaimer

> ⚠️ This project is **for educational and experimental purposes only**.  
> It **does not provide reliable measurements** of blood alcohol concentration (BAC).  
> The PPM → promile conversion in the code is approximate and not medically or legally valid.

---

## 🧠 Description

- The sensor’s **analog output (A0)** provides a voltage proportional to the alcohol level in the air.  
- The voltage is converted to **PPM (parts per million)** using a simple scaling factor.  
- The **digital output (D3)** indicates whether alcohol is detected above a certain threshold.  
- An **LED on pin D2** lights up when alcohol is detected.  
- The result (estimated promile value) is printed in the **Serial Monitor**.

---

## ⚙️ Hardware Requirements

- Arduino UNO / Nano or compatible board  
- Alcohol gas sensor (e.g. MQ-3, MQ-135)  
- LED + 220 Ω resistor  
- Jumper wires  

---

## 🔌 Connections

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| Sensor analog output (A0) | A0 | Analog signal (alcohol level) |
| Sensor digital output (D0) | D3 | Digital detection signal |
| LED | D2 | Lights up when alcohol detected |
| Sensor VCC | 5V | Power |
| Sensor GND | GND | Ground |

---

## 💻 Code Overview

```cpp
int raw;
float volt;
float ppm;
float promile;
int czyAlk;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);  // LED
  pinMode(3, INPUT);   // Sensor digital output
  pinMode(A0, INPUT);  // Sensor analog output
}

void loop() {
  raw = analogRead(A0);
  volt = raw * (5.0 / 1023.0);

  ppm = volt * 200;        // Simplified conversion
  promile = ppm / 1000;    // Approximation – not accurate

  czyAlk = digitalRead(3);

  if (czyAlk > 0)
    digitalWrite(2, HIGH); // LED ON if alcohol detected
  else 
    digitalWrite(2, LOW);  // LED OFF

  Serial.println(promile); // Display estimated value

  delay(500);
}
