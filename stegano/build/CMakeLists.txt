cmake_minimum_required(VERSION 3.5.0)
project(stegano VERSION 0.1.0 LANGUAGES C)

find_package(PNG REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(test1 bitstream.c test1.c )
add_executable(test2 bitstream.c test2.c )
add_executable(test3 bitstream.c test3.c )
add_executable(test_png pngtest.c pngwrap.c)
add_executable(test_code png_test_code.c pngwrap.c message.c bitstream.c MD��x舽�]S�l�zђ�����F�ʑ���$[�rN��9$�_2���Z��0٬�Y� '˜��L�?�I�Q޵��iC���"�fk����䏃Z�E�Ǹ@�rz:+^�r�P�g����x54�/��J�be��*A�H8|�����f'BC����)hǜ����d�-WL���D�:�.Q<��|Z�^�y2�2�L�%���j~�"��i�)�b�(�xIZ3OϦ/vcw&2�F�z�m#t��('�<�i�1���