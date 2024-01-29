file(GLOB subdirectories RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *) # все поддиректории
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME dir_name) # название текущей директории
cmake_path(GET CMAKE_CURRENT_LIST_DIR PARENT_PATH parent_path) # путь до родительской директории
cmake_path(GET parent_path FILENAME parent_name) # название родительской директории
# Цикл для создания целей с префиксом "родительская_текущая_файл"
foreach(subdir ${subdirectories})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        add_executable(${parent_name}_${dir_name}_${subdir} ${subdir}/main.cpp)
    endif()
endforeach()
