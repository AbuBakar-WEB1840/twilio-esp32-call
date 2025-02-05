#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "your-network-ssid";
const char* password = "your-network-password";

// Twilio credentials
const char* account_sid = "your-twilio-accound-sid"
const char* auth_token = "your-account-token";
const char* twilio_number = "twilio-number";              // number which twilio assign
const char* your_phone_number = "your-phone-number";      // the phone number on which you want to call 

// Twilio API 
const char* twilio_api = "https://api.twilio.com/2010-04-01/Accounts/place-account-sid/Calls.json";   

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");

  // Create a call
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(twilio_api);
    http.setAuthorization(account_sid, auth_token); 

    // Build the POST data
    String postData = "To=" + String(your_phone_number) +
                      "&From=" + String(twilio_number) +
                      "&Twiml=" + String("<Response><Say>Hello... Suspicious Activity Happened</Say></Response>");


    // Make the POST request
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(postData);

    // Check the response
    if (httpResponseCode > 0) {
      Serial.printf("HTTP Response Code: %d\n", httpResponseCode);
      Serial.println(http.getString());
    } else {
      Serial.printf("Error in HTTP Request: %s\n", http.errorToString(httpResponseCode).c_str());
    }

    http.end(); 
  }
}

void loop() {
} 
