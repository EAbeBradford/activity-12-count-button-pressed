#define LED_PIN 7
#define BUTTON_PIN 2

volatile bool buttonPressed = false;
int LEDState = LOW;
int countButton = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), 
                  buttonPressedInterrupt, 
                  RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(buttonPressed){
    count();
    buttonPressed = false;
  }
}

void buttonPressedInterrupt(){
  buttonPressed = true;
}

void count(){
  countButton++;
  Serial.print("button has been pressed ");
  Serial.print(countButton);
  Serial.println(" times!");
}
