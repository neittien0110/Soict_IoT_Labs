/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: động cơ servo quay tròn từ góc 0* tới 180* và ngược lại
   Gợi ý: servo là loại động có có thể điều chỉnh chính xác quay một góc X độ, nhưng không thể
   quay tròn vĩnh viễn như các loại động cơ thường.
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Servo
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_7%EF%BC%9AAdjusting_Motor_Servo_Angle
**/

#include <Servo.h> // Servo function library
Servo myservo;
int pos = 0; // Start angle of servo

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  myservo.attach (9); // Define the position of the servo on D9
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  for(pos = 0; pos < 180; pos += 1)// angle from 0 to 180 degrees
  {
    myservo.write (pos); // The servo angle is pos
    delay (15); // Delay 15ms
  }
  for(pos = 180; pos>=1; pos-=1) // Angle from 180 to 0 degrees
  {
    myservo.write (pos); // The angle of the servo is pos
    delay (15); // Delay 15ms
  }
}
