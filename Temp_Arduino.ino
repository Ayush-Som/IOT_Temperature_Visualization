const int tempSensorPin = A0; // TMP36 sensor connected to A0

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Wait for the serial monitor to open
  while (!Serial) {
    ;
  }

  // Print the header to the serial monitor
  Serial.println("Time\t\t\tTemperature (Celsius)");
}

void loop() {
  // Get the current time in milliseconds
  unsigned long currentMillis = millis();

  // Read the raw ADC value from the temperature sensor
  int rawValue = analogRead(tempSensorPin);

  // Convert the ADC value to Celsius temperature
  float temperatureCelsius = convertToCelsius(rawValue);

  // Print the time and temperature to the serial monitor
  printTime(currentMillis);
  Serial.print("\t\t");
  Serial.println(temperatureCelsius);

  // Wait for a short time before taking the next reading
  delay(1000);
}

// Function to convert ADC value to Celsius temperature
float convertToCelsius(int adcValue) {
  // Assuming a 5V reference voltage for the TMP36 sensor
  float voltage = (adcValue / 1023.0) * 5.0;
  return (voltage - 0.5) * 100.0;
}

// Function to print the time
void printTime(unsigned long currentMillis) {
  unsigned long seconds = currentMillis / 1000;
  int hours = seconds / 3600;
  int minutes = (seconds % 3600) / 60;
  int secondsRemain = seconds % 60;

  // Print the time in HH:mm:ss format
  if (hours < 10) {
    Serial.print("0");
  }
  Serial.print(hours);
  Serial.print(":");
  if (minutes < 10) {
    Serial.print("0");
  }
  Serial.print(minutes);
  Serial.print(":");
  if (secondsRemain < 10) {
    Serial.print("0");
  }
  Serial.print(secondsRemain);
}
