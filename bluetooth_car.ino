// Define motor pins
const int motor1Pin1 = 2; // IN1 for Motor 1
const int motor1Pin2 = 3; // IN2 for Motor 1
const int motor1En = 5;   // ENA for Motor 1 (PWM)

const int motor2Pin1 = 7; // IN3 for Motor 2
const int motor2Pin2 = 8; // IN4 for Motor 2
const int motor2En = 6;   // ENB for Motor 2 (PWM)

// Define LED pin
const int ledPin = 13;

int data;
int Speeed = 255; // Change this value between 0 to 255 for speed

void setup() {
  // Set up motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1En, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2En, OUTPUT);

  // Set up LED pin as output
  pinMode(ledPin, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize motors and LED to off
  Stop();
  digitalWrite(ledPin, LOW);
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data);

    // Motor control commands
    if (data == 'F') {
      forward();
    } else if (data == 'B') {
      back();
    } else if (data == 'L') {
      left();
    } else if (data == 'R') {
      right();
    } else if (data == 'T') {
      Stop();
    }

    // LED control commands
    if (data == 'A') {
      digitalWrite(ledPin, HIGH);
    } else if (data == 'B') {
      digitalWrite(ledPin, LOW);
    }
  }
}

// Motor control functions
void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(motor1En, Speeed);

  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(motor2En, Speeed);
}

void back() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  analogWrite(motor1En, Speeed);

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(motor2En, Speeed);
}

void left() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  analogWrite(motor1En, Speeed);

  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(motor2En, Speeed);
}

void right() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(motor1En, Speeed);

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(motor2En, Speeed);
}

void Stop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(motor1En, 0);

  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(motor2En, 0);
}
