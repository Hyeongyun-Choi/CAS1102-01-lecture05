#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb/stb_image.h"

void decode_steganography(int image_data[], int data_size, std::string key) {

    int currentIndex = 1000;

    // TODO: Implement the solve_steganography function.
    /**
     * Implement a loop to decrypt the message, starting from index 1000.
     *
     * Every character is just a number (its ASCII code).
     * Type casting allows you to switch between these two views.
     *
     * - To get a number from a character: (int)key_char
     *   Example: (int)'A' results in the integer 65.
     * - To get a character from a number: (char)secret_value
     *   Example: (char)65 results in the character 'A'.
     *
     * The decryption process is as follows:
     * - Use the ASCII value of the repeating `key` characters to determine the jump distance.
     *   (Hint: use the modulo '%' operator).
     * - Update your current index with the jump distance, then read the value from `image_data`.
     *   Remember to always stay within the array bounds!
     * - If the value is 0, stop the loop. Otherwise, cast the value to a `char` and print it.
     */
    int keyIndex = 0;         // key 문자열에서 현재 참조할 인덱스

    while (true) {
        // key에서 현재 문자를 가져와서 ASCII 코드 구하기
        int jump = (int)key[keyIndex];

        // currentIndex를 jump 만큼 이동
        currentIndex += jump;

        // 배열 범위를 벗어나면 종료
        if (currentIndex >= data_size) {
            break;
        }

        // 이미지 데이터에서 값 읽기
        int secret_value = image_data[currentIndex];

        // 0이면 메시지 끝
        if (secret_value == 0) {
            break;
        }

        // 정수 -> 문자 변환해서 출력
        std::cout << (char)secret_value;

        // keyIndex 갱신 (반복 사용 위해 모듈러 연산)
        keyIndex = (keyIndex + 1) % key.size();
    }


}


// DO NOT EDIT THE MAIN FUNCTION
int main() {
    const char* image_path = "secret.png";
    int width, height, channels;

    unsigned char* img_data_char = stbi_load(image_path, &width, &height, &channels, 1);

    int data_size = width * height;

    int* image_data_int = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        image_data_int[i] = (int)img_data_char[i];
    }

    stbi_image_free(img_data_char);

    std::string user_key;
    std::cout << "Of the four pillars of OOP, what is the principle of separating interface and implementation? (First letter capitalized): ";
    std::cin >> user_key;

    std::cout << "------------------------------------------" << std::endl;
    decode_steganography(image_data_int, data_size, user_key);
    std::cout << "\n------------------------------------------" << std::endl;

    delete[] image_data_int;

    return 0;
}
