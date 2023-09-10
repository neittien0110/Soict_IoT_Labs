/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: đo độ ẩm của đất rồi hiển thị ra màn hình lcd, đồng thời gửi về máy tính qua
   cổng COM. Ngoài ra trên màn hình lcd còn phân biệt 3 tình trạng của đất: khô, bình thường, ngập nước.
   Lưu ý:  Cần cài đặt thư viện LiquidCrystal_I2C của tác giả marco schwartz để sử dụng được đoạn
   chương trình bên dưới. Xem hướng dẫn cài đặt thư viện mới ở link bên dưới   
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module cảm biến độ ẩm của đất
    - Module màn hình LCD 16x2
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_13:_Soil_Humidity_Sensor

   Hướng dẫn sử dụng công cụ Monitor trong Arduino IDE để xem số liệu qua cổng COM
   https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor
   
   Hướng dẫn cài đặt thư viện mới
   https://arduinokit.vn/huong-dan-them-moi-thu-vien-trong-arduino-ide/   
**/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>       // Cần cài đặt thư viện LiquidCrystal_I2C của tác giả marco schwartz. Xem hướng dẫn ở trên

volatile int value;
LiquidCrystal_I2C mylcd (0x27,16,2); // set the LCD address to 0x27 for a16 chars and 2 line display

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  Serial.begin (9600); // Set the serial port baud rate to 9600
  value = 0;
  mylcd.init ();
  mylcd.backlight (); // Light up the backlight
  mylcd.clear (); // Clear the screen
  Serial.begin (9600); // Set the serial port baud rate to 9600
  pinMode (A2, INPUT); // Soil sensor is at A2, the mode is input
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  Serial.print ("Soil moisture value:"); // Print the value of soil moisture
  Serial.print ("");
  Serial.println (value);
  delay (500); // Delay 0.5S
  value = analogRead (A2); // Read the value of the soil sensor
  if (value <300) // If the value is less than 300
  {
    mylcd.clear (); // clear screen
    mylcd.setCursor (0, 0);
    mylcd.print ("value:"); //
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print ("dry soil"); // LCD screen print dry soil
    delay (300); // Delay 0.3S
  } else if ((value>=300) && (value <= 700)) { // If the value is greater than 300 and less than 700
    mylcd.clear (); //clear screen
    mylcd.setCursor (0, 0);
    mylcd.print ("value:");
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print ("humid soil"); // LCD screen printing humid soil
    delay (300); // Delay 0.3S
  } else if (value> 700) { // If the value is greater than 700
    mylcd.clear ();//clear screen
    mylcd.setCursor (0, 0);
    mylcd.print ("value:");
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print ("in water"); /// LCD screen printing in water
    delay (300); // Delay 0.3S
  }
}
