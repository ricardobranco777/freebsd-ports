--- chrome/browser/signin/signin_util.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -80,7 +80,7 @@ CookiesMover::CookiesMover(base::WeakPtr<Profile> sour
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
