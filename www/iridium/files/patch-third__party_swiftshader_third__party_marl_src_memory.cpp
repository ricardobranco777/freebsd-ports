--- third_party/swiftshader/third_party/marl/src/memory.cpp.orig	2025-05-07 06:48:23 UTC
+++ third_party/swiftshader/third_party/marl/src/memory.cpp
@@ -19,7 +19,7 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__OpenBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
