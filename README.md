# TestCppHttpClient

Android端使用[cpp-httplib](https://github.com/yhirose/cpp-httplib)的测试例子

ssl使用的测试so库
- [https://github.com/leenjewel/openssl_for_ios_and_android](https://github.com/leenjewel/openssl_for_ios_and_android)
- [https://github.com/PurpleI2P/OpenSSL-for-Android-Prebuilt](https://github.com/PurpleI2P/OpenSSL-for-Android-Prebuilt)

---

配置问题

- openssl_1.1.1 minSdkVersion需>=23。

- 测试时发现在使用静态库编译时需要在target_link_libraries中加入 z (表示zlib库)才可以正常编译.。
