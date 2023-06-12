#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = LEDterce(80, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels = LEDmag(50, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels = LEDzlu(50, PIN, NEO_GRB + NEO_KHZ800);

int skorem;
int skorez;

int rychblik = 500; //ms

void setup() {
  
  Serial.begin(9600);


}

void loop() {
  
  if(skorem < 50 && skorez < 50){
    
  }
  else if (skorem > 50 && skorez < 50){

    for(int i=0;i<50;i++){

      LEDmag.setPixelColor(i, LEDmag.Color(0,0,0)); 

      LEDmag.show(); 
    }

    delay(rychblik);

    for(int i=0;i<50;i++){

      LEDmag.setPixelColor(i, LEDmag.Color(255,0,255)); 

      LEDmag.show(); 
    }

    delay(rychblik);

  }
  else if (skorem < 50 && skorez > 50){

    for(int i=0;i<50;i++){

      LEDzlu.setPixelColor(i, LEDzlu.Color(0,0,0)); 

      LEDzlu.show(); 
    }

    delay(rychblik);

    for(int i=0;i<50;i++){

      LEDzlu.setPixelColor(i, LEDzlu.Color(255,255,0)); 

      LEDzlu.show(); 
    }

    delay(rychblik);

  }
  else{
    Serial.println("chyba!");
  };
}