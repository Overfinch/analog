
const int analogInPin = A1; 
const int analogOutPin = 9;

int FF =7;
int FR =6;
int Low =5;
int LFR =4;
int inPinff =12;
int inPinfr =8;
int ff = 0;
int fr = 0;

long  in = 0;        // value read from the pot
long  out = 0;        // value output to the PWM (analog out)
long  tempval;       // temp value for multipiing 


long minrange = 400; // ЗДЕСЬ ПОДСТАВЛЯЙ МИНИМАЛЬНЫЙ ПОРОГ 0-1023
long maxrange = 800; // ЗДЕСЬ ПОДСТАВЛЯЙ МАКСИМАЛЬНЫЙ ПОРОГ 0-1023, НО ВЫШЕ МИНИМАЛЬНОГО
long interval = maxrange - minrange;

void setup()
{
  pinMode(FF, OUTPUT);
  pinMode(FR, OUTPUT);
  pinMode(Low, OUTPUT);
  pinMode(LFR,OUTPUT );
  Serial.begin(9600);
}
void loop()
{
  ff = digitalRead(inPinff);
  fr = digitalRead(inPinfr);
  if(ff == 0){
  digitalWrite(FF, HIGH);}
  else{
    digitalWrite(FF,LOW );}
   if(fr == 0){
  digitalWrite(FR, HIGH);
  digitalWrite(LFR, HIGH);
   }else{
    digitalWrite(FR,LOW );
    digitalWrite(LFR,LOW );
  }
  if(ff == 0){
  digitalWrite(Low, LOW);}
  else{
    digitalWrite(Low,HIGH );
    }

    // analog read below

    in = analogRead(analogInPin);
    
      if(in >= minrange and in <= maxrange){
    
        tempval = in - minrange; 
        out = 255*tempval/interval;
        
      }else if(in < minrange){
        out = 0;
      }else if(in > maxrange){
        out = 255;
      }
   
      // print the results to the serial monitor:
      Serial.print("in = ");
      Serial.print(in);
      Serial.print("\t tempval = ");
      Serial.print(tempval);
      Serial.print("\t out = ");
      Serial.println(out);


      analogWrite(analogOutPin, out);
      delay(2);

 
}
