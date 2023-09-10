/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: Hiện 1 dòng chữ lên màn hình LCD 16 cột x 2 dòng
   Lưu ý:  Cần cài đặt thư viện LiquidCrystal_I2C của tác giả marco schwartz để sử dụng được đoạn
   chương trình bên dưới. Xem hướng dẫn cài đặt thư viện mới ở link bên dưới
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module màn hình LCD 16x2
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_12:_1602_LCD_Display

   Hướng dẫn cài đặt thư viện mới
   https://arduinokit.vn/huong-dan-them-moi-thu-vien-trong-arduino-ide/
   
**/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>      // Cần cài đặt thư viện LiquidCrystal_I2C của tác giả marco schwartz. Xem hướng dẫn ở trên

LiquidCrystal_I2C lcd (0x27,16,2); // set the LCD address to 0x27 for a16 chars and 2 line display

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  lcd.init (); // initialize the lcd
  lcd.init (); // Print a message to the LCD.
  lcd.backlight ();
  lcd.setCursor (3,0);
  lcd.print ("Hello, world!"); // LED print hello, world!
  lcd.setCursor (2,1);
  lcd.print ("Nhap mon CNTT!"); // LED print keyestudio!
  delay(2000);
  lcd.setCursor (0,0);
  lcd.print ("Toi la X      "); // LED print hello, world!  
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  // Không có gì phải làm cả. 
}
