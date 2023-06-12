#include <Adafruit_NeoPixel.h>

int citlivost = 500; // 0-1023, urcuje hranici

int starterc = 0;

int LMpin = 9;
int LZpin = 10;
int LTerpin = 11;

int pinS0 = 4;
int pinS1 = 5;
int pinS2 = 6;
int pinS3 = 7;
int pinSIG = A0;

Adafruit_NeoPixel LEDterce = Adafruit_NeoPixel(80, LTerpin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LEDmag = Adafruit_NeoPixel(50, LMpin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LEDzlu = Adafruit_NeoPixel(50, LZpin, NEO_GRB + NEO_KHZ800);

int skorem = 0;
int skorez = 0;

int Mterc;
int Zterc;

int rychblik = 500; //ms

void setup() {
  
  pinMode(pinS0, OUTPUT); 
  pinMode(pinS1, OUTPUT); 
  pinMode(pinS2, OUTPUT); 
  pinMode(pinS3, OUTPUT); 

  Serial.begin(9600);

  for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(255,0,0)); 

      LEDterce.show(); 
  }

  do {
  delay(1);
  } while (nactiKanal(starterc) > citlivost);

  LEDmag.setPixelColor(0, LEDmag.Color(255,0,255));
  LEDzlu.setPixelColor(0, LEDzlu.Color(255,255,0));
  LEDmag.show();
  LEDzlu.show();

  for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(255,165,0)); 

      LEDterce.show(); 
  }

  delay(1000);

  for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(0,255,0)); 

      LEDterce.show(); 
  }

  delay(1000);

}

void loop() {
  
  if(skorem < 50 && skorez < 50){
    
    do {

      Mterc = Rand(0,15);
      Zterc = Rand(0,15);
      
    } while (Mter != Zterc);


    for(int i=x;i<y;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(255,0,255)); 

      LEDterce.show(); 
    }

    for(int i=x;i<y;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(255,255,0)); 

      LEDterce.show(); 
    }

  }
  else if (skorem > 50 && skorez < 50){

    for(int i=0;i<50;i++){

      LEDmag.setPixelColor(i, LEDmag.Color(0,0,0)); 

      LEDmag.show(); 
    }

    for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(0,0,0)); 

      LEDterce.show(); 
    }

    delay(rychblik);

    for(int i=0;i<50;i++){

      LEDmag.setPixelColor(i, LEDmag.Color(255,0,255)); 

      LEDmag.show(); 
    }

    for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(255,0,255)); 

      LEDterce.show(); 
    }

    delay(rychblik);

  }
  else if (skorem < 50 && skorez > 50){

    for(int i=0;i<50;i++){

      LEDzlu.setPixelColor(i, LEDzlu.Color(0,0,0)); 

      LEDzlu.show(); 
    }

    for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(0,0,0)); 

      LEDterce.show(); 
    }

    delay(rychblik);

    for(int i=0;i<50;i++){

      LEDzlu.setPixelColor(i, LEDzlu.Color(255,255,0)); 

      LEDzlu.show(); 
    }

    for(int i=0;i<80;i++){

      LEDterce.setPixelColor(i, LEDterce.Color(255,255,0)); 

      LEDterce.show(); 
    }

    delay(rychblik);

  }
  else{
    Serial.println("chyba!");
  };
}

int nactiKanal(int kanal){
  
  int ovladaciPiny[] = {pinS0, pinS1, pinS2, pinS3};
  
  int kanaly[16][4]={
    {0,0,0,0},  // kanál  0
    {1,0,0,0},  // kanál  1
    {0,1,0,0},  // kanál  2
    {1,1,0,0},  // kanál  3
    {0,0,1,0},  // kanál  4
    {1,0,1,0},  // kanál  5
    {0,1,1,0},  // kanál  6
    {1,1,1,0},  // kanál  7
    {0,0,0,1},  // kanál  8
    {1,0,0,1},  // kanál  9
    {0,1,0,1},  // kanál 10
    {1,1,0,1},  // kanál 11
    {0,0,1,1},  // kanál 12
    {1,0,1,1},  // kanál 13
    {0,1,1,1},  // kanál 14
    {1,1,1,1}   // kanál 15
  };
  
  for(int i = 0; i < 4; i ++){
    digitalWrite(ovladaciPiny[i], kanaly[kanal][i]);
  }
  
  int napetiSIG = analogRead(pinSIG);
  
  return napetiSIG;
}