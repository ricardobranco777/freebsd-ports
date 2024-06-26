PORTNAME=	geogebra
PORTVERSION=	5.0.752.0
CATEGORIES=	math education java
MASTER_SITES=	http://download.geogebra.org/installers/5.0/ \
		https://static.geogebra.org/images/ \
		http://freebsd.uzsolt.hu/src/
DISTNAME=	GeoGebra-Linux-Portable-${PORTVERSION:S/./-/g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} geogebra.png geogebra-logo.svg
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Dynamic software that joins geometry, algebra, and calculus
WWW=		https://www.geogebra.org/

LICENSE=	GEOGEBRA
LICENSE_NAME=	GeoGebra Non-Commercial License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:bzip2 desktop-file-utils gnome shebangfix shared-mime-info
USE_JAVA=	yes

CONFLICTS=	math/geogebra-i18n

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

SUB_FILES=	geogebra.desktop geogebra.sh
SUB_LIST=	JAVA=${JAVA}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/geogebra.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/geogebra/*.jar ${STAGEDIR}${DATADIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${FILESDIR}/geogebra-mime.xml ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKDIR}/geogebra.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${DISTDIR}/geogebra.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/geogebra.png
	${INSTALL_DATA} ${DISTDIR}/geogebra-logo.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/geogebra.svg

.include <bsd.port.mk>
