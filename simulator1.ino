const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 6;
const int redLED = 7;
const int buzzer = 8;

const int threshold = 20;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(buzzer, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    long duration;
    float distance;

    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    // Read the returning echo
    duration = pulseIn(echoPin, HIGH);

    // Convert time into distance in centimeters
    distance = duration * 0.0343 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check if the parking space is occupied
    if (distance <= threshold)
    {
        // Vehicle detected
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzer, HIGH);

        Serial.println("Status: OCCUPIED");
    }
    else
    {
        // Parking space available
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        digitalWrite(buzzer, LOW);

        Serial.println("Status: AVAILABLE");
    }

    delay(500);
}