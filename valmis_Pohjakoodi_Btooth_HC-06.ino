//#include "DualVNH5019MotorShield.h"
#include <Servo.h> 

//DualVNH5019MotorShield md;
char dataIn='S';char determinant;char det;int vel = 0; //Bluetooth Stuff
//int power = 4; // Remove This To Enable Tollge Switch #2
int overdrive = 13; //Press Toggle Switch #1, the pin13 LED will light up
int ohjaus = 0, pos_alusta = 0, pos_tykki = 0, pos_keski = 90, pos_vasren = 87, pos_oikren = 120;
Servo vasp, oikp, vasen, oikea, vasreisi, oikreisi, vasren, oikren, keski, oikk, vask, alusta, tykki;


void setup(){
pinMode(7,OUTPUT); //ina1
pinMode(8,OUTPUT); //inb1
pinMode(4, OUTPUT); //ina2
pinMode(9,OUTPUT); //inb2
pinMode(5,OUTPUT); //pwm1
pinMode(6,OUTPUT); //pwm2



Serial.begin(9600);
//md.init();
/*pinMode(power , OUTPUT);*/ //toggle switch function
pinMode(overdrive, OUTPUT);
}

void loop(){  
  det = check();

if (det == 'F') // F, move forward
  { 
    vasren.attach(8);
    oikren.attach(9);
    delay(10);
    pos_vasren = pos_vasren + 1;
    pos_oikren = pos_oikren - 1;
    vasren.write(pos_vasren);
    oikren.write(pos_oikren);
    delay(10);
    vasren.detach();
    oikren.detach();
    det = check();

      
    
    }
  
if (det == 'B') // B, move backward
  { vasren.attach(8);
    oikren.attach(9);
    delay(10);
    pos_vasren = pos_vasren - 1;
    pos_oikren = pos_oikren + 1;
    vasren.write(pos_vasren);
    oikren.write(pos_oikren);
    delay(10);
    vasren.detach();
    oikren.detach();
    det = check();
    }

if (det == 'L') // L, move wheels left
  { 
    keski.attach(10);
    delay(10);
    pos_keski = pos_keski - 1;
    keski.write(pos_keski);
    delay(10);
    
    
    det = check();}
  
if (det == 'R') // R, move wheels right
  { 
    keski.attach(10);
    delay(10);
    pos_keski = pos_keski + 1;
    keski.write(pos_keski);
    delay(10);
    
    det = check();}

if (det == 'W') 
  { 
    
    vasp.attach(2);
    oikp.attach(3);
    delay(100);
    vasp.write(145);
    oikp.write(20);
    delay(1000);
    oikp.detach();
    vasp.detach();
    delay(100);
    
    vasreisi.attach(6);
    delay(100);
    vasreisi.write(70);
    delay(200);
    vasreisi.write(50);
    delay(200);
    vasreisi.write(30);
    delay(200);
    vasreisi.write(0);
    delay(500);
    vasreisi.detach();
    oikreisi.attach(7);
    delay(100);
    oikreisi.write(70);
    delay(200);
    oikreisi.write(90);
    delay(200);
    oikreisi.write(110);
    delay(200);    
    oikreisi.write(130);
    delay(500);
    oikreisi.detach();
    delay(100);

    vasen.attach(4);
    oikea.attach(5);
    delay(100);
    vasen.write(175);
    oikea.write(5);
    delay(1000);
    vasen.detach();
    oikea.detach();
    det = check();}



    

    
if (det == 'w') // R, move wheels right
  { 
    vasen.attach(4);
    oikea.attach(5);
    delay(100);
    vasen.write(5);
    oikea.write(180);
    delay(1000);
    vasen.detach();
    oikea.detach();
    delay(100);
    
    
    vasreisi.attach(6);
    oikreisi.attach(7);
    delay(200);
    vasreisi.write(30);
    oikreisi.write(100);
    delay(100);
    vasreisi.write(60);
    oikreisi.write(70);
    delay(100);
    vasreisi.write(90);
    oikreisi.write(40);
    delay(1000);
    oikreisi.detach();
    vasreisi.detach();
    delay(100);


    vasp.attach(2);
    oikp.attach(3);
    delay(100);
    vasp.write(90);
    oikp.write(80);
    delay(1000);
    oikp.detach();
    vasp.detach();
    
    det = check();}

if (det == 'S') // S, stop
{ vasen.detach();
  oikea.detach();
  oikp.detach();
  vasp.detach();
  vasreisi.detach();
  oikreisi.detach();
  vasren.detach();
  oikren.detach();
  keski.detach();
  vask.detach();
  oikk.detach();
  pos_vasren = 87;
  pos_oikren = 110;
  
  
  det = check();}


if (det == 'U') // 
  { 
    vask.attach(12);
    oikk.attach(11);
    delay(100);
    vask.write(10);
    oikk.write(160);
    delay(1000);
    vask.detach();
    oikk.detach();

    det = check();
    
  }


if (det == 'u') // 
  { 
    vask.attach(12);
    oikk.attach(11);
    delay(100);
    vask.write(180);
    oikk.write(0);
    delay(1000);
    oikk.detach();
    
    det = check();
    
  }






  
}

int check()
{if (Serial.available() > 0) {dataIn = Serial.read(); 
Serial.println(dataIn);
if (dataIn == 'F'){determinant = 'F';} 
else if (dataIn == 'B'){determinant = 'B';}else if (dataIn == 'L'){determinant = 'L';}
else if (dataIn == 'R'){determinant = 'R';}else if (dataIn == 'I'){determinant = 'I';} 
else if (dataIn == 'J'){determinant = 'J';}else if (dataIn == 'G'){determinant = 'G';} 
else if (dataIn == 'H'){determinant = 'H';}else if (dataIn == 'S'){determinant = 'S';}
else if (dataIn == '0'){vel = 400;}else if (dataIn == '1'){vel = 380;}
else if (dataIn == '2'){vel = 340;}else if (dataIn == '3'){vel = 320;}
else if (dataIn == '4'){vel = 280;}else if (dataIn == '5'){vel = 240;}
else if (dataIn == '6'){vel = 200;}else if (dataIn == '7'){vel = 160;}
else if (dataIn == '8'){vel = 120;}else if (dataIn == '9'){vel = 80;}
else if (dataIn == 'q'){vel = 40;}else if (dataIn == 'U'){determinant = 'U';}
else if (dataIn == 'u'){determinant = 'u';}else if (dataIn == 'W'){determinant = 'W';}
else if (dataIn == 'w'){determinant = 'w';}else if (dataIn == 'X'){determinant = 'X';}
else if (dataIn == 'x'){determinant = 'x';}}return determinant;}






int ylataso(){
  det = check();
 


  
if (det == 'B') // B, move backward
{if (pos_tykki > 0){
  alusta.attach(5);
  tykki.attach(6);  
  pos_tykki--;
  tykki.write(pos_tykki);
  det = check(); 
}
}

if (det == 'L') // L, move wheels left
{if (pos_alusta < 180){
  alusta.attach(5);
  tykki.attach(6);  
  pos_alusta++;
  alusta.write(pos_alusta);
   det = check();
}
}
  
if (det == 'R') // R, move wheels right
{if (pos_alusta > 0){
  alusta.attach(5);
  tykki.attach(6);
  pos_alusta--;
  alusta.write(pos_alusta);    
  det = check();
}
}

while (det == 'X') 
{  
   det = check();}


while (det == 'G'){
  ohjaus = 0;
  break;
  det = check();
  } 

if (det == 'S') // S, stop
 {tykki.detach();
  alusta.detach();
  det = check();}
 }




