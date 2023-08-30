/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: 
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module led
    - Module nút bấm
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: tắt bật đèn led bằng nút bấm
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_4%EF%BC%9AControlling_LED_by_Button_Module
**/

int ledpin = 5; // Define the led light in D5
int inpin = 4; // Define the button in D4
int val; // Define variable val

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  pinMode (ledpin, OUTPUT); // The LED light interface is defined as output
  pinMode (inpin, INPUT); // Define the button interface as input
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  val = digitalRead (inpin); // Read the digital 4 level value and assign it to val
  if (val == LOW) // Whether the key is pressed, the light will be on when pressed
  {
    digitalWrite (ledpin, HIGH);
  } else {
    digitalWrite (ledpin, LOW);
  }
}
