PORTNAME=	font-awesome
DISTVERSION=	6.2.1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://use.fontawesome.com/releases/v${DISTVERSION}/
DISTNAME=	fontawesome-free-${DISTVERSION}-desktop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of pictographic icons from Font Awesome (free version)
WWW=		https://fontawesome.com/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	site:https://github.com/FortAwesome/Font-Awesome/releases

PLIST_FILES=	${FONTSDIR}/Font\ Awesome\ 6\ Brands-Regular-400.otf \
		${FONTSDIR}/Font\ Awesome\ 6\ Free-Regular-400.otf \
		${FONTSDIR}/Font\ Awesome\ 6\ Free-Solid-900.otf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/otfs/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
