/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: Điều khiển động cơ quay theo 3 mức: quay thuận chiều kim đồng hồ, ngược chiều
   kim đồng hồ, và dừng.
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - motor
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_8%EF%BC%9AFan_Module
**/

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
   pinMode (7, OUTPUT); //define D7 pin as output
   pinMode (6, OUTPUT); //define  D6 pin as output
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
   digitalWrite (7, LOW);
   digitalWrite (6, HIGH); // Reverse rotation of the motor
   delay (3000); // delay 3S
   digitalWrite (7, LOW);
   digitalWrite (6, LOW); // The motor stops rotating
   delay (1000); //delay 1S
   digitalWrite (7, HIGH);
   digitalWrite (6, LOW); // The motor rotates in the forward direction
   delay (3000); // delay 3S
}
