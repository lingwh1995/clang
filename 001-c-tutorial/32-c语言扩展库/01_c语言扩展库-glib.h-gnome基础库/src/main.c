#include <glib.h>

/**
 * GLib - GNOME 基础库
 *
 * 1. 官网
 *    https://developer.gnome.org/glib/
 * 2. 功能
 *    数据结构、实用函数、事件循环、线程等
 * 3. 普通方式安装
 *    - windows(打开 MSYS2 UCRT64 的终端，执行以下命令)
 *       pacman -Syu                             # 更新系统
 *       pacman -S mingw-w64-ucrt-x86_64-glib2   # 安装glib2
 *       pacman -Qs glib2                        # 检查是否安装成功
 *    - linux
 *       sudo apt-get update
 *       sudo apt-get install libglib2.0-dev
 * 4. conan方式安装
 *    - 编写 conanfile.txt 和 CMakeLists.txt
 *    - pip install conan                                     # 安装conan
 *    - conan remote add conancenter https://center.conan.io  # 设置仓库
 *    - conan install . --output-folder=cmake-build-debug --build=missing # 安装依赖（在conanfile.txt同级别目录下执行）

 */
int main()
{
    // 动态数组
    GArray *array = g_array_new(FALSE, FALSE, sizeof(int));
    g_array_append_val(array, 10);
    g_array_append_val(array, 20);

    // 哈希表
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(hash, "key", "value");

    // 字符串操作
    gchar *str = g_strdup("Hello");
    gchar *upper = g_ascii_strup(str, -1);

    g_free(str);
    g_free(upper);
    g_array_free(array, TRUE);
    g_hash_table_destroy(hash);
    return 0;
}
