--- src/3rdparty/chromium/content/browser/media/frameless_media_interface_proxy.h.orig	2024-05-21 18:07:39 UTC
+++ src/3rdparty/chromium/content/browser/media/frameless_media_interface_proxy.h
@@ -19,7 +19,7 @@
 #include "mojo/public/cpp/bindings/receiver_set.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/mojom/stable/stable_video_decoder.mojom.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -105,7 +105,7 @@ class FramelessMediaInterfaceProxy final
   // Connections to the renderer.
   mojo::ReceiverSet<media::mojom::InterfaceFactory> receivers_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Connection to the StableVideoDecoderFactory that lives in a utility
   // process. This is only used for out-of-process video decoding and only when
   // the FramelessMediaInterfaceProxy is created without a RenderProcessHost
