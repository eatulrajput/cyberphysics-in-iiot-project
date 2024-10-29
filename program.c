// Upload the following code into the NodeMCU:

// Define constants for the ultrasonic sensor pins
const int trigPin = D5;
const int echoPin = D6;


// Variables to store ultrasonic sensor measurements
long duration;
int distance;


// Setup function runs once at the beginning
void setup()
{
  // Set the trigPin as an output
  pinMode(trigPin, OUTPUT);


  // Set the echoPin as an input
  pinMode(echoPin, INPUT);


  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);
}


// Loop function runs repeatedly
void loop()
{
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  // Read the echoPin, which returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);


  // Calculate the distance using the formula: distance = speed * time / 2
  // Speed of sound is approximately 34 cm per millisecond (or 0.034 cm/microsecond)
  distance = duration * 0.034 / 2;


  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");


  // Wait for 2 seconds before taking the next measurement
  delay(2000);
}
