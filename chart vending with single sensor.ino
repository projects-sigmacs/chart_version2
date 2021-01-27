
#define moto A1
#define moto1 A0
#define led A3
#define led1 10
#define heart A2
#define buzz 6


bool flag = false;


const int trigPin = 5;
const int echoPin = 4;

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

  if (!digitalRead(sweetbutton))
  {
    while (!digitalRead(sweetbutton));
    delay(500);
    Serial.println("Sweet flavour");
    sweet();
  }

  if (!digitalRead(spicebutton))
  {
    while (!digitalRead(spicebutton));
    delay(500);
    Serial.println("Spice flavour");
    spice();
  }
}



void spice()
{
  delay(200);
  flag = false;
  while (1) {
    flag =false;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance1 = ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.print("place now");
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
    if  ( !digitalRead(spicebutton) || !digitalRead(sweetbutton))
    {
      while (!digitalRead(spicebutton) );
     
      digitalWrite(moto, LOW);
      Serial.println("Exit");
      digitalWrite(led, LOW);
      digitalWrite(heart, LOW);
      
      return 0;
    }
  }
}

void sweet()
{
  delay(200);
  flag = false;

  while (1) {
    flag=false;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.print("place now");
    digitalWrite(led1, HIGH);
    digitalWrite(heart, HIGH);

    if ((distance > 10) && (distance <= 25))
    {
      if (distance == 0)
      {
        digitalWrite(moto1, LOW);
      }
      else
      {
        if (flag == false) {
          digitalWrite(moto1, HIGH);
          digitalWrite(buzz, HIGH);
          delay(100);
          digitalWrite(buzz, LOW);
          delay(1000);
          digitalWrite(moto1, LOW);
          digitalWrite(heart, LOW);
          Serial.print("remove");
          flag = true;
          delay(4000);

        }
      }
    }

    if ( !digitalRead(spicebutton) || !digitalRead(sweetbutton))
    {
      while ( !digitalRead(sweetbutton));
     
      digitalWrite(moto, LOW);
      Serial.println("Exit");
      digitalWrite(led1, LOW);
      digitalWrite(heart, LOW);
      return 0;
    }

  }
}
