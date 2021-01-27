
#define moto A1
#define moto1 A0
#define led A3
#define led1 10
#define heart A2
#define buzz 6


bool flag = false;
bool flag1 = false;

const int trigPin = 5;
const int echoPin = 4;
const int trigPin1 = 7;
const int echoPin1 = 8;

const int sweetbutton = 2;
const int spicebutton = 3;

long duration;
int distance;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(moto, OUTPUT);
  pinMode(moto1, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(heart, OUTPUT);
  pinMode(sweetbutton, INPUT_PULLUP);
  pinMode(spicebutton, INPUT_PULLUP);


}

void loop()
{
  flag = false;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
  digitalWrite(led, HIGH);
  digitalWrite(heart, HIGH);
  if ((distance > 10) && (distance <= 25))
  {
    if (distance == 0)
    {
      digitalWrite(moto, LOW);
    }
    else
    {
      if (flag == false)
      {
        digitalWrite(moto, HIGH);
        digitalWrite(buzz, HIGH);
        delay(100);
        digitalWrite(buzz, LOW);
        delay(1000);
        digitalWrite(moto, LOW);
        digitalWrite(heart, LOW);
        Serial.println("remove");
        flag = true;
        delay(4000);

      }
    }
  }



  bool flag1 = false;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;
  digitalWrite(led, HIGH);
  digitalWrite(heart, HIGH);
  if ((distance > 10) && (distance <= 25))
  {
    if (distance == 0)
    {
      digitalWrite(moto, LOW);
    }
    else
    {
      if (flag == false)
      {
        digitalWrite(moto, HIGH);
        digitalWrite(buzz, HIGH);
        delay(100);
        digitalWrite(buzz, LOW);
        delay(1000);
        digitalWrite(moto, LOW);
        digitalWrite(heart, LOW);
        Serial.println("remove");
        flag1 = true;
        delay(4000);

      }
    }
  }



}
