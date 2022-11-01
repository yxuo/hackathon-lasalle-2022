#include <RH_ASK.h>   // Include the RH_ASK library
#include <SPI.h>      // Not actually used but needed to compile the RH_ASK library
 
RH_ASK radio(2000, 11, 12);
 
void setup()
{
    Serial.begin(9600);   // Use this for debugging
 
    // Speed of 2000 bits per second
    // Use pin 11 for reception
    // Use pin 12 for transmission
    
    if (!radio.init())
    {
         Serial.println("Radio module failed to initialize");
    }
}
 
void loop()
{
    // Create our message
    const char *msg = "Hello World";
 
    // Send our message
    radio.send((uint8_t*)msg, strlen(msg));
 
    // Wait until the data has been sent
    radio.waitPacketSent();
 
    // Delay since we dont want to send a trillion packets 
    delay(1000);
 
    // Also inform the serial port that we are done!
    Serial.println("Data Sent");
}

void rad()
{
    Serial.begin(9600);   // Use this for debugging
 
    // Speed of 2000 bits per second
    // Use pin 11 for reception
    // Use pin 12 for transmission
    
    if (!radio.init())
    {
         Serial.println("Radio module failed to initialize");
    }
}
 
void devolve()
{
  // Create a 32 byte char buffer
  uint8_t receive_buffer[32];
  uint8_t buflen = sizeof(receive_buffer);
 
  // If data is available, print it
  if (radio.recv(receive_buffer, &buflen))
  {
    Serial.print("Message: ");
    Serial.println((char*)receive_buffer);         
  }
}