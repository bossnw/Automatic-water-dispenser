#define trigger1 2
#define echo1 3
#define trigger2 4
#define echo2 5
#define trigger3 6
#define echo3 7
#define trigger4 8
#define echo4 9
#define LED 13
#define MOSFET 12
#define LED0 10
#define LED1 11
 
 
 
float time1=0,distance1=0,time2=0,distance2=0,time3=0,distance3=0,time4=0,distance4=0;
 
void setup()
{
Serial.begin(9600);

 pinMode(trigger1,OUTPUT);
 pinMode(echo1,INPUT);
 pinMode(trigger2,OUTPUT);
 pinMode(echo2,INPUT);
 pinMode(trigger3,OUTPUT);
 pinMode(echo3,INPUT);
 pinMode(trigger4,OUTPUT);
 pinMode(echo4,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(LED0,OUTPUT);
 pinMode(LED1,OUTPUT);
 pinMode(MOSFET,OUTPUT);

 delay(2000);
}
 
void loop()
{
 measure_distance();

 if(distance1<10&&distance2<10&&distance3<10&&distance4<10) 
 {
   digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET,HIGH);
   Serial.println("1234");
 }
 else if(distance1<10&&distance2<10&&distance3<10)
 {
  digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET,HIGH);
  Serial.println("123");
 }
 else if(distance1<10&&distance2<10)
 {
  digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET,HIGH);
  Serial.println("12");
 }
 else if(distance1<10)
 {
  digitalWrite(LED,HIGH);digitalWrite(LED0,HIGH);digitalWrite(LED1,LOW);digitalWrite(MOSFET,HIGH);
  Serial.println("1");
 }
 else
 {   
   digitalWrite(LED,LOW);digitalWrite(MOSFET,LOW);digitalWrite(LED0,LOW);digitalWrite(LED1,HIGH);
 }

 delay(500);
}

void measure_distance()
{
 digitalWrite(trigger1,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger1,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger1,LOW);
 delayMicroseconds(2);
 time1=pulseIn(echo1,HIGH);
 distance1=time1*340/20000;

 digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger2,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 time2=pulseIn(echo2,HIGH);
 distance2=time2*340/20000;

  digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger3,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 time3=pulseIn(echo3,HIGH);
 distance3=time3*340/20000;
 
 digitalWrite(trigger4,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger4,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger4,LOW);
 delayMicroseconds(2);
 time4=pulseIn(echo4,HIGH);
 distance4=time4*340/20000;
}
