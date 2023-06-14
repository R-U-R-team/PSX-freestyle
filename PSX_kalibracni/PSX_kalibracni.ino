#include <Adafruit_NeoPixel.h>

int citlivost = 500; // 0-1023, urcuje hranici

int LTerpin = 11;

int pinS0 = 4;
int pinS1 = 5;
int pinS2 = 6;
int pinS3 = 7;
int pinSIG = A0;

int rozsah[16][2]={
  {0,4},   //0
  {5,9},   //1
  {10,14}, //2
  {15,19}, //3
  {20,24}, //4
  {25,29}, //5
  {30,34}, //6
  {35,39}, //7
  {40,44}, //8
  {45,49}, //9
  {50,54}, //10
  {55,59}, //11
  {60,64}, //12
  {65,69}, //13
  {70,74}, //14
  {75,79}  //15
};

Adafruit_NeoPixel LEDterce = Adafruit_NeoPixel(80, LTerpin, NEO_GRB + NEO_KHZ800);

void setup() {
  

  pinMode(pinS0, OUTPUT); 
  pinMode(pinS1, OUTPUT); 
  pinMode(pinS2, OUTPUT); 
  pinMode(pinS3, OUTPUT); 

}

void loop() {
  
  for(int i=0;i<16;i++){
    if(nactiKanal(i)>citlivost){
      for(int y=rozsah[i][1];y<=rozsah[i][2];y++){
      
        LEDterce.setPixelColor(y, LEDterce.Color(0,255,0)); 

        LEDterce.show(); 
      }
    };
  }

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
