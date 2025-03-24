cmake_minimum_required(VERSION 3.5.0)
project(stegano VERSION 0.1.0 LANGUAGES C)

find_package(PNG REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(test1 bitstream.c test1.c )
add_executable(test2 bitstream.c test2.c )
add_executable(test3 bitstream.c test3.c )
add_executable(test_png pngtest.c pngwrap.c)
add_executable(test_code png_test_code.c pngwrap.c message.c bitstream.c MD5.c)
add_executable(test_decode png_test_decode.c pngwrap.c message.c MD5.c bitstream.c)

target_link_libraries(test_png PRIVATE PNG::PNG)
target_link_libraries(test_code PRIVATE PNG::PNG OpenSSL::Crypto) 
target_link_libraries(test_decode PRIVATE PNG::PNG OpenSSL::Crypto) 
 