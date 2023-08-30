/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: Bật và tắt đèn led, nhấp nháy sáng đều
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module led, hoặc không cần vì đã có sẵn led D13 tích hợp sẵn trên bảng mạch Arduino UNO.
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_2:_Breathing_Light
**/

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}//