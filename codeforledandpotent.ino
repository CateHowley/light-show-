#define GREEN_LED 3 // where the green led is connected to the arduino board
#define YELLOW_LED 4 // where the yellow led is connected to arduino board
#define RED_LED 5 // where the red led is connected to arduino board 
#define BUTTON 1 // where the button is connected to arduino board
int potPin = A0; 
int potVal = 0; 
int brightness=0; // brightness for pent


int pin = 5;
void setup() { // defining input and output for each led and button
  // put your setup code here, to run once:

  pinMode(RED_LED, OUTPUT); 
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.begin(9600);
  Serial.setTimeout(10);  // this will wait 10 ms to proces the input
}

void loop() {

 // put your main code here, to run repeatedly:
  Serial.println(digitalRead(BUTTON)); 
  if (digitalRead(BUTTON) == 1) { // button in pin 1 and will read 1 in synapse
    digitalWrite(RED_LED, HIGH); // when pressing button the button will turn the red on
  } else {
    digitalWrite(RED_LED, LOW);
  }

  digitalWrite(GREEN_LED, HIGH); // green lights will flash
  digitalWrite(YELLOW_LED, HIGH); // yellow lights will flash

  delay(1000); // delay for the red button to turn on after the button is clicked 
  digitalWrite(RED_LED, LOW); // red off
  digitalWrite(GREEN_LED, LOW); // green off
  digitalWrite(YELLOW_LED, LOW); // yellow off 

  delay(1000);

  if (Serial.available() > 0) {  
    int flash = Serial.parseInt(); // reading the integer from serial number 
    Serial.println("flash number    :"); // print "flash Number" before the number that is greater than 0

    // this will make the led light flash a set amount of times
    for (int i = 0; i < 7; i++) {  // this will loop 7 times 
      digitalWrite(YELLOW_LED, HIGH);
      delay(150);
      digitalWrite(RED_LED, LOW);
      delay(150);
      digitalWrite(RED_LED, LOW);
      delay(150);





      // this will make the led light flash a set amount of times
     }
  }
  potVal = analogRead(potPin); // read the potentiometer value 
  
  brightness= 255*potVal/1023; //this is so the ranges of the led and pent match up
  analogWrite(GREEN_LED,brightness); // can control the brightness of the pent when you move it
  delay(1000); 
}
