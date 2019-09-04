# TestCppHttpClient

Android端使用[cpp-httplib](https://github.com/yhirose/cpp-httplib)的测试例子

ssl使用的测试so库
- [https://github.com/leenjewel/openssl_for_ios_and_android](https://github.com/leenjewel/openssl_for_ios_and_android)
- [https://github.com/PurpleI2P/OpenSSL-for-Android-Prebuilt](https://github.com/PurpleI2P/OpenSSL-for-Android-Prebuilt)

---

配置问题

- openssl_1.1.1 minSdkVersion需>=23。

- 需要zlib支持时要在target_link_libraries中加入 z (表示zlib库)才可以正常编译。

---
参考链接

- [https://github.com/leenjewel/openssl_for_ios_and_android/issues/48](https://github.com/leenjewel/openssl_for_ios_and_android/issues/48)
