project(socket)

add_executable(stream_client stream_client.cpp)
add_executable(stream_server stream_server.cpp)

add_executable(datagram_client datagram_client.cpp)
add_executable(datagram_server datagram_server.cpp)