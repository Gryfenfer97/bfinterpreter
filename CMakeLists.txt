cmake_minimum_required(VERSION 3.8)

project(bfi)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(bfi main.cpp)

install(TARGETS bfi
		DESTINATION bin
		PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
            GROUP_EXECUTE GROUP_READ
		)
