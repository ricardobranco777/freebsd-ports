PORTNAME=	freedink
PORTVERSION=	108.4
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	GNU
PKGNAMESUFFIX=	-engine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dink Smallwood RPG and RPG Construction Set
WWW=		https://www.gnu.org/software/freedink/

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libcheck.so:devel/check

USES=		gettext gmake pkgconfig sdl
USE_SDL=	sdl gfx ttf image mixer
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-static --disable-upx

OPTIONS_DEFINE=	EMBEDDED
OPTIONS_DEFAULT=EMBEDDED

EMBEDDED_DESC=			Embedded Resources
EMBEDDED_CONFIGURE_ENABLE=	embedded-resources
EMBEDDED_BUILD_DEPENDS=		zip:archivers/zip
EMBEDDED_LIB_DEPENDS=		libzip.so:archivers/libzip
EMBEDDED_RUN_DEPENDS=		zip:archivers/zip

post-patch:
	@${CHMOD} 0755 ${WRKSRC}/autotools/install-reloc

.include <bsd.port.mk>
