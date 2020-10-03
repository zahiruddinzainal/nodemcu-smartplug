#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// the project name address from firebase id
#define FIREBASE_HOST "replace with your own firebase"
// the secret key generated from firebase              
#define FIREBASE_AUTH "replace with your own firebase" 
// input your home or public wifi name 
#define WIFI_SSID "Zahir"
//password of wifi ssid
#define WIFI_PASSWORD "zahirpunya"


#define Relay1 14  //D5
#define Relay2 12  //D6
#define Relay3 13  //D7
#define Relay4 15  //D8
int rel1,rel2,rel3,rel4;

void setup() 
{
  Serial.begin(115200);// Set the baud rate 115200 in Serial Monitor to display debug messages
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);
  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  //Here the varialbe"FB1","FB2","FB3" and "FB4" needs to be the one which is used in our Firebase and MIT App Inventor
  Firebase.setInt("database/plug 1",0);     
  Firebase.setInt("database/plug 2",0); 
  Firebase.setInt("database/plug 3",0); 
  Firebase.setInt("database/plug 4",0);                 
  
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // initialize the firebase with HOST name anf AUTH key
  }

void loop() 
{
  if (Firebase.failed())
      {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());
      firebasereconnect();
      return;
      }
      
  rel1=Firebase.getString("database/plug 1").toInt();  //Reading the value of the varialble Status from the firebase
  rel2=Firebase.getString("database/plug 2").toInt();  //Reading the value of the varialble Status from the firebase
  rel3=Firebase.getString("database/plug 3").toInt();  //Reading the value of the varialble Status from the firebase
  rel4=Firebase.getString("database/plug 4").toInt();  //Reading the value of the varialble Status from the firebase
  
  if(rel1==1)                        // If, the Status is 1, turn on the Relay1
     {
      digitalWrite(Relay1,LOW);
      Serial.println("Relay 1 ON");
    }
 if(rel1==0)                         // If, the Status is 0, turn Off the Relay1
    {                                      
      digitalWrite(Relay1,HIGH);
      Serial.println("Relay 1 OFF");
    }
if(rel2==1)                          // If, the Status is 1, turn on the Relay2
     {
      digitalWrite(Relay2,LOW);
      Serial.println("Relay 2 ON");
    }
 if(rel2==0)                         // If, the Status is 0, turn Off the Relay2
    {                                      
      digitalWrite(Relay2,HIGH);
      Serial.println("Relay 2 OFF");
    }
if(rel3==1)                          // If, the Status is 1, turn on the Relay3
     {
      digitalWrite(Relay3,LOW);
      Serial.println("Relay 3 ON");
    }
if(rel3==0)                          // If, the Status is 0, turn Off the Relay3
    {                                      
      digitalWrite(Relay3,HIGH);
      Serial.println("Relay 3 OFF");
    }
 if(rel4==1)                         // If, the Status is 1, turn on the Relay4
     {
      digitalWrite(Relay4,LOW);
      Serial.println("Relay 4 ON");
    }
if(rel4==0)                          // If, the Status is 0, turn Off the Relay4
    {                                      
      digitalWrite(Relay4,HIGH);
      Serial.println("Relay 4 OFF");
    }    
}
