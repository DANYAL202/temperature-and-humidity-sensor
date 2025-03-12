#include <DHT.h>

#define DHTPIN 2     // Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11   // Defining sensor type

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

void setup() {
  Serial.begin(9600);  // Start the serial communication
  dht.begin();  // Initialize the DHT sensor
}

void loop() {
  // Reading temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if reading failed and exit early (try again)
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the values to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("°C");

  delay(2000);  // Wait for 2 seconds before next reading
}
