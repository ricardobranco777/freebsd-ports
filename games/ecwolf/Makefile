PORTNAME=	ecwolf
PORTVERSION=	1.4.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://maniacsvault.net/ecwolf/files/ecwolf/1.x/

PATCH_SITES=	https://bitbucket.org/ecwolf/ecwolf/commits/400aaf96a36a14ab8eab18a670ba6439046f3bb0/
PATCHFILES=	raw:-p1

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Source port for Wolfenstein 3D, Spear of Destiny
WWW=		https://maniacsvault.net/ecwolf/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/license-gpl.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang gnome jpeg localbase:ldflags \
		pkgconfig sdl tar:xz
USE_GNOME=	cairo gdkpixbuf gtk20
USE_SDL=	mixer2 net2 sdl2

SUB_FILES=	ecwolf pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/${PORTNAME}/${PORTNAME} \
		share/${PORTNAME}/${PORTNAME}.pk3

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}.pk3 \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
