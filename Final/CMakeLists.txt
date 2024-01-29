file(GLOB subdirectories RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *) # Все поддиректории
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME dir_name) # Получаем название корневой директории
# Цикл для создания целей с префиксом "текущая_файл"
foreach(subdir ${subdirectories})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        add_executable(${dir_name}_${subdir} ${subdir}/main.cpp)
    endif()
endforeach()