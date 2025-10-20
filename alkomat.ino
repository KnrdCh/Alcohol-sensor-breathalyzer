int raw;
float volt;
float ppm;
float promile;
int czyAlk;

void setup() 
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
}

void loop() 
{
  raw = analogRead(A0);
  volt = raw * (5.0 / 1023.0);

  ppm = volt * 200;
  promile = ppm /1000;

  czyAlk = digitalRead(3);

  if (czyAlk > 0)
    digitalWrite(2, HIGH);
  else 
    digitalWrite(2, LOW);

  Serial.println(promile);

  delay(500);
}