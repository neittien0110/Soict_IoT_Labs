/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: Còi kêu/tắt liên tục ở 2 mức chu kì 2ms và 4ms, tương ứng với 2 tần số 1/2ms=500Hz và 1/4ms=250Hz
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module còi buzzer
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_3:_Passive_Buzzer
**/

int tonepin = 3; // Set the Pin of the buzzer to the digital D3
       
/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
   pinMode (tonepin, OUTPUT); // Set the digital IO pin mode to output
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
   unsigned char i, j;
   while (1)
   {
      for (i = 0; i <80; i ++) // output a frequency sound
      {
         digitalWrite (tonepin, HIGH); // Sound
         delay (1); // Delay 1ms
         digitalWrite (tonepin, LOW); // No sound
         delay (1); // Delay 1ms
      }
      for (i = 0; i <100; i ++) // output sound of another frequency
      {
         digitalWrite (tonepin, HIGH); // Sound
         delay (2); // delay 2ms
         digitalWrite (tonepin, LOW); // No sound
         delay (2); // delay 2ms
      }
   }
}