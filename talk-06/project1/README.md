Компиляция: `em++ main.cpp`
Проверка: `node a.out.js`

Генерация HTML: `em++ main.cpp -o hello.html`
Проверка: `python3 -m http.server`

Генерация cmake: `cmake . -DCMAKE_TOOLCHAIN_FILE=<emscripten>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake`
