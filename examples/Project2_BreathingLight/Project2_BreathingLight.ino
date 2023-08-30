/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: Đèn led sáng dần từ từ, tối dần từ từ.
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module led
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_2:_Breathing_Light
**/

int ledPin = 5; // Define the LED pin at D5

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
      pinMode (ledPin, OUTPUT); // initialize ledpin as an output.
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
for (int value = 0; value<255; value = value + 1) { // Thiết lập mức độ sáng của đèn tăng dần
     analogWrite (ledPin, value); // Yêu cầu đèn led sáng theo mức đã thiết lập
     delay (5); // Đợi/không làm gì cả trong 5 giây --> duy trì mức độ sáng trong 5 giây
   }
   for (int value = 255; value>0; value = value-1) {  // Thiết lập mức độ sáng của đèn giảm dần
     analogWrite (ledPin, value); // Yêu cầu đèn led sáng theo mức đã thiết lập
     delay (5); // Đợi/không làm gì cả trong 5 giây --> duy trì mức độ sáng trong 5 giây
   }}
//